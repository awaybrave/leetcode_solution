#include "list.h"
/**/

class Solution{
public:
	ListNode *rotateRight(ListNode *head, int k){
		if(head == NULL)
			return NULL;
		ListNode *h = head;
		ListNode *t; 
		ListNode *cur = h;
		int size = 0;
		while(cur != NULL){
			t = cur;
			size++;
			cur = cur->next;
		}
		//int times = size >= k ? size-k : size*2-k;
		int times;
		if(size < k){
			while(k > size)
				k -= size;
		}
		times = size-k;
		for(int i = 0; i < times; i++){
			t->next = h;
			t = t->next;
			h = h->next;
		}
		t->next = NULL;
		return h;
	}
};

int main(){
	//int a[] = {1, 2, 3, 4, 5};
	int a[] = {1,2};
	ListNode *input = listGenerator(a, sizeof(a)/sizeof(int));
	Solution test;
	ListNode *output = test.rotateRight(input, 5);
	while(output != NULL){
		cout << output->val << " ";
		output = output->next;
	}
}
