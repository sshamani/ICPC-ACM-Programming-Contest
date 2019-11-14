//team159
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int count[26] = {0, };
    int total = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            count[str[i]-'A']++;
            total++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i]-'a']++;
            total++;
        }
    }
    total--;
    total *= 3;
    //cout << total << endl;

    sort(count, count+26);
    reverse(count, count+26);

    int i = 0;
    for (int k = 0; k < 1 && i < 26; k++, i++) {
        total += 1*count[i];
    }

    for (int k = 0; k < 2 && i < 26; k++, i++) {
        total += 3*count[i];
    } 

    for (int k = 0; k < 3 && i < 26; k++, i++) {
        total += 5*count[i];
    }

    for (int k = 0; k < 5 && i < 26; k++, i++) {
        total += 7*count[i];
    }

    for (int k = 0; k < 8 && i < 26; k++, i++) {
        total += 9*count[i];
    }

    for (int k = 0; i < 26; k++, i++) {
        total += 11*count[i];
    }

    cout << total << endl;

    return 0;
}