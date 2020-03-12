# kmeans_wifi.R
# R için k-means clustering'i göstermektedir  
# IDE: RGui

## readr kütüphanesini çağır
library(readr)
## csv içerisinden oku.
deneme5 <- read_csv("C:\\Path\\To\\File\\deneme5.csv", 
                    col_types = cols(
                      `CURRENT TIME NANOSECONDS` = col_skip(), 
                      `CURRENT TIME STRING` = col_skip()),
                    na = "0")

df <- deneme5

## Sonuca etkisi yok!!
#df$AP1 <- (df$AP1 + 100)/100
#df$AP2 <- (df$AP2 + 100)/100
#df$AP3 <- (df$AP3 + 100)/100
#df$AP4 <- (df$AP4 + 100)/100

df <- as.data.frame(df)

set.seed(1)
newdf <- df
newdf$Point <- NULL

## kmeans'i newdf'ye uygula, clustering sonuçlarını kc içerisinde sakla. Cluster sayısını 20'ye eşitle.
results <- kmeans(newdf, 20)
results


table(df$Point, results$cluster)
