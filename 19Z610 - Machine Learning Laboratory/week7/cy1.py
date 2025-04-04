# NN, mlpclass, reka
# TODO: yet to complete
import pandas as pd
import os, sys
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.neural_network import MLPClassifier

df = pd.read_csv(os.path.join(sys.path[0], "filename.csv"))

v = CountVectorizer(analyzer='char', ngram_range=(1,3))
X = v.fit_transform(df['Word']).toarray()
y = df['Label'].values

model = MLPClassifier(hidden_layer_sizes=(10,5), max_iter=1000, random_state=42)
model.fit(X,y)

input_word = input().strip().lower()

match = df[df['Word'] == input_word]