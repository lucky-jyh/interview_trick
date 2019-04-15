//递归的方法
bool is_similar(BiTree t1, BiTree t2) {
	if (t1 == nullptr && t2 == nullptr) //两个树都为空
		return true;
	else if (t1 == nullptr || t2 == nullptr)  //只有一棵树为空
		return false;
	else { //递归地进行判断
		l_b = is_similiar(t1->left, t2->left);
		r_b = is_similiar(t1->right, t2->right);
		return l_b && r_b;
	}
}

//非递归的方法
非递归的解法，就是同步的非递归的遍历两个二叉树（前序、中序、后序、分层都行），看是否遍历行为一致。