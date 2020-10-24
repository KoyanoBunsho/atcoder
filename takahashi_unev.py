from math import floor


x, y, a, b = map(int, input().split())
ans = 0
for i in range(10 ** 5):
    x = x * a
    ans += 1
    if(x * a >= b):
        break
ans += floor((y-x)/b)
print(ans)
