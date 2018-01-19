/*冒泡排序*/

void BubbleSort(int *list, int n) {
	if(list == NULL) return;
	
	int i, j, tmp;
	
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-1-i; j++) {
			if(list[j] > list[j+1]) {
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
	}
}
