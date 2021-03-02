n = int(input())
a_list = []
for i in range(n):
    a, p, x = map(int, input().split())
    a_list.append([a, p, x])
a_list.sort()
ans = 10 ** 10
for i in range(n):
    if a_list[i][0] < a_list[i][2]:
        ans = min(a_list[i][1], ans)
if ans == 10 ** 10:
    print(-1)
else:
    print(ans)