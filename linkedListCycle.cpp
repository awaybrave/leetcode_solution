#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
	bool hasCycle(ListNode* head){
		if(head != NULL){
			ListNode* slowp = head;
			ListNode* fastp = head->next;
			while(slowp != NULL && fastp != NULL){
				if(slowp == fastp)
					return false;
				else{
					slowp = slowp->next;	
					if(slowp == NULL)
						break;
					fastp = fastp->next;
					if(fastp == NULL)
						break;
					fastp = fastp->next;
				}
			}
			return true;
		}
		else
			return true;
	}
};

int main(){
	Solution test;
	ListNode*head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = head;
	cout << test.hasCycle(head) << endl;
}
