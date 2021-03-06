import sys
import numpy as np
 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

x = np.array(list(readline().rstrip().decode()), np.int64).astype(object)
m = int(readline())
d = x.max()
l = d
r = m + 1

if len(x) == 1:
    if x[0] <= m:
        print(1)
        exit()
    else:
        print(0)
        exit()

def C(mid):
    ans = 0
    for x_ in x:
        ans = ans * mid + x_
    if ans <= m:
        return True
    else:
        return False

while r - l > 1:
    mid = (r+l) // 2
    if C(mid):
        l = mid
    else:
        r = mid
print(l - d)