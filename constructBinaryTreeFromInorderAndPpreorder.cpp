#include<vector>
#include<map>
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
		if(inorder.size() == 0 && preorder.size() == 0)
			return NULL;
		int size = inorder.size(); 
		/*map the tree element*/
		inmap.clear();
		for(int i = 0; i < size; i++)
			inmap[inorder[i]] = i; 
		/*recursively build the tree*/	
		int p = 0;
		TreeNode *root = rbuildTree(0, size-1, p, preorder);
		return root;
	}
private:
	map<int,int>inmap;
	TreeNode* rbuildTree(int left, int right, int &p, vector<int> &pre){
		if(left > right)
			return NULL;
		if(left == right)
			return new TreeNode(pre[p++]); 

		TreeNode *r = new TreeNode(pre[p++]);

		//build the left subtree;
		int rp = inmap[pre[p-1]];
		int temp = pre[p];
		int tp = inmap[temp];

		if(tp >= left && tp <= right && tp < rp)
			r->left = rbuildTree(left, rp-1, p, pre);
		
		//build the right subtree;
		temp = pre[p];
		tp = inmap[temp];
		if(tp >= left && tp <= right && tp > rp)
			r->right = rbuildTree(rp+1, right, p, pre); 

		return r;
	}
};

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
				result.push_back(row);
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

int main(){
	int in[] = {1,2};
	int pre[] = {2,1};
	Solution test;
	vector<int> inorder(in, in+sizeof(in)/sizeof(int));
	vector<int> preorder(pre, pre+sizeof(pre)/sizeof(int));
	TreeNode *root = test.buildTree(preorder, inorder);
	vector<vector<int> >result = levelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
