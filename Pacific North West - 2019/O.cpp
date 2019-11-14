//team 159
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N%2 == 1) {
        cout << "Either" << endl;
    }
    else if (N%4 == 2){
        cout << "Odd" << endl;
    }
    else {
       cout << "Even" << endl;
    }

    return 0;
}