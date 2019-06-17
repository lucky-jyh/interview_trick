//二叉树的先序遍历非递归算法
void PreOrder(BiTree T) {
	stack<Node*> s;
	Node*p = T;

	while(p || !s.empty()) {
		if (p) {
			visit(p);
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
