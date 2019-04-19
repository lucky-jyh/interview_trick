/*一种更优雅和更好理解的方式*/
int InOrderTraverse(BiTree T) {
	stack<Node*> s;
	Node* p = T;

	while(p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			visit(p);
			s.pop();
			p = p->rchild;
		}
	}
}
