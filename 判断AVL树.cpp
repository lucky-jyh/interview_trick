
bool  is_AVL(BiTree T) {
	if (T == nullptr) 
		return true;
	
	l_h = cal_height(T->left);
	r_h = cal_height(T->right);
	if ( abs(l_h - r_h)  > 1 ) 
		return false; 
	if ( is_AVL(T->left) && is_AVL(T->right) )
		return ture;
	return false;
}

//判断是否为二叉搜索树
bool is_BST(TreeNode *root) {
	if(root == NULL) return true;
	if (!is_BST(root->left)) return false;
   	 if (!is_BST(root->right)) return false;
    	TreeNode *cur = root->left;
    	if (cur != NULL) {
        		while(cur->right!=NULL) cur = cur->right;
       		 if(root->key < cur->key) return false;
   	 }
    	TreeNode *cur = root->right;
    	if (cur != NULL) {
        		while(cur->left!=NULL) cur = cur->left;
       		 if(root->key > cur->key) return false;
   	}
    	return true;
}

//计算树的高度（同样是递归的方式）
int cal_height(BiTree T) {
	if (T == nullptr) 
		return 0;
	l_h = cal_height(T->left);
	r_h = cal_height(T->right);
	
	return max(l_h, r_h) + 1;
}