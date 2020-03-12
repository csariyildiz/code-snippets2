# kmeans_iris.R
# R için k-means clustering'i göstermektedir  
# iris dataseti kullanılmıştır

# iris'i newiris içerisine yükle
newiris <- iris

# newiris için tür değerlerini null ata
newiris$Species <- NULL

# 3 noktalı k-means uygula
kc <- kmeans(newiris, 3)
kc

# iris türlerini, cluster'lar ile karşılaştır
table(iris$Species, kc$cluster)

# değerleri çizdir, cluster'a göre renklendir
plot(newiris[c("Sepal.Length", "Sepal.Width")], col=kc$cluster)

# merkez noktalarını işaretle
points(kc$centers[,c("Sepal.Length", "Sepal.Width")], col=1:3, pch=8, cex=2)

# Data içerisinde dört boyut varken plot'u çizdirmek için yalnızca ilk ikisi kullanılmıştır.
# Yeşil merkeze (asterisk) yakın olan bazı siyah noktalar aslında 4 boyutlu uzayda siyaha daha yakındır.
