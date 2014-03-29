#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	int sumNumbers(TreeNode *root){
		sum = 0;	
		if(root != NULL)
			calNode(root, root->val); 
		return sum;
	}
private:
	int sum;
	void calNode(TreeNode *node, int curSum){
		if(node->left == NULL && node->right == NULL){
			sum += curSum;
		}
		else{
			curSum = curSum*10;
			if(node->left != NULL)
				calNode(node->left, curSum+node->left->val);
			if(node->right != NULL)
				calNode(node->right, curSum+node->right->val);
		}
	}
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(3);
	Solution test;
	cout << test.sumNumbers(root) << endl;
	cout << test.sumNumbers(NULL) << endl;
	cout << test.sumNumbers(root) << endl;
}
