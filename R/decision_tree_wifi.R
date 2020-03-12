# Decision Trees with Package: party
# AP5 ve sonrası dahil edilmedi
# Kademe kademe çalıştır

library(readr)
deneme5 <- read_csv("C:\\Users\\acsar\\Desktop\\deneme5.csv", 
                    col_types = cols(
                      AP8 = col_skip(), AP9 = col_skip(), 
                      AP10 = col_skip(), AP11 = col_skip(), 
                      AP12 = col_skip(), AP13 = col_skip(), 
                      AP14 = col_skip(), AP15 = col_skip(), 
                      AP16 = col_skip(), AP17 = col_skip(), 
                      AP18 = col_skip(), AP19 = col_skip(), 
                      AP20 = col_skip(), AP21 = col_skip(), 
                      AP22 = col_skip(), AP23 = col_skip(), 
                      AP24 = col_skip(), AP5 = col_skip(), 
                      AP6 = col_skip(), AP7 = col_skip(), 
                      `CURRENT TIME NANOSECONDS` = col_skip(), 
                      `CURRENT TIME STRING` = col_skip()), 
                    na = "0")

# Data üzerinde bazı düzenlemeler

df <- as.data.frame(deneme5)
df[] <- lapply( df, factor)
col_names <- names(df)
df[col_names] <- lapply(df[col_names] , factor)

# Datayı iki alt kümeye ayır: train(70%) ve test(%30)
# Rastgele bir seed ile örneklemenin random olmasını sağla

set.seed(1234)
ind <- sample(2,nrow(df),replace=TRUE,prob=c(0.7,0.3))
train.data <- df[ind==1, ]
test.data <- df[ind==2, ]


## party library gerekli yoksa: install.packages("party")
library(party)

# Karar ağacını oluştur. !! Bu işlem uzun sürüyor.
ap_ctree <- ctree(Point ~ AP1 + AP2 + AP3 + AP4, data=train.data)

# table(predict(ap_ctree),train.data$Point)

# Karar ağacını ekrana bas.
print(ap_ctree)

# Test verisi üzerine tahmin yap
testPred <- predict(ap_ctree, newdata=test.data)

# Tahmini tablo olarak görüntüle
table(testPred,test.data$Point)
