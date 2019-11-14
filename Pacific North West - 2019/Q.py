# team 159

from sys import stdin

A, B = [int(i) for i in stdin.readline().strip().split()]
count = 0

if A <= B:
    print(B - A)
else:
    while A > B:
        if A % 2 == 1:
            A += 1
            count += 1
        count += 1
        A = A // 2
    count += (B - A)
    print(count)


