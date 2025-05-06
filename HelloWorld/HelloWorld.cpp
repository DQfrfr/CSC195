#include <iostream>
#include <string>
using namespace std;

string checkVowel(char sum) {
    switch (sum) {
    case 'a':
        return "*";
    case 'e':
        return "*";
    case 'i' :
        return "*";
    case 'o':
        return "*";
    case 'u':
        return "*";
    default:
        return string(1,sum);
    }
}

string reverser(string sum) {
    string awnser;

    for (int i = sum.length() - 1; i >= 0; i--) {
        awnser.append(checkVowel(sum[i]));
    }
    cout << awnser << endl;
    return awnser;
}

int main() {
    cout << "Enter a string to reverse and scramble: " << endl;
    string stringToReverse;
    cin >> stringToReverse;
    cout << reverser(stringToReverse.) << endl;
    return 0;
}
