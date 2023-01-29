class Trie {
    array<Trie *, 26> children;
    bool is_word;
public:
    Trie(): children(), is_word(false) {

    }
    
    void insert(string word) {
        Trie *curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        Trie *curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        Trie *curr = this;
        for (char c : prefix) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
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
