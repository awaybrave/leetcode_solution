#include<vector>
#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<int> inorderTraversal(TreeNode *root){
		vector<int> result;
		if(root != NULL){
			stack<bool> status;
			stack<TreeNode*> nodes; 
			status.push(false);
			nodes.push(root);
			while(!nodes.empty()){
				TreeNode* cur = nodes.top();
				bool curStatus = status.top();
				if(!curStatus){
					status.pop();
					status.push(true);
					if(cur->left != NULL){
						nodes.push(cur->left);
						status.push(false);
					}
				}
				else{
					result.push_back(cur->val);	
					nodes.pop();
					status.pop();
					if(cur->right != NULL){
						nodes.push(cur->right);
						status.push(false);
					}
				}
			}
		}
		return result;
	}
};

int main(){
	Solution t;
	TreeNode* root = new TreeNode(1);	
	root->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->right = new TreeNode(6);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3); 
	vector<int> result = t.inorderTraversal(root);
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
}
