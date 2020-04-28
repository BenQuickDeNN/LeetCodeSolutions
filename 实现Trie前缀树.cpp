#include <string>
#include <vector>

using namespace std;

class Trie {
    bool is_string = false;
    Trie* next[26] = {NULL}; // 字母有26个
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* ptrie = this;
        for (const auto& w : word)
        {
            if (ptrie->next[w - 'a'] == NULL)
                ptrie->next[w - 'a'] = new Trie();
            ptrie = ptrie->next[w - 'a'];
        }
        ptrie->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* ptrie = this;
        for (const auto& w : word)
        {
            if (ptrie->next[w - 'a'] == NULL)
                return false;
            ptrie = ptrie->next[w - 'a'];
        }
        return ptrie->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* ptrie = this;
        for (const auto& p : prefix)
        {
            if (ptrie->next[p - 'a'] == NULL)
                return false;
            ptrie = ptrie->next[p - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */