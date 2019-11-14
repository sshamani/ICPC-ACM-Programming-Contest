# team 159

from sys import stdin

n = int(stdin.readline().strip())

isValid, grid = True, []
for i in range(n):
    grid.append(stdin.readline().strip())

def checkRow(row):
    if row.count('W') != len(row) // 2:
        return False
    if "BBB" in row or "WWW" in row:
        return False
    return True

for row in grid:
    if not checkRow(row):
       print(0)
       isValid = False
       break
if isValid:
    for i in range(n):
        line = "".join(row[i] for row in grid)
        if not checkRow(line):
            print(0)
            isValid = False
            break

if isValid:
    print(1)

