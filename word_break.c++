#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    class Node {
    public:
        unordered_map<char, Node*> children;
        bool endofword;
        Node() {
            endofword = false;
        }
    };

    class Trie {
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(string key) {
            Node* temp = root;
            for (char c : key) {
                if (temp->children.find(c) == temp->children.end()) {
                    temp->children[c] = new Node();
                }
                temp = temp->children[c];
            }
            temp->endofword = true;
        }
        bool search(string key) {
            Node* temp = root;
            for (char c : key) {
                if (temp->children.count(c)) {
                    temp = temp->children[c];
                } else {
                    return false;
                }
            }
            return temp->endofword;
        }
    };

    unordered_map<string, bool> memo;  // Memoization map

    bool helper(Trie &trie, string key) {
        if (key.empty()) return true;

        if (memo.find(key) != memo.end()) return memo[key];  // Memoization check

        for (int i = 0; i < key.size(); i++) {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);
            if (trie.search(first) && helper(trie, second)) {
                return memo[key] = true;  // Store result in memoization map
            }
        }
        return memo[key] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return helper(trie, s);
    }
};
