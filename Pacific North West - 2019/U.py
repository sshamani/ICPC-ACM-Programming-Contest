# team 159

from sys import stdin

N, M = [int(i) for i in stdin.readline().strip().split()]

badwords, answers = [], []
equiv = {
   '0': 'O', 
   '1': 'L', 
   '2': 'Z', 
   '3': 'E', 
   '5': 'S', 
   '6': 'B', 
   '7': 'T', 
   '8': 'B'
}

for i in range(N):
    badwords.append(stdin.readline().strip())
for i in range(M):
    word = stdin.readline().strip()
    word = "".join(list(map(lambda x: equiv[x] if x in equiv else x, list(word))))
    hasBad = False
    for j in range(N):
        if badwords[j] in word:
            answers.append("INVALID")
            hasBad = True
            break
    if not hasBad:
        answers.append("VALID")

for i in answers:
    print(i)

