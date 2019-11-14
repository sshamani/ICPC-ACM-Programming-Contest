//team 159

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C, A, B;
    cin >> R >> C >> A >> B;
    vector<int> rowData;
    rowData.reserve(R);
    vector<int> colData;
    colData.reserve(C);
    int next;
    for (int i = 0; i < A; i++) {
        cin >> next;
        rowData.push_back(next);
    }

    for (int i = 0; i < B; i++) {
        cin >> next;
        colData.push_back(next);
    }
    bool isW = false;
    for (int r = 0; r < rowData.size(); r++) {
        for (int i = 0; i < rowData[r]; i++) {
            for (int c = 0; c < colData.size(); c++) {
                if (!isW) {
                    for (int j = 0; j < colData[c]; j++) {
                       cout << "B"; 
                    }
                    isW = true;
                }
                else {
                    for (int j = 0; j < colData[c]; j++) {
                        cout << "W"; 
                    }
                    isW = false; 
                }
            }
            cout << endl;
        }
        isW = !isW;
    }

    return 0;
}