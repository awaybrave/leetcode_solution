struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		ListNode *cur = head;
		vector<int> num;
		while(cur != NULL){
			num.push_back(cur->val);
			cur = cur->next;
		}
		return sortedArrayToBST(num);
    }
private: 
	TreeNode *sortedArrayToBST(vector<int> &num){
		if(num.size() == 0)
			return NULL;
		int mid = (0+num.size()-1)/2;
		TreeNode* result = new TreeNode(num[mid]);
		getChild(num, 0, mid-1, result, false);
		getChild(num, mid+1, num.size()-1, result, true);
		return result;
	}
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

int main(){

}
