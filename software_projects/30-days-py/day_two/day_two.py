# BUILT IN FUNCTIONS & VARIABLES

"""
Commonly used Built In Functions:
    print() writes object
    len() returns the length of an object
    type() returns the type of an object 
    input() user input
    min() returns the smallest item of two or more arguments
    max() returns the largest item of two or more arguments
    sorted() return a new sorted list from the items in iterable
    open() open a file a return corresponding file object
"""

# prints min 

"""
print(min(20, 30, 40, 60, 100))
"""

# Dictionary variable with print and type
"""
person_info = {
    'firstname':'Angel',
    'lastname':'Simental',
    'age':25,
    'state':'Colorado'
}
print(person_info)
print(type(person_info))
"""

# Declaring Multiple Variable in a line
"""
EXAMPLE:

first_name, last_name, state, age, is_married = 'Angel', 'Simental', 'Colorado', '24', True
print(first_name, last_name, state, age, is_married)

"""

# Getting user Input
"""
first_name = input('What is your name: ')
age = input('What is your age: ')

print('First Name:', first_name)
print('Age:', age)
"""

###CASTING
"""
Casting = Converting one data type to another data type.

# string to list conversion
city = 'Grand Valley'
print('String:', city)
city_to_list = list(city)
print('List:', city_to_list)
"""

#Day 2: 30 days of python programming 
first_name = 'Angel'
last_name = 'Simental'
full_name = 'Angel Simental'
country = "Unfortunately, the U.S.A"
city = 'GJ'
age = 25
year = 2026
is_married = True
is_true = True
is_light = True

x, y, z, = 5, 4, 3

print(type(first_name))
print(type(last_name))
print(type(full_name))
print(type(country))
print(type(city))
print(type(age))
print(type(year))
print(type(is_married))
print(type(is_true))
print(type(is_light))

print('Length of name:', len(full_name))

print('Length of first name:', len(first_name), 'Length of last name:', len(last_name))

num_one, num_two = 5, 4
diff = num_one - num_two
print('num_one - num_two =', diff)
prod = num_one * num_two
print('num_one * num_two =', prod)
division = num_one / num_two
print('num_one / num_two =', division)







