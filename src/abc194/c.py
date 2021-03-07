from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
a_acc = list(accumulate(a))
ans = 0
for i in range(n):
    ans += (a[i] ** 2) * (n-1) - 2 * a[i]*(a_acc[-1]-a_acc[i])
print(ans)