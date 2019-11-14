//team159

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (B>=A) {
        cout << B-A << endl;
        return 0;
    }

    int num_plus = ceil(log2((double(A)/B)));
    unsigned int temp = B * pow(2, num_plus);
    temp -= A;

    //temp: 100101101.....->we want number of 1's.
    int count = 0;
    while (temp > 0) {
        count += temp & 0x1;
        temp >>= 1;
    }
    cout << count + num_plus << endl;

    return 0;
}