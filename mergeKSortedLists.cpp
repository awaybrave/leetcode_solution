#include"list.h"
#include<vector>

using namespace std;

class Solution{
public:	
	ListNode *mergeKLists(vector<ListNode *> &lists){
		vector<ListNode *> currents(lists);
		ListNode *result = NULL;
		ListNode *t = result;
		while(true){
			int min = 100; 
			int mark;
			for(int i = 0; i < currents.size(); i++){
				if(currents[i] != NULL){
					if(min > currents[i]->val){
						min = currents[i]->val;
						mark = i;
					}
					count++;
				}
			}
			if(min == 100)
				break;
		}
		return result;
	}
};

int main(){
	int a[] = {1,3,7,9,10,11,13,14};
	int b[] = {2,3,4};
	int c[] = {0,0};
	ListNode* al = listGenerator(a, sizeof(a)/sizeof(int));
	ListNode* bl = listGenerator(b, sizeof(b)/sizeof(int));
	ListNode* cl = listGenerator(c, sizeof(b)/sizeof(int));
	vector<ListNode *> input;
	input.push_back(al);
	//input.push_back(bl);
	//input.push_back(cl);
	Solution test;
	ListNode *result = test.mergeKLists(input);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}
}
