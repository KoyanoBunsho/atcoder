from math import sqrt

n = int(input())
ans = []
for i in range(2, int(sqrt(n)) + 1):
    b = 2
    while i ** b <= n:
        ans.append(i**b)
        b += 1
print(n - len(set(ans)))