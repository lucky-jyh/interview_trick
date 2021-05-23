
int lowestCommonAncestor(TreeNode* root, int a, int b) {
	if (root == NULL || root->val ==a || root->val == b) {
		return root;
	}

	TreeNode* left = lowestCommonAncestor(root->left, a, b);
	TreeNode* right = lowestCommonAncestor(root->right, a, b);
	if (left == NULL) {  //左子树中没有找到a,b，返回右子树的结果
		return right;
	}
	if (right == NULL) {  //右子树中没有找到a,b，返回左子树的结果
		return left;
	}

	return root;  //a,b分别再root左右子树的两侧
}