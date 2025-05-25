a, b, c = int(input()), int(input()), int(input())

if a + b + c != 180:
    print("Error")
else:
    if a == b == c == 60:
        print("Equilateral")
    elif a == b or b == c or a == c:
        print("Isosceles")
    else:
        print("Scalene")
