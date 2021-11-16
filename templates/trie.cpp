#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
public:
	bool end;
	vector<TrieNode*> kids;
	TrieNode(){
		end = false;
		kids = vector<TrieNode*>(27, NULL);
	}
};

void insert(TrieNode* root, string word){
 		TrieNode* node = root; 
 		for(char c: word){
 			if(!node->kids[c-'a']){
 				node->kids[c-'a'] = new TrieNode();
 			}
 			node = node->kids[c-'a'];
 		}
 		node->end = true;
}

bool search(TrieNode* root, string word){
	TrieNode* node = root;
	for(char c: word){
	if(!node->kids[c-'a']) return false;
	node = node->kids[c-'a'];
	}
	return node->end;
}


int main(){
	TrieNode* root = new TrieNode();
	vector<string> v = {"app","apple","end","appreciate"};
	for(string s : v){
		insert(root, s);
	}

	if(search(root, "app")){
		cout<<"found"<<endl;
	}else{
		cout<<"did not find";
	}
}
