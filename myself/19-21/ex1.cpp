#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

struct Client {
    int id;
    string name;
    double balance;
};

class Bank {
private:
    map<int, Client> clients;
    set<int> blockList;

    bool isBlocked(int id) {
        if (blockList.count(id) > 0) {
            return true;
        }
        return false;
    }

public:
    void addClient(int id, string name) {
        if (clients.count(id) > 0) {
            cout << "Client " << id << " already exists" << endl;
            return;
        }
        Client newClient;
        newClient.id = id;
        newClient.name = name;
        newClient.balance = 0.0;

        clients[id] = newClient;
        cout << "Client " << id << " added" << endl;
    }

    void blockClient(int id) {
        if (blockList.count(id) > 0) {
            cout << "Client " << id << " already blocked" << endl;
            return;
        }

        blockList.insert(id);
    }

    void deposit(int id, double amount) {
        if (clients.count(id) == 0) {
            cout << "Client " << id << " does not exist" << endl;
            return;
        }

        if (isBlocked(id)) {
            cout << "Client " << id << " already blocked" << endl;
            return;
        }

        clients[id].balance += amount;
        cout << "Client " << id << " deposited. New balance: " << amount << endl;
    }

    void showAllClients() {
        for (auto it = clients.begin(); it != clients.end(); ++it) {
            cout << "ID: " << it->first << " | " << " Name: "<< it->second.name << " | " << " Balance: " << it->second.balance << endl;
        }
    }
};

int main() {
    Bank mono;
    mono.addClient(101, "Alice");
    mono.addClient(102, "Bob");

    mono.deposit(101, 500);
    mono.blockClient(102);
    mono.deposit(102, 100);

    mono.showAllClients();


    return 0;
}