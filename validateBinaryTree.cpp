#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode{
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxm = 100000;
int minm = -100000;

class Solution{
public:
	bool isValidBST(TreeNode *root){
		if(root == NULL)
			return true;
		queue<TreeNode *> q;
		queue<vector<int> > range;

		q.push(root);
		vector<int> init;
		init.push_back(minm); //lowerbound for left subtree.
		init.push_back(maxm); //upperbound for right subtree.
		range.push(init);

		while(!q.empty()){
			TreeNode *head = q.front();
			vector<int> curRange = range.front();
			q.pop(); 
			range.pop();

			vector<int> leftRange;
			vector<int> rightRange;
			if(head->left != NULL){
				if(head->left->val > curRange[0] && head->left->val < head->val){
					leftRange.push_back(curRange[0]);
					leftRange.push_back(head->val);

					q.push(head->left);
					range.push(leftRange);
				}
				else
					return false;
			}
			if(head->right != NULL){
				if(head->right->val > head->val && head->right->val < curRange[1]){
					rightRange.push_back(head->val);
					rightRange.push_back(curRange[1]);

					q.push(head->right);
					range.push(rightRange);
				}
				else
					return false; 
			}
		}

		return true;
	}
};
 

int main(){
	// testCase 1: an empty tree;
	//TreeNode *root = NULL;
	
	// testCase 2: {2, 1, 3};
	//TreeNode * root = new TreeNode(2);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(3);

	// testCase 3: {2, 3, 1};
	//TreeNode * root = new TreeNode(2);
	//root->left = new TreeNode(3);
	//root->right = new TreeNode(1);

	// testCase 4: {2, 1, 4, #, #,  3, 5};
	//TreeNode * root = new TreeNode(2);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(4);
	//root->right->left = new TreeNode(3);
	//root->right->right= new TreeNode(5); 

	// testCase 4: {10, 5, 15, #, #,  9, 20};
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(9);
	root->right->right= new TreeNode(20); 
	
	Solution test;
	cout << test.isValidBST(root) << endl;
}
