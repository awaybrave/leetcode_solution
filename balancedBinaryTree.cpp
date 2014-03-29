/*{1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5}*/
#include<iostream>
#include<cmath>
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
	bool isBalanced(TreeNode *root){
		int left, right;
		return check(root, left, right);
	}
	bool check(TreeNode *node, int& leftHeight, int& rightHeight){
		if(node == NULL){
			leftHeight = 0;
			rightHeight = 0;
			return true;
		}
		int cl,cr; 
		bool rl = check(node->left, cl, cr);
		if(!rl) return false;
		leftHeight = max(cl, cr)+1;
		bool rr = check(node->right, cl, cr);
		if(!rr) return false;
		rightHeight = max(cl, cr)+1;
		if(abs(leftHeight-rightHeight)>1)
			return false;
		else
			return true;
	}
};

int main(){
	Solution test;
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(6);
	root->left = new TreeNode(2);
	/*
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);
	root->left->left->left = new TreeNode(5);
	*/
	cout << test.isBalanced(root) << endl;
}
