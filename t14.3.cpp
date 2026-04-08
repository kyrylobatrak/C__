#include <iostream>
#include <fstream>  // Для роботи з файлами (ifstream, ofstream)
#include <string>   // Для std::string
#include <algorithm> // Для std::reverse


bool isSeparator(char c) {
    return (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?');
}

int main() {
    std::string inputFilename = "input14.3.txt";
    std::string outputFilename = "output14.3.txt";

    std::ifstream inFile(inputFilename);
    std::ofstream outFile(outputFilename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFilename << std::endl;
        return 1;
    }
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open output file: " << outputFilename << std::endl;
        inFile.close();
        return 1;
    }

    std::string currentWord = "";
    char ch;

    // Читаємо вхідний файл по одному символу за раз (inFile.get(ch))
    // Це дозволяє нам читати *всі* символи, включаючи пробіли та нові рядки.
    while (inFile.get(ch)) {

        // Перевіряємо, чи поточний символ є одним із наших роздільників
        if (isSeparator(ch)) {
            // Так, це роздільник. Це означає, що слово, яке ми збирали, закінчилося.

            // 1. Перевіряємо, чи ми взагалі зібрали якесь слово
            //    (Це потрібно, якщо у нас кілька роздільників підряд, наприклад "word1, word2")
            if (!currentWord.empty()) {
                // 2. Якщо слово є, реверсуємо (розшифровуємо) його
                std::reverse(currentWord.begin(), currentWord.end());

                outFile << currentWord;

                currentWord = "";
            }

            outFile << ch;

        } else {
            // Ні, це не роздільник. Це звичайний символ.
            // Додаємо його до слова, яке ми зараз збираємо.
            currentWord += ch;
        }
    }

    // ОБРОБКА ОСТАННЬОГО СЛОВА
    // Цикл 'while' завершиться, коли файл закінчиться (EOF).
    // Якщо файл закінчується словом, а не роздільником (наприклад, "dlrow" <EOF>),
    // то це слово 'currentWord' ще не було оброблене та записане.
    if (!currentWord.empty()) {
        // Ми повинні обробити його тут, поза циклом
        std::reverse(currentWord.begin(), currentWord.end());
        outFile << currentWord;
    }

    inFile.close();
    outFile.close();

    std::cout << "File has been decrypted successfully. Check " << outputFilename << std::endl;

    return 0;
}