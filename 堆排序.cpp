//堆排序及堆调整的代码实现

template <typename T>
void heap_sort(T* a, int size)
{
	//构建初始堆（其实也是堆调整的过程，只不过只需要调整非叶子结点即可）
	for(int i = size/2 - 1; i >= 0; i--)
		heap_adjust(a, size-i, i);

	while(size > 0)
	{
		//最后一个叶子结点与堆顶元素a[0]交换，同时堆的大小减一，
		//也就是堆顶元素出堆
		a[size-1] <-> a[0]
		size--;
		//调整剩下的堆
		heap_adjust(a, size, 0);
	}
	return;
}


//堆调整的代码，第二个参数是堆的大小，第三个参数是要调整的结点的序号
template <typename T>
void heap_adjust(T*a, int size, int e)
{
	int l_ch = 2*e, r_ch = 2*e + 1;
	while(r_ch < size) //左右子结点都存在
	{
		if(a[e] <= a[l_ch] && a[e] <= a[r_ch]) return;
		if(a[l_ch] < a[r_ch])	//左子结点最小；
		{
			a[e] <-> a[l_ch];
			e = l_ch; 
		}else{
			a[e] <-> a[r_ch];
			e = r_ch;
		}
		l_ch = 2*e;
		r_ch = 2*e + 1;
	}

	if(l_ch < size && a[l_ch] < a[e]) //待调整结点只有左子结点，并且比该结点小；
		a[e] <-> a[l_ch];
	
	return;
}