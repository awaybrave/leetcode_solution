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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
		if(inorder.size() == 0 && postorder.size() == 0)
			return NULL;
		int size = postorder.size();

		/*map the tree element*/
		inmap.clear();
		for(int i = 0; i < size; i++)
			inmap[inorder[i]] = i;
	
		/*recursively build the tree*/	
		int p = size-1;
		TreeNode *root = rbuildTree(0, size-1, p, postorder);
		return root;
	}
private:
	map<int,int>inmap;
	TreeNode* rbuildTree(int left, int right, int &p, vector<int> &post){
		if(left > right)
			return NULL;
		if(left == right)
			return new TreeNode(post[p--]);

		TreeNode *r = new TreeNode(post[p]);
		p--;

		int rp = inmap[post[p+1]];
		int temp = post[p];
		int tp = inmap[temp];

		//build the right subtree;
		if(tp >= left && tp <= right && tp > rp){
			r->right = rbuildTree(rp+1, right, p, post);
		}
		
		//build the left subtree;
		temp = post[p];
		tp = inmap[temp];
		if(tp >= left && tp <= right && tp < rp){
			r->left = rbuildTree(left, rp-1, p, post);
		}
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
	int in[] = {1,2,3,4};
	int post[] = {1,4,3,2};
	Solution test;
	vector<int> inorder(in, in+sizeof(in)/sizeof(int));
	vector<int> postorder(post, post+sizeof(post)/sizeof(int));
	TreeNode *root = test.buildTree(inorder, postorder);
	vector<vector<int> >result = levelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
