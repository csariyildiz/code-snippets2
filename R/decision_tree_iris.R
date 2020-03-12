# decision_tree_iris.R
str(iris)

set.seed(1234)

ind <- sample(2, nrow(iris), replace = TRUE, prob = c(0.7, 0.3))

train.data <- iris[ind == 1, ]

test.data <- iris[ind == 2, ]

library(party)

myFormula <- Species ~ Sepal.Length + Sepal.Width + Petal.Length +

Petal.Width

iris_ctree <- ctree(myFormula, data = train.data)

print(iris_ctree)

plot(iris_ctree)

plot(iris_ctree, type = "simple")

testPred <- predict(iris_ctree, newdata = test.data)

table(testPred, test.data$Species)
