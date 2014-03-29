#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
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
}

class Solution{
public:
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		ListNode* c1 = l1;
		ListNode* c2 = l2;
		ListNode* result = NULL;
		ListNode* result2;
		while(c1 != NULL && c2 != NULL){
			if(c1->val <= c2->val){
				ListNode* temp = c1->next;
				if(result == NULL){
					result = c1;
					result2 = result;
				}
				else{
					result->next = c1;
					result = result->next;
				}
				c1 = temp;
			}
			else{
				ListNode* temp = c2->next;
				if(result == NULL){
					result = c2;
					result2 = result;
				}
				else{
					result->next = c2;
					result = result->next;
				}
				c2 = temp; 
			}
		}
		if(c1 != NULL){
			result->next = c1;
		}
		if(c2 != NULL)
			result->next = c2;
		return result2;
	}
};

int main(){
	int a[] = {1,3,5,7,9};
	int b[] = {2,4,6,8,10,12};
	ListNode *l1 = listGenerator(a, sizeof(a)/sizeof(int));
	ListNode *l2 = listGenerator(b, sizeof(b)/sizeof(int));
	Solution test;
	ListNode *result = test.mergeTwoLists(l1, NULL);
	printList(result);
}
