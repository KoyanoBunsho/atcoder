n = int(input())
ab_list = []
b_list = []
c_list = []
a_min = 10 ** 5 + 1
b_min = 10 ** 5 + 1
c_min = 10 ** 5 + 1
for i in range(n):
    a, b = map(int, input().split())
    c = a + b
    a_min = min(a, a_min)
    b_min = min(b, b_min)
    b_list.append(b)
    ab_list.append([a, b])
    c_list.append(c)
ab_list.sort()
b_list.sort()
if ab_list[0][1] == b_min:
    print(min(max(b_list[1], a_min), min(c_list)))
else:
    print(min(max(a_min, b_min), min(c_list)))