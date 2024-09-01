#install packages
#install.packages('RColorBrewer')
#install.packages('rgeos')


# load spatial packages
library(raster)
library(rgdal)
library(rgeos)
library(RColorBrewer)

setwd("/Users/hannascheiwe/Desktop/Geo4.Semester/PjS_urbanefernerkundun/Vortrag_Trockenstress/daten")

# turn off factors
#options(stringsAsFactors = FALSE)

multispectral_st_2018 <- stack("/Users/hannascheiwe/Desktop/Geo4.Semester/PjS_urbanefernerkundun/Vortrag_Trockenstress/daten/sen2_20180901.tif")

plotRGB(multispectral_st_2018, 3,2,1, stretch="lin")

crop_extent <- readOGR("/Users/hannascheiwe/Desktop/Geo4.Semester/PjS_urbanefernerkundun/Vortrag_Trockenstress/daten/Berlin_Bezirke.shp")

charlottenburg_wilmersdorf <- crop_extent[crop_extent$ORTSTNAME=="Grunewald",]

plot(charlottenburg_wilmersdorf)

plot(charlottenburg_wilmersdorf,
     main = "Shapefile imported into R - crop extent",
     axes = TRUE,
     border = "blue")

#compare_CRS(charlottenburg_wilmersdorf, multispectral_st_2018)

shp<- spTransform(charlottenburg_wilmersdorf, crs(multispectral_st_2018))

ausschnitt_grunewald_2018<- crop(multispectral_st_2018, shp)

plotRGB(ausschnitt_grunewald_2018,3,2,1, stretch= "lin")

ndvi_2018 <- (ausschnitt_grunewald_2018[[7]] - ausschnitt_grunewald_2018[[3]]) / (ausschnitt_grunewald_2018[[7]] + ausschnitt_grunewald_2018[[3]])

plot(ndvi_2018, main = "ndvi_2018", axes = FALSE, box = FALSE)

hist(ndvi_2018,
     main = "ndvi_2018: Distribution of pixels",
     col = "springgreen",
     xlab = "NDVI Index Value")

#writeRaster(x = ndvi_2018,
    #filename="...",
    #format = "GTiff", # save as a tif
    #datatype='INT2S', # save as a INTEGER rather than a float
    #overwrite = TRUE)  # OPTIONAL - be careful. This will OVERWRITE previous files.

ndwi_2018 <- (ausschnitt_grunewald_2018[[7]] - ausschnitt_grunewald_2018[[10]]) / (ausschnitt_grunewald_2018[[7]] + ausschnitt_grunewald_2018[[10]])

plot(ndwi_2018, main = "ndwi_2018", axes = FALSE, box = FALSE)

hist(ndwi_2018,
     main = "ndwi_2018: Distribution of pixels",
     col = "springgreen",
     xlab = "NDVI Index Value")

#writeRaster(x = ndwi_2018,
            #filename="...",
            #format = "GTiff", # save as a tif
            #datatype='INT2S', # save as a INTEGER rather than a float
            #overwrite = TRUE)  # OPTIONAL - be careful. This will OVERWRITE previous files.

multispectral_2020 <- stack("/Users/hannascheiwe/Desktop/Geo4.Semester/PjS_urbanefernerkundun/Vortrag_Trockenstress/daten/S2A_20200816.tif")

plotRGB(multispectral_2020, 3,2,1, stretch="lin")

compare_CRS(charlottenburg_wilmersdorf_2020, multispectral_2020)

shp_2020<- spTransform(charlottenburg_wilmersdorf_2020, crs(multispectral_2020))

ausschnitt_grunewald_2018_2020<- crop(multispectral_2020, shp_2020)

plotRGB(ausschnitt_grunewald_2018_2020,3,2,1, stretch= "lin")

ndvi_2020 <- (ausschnitt_grunewald_2020[[7]] - ausschnitt_grunewald_2020[[3]]) / (ausschnitt_grunewald_2020[[7]] + ausschnitt_grunewald_2020[[3]])

plot(ndvi_2020, main = "ndvi_2020", axes = FALSE, box = FALSE)

hist(ndvi_2020,
     main = "NDVI: Distribution of pixels",
     col = "springgreen",
     xlab = "NDVI Index Value")

#writeRaster(x = ndvi_2020,
            #filename="...",
            #format = "GTiff", # save as a tif
            #datatype='INT2S', # save as a INTEGER rather than a float
            #overwrite = TRUE)  # OPTIONAL - be careful. This will OVERWRITE previous files.

#NDWI:
#(NIR-SWIR)/(NIR+SWIR)

ndwi_2020 <- (ausschnitt_grunewald_2020[[7]] - ausschnitt_grunewald_2020[[10]]) / (ausschnitt_grunewald_2020[[7]] + ausschnitt_grunewald_2020[[10]])

plot(ndwi_2020, main = "ndwi_2020", axes = FALSE, box = FALSE)

hist(ndwi_2020,
     main = "NDWI: Distribution of pixels",
     col = "springgreen",
     xlab = "NDVI Index Value")

#writeRaster(x = ndwi_2020,
            #filename="...",
            #format = "GTiff", # save as a tif
            #datatype='INT2S', # save as a INTEGER rather than a float
            #overwrite = TRUE)  # OPTIONAL - be careful. This will OVERWRITE previous files.

difference_ndvi<- ndvi_2018 - ndvi_2020
plot(difference_ndvi, main = "NDVI Difference", axes = FALSE, box = FALSE)

difference_ndvi<- ndvi_2018 - ndvi_2020
plot(difference_ndvi, main = "NDVI Difference", axes = FALSE, box = FALSE)