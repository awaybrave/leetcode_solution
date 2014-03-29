#include<iostream>
#include<queue>
using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
	void connect(TreeLinkNode *root){
		if(root != NULL){
			queue<TreeLinkNode*> q;
			q.push(root);
			q.push(NULL);
			while(!q.empty()){
				TreeLinkNode* current = q.front();
				q.pop();
				if(current != NULL){
					current->next = q.front();
					if(current->left != NULL)
						q.push(current->left);
					if(current->right != NULL)
						q.push(current->right);
				}
				else{
					if(!q.empty()){
						q.push(NULL);
					}
				}
			}
		}
	}
};

int main(){
	Solution test;
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->right->left = new TreeLinkNode(5);
	test.connect(root);
	queue<TreeLinkNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeLinkNode* current = q.front();
		q.pop();
		if(current->next != NULL)
			cout << current->val << "-->" << current->next->val << endl;
		else 
			cout << current->val << "-->" << "NULL" << endl;
		if(current->left != NULL)
			q.push(current->left);
		if(current->right != NULL)
			q.push(current->right);

	}
}
