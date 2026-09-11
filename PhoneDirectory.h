#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H

#include "Acquaintance.h"
#include <string>

const int MAX_CONTACTS = 100;

class PhoneDirectory {
private:
    Acquaintance contacts[MAX_CONTACTS];
    int currentSize;
    std::string filename;

public:
    PhoneDirectory(const std::string& file);

    void loadFromFile();

    void saveToFile() const;

    void addContact();

    void searchByName() const;

    void replaceNumber();

    void showAllContacts() const;

private:
    int findContactIndex(const std::string& name) const;
};

#endif // PHONEDIRECTORY_H