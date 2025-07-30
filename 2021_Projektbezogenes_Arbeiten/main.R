# Functions
process_spectral_data <- function(file_path, grouping_size = 17, exclude_index = 13, encoding = "UTF-16LE", baum_ids = NULL) {
  spektren <- readLines(file(file_path, encoding = encoding))
  spektren <- gsub("\ufeff", "", spektren)
  spektren <- strsplit(spektren, "\t")
  wavelengths <- as.numeric(sapply(spektren, function(x) strsplit(x[1], ",")[[1]][1]))
  measurements <- do.call(rbind, lapply(spektren, function(row) {
    sapply(row, function(part) as.numeric(strsplit(part, ",")[[1]][2]))
  }))
  if (basename(file_path) == "export_20220721.dat") {
    whites <- c()
    for (j in 1:ncol(measurements)) {
      value <- measurements[1, j]
      if (!is.na(value) && floor(value) == 1) {
        whites <- c(whites,j)
      }
    }
    skipped <- c(88, 138, 139, 180, 293, 311, 312, 313, 317, 395)
    fix <- c(0:11)
    columns_to_remove <- unique(c(whites, skipped, fix))
    measurements <- measurements[, -columns_to_remove]
    spektren.df <- as.data.frame(measurements)
    if (!is.null(baum_ids)) {
      baum_ids_20220721 <- c(
        "ES8 (B 2-10-5-5)", "ES9 (B 2-10-2-4)", "IT8 (B 1-2-2-2)", "DE7 (B3-11-3-3)", "DE8 (B3-11-1-3)",
        "FR1 (A 1-7-2-5)", "FR2 (A 1-7-1-1)", "ES1 (A 2-3-3-3)", "ES2 (A 2-3-3-2)", "IT2 (A 1-9-3-5)",
        "IT3 (A 1-9-4-4)", "FR5 (A 1-1-2-5)", "FR6 (A 1-1-2-3)", "DE1 (B1-10-5-5)", "DE2 (B1-10-5-3)",
        "IT7 (B 1-2-3-3)", "DE4 (B1-10-4-5)", "DE10 (B 3-11-1-1)", "ES10 (B 2-10-3-1)", "IT9 (B 1-2-2-3)",
        "IT5 (A 1-9-5-2)", "ES5 (A 2-3-4-4)", "FR10 (A 1-1-5-4)", "FR4 (A 1-1-1-3)"
      )
      baum_order_20220721 <- match(baum_ids, baum_ids_20220721)
      reordered_columns <- unlist(lapply(baum_order_20220721, function(x) {
        start_col <- (x - 1) * 15 + 1
        end_col <- start_col + 14
        return(start_col:end_col)
      }))
      spektren.df <- spektren.df[, reordered_columns]
    }
  }
  if (basename(file_path) == "export_20220812.dat") {
    measurements_filtered <- list()
    for (i in seq(1, ncol(measurements), by = grouping_size)) {
      tree_index <- (i - 1) / grouping_size + 1
      if (tree_index != exclude_index) {
        measurements_filtered[[length(measurements_filtered) + 1]] <- measurements[, (i + 1):(i + grouping_size - 2)]
      }
    }
    measurements_filtered <- do.call(cbind, measurements_filtered)
    spektren.df <- as.data.frame(measurements_filtered)
  }
  rownames(spektren.df) <- wavelengths
  return(spektren.df)
}

calculate_mean_values <- function(spektren.df, baum_id, spalten_pro_baum) {
  start_spalte <- (baum_id - 1) * spalten_pro_baum + 1
  end_spalte <- start_spalte + spalten_pro_baum - 1
  spalten_messungen <- start_spalte:end_spalte
  mean_values <- rowMeans(spektren.df[, spalten_messungen], na.rm = TRUE)
  return(mean_values)
}

create_mean_values_df <- function(spektren.df, num_baeume, spalten_pro_baum) {
  mean_values_list <- list()
  for (baum_id in 1:num_baeume) {
    mean_values <- calculate_mean_values(spektren.df, baum_id, spalten_pro_baum)
    mean_values_list[[baum_id]] <- mean_values
  }
  mean_values_df <- as.data.frame(do.call(cbind, mean_values_list))
  colnames(mean_values_df) <- paste0("Tree_", 1:num_baeume)
  rownames(mean_values_df) <- rownames(spektren.df)
  return(mean_values_df)
}

