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
	TreeNode *sortedArrayToBST(vector<int> &num){
		if(num.size() == 0)
			return NULL;
		int mid = (0+num.size()-1)/2;
		TreeNode* result = new TreeNode(num[mid]);
		getChild(num, 0, mid-1, result, false);
		getChild(num, mid+1, num.size()-1, result, true);
		return result;
	//	cout << "finished!" << endl;
	}
private:
	void getChild(vector<int> &num, int head, int tail, TreeNode* current, bool flag){
		if(head > tail){
			return;
		}
		if(head == tail){
			if(!flag)
				current->left = new TreeNode(num[head]);
			else
				current->right = new TreeNode(num[head]);
			return;
		}
		int mid = (head+tail)/2;
		if(!flag){
			current->left = new TreeNode(num[mid]);
			getChild(num, head, mid-1, current->left, false);
			getChild(num, mid+1, tail, current->left, true);
		}
		else{
			current->right = new TreeNode(num[mid]);
			getChild(num, head, mid-1, current->right, false);
			getChild(num, mid+1, tail, current->right, true);
		}
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
	Solution test;
	vector<int> number;//(1,1);
	for(int i = 0; i < 10; i++){
		number.push_back(i);
	}
	TreeNode* root = test.sortedArrayToBST(number);
	vector<vector<int> > result = levelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
