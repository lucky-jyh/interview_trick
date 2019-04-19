//二叉树的先序遍历非递归算法
//更好理解的版本
void Preorder(BiTree root) {
	stack<const BtNode*> s;
	if (root != nullptr) 
		s.push(root);
	
	while (!s.empty()) {
		const BtNode *p = s.top();
		s.pop();
		visit(p);

		if (p->lchild != nullptr) s.push(p->lchild);
		if (p->rchild != nullptr) s.push(p->rchild);
	}
}
