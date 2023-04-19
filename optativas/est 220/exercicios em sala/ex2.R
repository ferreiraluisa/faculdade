library(openxlsx)
df <- data.frame($ = c(1,1,1,1,1,2,2,2,2,2),
                 $ = c(2.1,2.3,2.5,2.7,2.9,2.5,2.6,2.7,2.8,2.9))
write.xlsx(df, "mydata.xlsx", sheetName = "Sheet1", colNames = TRUE)

str(df)

library(openxlsx)
mydata <- read.xlsx("mydata.xlsx", sheet = "Sheet1")

# Use $ notation
mydata$x
mydata$y

# Use with() function
with(mydata, var.test(y ~ x, ratio = 1, alternative = "two.sided", conf.level = 0.95))
with(mydata, var.test(y ~ x, alternative = "greater"))
