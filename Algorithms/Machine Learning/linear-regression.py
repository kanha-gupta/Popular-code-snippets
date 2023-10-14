import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Generate some sample data for demonstration
X = np.array([1, 2, 3, 4, 5]).reshape(-1, 1)
y = np.array([2, 3, 4, 4, 5])

# Create a linear regression model
model = LinearRegression()

# Fit the model to the data
model.fit(X, y)

# Make predictions using the trained model
y_pred = model.predict(X)

# Plot the original data and the regression line
plt.scatter(X, y, label='Original Data')
plt.plot(X, y_pred, color='red', label='Linear Regression Line')
plt.legend()
plt.xlabel('X')
plt.ylabel('y')
plt.title('Linear Regression Example')
plt.show()

