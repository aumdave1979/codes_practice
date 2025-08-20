#ex-8+

'''
def add(a,b):
    c=a+b
    return c

import lec4 as addition
x=int(input("Enter the user x value:"))
y=int(input("Enter the user y value:"))

result = addition.add(x,y)
print("",result)'''
'''
import math
print("Value of pi",math.pi)
print(dir(math))

import math as vishant
print(vishant.pi)'''

'''
def area(r):
    result=pi*(r**2)
    return result

from math import pi
import lec4 as AreaCal 

r=int(input("Enter the r valur: "))
result=AreaCal.area(r)
print("After cal area is:",result)'''

from math import sin

def cal_for(x):
    
    y = 6*x*x + 4*sin(x)
    return y


import lec4 as formula
x=int(input("Enter the x valur: "))

result = formula.cal_for(x)
print("Formula:",result)
