#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	int num;
};
vector<node> v, tv;
int p[100];
int l = 54;
void change()
{
	tv = v;
	int tid;
	for(int i=1; i<=l; i++){
		tid = p[i];
		tv[tid] = v[i];
	}
	v = tv;
}
int main()
{
	node t;
	char kg;
	int k, g;
	v.push_back(t);
	for(int i=1; i<=13; i++){
		t.c = 'S';
		t.num = i;
		v.push_back(t);
	}
	for(int i=1; i<=13; i++){
		t.c = 'H';
		t.num = i;
		v.push_back(t);
	}
	for(int i=1; i<=13; i++){
		t.c = 'C';
		t.num = i;
		v.push_back(t);
	}
	for(int i=1; i<=13; i++){
		t.c = 'D';
		t.num = i;
		v.push_back(t);
	}
	t.c = 'J'; t.num = 1; v.push_back(t);
	t.c = 'J'; t.num = 2; v.push_back(t);
	
	scanf("%d", &k);
	for(int i=1; i<=54; i++){
		scanf("%d", &g);
		p[i] = g;
	}
	
	for(int i=0; i<k; i++){
		change();
	}
	for(int i=1; i<v.size(); i++){
		if(i!=1) printf(" ");
		t = v[i];
		printf("%c%d", t.c, t.num);
	}
	return 0;
}
