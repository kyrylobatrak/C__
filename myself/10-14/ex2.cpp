#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};


int main() {
    int N;
    cout << "Enter amount of products: ";
    cin >> N;

    ofstream out("inventory.txt");

    if (!out.is_open()) {
        cout << "Problem writing file!" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        Product temp;
        cout << "Product #" << i+1 << "(Name Price Quantity): ";
        cin >> temp.name >> temp.price >> temp.quantity;

        out << temp.name << " " << temp.price << " " << temp.quantity << endl;
    }

    out.close();


    ifstream in("inventory.txt");

    if (!in.is_open()) {
        cout << "Problem opening file!" << endl;
        return 1;
    }

    vector<Product> products;
    Product temp;
    double totalsum = 0;

    while (in >> temp.name >> temp.price >> temp.quantity) {
        products.push_back(temp);
        double cost = temp.price * temp.quantity;
        totalsum += cost;

        cout << "Loaded: " << temp.name << " | Cost: " << temp.price << endl;
    }

    in.close();

    cout << "Total inventory value: " << totalsum << endl;

    return 0;
}