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
			queue<TreeNode*> q;
			q.push(root);
			q.push(NULL);
			vector<int> row;
			while(true){
				TreeNode* current = q.front();
				q.pop(); 
				if(current != NULL){
					row.push_back(current->val);	
					if(current->left != NULL)
						q.push(current->left);
					if(current->right != NULL)
						q.push(current->right);
				}
				else{
					//result.push_back(row);
					result.insert(result.begin(), row);
					row.clear();
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
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	vector<vector<int> > result = test.levelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
