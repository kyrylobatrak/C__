#include "PhoneDirectory.h"
#include <iostream>
#include <fstream>

PhoneDirectory::PhoneDirectory(const std::string& file)
    : currentSize(0), filename(file) {}

void PhoneDirectory::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File '" << filename << "' not found. Creating a new one.\n";
        return;
    }

    currentSize = 0;

    while (currentSize < MAX_CONTACTS && !file.eof()) {
        Acquaintance temp;
        temp.readFromFile(file);

        if (file.fail() || file.eof()) {
            break;
        }

        contacts[currentSize] = temp;
        currentSize++;
    }

    file.close();
    std::cout << "Loaded " << currentSize << " contacts.\n";
}

void PhoneDirectory::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < currentSize; ++i) {
        contacts[i].writeToFile(file);
    }

    file.close();
    std::cout << "Directory saved to file '" << filename << "'.\n";
}

void PhoneDirectory::addContact() {
    if (currentSize >= MAX_CONTACTS) {
        std::cout << "Error: Directory is full. (Limit " << MAX_CONTACTS << ")\n";
        return;
    }

    Acquaintance newContact;
    std::cin >> newContact;

    contacts[currentSize] = newContact;
    currentSize++;

    std::cout << "Contact added successfully.\n";
}

int PhoneDirectory::findContactIndex(const std::string& name) const {
    for (int i = 0; i < currentSize; ++i) {
        if (contacts[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void PhoneDirectory::searchByName() const {
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin >> name;

    int index = findContactIndex(name);

    if (index != -1) {
        std::cout << "\n--- Contact Found ---\n";
        std::cout << contacts[index] << std::endl;
    } else {
        std::cout << "Contact with name '" << name << "' not found.\n";
    }
}

void PhoneDirectory::replaceNumber() {
    std::string name;
    std::cout << "Enter the name of the contact whose number you want to change: ";
    std::cin >> name;

    int index = findContactIndex(name);

    if (index == -1) {
        std::cout << "Contact with name '" << name << "' not found.\n";
        return;
    }

    std::cout << "Current contact:\n" << contacts[index] << std::endl;

    std::string newNumber;
    std::cout << "Enter new phone number: ";
    std::cin >> newNumber;

    contacts[index].setPhoneNumber(newNumber);
    std::cout << "Phone number updated successfully.\n";
}

void PhoneDirectory::showAllContacts() const {
    if (currentSize == 0) {
        std::cout << "Directory is empty.\n";
        return;
    }

    std::cout << "\n--- All Contacts (" << currentSize << ") ---\n";
    for (int i = 0; i < currentSize; ++i) {
        std::cout << "--- Contact " << (i + 1) << " ---\n";
        std::cout << contacts[i] << std::endl;
        std::cout << "---------------------\n";
    }
}