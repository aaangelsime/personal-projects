# INDENTATION is used to create code blocks instead of curly braces.

# LIST in python is = an array in other languages.
# a list can contain elements of different types.

# DICTIONARY in python is similar to a map in other languages.
# EXAMPLE:

"""
'first_name': 'John',
'last_name': 'Doe',
'age': 25,
'is_student': False,
'courses': ['Math', 'Science']
""" 

# TUPLE in python is similar to a list, but it is IMMUTABLE (CANNOT be changed after creation).

"""
Example:

(1, 2, 3, 4, 5)
('apple', 'banana', 'cherry')
"""

# SET in python is an UNORDERED collection of unique elements.

"""
{2, 4, 3, 5}
{3.14, 9.81, 2.7} # order is not important in set
"""

# CHECKING DATA TYPES

"""
To check the data type of certain data/variable we use the 'type' function.
EXAMPLE:

type(10) = class 'int'
"""

### TO COMPILE IN TERMINAL RUN -> python3 "./filename"
"""
print (3 ** 2) # exponential(**)
print (3 // 2) # floor division operator(//)
"""

### PRINTING DATA TYPES
"""
print(type(1 + 3j)) # Complex number
print(type({'name':'Asabench'})) # Dictionary
print(type({9.8, 3.14, 2.7})) # Set
print(type((9.8, 3.14, 2.7))) # Turple

print("Angel Simental")
print("United States of America")

"""

#### BUILT IN FUNCTION
"""
 # Len function counts the num of chars including spaces
len('Angel Simental')

# str functions converts number to string
str(10)

# int converts to number
int('10')

# float converts integer to decimal
float(10)
"""

#### PYTHON VARIABLE NAME RULES
"""
- must start with a letter or underscore 
- cannot start with number 
- case sensitive
"""

### DECLARING A VARIABLE AND PRINTING

"""
skills = ['HTML', 'CSS', 'JS', 'REACT']

person_info = {
    'firstname' : 'angel',
    'lastname' : 'simental',
    'country' : 'usa'
}
print(skills)
print(person_info)

"""


### USER INPUT AND PRINTING

"""
name = input('What is your name: ')
print(name)
"""

## Day Two Exercise
"""
print('Day 2: 30 Days of python programming')
first_name = 'angel'
last_name = 'simental'
full_name = 'Angel Simental'

color, item, weight = 'blue', 'ball', 25

print('first name:', first_name)
print('last name:', last_name)
print('full name:', full_name)
print('multi variables:', color, item, weight)
"""

## Day Three Exercise 
age = 12
height = 5.8
complex_num = 6j

# triangle area
base = float(input('Base: '))
height = float(input('Height: '))
x = 0.5

area_tri = base * height * x

# triangle parameter 
print("Triangle Area: ", base, "*", height, "*", x, "=", area_tri)

a = float(input('Triangle Side A: '))
b = float(input('Triangle Side B: '))
c = float(input('Triangle Side C: '))
tri_par = a * b * c
print('Triangle Parameter:', a, '*', b, '*', c, '=', tri_par)
#Left off at 6

# rectangle area 
y = float(input('Enter rectangle length size of y: '))
x = float(input('Enter rectangle width size of x: '))
rect_area = x * y
print('Rectangle Area:', rect_area)

# rectangle parameter
rect_per = 2 * x + y
print('Rectangle Parameter:', rect_per)