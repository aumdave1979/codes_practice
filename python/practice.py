# import hashlib
# import pandas
# import numpy as num

def operators():
    # floor division operator
    e=5
    u=2
    c = e//u # this means if 5//2 is 2.5 then it will only return 2 only the int part
    print(c)
    #exponential operator 
    print(5**3) # means 5^3 = 125

def typecasting():
    a = "1"
    a1 = int(a) #converting the a variable into int data typee using int()
    print(type(a))
    print(type(a1))

def user_input():
    print("Enter value: ")
    i = input() # here input is taken in string data type we need to convert
    print(i)
    o = int(input()) #here the input is taken in string but is then converted into int data type
    print(o) 

user_input()
                        