from sklearn.datasets import load_boston
import numpy as no
import pandas as pd
import matplotlib.pyplot as plt

df = load_boston()
dataset = pd.DataFrame(df.data)
target = df.target
dataset.isnull().sum()
dataset.columns = df.feature_names
dataset["Price"] = target
X = dataset.loc[:, : 'LSTAT']   # independent features
y = dataset.loc[:, 'Price']    # dependent features
