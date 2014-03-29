#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
	ListNode* detectCycle(ListNode* head){
		if(head != NULL){
				ListNode* slowp = head;
			ListNode* fastp = head;
			bool init = true;
			while(slowp != NULL && fastp != NULL){
				if(!init && slowp == fastp){ 
					return findCycleEnter(head, slowp); 
				}
				else{
					slowp = slowp->next;	
					if(slowp == NULL)
						break;
					fastp = fastp->next;
					if(fastp == NULL)
						break;
					fastp = fastp->next;
				}
				if(init)
				    init = false;
			return NULL;
		}
		else
			return NULL;
	}
private:
	ListNode* findCycleEnter(ListNode* head, ListNode* tak){
		ListNode* slowp = head;
		ListNode* fastp = tak;
		while(slowp != fastp){
			slowp = slowp->next;
			fastp = fastp->next;
		}
		return slowp;
	}
};

int main(){
	Solution test;
	ListNode*head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = head;
	ListNode* cycleEntrance = test.detectCycle(head); 
	if(cycleEntrance != NULL){
		cout <<  cycleEntrance->val << endl;
	}
	else{
		cout << "NULL" << endl;
	}
}
