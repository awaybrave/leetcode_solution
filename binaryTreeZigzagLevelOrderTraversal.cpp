#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode * right;
	TreeNode (int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<vector<int> > levelOrder(TreeNode *root){
		vector<vector<int> > result;
		if(root != NULL){
			bool status = true;
			queue<TreeNode*> q;
			q.push(root);
			q.push(NULL);
			vector<int> row;
			while(true){
				TreeNode* current = q.front();
				q.pop(); 
				if(current != NULL){
					if(status)
						row.push_back(current->val);	
					else
						row.insert(row.begin(), current->val);
					if(current->left != NULL)
						q.push(current->left);
					if(current->right != NULL)
						q.push(current->right);
				}
				else{
					result.push_back(row);
					row.clear();
					status = !status;
					if(!q.empty())
						q.push(NULL);
					else
						break;
				}
			}
		}
		return result;
	}
};

int main(){
	Solution test;
	TreeNode* root = new TreeNode(3); 
	root->left = new TreeNode(9);
	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > result = test.levelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
