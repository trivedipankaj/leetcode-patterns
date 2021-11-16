class TrieNode{
  public:
  bool end;
  string word;
  vector<TrieNode*> kids;

    TrieNode(){
        end = false;
        kids = vector<TrieNode*>(27, NULL);
        word = "";
    }
};

class Solution {
public:
   
    void insert(TrieNode* root, string word){
        TrieNode* node = root;
       for(char c: word){
           if(!node->kids[c-'a']){
               node->kids[c-'a'] = new TrieNode();
           }
           node = node->kids[c-'a'];
       }
        node->end = true;
        node->word = word;
    } 
    
    string longest(TrieNode* root){
        string result ="";
        queue<TrieNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto curr = q.front(); q.pop();
                for(int j=25; j>=0; j--){
                    if(curr->kids[j] != NULL && curr->kids[j]->end ){
                        result = curr->kids[j]->word;
                        q.push(curr->kids[j]);
                    }
                }
            }
            
        }
        return result;
    }
    
    
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word: words){
            insert(root, word);
        }
        return longest(root);
    }
};