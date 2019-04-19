//二叉树的先序遍历非递归算法

void PreOrder(BTree root) {
	if (root == null) return;
	
	//模拟栈；
	vector<BTNode*> s;
	auto p = root;
	
	while(p || !s.empty()) {
		if(p) {
			visit(p);
			s.push_back(p);
			p = p->lchild;
		} else {
			p = s.pop_back();
			p = p->rchild;
		}
	}	
}

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
