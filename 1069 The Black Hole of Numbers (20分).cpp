#include<bits/stdc++.h>
using namespace std;
int main()
{
	int val1, val2;
	int n;
	scanf("%d", &n);
	char s[10];
	while(n){
		sprintf(s, "%04d", n);// ���͸�ʽ������� s
		sort(s,s+4);
		sscanf(s, "%d", &val2);//���ַ�����ȡ��ʽ������ s -> val2
		reverse(s,s+4);
		sscanf(s, "%d", &val1);//s ->val1
		int g = val1 - val2;
		printf("%04d - %04d = %04d\n", val1, val2, g);
		if(g==0 || g==6174) break;
		n = g;
	}
	return 0;
}
