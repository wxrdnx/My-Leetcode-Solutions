struct TrieNode {
    array<TrieNode *, 26> children;
    bool is_word;
    TrieNode(): children(), is_word(false) {
        
    }
};
class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        return search_helper(word, root, 0);
    }
private:

    bool search_helper(string& word, TrieNode *curr, int i) {
        if (!curr) {
            return false;
        }
        if (i == word.length()) {
            return curr->is_word;
        }
        if (word[i] != '.') {
            return search_helper(word, curr->children[word[i] - 'a'], i + 1);
        }
        for (char c = 0; c < 26; c++) {
            if (search_helper(word, curr->children[c], i + 1)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
