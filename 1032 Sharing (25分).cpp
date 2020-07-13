#include<bits/stdc++.h>
using namespace std;
//找到开始相同的位置 
struct node{
	int st, end;
	char num;
};
vector<node> l(200005), l1, l2, l3(200005);
int main()
{
	int h1, h2;
	int n;
	node t;
	scanf("%d %d %d", &h1, &h2, &n);
	for(int i=0; i<n; i++){
		scanf("%d %c %d", &t.st, &t.num, &t.end);
		l[t.st] = t;
	}
	int t1=h1, t2=h2;
	string s1="", s2="";
	while(t1!=-1){
		t = l[t1];
		s1 += t.num;
		l1.push_back(t);
		t1 = t.end;
	}
	while(t2!=-1){
		t = l[t2];
		s2 += t.num;
		l2.push_back(t);
		t2 = t.end;
	}
	bool flag = false;
	int len1=s1.size()-1, len2=s2.size()-1;
	while(len1>=0&&len2>=0){
		if(l1[len1].st==l2[len2].st&&l1[len1].num==l2[len2].num&&l1[len1].end==l2[len2].end){
			len1--;
			len2--;
			flag = true;
		}
		else break;
	}
	if(flag){
		printf("%05d\n", l1[len1+1].st);
	}
	else printf("-1\n");
	return 0;
}
