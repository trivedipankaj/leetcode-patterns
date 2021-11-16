#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	ListNode* next;
	int val;

	

	ListNode(int value){
		val = value;
		next = NULL;
	}
};


ListNode* insert(ListNode* head, int val){
	if(!head){
		return new ListNode(val); 
	}
	ListNode* node = head;
	while(node->next != NULL){
		node = node->next;
	}
	node->next = new ListNode(val);
	return head;
}

ListNode* reverse(ListNode* head){
	ListNode* current = head;
	ListNode* next;
	ListNode* prev = NULL;

	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

ListNode* getMiddle(ListNode* head){
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	reverse(slow);
	return slow;
}

void printList(ListNode* head){
	ListNode *node = head;
	while(node != NULL){
		cout<<node->val<<" ";
		node = node->next;
	}
	cout<<endl;
}

int main(){
    ListNode* head = NULL;
    vector<int> v = {3,5,21,1,3,45,322};
    for( auto val : v){
    	head = insert(head, val);
	}
    
    //auto reversed = reverse(head);

    printList(head);
     //printList(reversed);
    auto mid = getMiddle(head);
    cout<<mid->val<<endl;
     printList(head);
}