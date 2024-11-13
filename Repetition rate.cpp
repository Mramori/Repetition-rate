#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cctype>

int main() {
    std::ifstream file("your_file.txt");
    if (!file) return 1;

    std::unordered_map<char, int> letterCount;
    std::unordered_map<std::string, int> bigramCount;
    std::string text, line;

    while (std::getline(file, line)) {
        text += line + " ";
    }

    for (size_t i = 0; i < text.size(); ++i) {
        char c = std::tolower(text[i]);
        if (std::isalpha(c)) {
            letterCount[c]++;
            if (i < text.size() - 1) {
                char next = std::tolower(text[i + 1]);
                if (std::isalpha(next)) {
                    bigramCount[std::string(1, c) + next]++;
                }
            }
        }
    }

    for (const auto& p : letterCount) {
        std::cout << p.first << ": " << p.second << 'n';
    }

    std::cout << "n";

    for (const auto& p : bigramCount) {
        std::cout << p.first << ": " << p.second << 'n';
    }

    return 0;
}
