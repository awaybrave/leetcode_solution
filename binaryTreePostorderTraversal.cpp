#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<int> postorderTraversal(TreeNode *root){
		vector<int> result;
		if(root != NULL){
			stack<TreeNode*> s;
			stack<int> status;
			s.push(root);
			status.push(0);
			while(!s.empty()){
				int currentStatus = status.top();
				TreeNode* current = s.top();
				if(currentStatus == 0){
					if(current->left != NULL){
						s.push(current->left);
						status.push(0);
					}
					else{
						status.pop();
						status.push(1);
					}
				}
				if(currentStatus == 1){
					if(current->right != NULL){
						s.push(current->right);
						status.push(0);
					}
					else{
						status.pop();
						status.push(2);
					}
				}
				if(currentStatus == 2){
					result.push_back(current->val);
					s.pop();
					status.pop();
					if(!s.empty()){
						int temp = status.top();
						status.pop();
						status.push(temp+1);
					}
				}
			}
		}
		return result;
	}
};

int main(){
	Solution test;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	vector<int> result = test.postorderTraversal(root);
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
