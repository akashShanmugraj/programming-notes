# kmeans clustering Diya 

import pandas as pd
from sklearn.cluster import KMeans
import os,sys

df = pd.read_csv(os.path.join(sys.path[0], "data.csv"))

if not all(col in df.columns for col in ["COLUMN_A", "COLUMN_B"]):
    raise ValueError("Missing required Columns")

X = df[["COLUMN_A", "COLUMN_B"]]

kmeans = KMeans(n_clusters=4, random_state=42, n_init=10);
kmeans.fit(X)

v1, v2 = float(input()), float(input()) #TODO Monish had different input method

pred = kmeans.predict([[v1, v2]])[0] #TODO actual params and the params that monish passes seems to be contradicting

print(pred)