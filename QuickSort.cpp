//快速排序
/*
 基本思想：首先通过一趟排序将待排序记录序列分为两个部分，其中一部分的关键字都不大于另一部分
*/

//一趟排序过程
int Partition(SqList &L, int low, int high) {
	auto tmp = L[low];
	
	while(low < high) {
		while(low < high && L[high] >= tmp) {
			--high;
		}
		L[low] = L[high];
		while(low < high && L[low] <= tmp) {
			++low;
		}
		L[high] = L[low];
	}
	
	L[low] = tmp;
	return low;
}

//递归的快速排序主函数
void QSort(SqList &L, int low, int high) {
	if(low < high) {
		int position = Partition(L, low, high);
		QSort(L, low, position - 1);
		QSort(L, position + 1, high);
	}
}