integrate_difference <- function(df1, df2, num_baeume, spalten_pro_baum) {
  if (ncol(df1) != ncol(df2) || nrow(df1) != nrow(df2)) {
    stop("The dataframes must have the same dimensions.")
  }
  wavelengths <- as.numeric(rownames(df1))
  integral_results <- numeric(num_baeume)
  for (baum_id in 1:num_baeume) {
    mean_values_df1 <- calculate_mean_values(df1, baum_id, spalten_pro_baum)
    mean_values_df2 <- calculate_mean_values(df2, baum_id, spalten_pro_baum)
    difference <- mean_values_df1 - mean_values_df2
    integral_results[baum_id] <- sum(diff(wavelengths) * (head(difference, -1) + tail(difference, -1)) / 2)
  }
  return(integral_results)
}

calculate_wbi <- function(mean_values_df) {
  wavelengths <- 325:1075
  wavelength_900 <- which(wavelengths == 900)
  wavelength_970 <- which(wavelengths == 970)
  
  wbi_values <- apply(mean_values_df, 2, function(column) {
    column[wavelength_900] / column[wavelength_970]
  })
  
  return(wbi_values)
}

calculate_wbi_differences <- function(wbi_values1, wbi_values2) {
  if (length(wbi_values1) != length(wbi_values2)) {
    stop("The two WBI datasets must have the same length.")
  }
  
  wbi_diff <- wbi_values1 - wbi_values2
  return(wbi_diff)
}


plot_spectral_data <- function(mean_values_df, output_file = "all.png", baum_ids, xlim = c(400, 1050), ylim = c(0, 1), date_of_capture) {
  num_baeume <- ncol(mean_values_df)
  png(output_file, width = 1024, height = 720)
  colors <- rainbow(num_baeume)
  plot(as.numeric(rownames(mean_values_df)), rep(NA, nrow(mean_values_df)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = paste("Spectral Data -", date_of_capture)
  )
  for (baum_id in 1:num_baeume) {
    lines(as.numeric(rownames(mean_values_df)), mean_values_df[, baum_id], type = "l", col = colors[baum_id], lwd = 6)
  }
  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )
  dev.off()
}


plot_side_by_side_spectral_data <- function(mean_values_df1, mean_values_df2, output_file = "side_by_side_plot.png", baum_ids, xlim = c(400, 1050), ylim = c(0, 1), dates) {
  num_baeume <- ncol(mean_values_df1)
  png(output_file, width = 1080, height = 1280)
  par(mfrow = c(2, 1)) 
  colors <- rainbow(num_baeume)
  
  plot(as.numeric(rownames(mean_values_df1)), rep(NA, nrow(mean_values_df1)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = paste("Spectral Data -", dates[1])
  )
  for (baum_id in 1:num_baeume) {
    lines(as.numeric(rownames(mean_values_df1)), mean_values_df1[, baum_id], type = "l", col = colors[baum_id], lwd = 6)
  }
  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )
  
  plot(as.numeric(rownames(mean_values_df2)), rep(NA, nrow(mean_values_df2)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = paste("Spectral Data -", dates[2])
  )
  for (baum_id in 1:num_baeume) {
    lines(as.numeric(rownames(mean_values_df2)), mean_values_df2[, baum_id], type = "l", col = colors[baum_id], lwd = 6)
  }
  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )
  
  dev.off()
}

plot_wbi_values <- function(wbi_values, baum_ids, output_file = "wbi_values_sorted_scaled.png", date_of_capture) {
  png(output_file, width = 1024, height = 720)
  par(mar = c(10, 5, 4, 2) + 0.1)
  sorted_indices <- order(wbi_values)
  sorted_wbi_values <- wbi_values[sorted_indices]
  sorted_baum_ids <- baum_ids[sorted_indices]
  min_wbi <- min(sorted_wbi_values) - 0.002
  max_wbi <- max(sorted_wbi_values) + 0.002
  barplot(
    sorted_wbi_values, 
    names.arg = sorted_baum_ids,
    col = "steelblue", 
    main = paste("Water Band Index (WBI) -", date_of_capture),
    xlab = "", 
    ylab = "WBI Value",
    las = 2,
    ylim = c(min_wbi, max_wbi)
  )
  dev.off()
}

plot_combined_wbi_values <- function(wbi_values_1, wbi_values_2, baum_ids, output_file = "combined_wbi_plot.png", dates = c("2022/07/21", "2022/08/12")) {
  combined_wbi <- cbind(wbi_values_1, wbi_values_2)
  colnames(combined_wbi) <- dates
    sorted_indices <- order(wbi_values_1)
  sorted_combined_wbi <- combined_wbi[sorted_indices,]
  sorted_baum_ids <- baum_ids[sorted_indices]
  png(output_file, width = 1024, height = 720)
  par(mar = c(10, 5, 4, 2) + 0.1)
  barplot(
    t(sorted_combined_wbi), 
    beside = TRUE,
    names.arg = sorted_baum_ids,
    col = c("steelblue", "darkorange"),
    main = "Water Band Index (WBI) - 2022/07/22 & 2022/08/12",
    xlab = "",
    ylab = "WBI Value",
    las = 2,
    ylim = range(sorted_combined_wbi) * c(0.95, 1.05)
  )
  legend("topleft", legend = dates, fill = c("steelblue", "darkorange"))
  dev.off()
}

