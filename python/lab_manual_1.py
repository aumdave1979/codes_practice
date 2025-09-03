def lab1():
    num1 = 10 
    print(num1)
    print("Datatype of num1 is", type(num1))

    num2 = 2.5
    print(num2)
    print("Datatype of num1 is", type(num2))

    num3 = 2+6j
    print(num3)
    print("Datatype of num1 is", type(num3))

def example1():
    x = 5
    y = -6
    # Performing arithmetic operations
    sum_result = x + y
    difference_result = x - y
    multiplication_result = x * y
    division_result = x / y
    # Printing the results
    print("Sum:", sum_result)
    print("Difference:", difference_result)
    print("Multiplication:", multiplication_result)
    print("Division:", division_result)

def example2():
    a = 10
    b = 20
    # Comparing the values
    greater_than = a > b
    less_than_or_equal = a <= b
    equal_to = a == b
    not_equal_to = a != b
    # Printing the results
    print("Greater than:", greater_than)
    print("Less than or equal to:", less_than_or_equal)
    print("Equal to:", equal_to)
    print("Not equal to:", not_equal_to)

def example3():
    x = 3.14
    y = 2.5
    # Performing arithmetic operations
    sum_result = x + y
    difference_result = x - y
    multiplication_result = x * y
    division_result = x / y
    # Printing the results
    print("Sum:", sum_result)
    print("Difference:", difference_result)
    print("Multiplication:", multiplication_result)
    print("Division:", division_result)

def example4():
    a = 1.2
    b = 2.7
    greater_than = a > b
    less_than_or_equal = a <= b
    equal_to = a == b
    not_equal_to = a != b
    print("Greater than:", greater_than)
    print("Less than or equal to:", less_than_or_equal)
    print("Equal to:", equal_to)
    print("Not equal to:", not_equal_to)

def example5():
    x = 2 + 3j
    y = -1 + 2j
# Performing arithmetic operations
    sum_result = x + y
    difference_result = x - y
    multiplication_result = x * y
    division_result = x / y
# Printing the results
    print("Sum:", sum_result)
    print("Difference:", difference_result)
    print("Multiplication:", multiplication_result)
    print("Division:", division_result)

def example6():
    a = 1 + 2j
    b = 3 + 4j
    # Comparing the values
    equal_to = a == b
    not_equal_to = a != b
    # Printing the results
    print("Equal to:", equal_to)
    print("Not equal to:", not_equal_to)

def example7():
    st1 = "ICT Department 3EK1"
    print(st1)  
    print(st1[0])
    print(st1[0:4])

def example8():
    st1 = "ICT"
    st2 = "Department"
    st3 = "3EK1"    
    print(st1+st2+st3)
   

def example9():
    st1 ="Aum"
    print(4*st1)

def example10():
    st1 = "ICT Department 3EK1"
    # print("p" in st1)
    print("f" not in st1)

def example11():
    list1=[123,567,89] 
    print(list1)
    list2=["hello","how","are"] 
    print(list2)
    list3= ["hey",1223,"hello"] 
    print(list3)

def example12():
    list1=["apple","mango",123,345]
    list2 = ["grapes"]
    print(list1+ list2)

def example13():
    dict={"comp": "computer" , "sci" : "science"}
    print(dict["comp"])
    dict2={"123":"computer",456 : "maths"}
    print(dict2["123"])
    print(dict["comp"]+ dict2["123"])

    print(dict+ dict2)
    print(dict["computer"]+ dict2["computer"])

def example14():
    my_set = {1, 2, 3, 4, 5}
    print(my_set)
    set1 = {1, 2, 3, 4, 5}
    set2 = {4, 5, 6, 7, 8}
    print(set1+set2)

def example15():
    my_tuple = (1, 2, 3, 4, 5)
    t1 = (2,3,4)
    t2 = (5,6,7)
    print(t1+t2)


def example16():
    print("Welcome to Python \n"*5)


def postlab_2():
    print("Number\tSquare\tCube \n")

    for i in range(1, 5):
        print(f"{i}\t{i**2}\t{i**3}")


def postlab_3():
    result = (9.5 * 4.5 - 2.5 * 3) / (45.5 - 3.5)
    print("The result is:", result)



postlab_3()
