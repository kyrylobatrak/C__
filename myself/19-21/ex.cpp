#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Item {
    string name;
    string category;
    int price;
    double weight;
};

class Inventory {
private:
    vector<Item> items;
public:
    void addItem(Item i) {
        items.push_back(i);
    }

    void showInventory() {
        if (items.empty()) {
            cout << "Inventory is empty!" << endl;
            return;
        }
        for (const auto& i : items) {
            cout << "Item: " << i.name
                 << " | Price: " << i.price << endl;
        }
    }

    void dropHeavyItems(double limit) {
        for (auto it = items.begin(); it != items.end(); ) {
            if (it->weight > limit) {
                it = items.erase(it);
            } else {
                ++it;
            }
        }
    }

    void sortByPrice() {
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price > b.price;
        });
    }

    void showByCategory() {
        if (items.empty()) {
            cout << "Inventory is empty!" << endl;
            return;
        }

        map<string, vector<Item>> categorized;
        for (const auto& i : items) {
            categorized[i.category].push_back(i);
        }

        cout << "\n=== INVENTORY BY CATEGORY ===" << endl;

        for (const auto& pair : categorized) {
            cout << "[" << pair.first << "]:" << endl;

            for (const auto& item : pair.second) {
                cout << "  - " << item.name
                     << " (" << item.price << " gold)" << endl;
            }
        }
        cout << "=============================" << endl;
    }
};

int main() {
    Inventory inv;

    inv.addItem({"Rusty Sword", "Weapon", 50, 5.5});
    inv.addItem({"Health Potion", "Potion", 20, 0.5});
    inv.addItem({"Golden Ring", "Jewelry", 500, 0.1});
    inv.addItem({"Old Shoe", "Junk", 1, 0.8});
    inv.addItem({"Magic Staff", "Weapon", 300, 2.0}); // Додали ще зброю для тесту груп

    inv.dropHeavyItems(5.0);

    inv.sortByPrice();

    inv.showByCategory();

    return 0;
}