plot_wbi_differences <- function(wbi_diff, baum_ids, output_file = "wbi_differences_sorted.png") {
  wbi_diff <- -wbi_diff
  sorted_indices <- order(wbi_diff)
  sorted_wbi_diff <- wbi_diff[sorted_indices]
  sorted_baum_ids <- baum_ids[sorted_indices]
  
  png(output_file, width = 1024, height = 720)
  par(mar = c(10, 5, 4, 2) + 0.1)
  barplot(
    sorted_wbi_diff, 
    names.arg = sorted_baum_ids,
    col = "steelblue", 
    main = "Differenzen im Water Band Index (WBI)",
    xlab = "", 
    ylab = "WBI Differenz",
    las = 2
  )
  
  dev.off()
}


# Variables
baum_ids_20220812 <- c(
  "DE1 (B1-10-5-5)", "DE2 (B1-10-5-3)", "DE4 (B1-10-4-5)", "DE7 (B3-11-3-3)", "DE8 (B3-11-1-3)",
  "DE10 (B 3-11-1-1)", "IT2 (A 1-9-3-5)", "IT3 (A 1-9-4-4)", "IT5 (A 1-9-5-2)", "IT7 (B 1-2-3-3)",
  "IT8 (B 1-2-2-2)", "IT9 (B 1-2-2-3)", "ES2 (A 2-3-3-2)", "ES5 (A 2-3-4-4)",
  "ES8 (B 2-10-5-5)", "ES9 (B 2-10-2-4)", "ES10 (B 2-10-3-1)", "FR1 (A 1-7-2-5)", "FR2 (A 1-7-1-1)",
  "FR4 (A 1-1-1-3)", "FR5 (A 1-1-2-5)", "FR6 (A 1-1-2-3)", "FR10 (A 1-1-5-4)"
)

# Calculation
spektren20220721.df <- process_spectral_data(file_path = "~/Developer/courses/2021\ Projektbezogenes\ Arbeiten/Abschlussarbeit/data/export_20220721.dat", grouping_size = 17, exclude_index = 8, encoding = "UTF-16LE", baum_ids = baum_ids_20220812)
spektren20220812.df <- process_spectral_data(file_path = "~/Developer/courses/2021\ Projektbezogenes\ Arbeiten/Abschlussarbeit/data/export_20220812.dat", grouping_size = 17, exclude_index = 13, encoding = "UTF-16LE")
mean_values_20220721.df <- create_mean_values_df(spektren20220721.df, num_baeume = 23, spalten_pro_baum = 15)
mean_values_20220812.df <- create_mean_values_df(spektren20220812.df, num_baeume = 23, spalten_pro_baum = 15)
wbi_20220721 <- calculate_wbi(mean_values_20220721.df)
wbi_20220812 <- calculate_wbi(mean_values_20220812.df)
wbi_diff <- calculate_wbi_differences(wbi_20220721,wbi_20220812)

# Plotting
plot_spectral_data(mean_values_df = mean_values_20220721.df, output_file = "plots/spectrum_20220721.png", baum_ids = baum_ids_20220812, xlim = c(400, 1050), ylim = c(0, 1), date_of_capture = "2022/07/21")
plot_spectral_data(mean_values_df = mean_values_20220812.df, output_file = "plots/spectrum_20220812.png", baum_ids = baum_ids_20220812, xlim = c(400, 1050), ylim = c(0, 1), date_of_capture = "2022/08/12")
plot_wbi_values(wbi_20220721, baum_ids = baum_ids_20220812, output_file = "plots/wbi_20220721.png", date_of_capture = "2022/07/21")
plot_wbi_values(wbi_20220812, baum_ids = baum_ids_20220812, output_file = "plots/wbi_20220812.png", date_of_capture = "2022/08/12")
plot_combined_wbi_values(wbi_values_1 = wbi_20220721, wbi_values_2 = wbi_20220812, baum_ids = baum_ids_20220812, output_file = "plots/wbi_combined.png", dates = c("2022/07/21", "2022/08/12"))
plot_wbi_differences(wbi_diff, baum_ids = baum_ids_20220812, output_file = "plots/wbi_differences.png")