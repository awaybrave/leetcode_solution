#include<iostream>
#include "list.h"
using namespace std;

class Solution{
public:
	ListNode *partition(ListNode *head, int x){ 
		ListNode *pre = NULL; 
		ListNode *post = NULL;
		ListNode *tail1 = NULL;
		ListNode *tail2 = NULL;
		while(head != NULL){
			if(head->val < x){
				if(pre == NULL){
					pre = new ListNode(head->val);
					tail1 = pre;
				}
				else{
					tail1->next = new ListNode(head->val);
					tail1 = tail1->next;
				}
			}
			else{
				if(post == NULL){
					post = new ListNode(head->val);
					tail2 = post;
				}
				else{
					tail2->next = new ListNode(head->val);
					tail2 = tail2->next;
				}
			}
			head = head->next;
		}
		if(pre != NULL){
			tail1->next = post;
			return pre;
		}
		else
			return post;
	}
};

int main(){
	int a[] = {};// = {1, 4, 3, 2, 5, 2};
	ListNode *input = listGenerator(a, sizeof(a)/sizeof(int));
	Solution test;
	ListNode *result = test.partition(input, 3);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}
}
