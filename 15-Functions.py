# Creating and calling a function

def greet():
    print("Inside of function")
greet()
print("Outside of function")

# Function with arguments

def SUM(num1,num2):
    print(num1+num2)
SUM(1,2)

# Function with return statement

def SUM(num1,num2):
    return (num1+num2)
Sum=SUM(2,3)
print("SUM: ", Sum)

# The Pass Statment

def fun1():
    pass #It's typically used where code is planned but has yet to be written.
print("Hello")