
###############################################
# Spektrendatei �ffnen                        #
###############################################

setwd("C:\\Users\\stellmes\\Documents\\202207")

spektren <- read.table("export_20220714.dat", header=F, fileEncoding = "UTF16")

View(spektren)

###############################################
# Tabelle anpassen                            #
###############################################


spektren.df <- lapply(spektren, function(x) {gsub(",", "", x)})
spektren.df <- lapply(spektren.df, function(x) as.numeric(x))
spektren.df <- as.data.frame(spektren.df)

wl <- "wavelength"
#white <- as.character(1)
messungen <- as.character(seq(1,290,1))

names <- c(rbind(wl, messungen))
names(spektren.df) <- names

View(spektren.df)


###############################################
# Messungen mit Korrektur der Referenzmessung #
###############################################

# Die �berpr�fung der Plausibilt�t der Messungen ist ein wichtiger Schritt
# Wir �berpr�fen hier die Referenzmessung und bekommen einen Eindruck
# vom mittleren Reflexionsverhalten der gemessenen Bl�tter


### Angaben zur Messung des Baumes
prov = "xyz"
baum.id = "abc"

# Spalte der Referenzmessung
spalte.ref = 1

# Vektor mit Blattmessungen
spalten.messungen = seq(2,16,1)

# alternativ (falls es mal Fehlmessungen etc. gibt)
#spalten.messungen = c(2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)

# Spalte der wei�en Referenz
white=as.character(spalte.ref)

# Spalten der dazugeh�rigen Messungen
mean <- rowMeans(spektren.df[, as.character(spalten.messungen)])

# Farbe Linie f�r das mittlere Spektrum
col1 =" forest green"
# Farbe f�r die Referenzmessung
col2 = "gray"

# Plot mean
plot(spektren.df$wavelength, 
     mean, 
     xlab="Wellenl�nge (nm)", ylab="Reflexion (%)", 
     type="l", col=col1, lwd=3, 
     ylim= c(0,1), xlim=c(400,1050),
     main=paste("Baum ", baum.id, ", Provenienz ", prov, sep=""))
lines(spektren.df$wavelength, unlist(spektren.df[white]), type="l", col=col2, lwd=3)

legend("bottomright",legend=c(paste("Baum ", baum.id, ", Provenienz ", prov, sep=""), "Referenz"),
       text.col=c(col1, col2),pch=c("-"),col=c(col1, col2), lwd=3)


# Folgende Korrekture ist normalerweise nicht notwendig, wir m�ssen aber teilweise die Spektren
# korrigieren, da die gemessene wei�e Referenz start von der "Einserlinie" abweicht.

# Bei den Messungen, wo die Referenz um 1 liegt, sieht man nat�rlich keinen 
# gro�en Effekt,

# Es is aber fraglich, ob die Korrektur immer ausreichend ist.
mean.ratio <- mean*1/unlist(spektren.df[white])



# Plot mean.ratio
plot(spektren.df$wavelength, 
     mean.ratio, 
     xlab="Wellenl�nge (nm)", ylab="Reflexion (%)", 
     type="l", col=col1, lwd=3, 
     ylim= c(0,1), xlim=c(400,1050),
     main=paste("Korrigiert - Baum ", baum.id, ", Provenienz ", prov, sep=""))
lines(spektren.df$wavelength, unlist(spektren.df[white]), type="l", col=col2, lwd=3)

legend("bottomright",
       legend=c(paste("Baum ", baum.id, ", Provenienz ", prov, sep=""), "Referenz"),
       text.col=c(col1, col2), pch=c("-"),col=c(col1, col2), lwd=3)




################################################
# Plotten der Einzelmessungen f�r eine Messreihe #
################################################

# Einzelmessungen einer Messreihe

# Hier k�nnen wir uns anschauen, ob alles mit den einzelnen Spektren passt un
# wie variabel die Messungen sind. Ggf. k�nnen noch Fehlmessungen ausgeschlossen werden.

# Hier der Plot ohne Korrektur der Referenz, ist aber nat�rlich ohne Weiteres umsetzbar

plot(spektren.df$wavelength, 
     spektren.df[, as.character(spalten.messungen)[1]], 
     xlab="Wellenl�nge (nm)", 
     ylab="Reflexion (%)", 
     type="l", col=col2, lwd=1, 
     ylim= c(0,0.6), xlim=c(400,1050), 
     main=paste("Baum ", baum.id, ", Provenienz ", prov, sep=""))
for (i in 2:length(spalten.messungen)){
  lines(spektren.df$wavelength, 
        spektren.df[, as.character(spalten.messungen [i])], 
        col=col2, lwd=1)
}

