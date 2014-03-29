#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
	ListNode *insertionSortlist(ListNode *head){
		if(head == NULL)
			return NULL;
		ListNode *result = new ListNode(head->val);
		ListNode *current = head->next;
		ListNode *pre = NULL;
		ListNode *temp = result;
		while(current != NULL){
			while(temp != NULL && current->val > temp->val){
				pre = temp;
				temp = temp->next;
			}
			if(pre != NULL){
				pre->next = new ListNode(current->val);
				pre->next->next = temp;
			}
			else{
				ListNode* newhead = new ListNode(current->val);
				newhead->next = result;
				result = newhead;
			}
			pre = NULL;
			temp = result;
			current = current->next;
		}
		return result;
	}
};


ListNode *listGenerator(int A[], int n){
	if(n == 0)
		return NULL;
	ListNode *head = new ListNode(A[0]);
	ListNode *current = head;
	for(int i = 1; i < n; i++){
		current->next = new ListNode(A[i]);	
		current = current->next;
	}
	return head;
}


void printList(ListNode* l){
	ListNode* current = l;
	while(current != NULL){
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

int main(){
	//int a[] = {3,2,5,1,5,8,10,7,3,13,42,84,24,56,92,46,22,87,61};
	int a[] = {};
	Solution test;
	ListNode* head = listGenerator(a, sizeof(a)/sizeof(int));
	printList(test.insertionSortlist(head));
}
