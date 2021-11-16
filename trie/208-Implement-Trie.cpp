class Trie {
public:
    
    struct TrieNode{
        vector<TrieNode*> kids;
        bool end;
        TrieNode(){
             kids = vector<TrieNode*>(27, NULL);
            end = false;
        }
    };
    
   TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c: word){
            if(!node->kids[c-'a']){
                node->kids[c-'a'] = new TrieNode();
            }
           
            node = node->kids[c-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c: word){
            if(!node->kids[c-'a']){
               return false;
            }
            node = node->kids[c-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string word) {
         TrieNode* node = root;
        for(char c: word){
            if(!node->kids[c-'a']){
               return false;
            }
             node = node->kids[c-'a'];
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