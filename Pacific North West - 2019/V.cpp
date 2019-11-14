//team 159

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> results;

    string testcase;
    cin >> testcase;

    set<char> alphabet_in_testcase;
    for (int i = 0; i < testcase.length(); i++) {
        alphabet_in_testcase.insert(testcase[i]); 
    }

    cin >> testcase;

    for (int i = 0; i < testcase.length(); i++) {
        string temp = testcase;
        //1. changing any letter
        for (set<char>::iterator it = alphabet_in_testcase.begin(); it != alphabet_in_testcase.end(); it++) {
            temp[i] = *it;
            results.insert(temp);
        }

        //2. adding any letter "before [i]"
        temp = testcase;
        temp.insert(temp.begin()+i, 1, 'a');
        for (set<char>::iterator it = alphabet_in_testcase.begin(); it != alphabet_in_testcase.end(); it++) {
            temp[i] = *it;
            results.insert(temp);
            
        }

        //3. erasing any letter
        
        temp = testcase;
        temp.erase(temp.begin()+i);
        results.insert(temp);
    }
    string temp = testcase;
    temp.insert(temp.end(), 1, 'a');
    for (set<char>::iterator it = alphabet_in_testcase.begin(); it != alphabet_in_testcase.end(); it++) {
        temp[temp.size()-1] = *it;
        results.insert(temp);

    }
    results.erase(testcase);


    for (set<string>::iterator it = results.begin(); it != results.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}