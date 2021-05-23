//单链表反转(极其简单的操作，为什么以前就是不明白呢？
//也许在农大这段不工作的时间，静下心来，有些东西不再“浑浊”)

void ReverseList(NodeList &L) {
	if(L == nullptr){
		return;
	}
	
	Node* p = L->next; //带头结点的情况，L即是头结点，不带头结点的情况下，是p=L；下面关键的两步的第一步是p->next = L; L = p;
	L->next = nullptr;
	Node* q;
	
	//逐步把单链表剥离，一次剥离一个结点；
	while(p) {
		q = p->next;
		/*最关键的两步*/
		p->next = L->next;
		L->next = p;
		/*************/
		p = q;
	}
}


//递归方式实现链表的反转
Node* reverse_list(NodeList &L)
{
	if(L == nullptr || L->next == nullptr) 
		return;
	
	Node* new_head = reverse_list(L->next);
	//L->next指向的是原来的第二个结点，经过上一条语句的执行，该结点变为最后一个结点
	L->next->next = L;	
	L->next = nullptr;
	
	return new_head;
}
		