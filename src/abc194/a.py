a, b = map(int, input().split())
ab = a+b
if ab >= 15 and b >= 8:
    print(1)
elif 10<=ab and b >= 3:
    print(2)
elif ab >= 3:
    print(3)
else:
    print(4)