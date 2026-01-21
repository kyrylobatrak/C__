#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    ofstream out("general.txt");

    if (!out.is_open()) {
        cout << "Unable to writing file." << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        Student st;
        cout << "Student" << i + 1 << "(Name Score): " << endl;
        cin >> st.name >> st.score;

        out << st.name << " " << st.score << endl;
    }

    out.close();


    ifstream in("general.txt");

    if (!in.is_open()) {
        cout << "Unable to read file." << endl;
        return 1;
    }

    ofstream pass("passeed.txt");

    if (!pass.is_open()) {
        cout << "Unable to write pass file." << endl;
        return 1;
    }

    ofstream fail("failed.txt");

    if (!fail.is_open()) {
        cout << "Unable to write fail file." << endl;
        return 1;
    }

    Student temp;

    while (in >> temp.name >> temp.score) {
        if (temp.score >= 60) {
            pass << temp.name << " " << temp.score << endl;
        }
        else {
            fail << temp.name << " " << temp.score << endl;
        }
    }

    in.close();
    pass.close();
    fail.close();

    return 0;
}