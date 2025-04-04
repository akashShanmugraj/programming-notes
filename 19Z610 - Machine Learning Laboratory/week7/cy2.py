# decision tree classifier, ravi, products
# TODO: Check if this file can actually

import pandas as pd
import os, sys
from sklearn.tree import DecisionTreeClassifier
from sklearn.preprocessing import OneHotEncoder


df = pd.read_csv(os.path.join(sys.path[0], "filename.csv"))
X = df[['Unit_Price', 'Units_Sold', 'Total_Revenue', 'Category']]
y = df['Product_Name']

def ppr(xframe):
    ecdr = OneHotEncoder(handle_unknown='ignore', sparse=False)
    nxs = pd.DataFrame(ecdr.fit_transform(xframe['Category']))
    nxs.cols = ecdr.get_feature_names(['Category'])

    Xf = pd.concat([
        xframe[['Unit_Price', 'Units_Sold', 'Total_Revenue']],
        nxs
        ],
        axis=1
    )
    
    return Xf, nxs

Xf, nxs = ppr(X)

v1, v2, v3, v4 = int(input().strip()), int(input().strip()), int(input().strip()), input().strip()
indf = pd.DataFrame([[v1,v2,v3,v4]], columns=['Unit_Price', 'Units_Sold', 'Total_Revenue', 'Category'])

dtc = DecisionTreeClassifier(random_state=42)
dtc.fit(Xf, y)

ppr_indf = ppr(indf)
pred = dtc.predict(ppr_indf)

print(f"Prediction: {pred}")