import pandas as pd
import sys, os
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, MinMaxScaler

dataset = "filename.csv"

df = pd.read_csv(os.path.join(sys.path[0], dataset))

missingvals = df.isnull().sum()
df = df.dropna()

imputeddf = df.copy()

meanimputer = SimpleImputer(strategy="mean")
imputeddf[['LoanAmount']] = meanimputer.fit_transform(df[["LoanAmount"]])

mostfreqimputer = SimpleImputer(strategy="most_frequent")
imputeddf[['Loan_Term']] = mostfreqimputer.fit_transform(df[["Loan_Term"]])

categorical_cols = ["Gender", "Credit_History", "Loan_Status"]
for col in categorical_cols:
    imputeddf[col].fillna(imputeddf[col].mode()[0], inplace=True)
    
scaler = StandardScaler()
imputeddf['LoanAmount_Standardized'] = scaler.fit_transform(imputeddf[["LoanAmount"]])

normalizer = MinMaxScaler()
imputeddf['LoanAmount_Normalized'] = normalizer.fit_transform(imputeddf[["LoanAmount"]])

print(imputeddf["LoanAmount_Standardized"].to_string(index=False))
print(imputeddf["LoanAmount_Normalized"].to_string(index=False))