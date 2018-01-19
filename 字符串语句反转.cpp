//字符串语句翻转；

void ReverseSentence(char* sen)  //接口；


/******代码更清晰版本********/
void ReverseWord(char* pBegin, char* pEnd) {
	if (pBegin == NULL || pEnd == NULL) {
		return;
	}
	
	pEnd--;	
	while(pBegin < pEnd) {
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		
		pBegin++;
		pEnd--;
	}
}

void ReverseSentence(char* sen) {
	if(sen == NULL) 
		return;
	
	char* pStart = sen;
	char* pEnd = pStart + strlen(pStart);
	ReverseWord(pStart, pEnd);
	
	pEnd = sen;
	//这个if-else逻辑写的非常好。
	while(*pStart != '\0') {
		if(*pEnd == ' ' || *pEnd == '\0') {
			ReverseWord(pStart, pEnd);
			pStart = pEnd;
		} else if(*pStart == ' ') {	//遇到空格的情况，可以处理连续多个空格；
			pStart++;
			pEnd = pStart;
		} else {
			pEnd++;
		}
	}
}

/******更高效的版本******/
void ReverseSentence(char* sen) {
	if (sen == NULL)
		return;
	
	char* p = sen;
	for(int i = 0; i < len/2; i++) {
		p[i] <-> p[len-1 - i];
	}
	
	int pre = 0;
	for(int i = 0; i <= len; i++) {
		if(p[i] == ' ' || i == len) {
			int leng = i - pre;
			char* q = p + pre;
			for(int j = 0; j < leng/2; j++) {
				q[j] <-> q[leng-1 - j];
			}
			pre = i;
		}
	}
}


