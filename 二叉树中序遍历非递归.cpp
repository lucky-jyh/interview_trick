/*一种更优雅和更好理解的方式*/
int InOrderTraverse(BiTree T) {
	stack<Node*> s;
	Node* p = T;

	while(p || !s.empty()) {
		while(p) {
			s.push(p);
			p = p->lchild;
		}
		while(!s.empty()) {
			p = s.top();
			visit();
			s.pop();
			p = p->rchild;
		}
	}
}
//上面的方法不用判断T的合法性，不用先push根节点进栈，并且不会push空指针进stack


//二叉树的中序遍历非递归排序
void InOrderTraverse(BiTree T) {
	if(T == nullptr) return;
	
	//辅助栈
	vector<BiTNode*> S;
	BiTNode* p = T;
	S.push_back(p);
	
	while(!S.empty()) {
		while(p) {
			p = p->lchild;
			S.push_back(p);
		}
		S.pop_back();
		
		//出栈，访问结点，转到右子树；
		if(!S.empty()) {
			p = S.pop_back();
			Visit(p);
			p = p->rchild;
			S.push_back(p);
		}
	}
}