#pragma once

#include <unordered_map>
#include <string>

struct trie_node {
    bool terminal = false;
    std::unordered_map<char, trie_node*> children;
};

class trie {
public:
    trie_node* root;

    trie() {
        root = new trie_node;
    }
    ~trie() {
        delete_subtree(root);
    }

    void insert(const std::string& word) {
        trie_node* curr = root;
        for (const char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new trie_node;
            }
            curr = curr->children[c];
        }
        curr->terminal = true;
    }

    bool starts_with(const std::string& prefix) const {
        trie_node* curr = root;
        for (const char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

    bool contains(const std::string& word) const {
        trie_node* curr = root;
        for (const char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->terminal;
    }

    void delete_subtree(trie_node* node) {
        if (node == nullptr) {
            return;
        }
        for (const auto& i : node->children) {
            delete_subtree(i.second);
        }
        delete node;
    }

};
