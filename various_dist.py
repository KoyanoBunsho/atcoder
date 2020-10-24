n = int(input())
x = list(map(int, input().split()))
abs_dist = 0
euc_dist = 0
cheb_dist = 0
for i in range(n):
    abs_dist += abs(x[i])
    euc_dist += (x[i] ** 2)
    cheb_dist = max(cheb_dist, abs(x[i]))
print(abs_dist)
print(euc_dist ** (0.5))
print(cheb_dist)
