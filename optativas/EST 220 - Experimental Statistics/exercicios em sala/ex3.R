library(openxlsx)
df <- data.frame(x = c(5,7,2,4,9,3,6,1,8),
                 trat = c(1,1,1,2,2,2,3,3,3),
                 rept = c(1,2,3,1,2,3,1,2,3),
                y = c(98,102,100,103,112,115,117,115,128))
#write.xlsx(df, "mydata.xlsx", sheetName = "Sheet1", colNames = TRUE)

# Realizar a análise de variância
# Ajustar o modelo estatístico
modelo <- aov(y ~ trat, data = df)

summary(modelo)

# Obter os resíduos
residuos <- residuals(modelo)

# Teste de Lilliefors
install.packages("nortest")
library(nortest)
lillie.test(residuos)

tratq <- factor(df$trat)
# Teste de Cochran
install.packages("outliers")
library(outliers)
cochran.test(residuos ~ tratq)

