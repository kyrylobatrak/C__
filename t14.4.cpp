#include <iostream>
#include <fstream>   // Для роботи з файлами (ifstream)
#include <string>    // Для std::string
#include <sstream>   // Для std::stringstream (легкий спосіб зчитати весь файл)

int main() {
    std::string inputFilename = "input14.4.txt";

    std::ifstream inFile(inputFilename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFilename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    // "Всмоктуємо" весь вміст файлу (rdbuf() - read buffer) в наш буфер
    buffer << inFile.rdbuf();
    // Конвертуємо буфер в один великий std::string
    std::string fileContent = buffer.str();

    // Закриваємо файл, оскільки весь його вміст вже у пам'яті
    inFile.close();

    // Лічильник для відстеження балансу:
    // +1 за <td>
    // -1 за </td>
    int balance = 0;

    // Позиція (індекс), з якої ми починаємо наступний пошук у рядку
    std::size_t pos = 0;

    std::string openTag = "<td>";
    std::string closeTag = "</td>";

    // Цикл, що триває, доки ми знаходимо будь-який з тегів
    while (true) {
        // Знаходимо позицію *наступного* <td>, починаючи з 'pos'
        std::size_t openPos = fileContent.find(openTag, pos);

        // Знаходимо позицію *наступного* </td>, починаючи з 'pos'
        std::size_t closePos = fileContent.find(closeTag, pos);


        // Випадок 1: Жоден з тегів (ні <td>, ні </td>) більше не знайдено.
        // (std::string::npos - це спеціальне значення, що означає "не знайдено")
        if (openPos == std::string::npos && closePos == std::string::npos) {
            break;
        }

        // Випадок 2: Знайдено <td>, і він знаходиться *раніше* за </td>
        // (або </td> взагалі не знайдено, тобто closePos == npos)
        if (openPos != std::string::npos && (closePos == std::string::npos || openPos < closePos)) {

            balance++;

            // Пересуваємо нашу позицію пошуку *після* цього тегу
            pos = openPos + openTag.length();

        }
        // Випадок 3: Знайдено </td>, і він знаходиться *раніше* за <td>
        // (або <td> взагалі не знайдено, тобто openPos == npos)
        else if (closePos != std::string::npos && (openPos == std::string::npos || closePos < openPos)) {

            balance--;

            // Пересуваємо нашу позицію пошуку *після* цього тегу
            pos = closePos + closeTag.length();

            // --- КРИТИЧНА ПЕРЕВІРКА ---
            // Якщо баланс став від'ємним, це означає, що ми знайшли </td>
            // *до* того, як знайшли відповідний <td>. Це завжди помилка.
            if (balance < 0) {
                std::cerr << "Validation Error: Found '</td>' without a matching '<td>'." << std::endl;
                std::cerr << "Error occurred near position: " << pos << std::endl;
                return 1;
            }
        }
    }


    if (balance == 0) {
        std::cout << "Validation Success: All '<td>' tags are correctly balanced." << std::endl;
    } else {
        std::cerr << "Validation Error: Found " << balance << " unclosed '<td>' tag(s)." << std::endl;
        return 1;
    }

    return 0;
}