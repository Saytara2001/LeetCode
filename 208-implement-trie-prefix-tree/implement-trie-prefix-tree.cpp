struct trie {
    struct Node {
        Node *child[27];
        int prefix, end;

        Node() {
            memset(child, 0, sizeof child);
            prefix = end = 0;
        };
    };

    Node *root = new Node();
    char const BASE = 'a';

    void insert(string &s) {
        Node *current = root;
        for (auto c: s) {
            int idx = c - BASE;
            if (current->child[idx] == 0) {
                current->child[idx] = new Node();
            }
            current = current->child[idx];
            current->prefix++;
        }
        current->end++;
    }

    bool find(string &s) {
        Node *current = root;
        for (auto c: s) {
            int idx = c - BASE;
            if (current->child[idx] == 0) {
                return false;
            }
            current = current->child[idx];
        }
        return current->end;
    }

    int countPrefix(string &s) {
        Node *current = root;
        for (auto c: s) {
            int idx = c - BASE;
            if (current->child[idx] == 0) {
                return 0;
            }
            current = current->child[idx];
        }
        return current->prefix;
    }

    bool isPrefix(string &s) {
        Node *current = root;
        for (auto c: s) {
            int idx = c - BASE;
            if (current->child[idx] == 0) {
                return 0;
            }
            current = current->child[idx];
        }
        return true;
    }

};
class Trie {
public:
    trie t;
    Trie() {
        
    }
    
    void insert(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.find(word);
    }
    
    bool startsWith(string prefix) {
        return t.isPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */