#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	void flatten(TreeNode *root){
		tail = root;
		if(root != NULL)
			pre_flatten(root);
	}
private:
	void pre_flatten(TreeNode *node){
		if(node->left == NULL && node->right == NULL){
			tail = node;
			return;
		}
		else{
			TreeNode *temp;
			if(node->right != NULL && node->left == NULL)
				pre_flatten(node->right);
			else{
				if(node->left != NULL && node->right == NULL){ 
					node->right = node->left;
					node->left = NULL;
					pre_flatten(node->right);
				}
				else{
					temp = node->right;
					node->right = node->left;
					node->left = NULL;
					pre_flatten(node->right);
					tail->right = temp;
					pre_flatten(temp);
				}
			}
		}
	}
	TreeNode *tail;
};

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
//	root->right = new TreeNode(2);
/*	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(6);
	root->right->right = new TreeNode(4);
*/
	Solution test;
	test.flatten(root);
	
	
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode * top = q.front();
		q.pop();
		cout << top->val << " ";
		if(top->left != NULL)
			q.push(top->left);
		if(top->right != NULL)
			q.push(top->right);
	}
	
}
