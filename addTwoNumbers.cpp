#include<iostream>
#include "list.h"
using namespace std;

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode *result = NULL;
		ListNode **cur = &result;
		int carry = 0;
		while(l1 != NULL && l2 != NULL){
			*cur = new ListNode((l1->val+l2->val+carry)%10);
			carry = l1->val+l2->val+carry >= 10 ? 1 : 0;
			cur = &((*cur)->next);
			l1 = l1->next;
			l2 = l2->next;
		}
		if(l1 != NULL || l2 != NULL){
			ListNode *remain = l1 == NULL ? l2 : l1;
			while(remain != NULL){
				*cur = new ListNode((remain->val+carry)%10);
				carry = remain->val+carry >= 10 ? 1 : 0;
				cur = &((*cur)->next);
				remain = remain->next;
			}
		}
		if(carry == 1)
			*cur = new ListNode(1);
		return result; 
	}
};

int main(){
	int a[] = {2, 4, 3};
	int b[] = {5, 6, 4};
	ListNode *x = listGenerator(a, sizeof(a)/sizeof(int));
	ListNode *y = listGenerator(b, sizeof(b)/sizeof(int)); 

	Solution test;
	ListNode *result = test.addTwoNumbers(x, y);
}
