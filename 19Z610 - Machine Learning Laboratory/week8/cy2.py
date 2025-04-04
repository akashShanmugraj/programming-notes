# SVM, alice, measurements of Iris flowers
import os, sys
import pandas as pd
from sklearn.svm import LinearSVC, SVC
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split

df = pd.read_csv(os.path.join(sys.path[0], "iris.csv"))

X = df.iloc[:, :-1] # TODO: should i do df.iloc[,].values
y = df.iloc[:, -1]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

svcl = SVC(kernel='linear', random_state=42)
lsvc = LinearSVC(random_state=42)
svcl.fit(X_train, y_train)
lsvc.fit(X_train, y_train)

pred = svcl.predict(X_test)

classification_report(y_test, pred)
cm = confusion_matrix(y_test, pred)
print(cm)