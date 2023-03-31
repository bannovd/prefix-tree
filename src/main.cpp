#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "trie.h"


static void prompt() {
    std::cout << "Next input please:\n>> ";
}

int main() {
    std::cout << "Loading trie..." << std::endl;
    Trie<std::string> trie;
    std::fstream input {"db.txt"};
    for (std::string line; std::getline(input, line);) {
        std::istringstream iss {line};
        trie.Insert(std::istream_iterator<std::string>{iss}, {});
    }
    prompt();
    for (std::string line; std::getline(std::cin, line);) {
        std::istringstream iss {line};
        if (auto subtrie (trie.Subtrie(std::istream_iterator<std::string>{iss}, {})); subtrie) {
            std::cout << "Suggestions:" << std::endl;
            subtrie->get().Print();
            prompt();
        } else {
            std::cout << "No suggestions found." << std::endl;
            prompt();
        }
    }
    return 0;
}
