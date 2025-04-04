# encoding, dev, employee_data.csv

import pandas as pd
import os, sys
from sklearn.preprocessing import OneHotEncoder, OrdinalEncoder, LabelEncoder
df = pd.read_csv(os.path.join(sys.path[0], "filename.csv"))

ohe = OneHotEncoder(sparse=False)
ge = ohe.fit_transform(df['Gender'])
