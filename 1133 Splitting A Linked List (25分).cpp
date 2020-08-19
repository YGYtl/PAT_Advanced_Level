#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
	int head, num, next;
}l1[maxn];
vector<node> l2, l3, l4, l5, l;
int main()
{
	int h, n, k;
	node t;
	scanf("%d %d %d", &h, &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &t.head, &t.num, &t.next);
		l1[t.head] = t;
	}
	while(h!=-1){
		t = l1[h];
		l2.push_back(t);
		h = t.next;
	}
	for(int i=0; i<l2.size(); i++){
		if(l2[i].num<=k){
			if(l2[i].num<0) l3.push_back(l2[i]);
			else l4.push_back(l2[i]);
		}
		else l5.push_back(l2[i]);
	}
	for(int i=0; i<l3.size(); i++) l.push_back(l3[i]);
	for(int i=0; i<l4.size(); i++) l.push_back(l4[i]);
	for(int i=0; i<l5.size(); i++) l.push_back(l5[i]);
	for(int i=0; i<l.size()-1; i++){
		printf("%05d %d %05d\n", l[i].head, l[i].num, l[i+1].head);
	}
	printf("%05d %d -1\n", l[l.size()-1].head, l[l.size()-1].num);
	return 0;
}
