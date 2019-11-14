# team 159

from sys import stdin

N = int(stdin.readline().strip())

cumT, cumD, mSpeed = 0, 0, 0

for i in range(N):
    t, d = [int(i) for i in stdin.readline().strip().split()]
    if t == 0:
        continue
    v = (d - cumD) // (t - cumT)
    cumT, cumD = t, d
    if v > mSpeed:
        mSpeed = v

print(mSpeed)
