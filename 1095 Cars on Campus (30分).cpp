#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, m, cet[maxn];;
struct node{
	char name[10];
	int time, flag;
};
vector<node> List, new_list;
map<string,int> p;
bool cmp1(node a, node b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else return a.time < b.time;
}
bool cmp2(node a, node b){
	return a.time < b.time;
}
int main()
{
	scanf("%d %d", &n, &m);
	node t, t1, t2;
	char f[10];
	int hh, mm, ss, mx=0;
	for(int i=0; i<n; i++){
		scanf("%s %d:%d:%d %s", t.name, &hh, &mm, &ss, f);
		t.time = hh*3600 + mm*60 + ss;
		t.flag = strcmp(f,"in")==0 ? 1 : -1;
		List.push_back(t);
	}
	sort(List.begin(),List.end(),cmp1);
	for(int i=0; i<n-1; i++){
		t1 = List[i]; t2 = List[i+1];
		if(strcmp(t1.name,t2.name)==0&&t1.flag==1&&t2.flag==-1){
			new_list.push_back(t1);
			new_list.push_back(t2);
			p[t1.name] += t2.time - t1.time;
			mx = max(mx,p[t1.name]);
		}
	}
	sort(new_list.begin(),new_list.end(),cmp2);
	for(int i=0; i<new_list.size(); i++){
		if(i==0) cet[i] = new_list[i].flag;
		else cet[i] = cet[i-1]+new_list[i].flag;
	}
	int j, k=0;
	for(int i=0; i<m; i++){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		t1.time = hh*3600 + mm*60 + ss;
		for(j=k; j<new_list.size(); j++){
			t2 = new_list[j];
			if(t2.time>t1.time){
				printf("%d\n", cet[j-1]);
				break;
			}
			else if(j==new_list.size()-1){
				printf("%d\n", cet[j]);
			}
		}
		k = j;
	}
	map<string,int>::iterator it;
	for(it=p.begin(); it!=p.end(); it++){
		if(it->second==mx) printf("%s ", it->first.c_str());
	}
	hh = mx/3600; mm = (mx%3600)/60; ss = mx%60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}
