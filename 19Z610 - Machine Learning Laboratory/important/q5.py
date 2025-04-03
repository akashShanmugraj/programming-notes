import pandas as pd
import sys, os

from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.impute import SimpleImputer

filename = "filename.csv"
df = pd.read_csv(os.path.join(sys.path[0], filename))
df = df.dropna()

meanimputer = SimpleImputer(strategy="mean")
modeimputer = SimpleImputer(strategy="most_frequent")
medianimputer = SimpleImputer(strategy="median")

df["ImputedEmployment"] = modeimputer.fit_transform(df[["Employment"]])
df["ImputedPopulation"] = meanimputer.fit_transform(df[["Population"]])
df["ImputedIncome"] = medianimputer.fit_transform(df[["Income"]])

stdscaler = StandardScaler()
normscaler = MinMaxScaler()
df["StandardizedImputedIncome"] = stdscaler.fit_transform(df[["ImputedIncome"]])
df["NormalizedImputedIncome"] = normscaler.fit_transform(df[["ImputedIncome"]])