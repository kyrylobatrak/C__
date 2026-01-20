#include<iostream>
#include<vector>

using namespace std;

struct Journal {
    double price;
    int amount;
};

Journal getJournals() {
    Journal j;
    cout << "Enter price: ";
    cin >> j.price;
    cout << "Enter amount: ";
    cin >> j.amount;
    return j;
}

double getAveragePrice(const vector<Journal>& journals) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < journals.size(); i++) {
        if (journals[i].amount < 10000) {
            sum += journals[i].price;
            count++;
        }
    }
    if (count == 0) {
        return -1.0;
    }
    else {
        return sum / count;
    }
}

int main () {
    int n;
    cout << "Enter number of journals: ";
    cin >> n;

    vector<Journal> journals;

    for (int i = 0; i < n; i++) {
        cout << "\nJournal #" << i + 1 << endl;
        journals.push_back(getJournals());
    }

    if (n > 0) {
        double averageprice = getAveragePrice(journals);

        if (averageprice > 0) {
            cout << "Average price journals which amount less than 10000: " << averageprice << endl;
        }
        else {
            cout << "No journals amount less than 100000" << endl;
        }

    }

    return 0;
}