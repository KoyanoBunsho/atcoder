n, k = map(int, input().split())
a = [0] * (k+1)
a[0] = n
for i in range(1, k+1):
    g = list(str(a[i-1]))
    g1 = sorted(g)
    g2 = sorted(g, reverse=True)
    a[i] = int("".join(g2)) - int("".join(g1))
print(a[k])