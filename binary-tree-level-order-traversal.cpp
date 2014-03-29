#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<vector<int> > levelOrder(TreeNode* root){
		vector<vector<int> >result;
		if(root != NULL){
			queue<TreeNode*> q;
			q.push(NULL);
			vector<int> row;
			while(!q.empty()){
				TreeNode* current = q.front();
				q.pop();
				if(current == NULL){
					result.push_back(row);
					row.clear();
					q.push(NULL);
				}
				else{
					row.push_back(current->val);
					if(current->left != NULL)
						q.push(current->left);
					if(current->right!= NULL)
						q.push(current->right); 
				}
			}
		}
		return result;
	}
};

int main(){
	TreeNode* root = new TreeNode(1);
	Solution test;
	test.levelOrder(root);
}
