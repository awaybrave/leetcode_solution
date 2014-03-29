#include "list.h"

class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		ListNode * current = head;
		ListNode * result = head;
		ListNode * pre = NULL;
		bool nailDownHead = false;
		while(current != NULL){
			ListNode *search = current->next;
			bool flag = false;
			while(search != NULL && search->val == current->val){
				flag = true;
				ListNode *delNode = search;
				search = search->next;
				delete(delNode);
			}
			if(flag){ 
				ListNode *delNode = current; 
				current = search;
				if(!nailDownHead)
					result = current;
				if(pre != NULL)
					pre->next = current;
				delete(delNode);
			}
			else{
				if(!nailDownHead){
					result = current;
					nailDownHead = true;
				}
				pre = current;
				current = current->next;
			}
		}
		return result;
	}
};

int main(){
	// 1.null head;
	// 2.tail duplicate which make the tail point to an
	// unknown position because I delete every duplicate
	// node;
	int arr[] = {2,2,3,3};
	ListNode *list = listGenerator(arr, sizeof(arr)/sizeof(int));
	Solution test;
	ListNode *result = test.deleteDuplicates(list);
	ListNode *tra = result;
	while(tra != NULL){
		cout << tra->val << " ";
		tra= tra->next;
	}
	cout << endl;
	return 0;
}
