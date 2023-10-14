import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

# Generate some sample data
X = np.array([1, 2, 3, 4, 5]).reshape(-1, 1)
y = np.array([2, 3, 4, 4, 5])

# Create a polynomial regression model
poly = PolynomialFeatures(degree=2)  # You can change the degree
X_poly = poly.fit_transform(X)
model = LinearRegression()

# Fit the model to the transformed data
model.fit(X_poly, y)

# Make predictions using the trained model
y_pred = model.predict(X_poly)

