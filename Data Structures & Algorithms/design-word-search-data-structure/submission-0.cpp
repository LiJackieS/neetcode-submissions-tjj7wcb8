class Trie {
    public:
    vector<Trie*> children;
    bool word;

    Trie() : children(26,nullptr), word(false) {}
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() : root(new Trie()) {}
    
    void addWord(string word) {
        Trie* cur = root;
        for (char c : word) {
            if (cur->children[c-'a'] == nullptr) {
                cur->children[c-'a'] = new Trie();
            }
            cur = cur->children[c-'a'];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string word, int j, Trie* root) {
        Trie* cur = root;
        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (Trie* child : cur->children) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (cur->children[c-'a'] == nullptr) {
                    return false;
                }
                cur = cur->children[c-'a'];
            }
        }
        return cur->word;
    }
};
