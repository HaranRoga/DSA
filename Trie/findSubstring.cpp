#include <vector>

using namespace::std;


class Node {
    public:
    Node* ch[26];
    vector<int> vc;
    Node() {
        for(int i=0; i<26; i++)
        {
            ch[i] = NULL;
        }
        vc.clear();
    }
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

class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete root;
        root = NULL;
    }
    void addWord(string s, int  idx) {
        Node* cur = root;
        for(char ch: s)
        {
            if(cur->ch[ch - 'a'] == NULL)
            {
                cur->ch[ch - 'a'] = new Node();
            }
            cur = cur->ch[ch - 'a'];
        }
        cur->vc.push_back(idx);
    }
    vector<int> search(string s) {
        for(char ch: s)
        {
            if(cur->ch[ch - 'a'] == NULL)
            {
                return {-1};
            }
            else
            {
                cur = cur->ch[ch - 'a'];
            }
        }
        return cur->vc;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // use 2d array that tracks the use of words while iterating through s
        // another array contains number of matching words found so far

        // define the following integers:
        // n: string lengeth
        // w1: number of words
        // w2: length of words
        // w3: calculated length of the concatenated (s0 destination)

        // define the following arrays
        // used(w2, w1): matrix contains index of used words (-1 unused)
        // idx0(w2): index of first matching word (-1 no matches yet)

        // define Trie of characters that contains list with idexes of the words
        // searching the Trie will return vector with the indexes

        // iterate through s 0 to n -> w2 (i)
        // handle word offset 0 -> w2 (wOff)
        // search the Tire with substring i -> i+w2-1
        // when returned array is empty:
        //      set all used [wOff][x] to -1
        //      set idx0[wOff] to -1
        // when returned array contains indexes:
        //      check used[wOff][idx]:
        //          if not used:
        //              set it to i
        //              check length of idx0[wOff] against w3, if equals:
        //                  add idx0[wOff] to ans[]
        //                  set used[wOff][x] that points to idx0[wOff] to -1
        //                  increase idx0[wOff] by w2
        //          if all used...
        //              set all used [wOff][x] to -1
        //              set idx0[wOff] to -1

    }
};