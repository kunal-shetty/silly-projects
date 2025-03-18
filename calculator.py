import math


def maths():
    print("Enter 1 for Sum of two numbers")
    print("Enter 2 for Difference of two numbers")
    print("Enter 3 for Quotient of two numbers")
    print("Enter 4 for Product of two numbers")
    ch = int(input())

    if ch in [1, 2, 3, 4]:
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
        if ch == 1:
            return a + b
        elif ch == 2:
            return a - b
        elif ch == 3:
            return a / b
        elif ch == 4:
            return a * b
    else:
        print("Invalid operation")
        return 0


def trig():
    print("Enter 1 for sine, 2 for cosine, 3 for tangent")
    print("Enter 4 for secant, 5 for cosecant, 6 for cotangent")
    ch = int(input())
    angle = float(input("Enter angle in degrees: "))
    rad = math.radians(angle)

    if ch == 1:
        return math.sin(rad)
    elif ch == 2:
        return math.cos(rad)
    elif ch == 3:
        return math.tan(rad) if angle % 90 != 0 else "Undefined"
    elif ch == 4:
        return 1 / math.cos(rad) if angle % 90 != 0 else "Undefined"
    elif ch == 5:
        return 1 / math.sin(rad) if angle % 90 != 0 else "Undefined"
    elif ch == 6:
        return 1 / math.tan(rad) if angle % 90 != 0 else "Undefined"
    else:
        print("Invalid Input")
        return 0


def logar():
    print("Enter 1 for log base 10, 2 for natural log, 3 for exponentiation")
    ch = int(input())
    n = float(input("Enter number: "))

    if ch == 1:
        return math.log10(n)
    elif ch == 2:
        return math.log(n)
    elif ch == 3:
        return math.exp(n)
    else:
        print("Invalid Input")
        return 0


while True:
    print("Enter 1 for Maths\n2 for Trigonometry\n3 for Logarithms\n4 to Exit")
    ch = int(input())
    if ch == 1:
        print("Result:", maths())
    elif ch == 2:
        print("Result:", trig())
    elif ch == 3:
        print("Result:", logar())
    elif ch == 4:
        print("Terminating the program!")
        break
    else:
        print("Invalid Input, Try again")