### NOTE(s)
"""

DEFINITION(S):

    Indentation - Is used to create blocks of code, like curly brackets in c

    Lists - is an ordered collection of data which allows to store different data types,
            similiar to an array

            Example
          - [0,1,2,3] a list of numbers
          - ['banana', 10, false, 9,18] different data types in a list; string, int, bool, float

    Dictionary - Is an unordered collection of data in a key value pair format

            Example
            {
            'first_name':'Angel',
            'last_name':'Simental',
            'age':25,
            'is_married':True
            'skills':['JS', 'C++', 'C', 'Python']
            }

    Tuple - An ordered collection of data like list but cannot be modified

            Example
          - ('Angel', 'Sarah', 'Lucas', 'Arya') Names

    Set - Collection of data types, unlike list & tuple, set is not an ordered collection of items

            Example
          - {2.14, 9.74, 1.89} order is not important in a set

"""

"""
BASIC FUNCTION(S):

        type - checks the data type of certain data/variable
                example: type(10)  -> output = class 'int'
        
"""

# Exercise Level 3

# Write an example for different python data types

first_name = 'Angel'
last_name = 'Simental'
age = 24
programming_languages_skills = ('JS', 'Python', 'C/C++', 'Verilog')
major = 'Electrical & Computer Engineer'
gpa = 3.17

print('First Name:', first_name) 
print(type(first_name))
print('Last Name:', last_name)
print(type(last_name))
print('Age:', age)
print(type(age))
print('Programming Languages:', programming_languages_skills)
print(type(programming_languages_skills))
print('College Major:', major)
print(type(major))
print('GPA:', gpa)
print(type(gpa))

