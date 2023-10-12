# Function to check if a number is positive, negative, or zero
def check_number(number):
    if number > 0:
        return "Positive"
    elif number < 0:
        return "Negative"
    else:
        return "Zero"

# Function to square a list of numbers using list comprehension
def square_numbers(numbers):
    squared_numbers = [x**2 for x in numbers]
    return squared_numbers

# Function to concatenate two strings
def concatenate_strings(first_name, last_name):
    full_name = first_name + " " + last_name
    return full_name

# Function to read content from a file
def read_file(file_name):
    try:
        with open(file_name, "r") as file:
            content = file.read()
        return content
    except FileNotFoundError:
        return "File not found."

# Function to write content to a file
def write_to_file(file_name, text):
    with open(file_name, "w") as file:
        file.write(text)

