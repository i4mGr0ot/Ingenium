import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVR

## read the dataset
df = pd.read_csv('bitcoin.csv')
df.head()
## remove date column
df.drop(['Date'],1,inplace=True)
df.head()
predictionDays = 30
# Create another column shifted 'n'  units up
df['Prediction'] = df[['Price']].shift(-predictionDays)
# show the first 5 rows
df.head()
df.tail()
# Create the independent dada set
# Here we will convert the data frame into a numpy array and drp the prediction column
x = np.array(df.drop(['Prediction'],1))
# Remove the last 'n' rows where 'n' is the predictionDays
x = x[:len(df)-predictionDays]
print(x)
# Create the dependent data set
# convert the data frame into a numpy array
y = np.array(df['Prediction'])
# Get all the values except last 'n' rows
y = y[:-predictionDays]
print(y)
## train test split
xtrain, xtest, ytrain, ytest = train_test_split(x,y, test_size = 0.2)

# set the predictionDays array equal to last 30 rows from the original data set
predictionDays_array = np.array(df.drop(['Prediction'],1))[-predictionDays:]
print(predictionDays_array)
## SVR
svr_rbf = SVR(kernel='rbf', C=1e3, gamma=0.00001)
svr_rbf.fit(xtrain, ytrain)
## testing
svr_rbf_confidence = svr_rbf.score(xtest,ytest)
print('SVR_RBF accuracy :',svr_rbf_confidence)
# print the predicted values
svm_prediction = svr_rbf.predict(xtest)
print(svm_prediction)
print()
print(ytest)
# Print the model predictions for the next 30 days
svm_prediction = svr_rbf.predict(predictionDays_array)
print(svm_prediction)
print()
#Print the actual price for bitcoin for last 30 days
print(df.tail(predictionDays))
