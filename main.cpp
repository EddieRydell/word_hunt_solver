#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

#define SIDE_LENGTH 4
char letter_array[SIDE_LENGTH][SIDE_LENGTH];
bool visited[SIDE_LENGTH][SIDE_LENGTH] = {false};

std::unordered_set<std::string> dictionary;
std::unordered_set<std::string> found_words; // Global variable for storing found words

unsigned int num_words_found = 0;
#define MAX_WORDS 100
int MIN_WORD_LENGTH;

// Directions for exploring neighbors (8 directions: up, down, left, right, diagonals)
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Initialize dictionary from file
void init_dictionary() {
    std::cout << "Initializing dictionary\n";
    std::ifstream input_file("sowpods.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error opening file\n";
        exit(1);
    }

    std::string word;
    while (std::getline(input_file, word)) {
        // Convert to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
    }
    std::cout << "Dictionary size: " << dictionary.size() << std::endl;
    input_file.close();
}

// Template for iterating over letters
template <typename F>
void iterate_over_letters(F function) {
    for (auto& i : letter_array) {
        for (char& j : i) {
            function(j);
        }
    }
}

// Recursive backtracking to search words in the grid
void search_words(int x, int y, std::string current_word) {
    if (num_words_found >= MAX_WORDS || current_word.length() > MIN_WORD_LENGTH - 1) {
        return;
    }
    if (x < 0 || x >= SIDE_LENGTH || y < 0 || y >= SIDE_LENGTH || visited[x][y]) {
        return;
    }

    current_word += letter_array[x][y];
    if (dictionary.count(current_word) && current_word.length() >= MIN_WORD_LENGTH) {
        if (found_words.insert(current_word).second) {
            num_words_found++;
        }
    }

    visited[x][y] = true;

    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        search_words(nx, ny, current_word);
    }

    visited[x][y] = false;
}

void find_all_words() {
    for (int i = 0; i < SIDE_LENGTH; ++i) {
        for (int j = 0; j < SIDE_LENGTH; ++j) {
            memset(visited, false, sizeof(visited));
            search_words(i, j, "");
        }
    }
}

int main() {
    init_dictionary();

    std::cout << "Enter letters for a 4x4 grid (row by row):\n";
    iterate_over_letters([](char& letter) {
        std::cin >> letter;
    });
    std::cout << "Got letters\n\n";

    std::cout << "Grid:\n";
    iterate_over_letters([](const char& letter) {
        std::cout << letter << ' ';
    });
    std::cout << std::endl;

    for (MIN_WORD_LENGTH = 10; MIN_WORD_LENGTH > 3; MIN_WORD_LENGTH--) {
        std::cout << "Finding words " << MIN_WORD_LENGTH << " or more letters long\n";
        find_all_words();

        std::cout << "Found words:\n";
        for (const auto& word : found_words) {
            std::cout << word << std::endl;
        }
        found_words.clear();
    }

    return 0;
}
