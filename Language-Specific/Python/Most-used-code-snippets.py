# This is a simple Hello World program in Python
print("Hello, World!")

# Declare a variable and assign a value
age = 30
name = "John"

# Check if a number is positive, negative, or zero
number = 5
if number > 0:
    print("Positive")
elif number < 0:
    print("Negative")
else:
    print("Zero")

# Iterate through a list
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)

# Define a function that adds two numbers
def add_numbers(a, b):
    result = a + b
    return result

# Create a new list by squaring each element of an existing list
numbers = [1, 2, 3, 4, 5]
squared_numbers = [x**2 for x in numbers]

# Concatenate two strings
first_name = "John"
last_name = "Doe"
full_name = first_name + " " + last_name

# Handle exceptions using try-except block
try:
    result = 10 / 0
except ZeroDivisionError as e:
    print("Error:", e)

# Create a dictionary and access its values
person = {"name": "Alice", "age": 30, "city": "New York"}
age = person["age"]

# Read from a file
with open("file.txt", "r") as file:
    content = file.read()

# Write to a file
with open("output.txt", "w") as file:
    file.write("Hello, World!")


