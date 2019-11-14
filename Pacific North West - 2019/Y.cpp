//team 159

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool checkAllMiddleSums(const int& index, const vector<int>& N, vector<int> a) {
    //cout << "function checkAllMiddleSums called for index: " << index << endl;
    if (index >= N.size()) {
        //cout << "returning true" << endl;
        return true;
    }
    int middlesum = 0;
    a.push_back(0);
    for (int i = 1; i < index; i++) {
        middlesum += a[i]*a[index-i]%10;
    }
    //cout << "middlesum:" << middlesum << ", N[index]: " << N[index] << endl;
    if (middlesum == N[index]) {
       return checkAllMiddleSums(index+1, N, a); 
    }
    return false;
}

int generate(const long long& index, const vector<int>& N, const vector<int>& a) {
    //cout << "function call: index " << index << endl;
    if (index > N.size()/2+1) {
        //impossible
        return -1;
    }

    int possible = -1;
    int least = -1;
    //calculating: a[1]a[i-1]+....+a[i-1]a[1].
    int middlesum = 0;
    for (int i = 1; i < index; i++) {
        middlesum += a[i]*a[index-i]%10;
    }

    if (middlesum == N[index]) {
        //success
        int result = 0;
        for (int i = a.size()-1; i >= 0; i--) {
            result *= 10;
            result += a[i];
        }
        //cout << "found result: " << result << endl;
        if (checkAllMiddleSums(index+1, N, a)) {
            return result;
        }
    }
    if (index > 0) {
        for (int i = 0; i < 10; i++) {
            //trying 0..9 for ai.
            if ((a[0]*i*2 + middlesum)%10 == N[index]) {
                vector<int> a_temp = a;
                a_temp.push_back(i);
                //cout << "Recursive call on index: " << index << ", a: " << i << endl;
                possible = generate(index+1, N, a_temp);
                if (possible != -1 && (least == -1 || possible < least)) {
                    least = possible;
                }
            }
        }
    }
    else {
       for (int i = 0; i < 10; i++) {
            //trying 0..9 for ai.
            if ((i*i)%10 == N[index]) {
                vector<int> a_temp = a;
                a_temp.push_back(i);
                //cout << "Recursive call on index: " << index << ", a: " << i << endl;
                possible = generate(index+1, N, a_temp);
                if (possible != -1 && (least == -1 || possible < least)) {
                    least = possible;
                }
            }
        } 
    } 
   
    return least;
}

int main() {
    string N;
    cin >> N;
    if (N == "0") {
        cout << 0 << endl;
        return 0;
    }
    vector<int> N_vec;
    int i = 0;
    while (i < N.size()) {
        N_vec.push_back(N[i]-'0');
        i++;
        //N/=10;
    }
    
    //reverse(N_vec.begin(), N_vec.end());
    

    vector<int> a;
    
    int result = generate(0, N_vec, a);
 
    cout << result << endl;

    return 0;
}