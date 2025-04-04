import pandas as pd
import os, sys
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

df = pd.read_csv(os.path.join(sys.path[0], input()))

X = df.iloc[:, :-1]
y = df.iloc[:, -1]

xtra, xtes, ytra, ytes = train_test_split(X, y, test_size=0.3, random_state=42)

lr = LinearRegression()
lr.fit(xtra, ytra)

pred = lr.predict(xtes)
intercept = lr.intercept_
coeff = lr.coef_[0]

print(f"Intercept: {intercept}")
print(f"Coefficient: {coeff}")
print(f"R2 Score: {r2_score(ytes, pred)}")