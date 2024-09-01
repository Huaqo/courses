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
    
    # Remove when found a solution
    fix <- c(0:11)
    
    columns_to_remove <- unique(c(whites, skipped, fix))

    measurements <- measurements[, -columns_to_remove]
    spektren.df <- as.data.frame(measurements)
    
    # Reorder columns to match baum_ids if provided
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

  print(dim(measurements))

  rownames(spektren.df) <- wavelengths

  return(spektren.df)
}
# Function to calculate mean values for each tree
calculate_mean_values <- function(spektren.df, baum_id, spalten_pro_baum) {
  start_spalte <- (baum_id - 1) * spalten_pro_baum + 1
  end_spalte <- start_spalte + spalten_pro_baum - 1
  spalten_messungen <- start_spalte:end_spalte
  mean_values <- rowMeans(spektren.df[, spalten_messungen], na.rm = TRUE)
  return(mean_values)
}

# Function to create a dataframe with mean values for each tree
create_mean_values_df <- function(spektren.df, num_baeume, spalten_pro_baum) {
  mean_values_list <- list()
  
  for (baum_id in 1:num_baeume) {
    mean_values <- calculate_mean_values(spektren.df, baum_id, spalten_pro_baum)
    mean_values_list[[baum_id]] <- mean_values
  }
  
  # Combine all the mean values into a dataframe
  mean_values_df <- as.data.frame(do.call(cbind, mean_values_list))
  
  # Set the column names as the tree IDs (baum_id)
  colnames(mean_values_df) <- paste0("Tree_", 1:num_baeume)
  
  # Set the row names as the wavelengths
  rownames(mean_values_df) <- rownames(spektren.df)
  
  return(mean_values_df)
}

# Plot function for spectral data
plot_spectral_data <- function(spektren.df, output_file = "all.png", num_baeume, spalten_pro_baum, baum_ids, xlim = c(400, 1050), ylim = c(0, 1), main_title = "All Trees") {
  spalten_pro_baum <- as.integer(spalten_pro_baum)
  expected_columns <- num_baeume * spalten_pro_baum
  if (ncol(spektren.df) != expected_columns) {
    stop("The number of columns in spektren.df does not match the expected number based on num_baeume and spalten_pro_baum.")
  }

  png(output_file, width = 1024, height = 720)

  colors <- rainbow(num_baeume)

  plot(as.numeric(rownames(spektren.df)), rep(NA, nrow(spektren.df)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = main_title
  )

  for (baum_id in 1:num_baeume) {
    mean_values <- calculate_mean_values(spektren.df, baum_id, spalten_pro_baum)
    lines(as.numeric(rownames(spektren.df)), mean_values, type = "l", col = colors[baum_id], lwd = 6)
  }

  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )

  dev.off()
}

# Plot function for side-by-side spectral data
plot_side_by_side_spectral_data <- function(spektren.df1, spektren.df2, output_file = "side_by_side_plot.png", num_baeume, spalten_pro_baum, baum_ids, xlim = c(400, 1050), ylim = c(0, 1), titles = c("2022/07/21", "2022/08/12")) {
  spalten_pro_baum <- as.integer(spalten_pro_baum)

  expected_columns <- num_baeume * spalten_pro_baum
  if (ncol(spektren.df1) != expected_columns || ncol(spektren.df2) != expected_columns) {
    stop("The number of columns in one of the datasets does not match the expected number based on num_baeume and spalten_pro_baum.")
  }

  png(output_file, width = 1080, height = 1280)

  par(mfrow = c(2, 1)) # Set up the layout for two side-by-side plots

  colors <- rainbow(num_baeume)

  # Plot for the first dataset
  plot(as.numeric(rownames(spektren.df1)), rep(NA, nrow(spektren.df1)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = titles[1]
  )

  for (baum_id in 1:num_baeume) {
    mean_values <- calculate_mean_values(spektren.df1, baum_id, spalten_pro_baum)
    lines(as.numeric(rownames(spektren.df1)), mean_values, type = "l", col = colors[baum_id], lwd = 6)
  }

  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )

  # Plot for the second dataset
  plot(as.numeric(rownames(spektren.df2)), rep(NA, nrow(spektren.df2)),
       xlab = "Wavelength (nm)", ylab = "Reflection (%)",
       type = "n", ylim = ylim, xlim = xlim,
       main = titles[2]
  )

  for (baum_id in 1:num_baeume) {
    mean_values <- calculate_mean_values(spektren.df2, baum_id, spalten_pro_baum)
    lines(as.numeric(rownames(spektren.df2)), mean_values, type = "l", col = colors[baum_id], lwd = 6)
  }

  legend("topleft",
         legend = baum_ids,
         text.col = colors,
         pch = rep("-", num_baeume),
         col = colors, lwd = 2
  )

  dev.off()
}

