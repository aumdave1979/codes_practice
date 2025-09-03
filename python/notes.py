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

def user_input():
    s = int(input()) #taking input and typecasting it into integer
    print(s)

def slicing():
    name = "Aum,dimple"
    #line 34 is often called slicing
    print(name[0:5]) #in this the print function will only print from 1 upto 4th index the and will not prnt the 5th index element
    #negative slicing
    print(name[0:-1]) #means it will take as len(name)-1 means 10-1 so 9 so it will print "Aum,dimpl"

def string_method():
    name = "Dimple"
    example = "DIMPLE!!!!!!"
    replace = "Aum dimple DIMPLE dimple"
    blog = "aum and dimple company"
    lenght = print("LEN FUNCTION - ",len(name)) # len function gives out the lenght of the string 
    print("UPPER CASE FUNCTION - ",name.upper()) #prints all the letter with upper case 
    print("LOWER CASE FUNCTION - ", name.lower()) #print all letter in lower case
    print(name)  # this shows that it will not change the orignal 
    print("rstrip 'will remove all !' - ",name.rstrip("!")) #removes all the element of !
    print("REPLACE FUNCTION - ",replace.replace("Aum","Dimple")) #replaces all the element of Aum with Rashi
    print("SPLIT FUNCTION - ",replace.split(" ")) # split string into list where after 1 space it is other element
    print("CAPITALIZE FUNCTION - ",blog.capitalize()) #gives capital letter after any punctuation or starting of a statement
    print("CENTER FUNCTION - ",name.center(50)) #moves the    name string towards center
    print("COUNT FUNCTION - ",replace.count("dimple")) # counts that how many times the particular string is occuring
    print("ENDS WITH FUNTION - ",name.endswith("ple")) # checks weather the string is ending with the particular 
    print("ISALNUM FUNCTION - ",name.isalnum()) # return true only when the whole string consists of A-Z , a-z or 0-9
    print("ISALPHA FUNCTION - ",name.isalpha()) # gives out true only whrn the whole string consist of A-Z , a-z



def StringMethod2():
#find function
    # s1 = "Hello krisha krisha"
    # print(s1.find("krisha")) # give the index number of the first occurrence of in the whole string
    # print(s1.find("aum")) #returns -1 because no such word is present in whole string

#index function

 #it is same as the find function but the only difference is that in the find function it will return -1 if not present 
 # and  in the index function it will return out the error
 
    s1 = "Hello krisha krisha"
    print(s1.index("krisha")) # give the index number of the first occurrence of in the whole string
    print(s1.index("aum")) #returns -1 because no such word is present in whole string




StringMethod2()