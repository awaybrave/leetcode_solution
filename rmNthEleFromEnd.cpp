#include<stack>
#include<iostream>
#include"list.h"
using namespace std; 

void printList(ListNode* l){
	ListNode* current = l;
	while(current != NULL){
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n){ 
		stack<ListNode*> s;
		ListNode* current = head;
		while(current != NULL){
			s.push(current);
			current = current->next;
		}
		int count = 0;
		ListNode* tail = NULL;
		while(count < n-1){
			tail = s.top();
			s.pop();
			count++;
		}
		if(s.size() >= 2){
			ListNode* delp = s.top();
			delete(delp);
			s.pop();	
			s.top()->next = tail;
			return head;
		}
		else{
			delete(head);
			return tail;
		}
	}
};

int main(){
	int A[] = {1,2,3,4,5};
	ListNode* head = listGenerator(A, sizeof(A)/sizeof(int));
	Solution test;
	ListNode* current = test.removeNthFromEnd(head, 3);
	printList(current);
}
