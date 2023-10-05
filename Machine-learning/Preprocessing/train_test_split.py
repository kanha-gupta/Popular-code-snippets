#This snippet is used to split data for training and testing to avoid problems like over fitting and underfitting.
#The most common split ratio is 80:20.
#That is 80% of the dataset goes into the training set and 20% of the dataset goes into the testing set.
#Before splitting the data, make sure that the dataset is large enough. Train/Test split works well with large datasets.

#Code for CSV dataset
import pandas as pd
import sklearn 

data = pd.read_csv("your_file_path")
 
#output
y= data.output_column_name
 
#input
x=data.drop('output_column_name',axis=1)
 
#splitting
x_train, x_teinst, y_train, y_test = train_test_split(x, y, test_size=0.2) #train_test_split() is a part of sklearn library
 
#printing shapes of testing and training sets :
print("shape of original dataset :", data.shape)
print("shape of input - training set", x_train.shape)
print("shape of output - training set", y_train.shape)
print("shape of input - testing set", x_test.shape)
print("shape of output - testing set", y_test.shape)