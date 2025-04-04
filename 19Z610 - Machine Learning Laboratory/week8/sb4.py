# naive bayes, james, text classification
import pandas as pd
import os, sys

from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics import classification_report, accuracy_score
filename = input()
df = pd.read_csv(os.path.join(sys.path[0], filename))

X = df['document']
y = df['label']

xtr, xte, ytr, yte = train_test_split(X,y,test_size=0.3, random_state=42)
v = CountVectorizer()
vxtr = v.fit_transform(xtr)
vxte = v.fit_transform(xte)
# TODO: what is the difference between fit, transform and fit_transform

mnb = MultinomialNB()
mnb.fit(vxtr, ytr)
pred = mnb.predict(vxte)

ac = accuracy_score(yte, pred)
print(f"accuracy {ac:.2f}")

cr = classification_report(yte, pred, zero_division=1) # TODO: what is the use of zero_division
print(cr)