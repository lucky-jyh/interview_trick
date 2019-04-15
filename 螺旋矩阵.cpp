//输出螺旋矩阵

/*****
           21 22................
           20  7  8  9  10
           19  6  1  2  11
           18  5  4  3  12
           17  16 15 14 13

*/
//可以看到从1开始的方向变化始终是 right->down->left->up，
//所持续走的长度为1->1->2->2->3->3->4->4->...，发现了这个规律不难写出代码了！

void LuoxuanMatrix(int n) {
	int x, y;
	x = y = (n - 1)/2;
	data[x][y] = 1;
	
	//每次持续走的步长；
	int len = 1;
	int count = 0;
	
	int num = 2;
	DIRECTION dir = RIGHT;
	
	while(num <= n * n) {
		
		for(int i = 0; i < len; i++) {
			switch(dir) {
				case LEFT:
					--x; break;
				case RIGHT:
					++x; break;
				case UP:
					++y; break;
				case DOWN:
					--y; break;
			}
			data[x][y] = num++;
		}
		
		count++;
		if(count == 2) {
			count = 0;
			len++;
		}
		
		dir = (dir + 1) % 4;
	}
}

//2.输入任一坐标（x, y），输出对应数字。
/*****
我们可以把它看成是一层一层往外扩展的，第0层为一个1，第一层为2到9.。。。
第t层共有(2t-1)*(2t-1)个数，第t+1层会从(2t-1)*(2t-1)+1开始往外螺旋，
给定坐标（x,y)就知道该点存在的层数 t=max(|x|,|y|)。
******/

int foo(int x, int y) {
	int t = max(abs(x), abs(y));
	
	int v = (2*t - 1)*(2*t - 1) + 2*t;
	
	if(x == -t) {
		v += 3*t - y;
	} else if(y == -t) {
		v += 5*t + x;
	} else if(y == t) {
		v += t - x;
	} else
		v += y - t;
	
	return v;
}


