import numpy as np
from sklearn.linear_model import LogisticRegression

# Generate some sample data for binary classification
X = np.array([[1, 2], [2, 3], [3, 4], [4, 5], [5, 6]])
y = np.array([0, 0, 1, 1, 1])  # Binary labels

# Create a logistic regression model
model = LogisticRegression()

# Fit the model to the data
model.fit(X, y)

# Make predictions using the trained model
y_pred = model.predict(X)

