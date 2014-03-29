#include<vector>
#include<queue>
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
	bool isSymmetric(TreeNode *root){
		if(root == NULL)
			return true;
		int levelCount = 2;
		int nodeCount = 0;
		int nullCount = 0;
		queue<TreeNode*> q;
		vector<TreeNode*> levelList;
		q.push(root);
		while(!q.empty()){
			TreeNode* current = q.front();
			q.pop();
			levelList.push_back(current->left);	
			levelList.push_back(current->right);	
			nodeCount += 2;
			if(current->left != NULL)
				q.push(current->left);
			else
				nullCount++;
			if(current->right != NULL)
				q.push(current->right);
			else
				nullCount++;
			if(nodeCount == levelCount){
				/*check symmetricity*/
				for(int i = 0; i < levelCount / 2; i++){
					if(levelList[i] == NULL && levelList[levelCount-i-1] != NULL
						|| levelList[i] != NULL && levelList[levelCount-i-1] == NULL
						|| levelList[i] != NULL && levelList[levelCount-i-1] != NULL 
						&&levelList[i]->val != levelList[levelCount-i-1]->val)
						return false;
				}
				levelCount = (levelList.size()-nullCount)*2;
				levelList.clear();
				nodeCount = 0;
				nullCount = 0;
			}
		}
		return true;
	}
};

int main(){
	Solution test;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(5);
	//root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(6);
	root->right = new TreeNode(4);
	//root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(6);
	cout << test.isSymmetric(root) << endl;
}
