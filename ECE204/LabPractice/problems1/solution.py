
# 1
# Numerical Methods (ECE 204)
# Practice Simulation Exercises no. 1
# Using MATLAB, do the following tasks:
# Q1.
# Load the file “data.txt”, (available in LEARN) and calculate the total number of entries (XXX)
# and number of entries more than 2 (YYY). Your output should look like:
# The number of elements is: XXX
# The number of elements more than 2 is: YYY
# Q2.
# Calculate the value of ex using its expansion....................
# !3!2
# 1
# 32
# ++++= xx
# xex for any value of x
# entered by the user till the approximate error is less than 10-6. In each iteration increase the
# number of the terms till you reach the required accuracy.
# So, first your program will request the value of x (AAA), then it will compute ex (BBB) till the
# approximate error is less than 10-6 for the last two consecutive iterations.
# Your output should look like:
# Enter the value of x: AAA
# For x= AAA, e^x = BBB
# Q3.
# Load the file “data_2.txt”, (available in LEARN) and plot column1 vs column 2 and column 1
# vs column 3 in the same figure. The x-axis label is “time (sec)”, the y-axis label is “magnitude
# (meter)”, the legend for the first graph is “First data set” and the legend for the second graph is
# “Second data set”. Also, perform the following statistical operations to the second column:
# Maximum, minimum, mean, standard deviation, median, mode, and number of data points.



import os

def p1():
    numData = 0
    numGreat2 = 0
    # Load data.txt and process it
    with open('data.txt', 'r') as file:
        lines = file.readlines() # array of lines split by \n
        print(lines[0])
        data = None
        for line in lines:
            data = list(map(float, line.split()))
            numData += 1
            if int(data[0]) > 2:
                numGreat2 += 1
    
    print(f"The number of elements is: {numData}")
    print(f"The number of elements more than 2 is: {numGreat2}")
    
    
def p2():
    x = input("Please enter your x value: ")

    



p1()