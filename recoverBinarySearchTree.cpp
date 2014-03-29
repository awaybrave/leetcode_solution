#include"tree.h"

class Solution{
public:
	void recoverTree(TreeNode *root){
		pre = NULL;
		wer1 = NULL;
		wer2 = NULL;
		recursive(root);
		cout << wer1->val << wer2->val << endl;
		int temp = wer1->val;
		wer1->val = wer2->val;
		wer2->val = temp;
	}
private:
	TreeNode *wer1;
	TreeNode *wer2;
	TreeNode *pre;
	void recursive(TreeNode *node){ 
		if(node){
			if(node->left != NULL) 
				recursive(node->left);
			if(pre != NULL){
				if(pre->val > node->val){
					if(wer1 == NULL){
						wer1 = pre;
						wer2 = node;
					}
					else
						wer2 = node;
				}
			}
			pre = node;
			if(node->right != NULL)
				recursive(node->right);
		}
	}
};

int main(){
	TreeNode *head = new TreeNode(4);
	head->left = new TreeNode(2);
	head->right = new TreeNode(8);
	head->left->left = new TreeNode(1);
	head->left->right = new TreeNode(3);
	head->right->left = new TreeNode(10);
	head->right->right = new TreeNode(9);
	head->right->right->right = new TreeNode(5);
	Solution test;
	test.recoverTree(head);
	inorder_print_tree(head);
}
