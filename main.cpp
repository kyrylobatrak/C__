#include "PhoneDirectory.h"
#include <iostream>

void showMenu() {
    std::cout << "\n===== PHONE DIRECTORY MENU =====\n";
    std::cout << "1. Add new contact\n";
    std::cout << "2. Find contact by name\n";
    std::cout << "3. Change phone number\n";
    std::cout << "4. Show all contacts\n";
    std::cout << "5. Save directory to file\n";
    std::cout << "6. Load directory from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main() {
    PhoneDirectory directory("directory.txt");

    directory.loadFromFile();

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                directory.addContact();
                break;
            case 2:
                directory.searchByName();
                break;
            case 3:
                directory.replaceNumber();
                break;
            case 4:
                directory.showAllContacts();
                break;
            case 5:
                directory.saveToFile();
                break;
            case 6:
                directory.loadFromFile();
                break;
            case 0:
                std::cout << "Saving changes before exit...\n";
                directory.saveToFile();
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}