# Function to integrate the difference between two datasets
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

### Main

# Process and plot spectral data from "export_20220721.dat"
baum_ids_20220812 <- c(
  "DE1 (B1-10-5-5)", "DE2 (B1-10-5-3)", "DE4 (B1-10-4-5)", "DE7 (B3-11-3-3)", "DE8 (B3-11-1-3)",
  "DE10 (B 3-11-1-1)", "IT2 (A 1-9-3-5)", "IT3 (A 1-9-4-4)", "IT5 (A 1-9-5-2)", "IT7 (B 1-2-3-3)",
  "IT8 (B 1-2-2-2)", "IT9 (B 1-2-2-3)", "ES2 (A 2-3-3-2)", "ES5 (A 2-3-4-4)",
  "ES8 (B 2-10-5-5)", "ES9 (B 2-10-2-4)", "ES10 (B 2-10-3-1)", "FR1 (A 1-7-2-5)", "FR2 (A 1-7-1-1)",
  "FR4 (A 1-1-1-3)", "FR5 (A 1-1-2-5)", "FR6 (A 1-1-2-3)", "FR10 (A 1-1-5-4)"
)

spektren20220721.df <- process_spectral_data(
  file_path = "~/Developer/courses/2021\ Projektbezogenes\ Arbeiten/Abschlussarbeit/data/export_20220721.dat",
  grouping_size = 17,
  exclude_index = 8,
  encoding = "UTF-16LE",
  baum_ids = baum_ids_20220812
)

plot_spectral_data(
  spektren.df = spektren20220721.df,
  output_file = "20220721.png",
  num_baeume = 23,
  spalten_pro_baum = 15,
  baum_ids = baum_ids_20220812,
  xlim = c(400, 1050),
  ylim = c(0, 1),
  main_title = "2022/07/21"
)

# Process and plot spectral data from "export_20220812.dat"
spektren20220812.df <- process_spectral_data(
  file_path = "~/Developer/courses/2021\ Projektbezogenes\ Arbeiten/Abschlussarbeit/data/export_20220812.dat",
  grouping_size = 17,
  exclude_index = 13,
  encoding = "UTF-16LE"
)

plot_spectral_data(
  spektren.df = spektren20220812.df,
  output_file = "20220812.png",
  num_baeume = 23,
  spalten_pro_baum = 15,
  baum_ids = baum_ids_20220812,
  xlim = c(400, 1050),
  ylim = c(0, 1),
  main_title = "2022/08/12"
) 

# Plot side-by-side comparison of 20220721 and 20220812 datasets
plot_side_by_side_spectral_data(
  spektren.df1 = spektren20220721.df,
  spektren.df2 = spektren20220812.df,
  output_file = "20220722_and_20220812.png",
  num_baeume = 23,
  spalten_pro_baum = 15,
  baum_ids = baum_ids_20220812,
  xlim = c(400, 1050),
  ylim = c(0, 1),
  titles = c("2022/07/21", "2022/08/12")
)

# Create a dataframe with mean values for each tree from the 20220721 dataset
mean_values_20220721.df <- create_mean_values_df(spektren20220721.df, num_baeume = 23, spalten_pro_baum = 15)

write.csv(mean_values_20220721.df,"means.csv")

# Create a dataframe with mean values for each tree from the 20220812 dataset
mean_values_20220812.df <- create_mean_values_df(spektren20220812.df, num_baeume = 23, spalten_pro_baum = 15)

# Integrate differences between the two datasets
integral_results <- integrate_difference(
  df1 = spektren20220721.df,
  df2 = spektren20220812.df,
  num_baeume = 23,
  spalten_pro_baum = 15
)

# Invert and sort the integral results
inverted_integral_results <- -integral_results
sorted_indices <- order(inverted_integral_results)
sorted_integral_results <- inverted_integral_results[sorted_indices]
sorted_baum_ids <- baum_ids_20220812[sorted_indices]

# Plot the integral of reflection differences
png("integral.png", width = 1024, height = 1024)

par(mar = c(10, 5, 4, 2) + 0.1)

barplot(sorted_integral_results, 
        names.arg = sorted_baum_ids, 
        las = 2,
        col = "skyblue", 
        main = "Integral of Reflection Differences", 
        xlab = "", 
        ylab = "Percentage-Nanometers (%·nm)",
        cex.names = 1,
        horiz = FALSE)
dev.off()
