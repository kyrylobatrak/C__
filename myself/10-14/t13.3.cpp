#include <iostream>
#include <string>
#include <cctype> // Потрібна для isspace

using namespace std;

int main() {
    string s;

    cout << "Enter text: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {

        if (!isspace(s[i])) {

            if (i + 1 == s.length() || isspace(s[i + 1])) {
                s.erase(i, 1);

            }
        }
    }

    cout << "Result: " << s << endl;

    return 0;
}