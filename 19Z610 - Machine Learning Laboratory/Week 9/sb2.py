import pandas as pd
from sklearn.cluster import KMeans
import os, sys

df = pd.read_csv(os.path.join(sys.path[0], "data.csv"))

X = df[["SALES_AMOUNT", "TOTAL_SALES_AMOUNT"]].dropna()

kms = KMeans(n_clusters=2, random_state=42, n_init=10);
kms.fit(X)

v1, v2 = float(input()), float(input())

pred = kms.predict([[v1, v2]])

print(pred)