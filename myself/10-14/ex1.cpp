#include <iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    ofstream outFile("notest.txt");

    if (!outFile.is_open()) {
        cout << "Unable to write file" << endl;
        return 1;
    }

    string text;

    cout << "Enter text: " << endl;
    getline(cin,text);

    outFile << text << endl;

    outFile.close();


    ifstream inFile("notest.txt");

    if (!inFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string word;

    while (inFile >> word) {
        cout << word << endl;
    }

    inFile.close();

    return 0;
}