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