from sklearn.linear_model import LinearRegression
from sklearn.model_selection import cross_val_score    # Cross Validation 

lin_regression = LinearRegression()
mse = cross_val_score(lin_regression, X, y, scoring='neg_mean_squared_error', cv=5)
print(type(mse))
mse = np.mean(mse)    # we will get the five values, then we calculate the mean
print(mse)
