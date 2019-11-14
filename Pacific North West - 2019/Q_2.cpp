/*
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
    print(count*/

//team 159

#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int count = 0;
    if (A <= B) {
        cout << B-A << endl;
    }
    else {
        while (A > B) {
            if (A%2 == 1) {
                A += 1;
                count++;
            }
            A >>= 1;
            count++;
        }
        count += (B-A);
        cout << count << endl;
    }
    return 0;
}