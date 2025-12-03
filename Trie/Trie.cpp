#include <iostream>
#include <vector>

using namespace::std;

// node used to keep alphabetic character of a word
class Node {
    Node* ch[26];
    bool endOfWord;
    // default constructor
    Node() {
        for(int i=0; i<26; i++)
        {
            ch[i] = NULL;
        }
    }
    // destructor
    ~Node() {
        for(int i=0; i<26; i++)
        {
            if(ch[i])
            {
                delete ch[i];
                ch[i] = NULL;
            }
        }
    }
}

// Trie stores words in highly efficient whay to sort them up
class Trie {
    Node* root;
    // default constructor
    Trie() {
        root = new Node();
    }
    // destructor
    ~Trie() {
        delete root;
        root = NULL;
    }
    // add element to the storage
    void addWord(string& word) {
        Node* cur = root;
        for(char ch: word)
        {
            if(cur->ch[ch - 'a'] == NULL)
            {
                cur->ch[ch - 'a'] = new Node();
            }
            cur = cur->ch[ch - 'a'];
        }
        cur->endOfWord = true;
    }
}