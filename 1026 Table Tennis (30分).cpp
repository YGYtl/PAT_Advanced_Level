#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int h, m, s;
	int p, tag;
	int start, arrive;
	bool vip;
};
struct tablenode{
	int end=8*3600, num;
	bool vip;
};
vector<node> v;
bool cmp1(node a, node b){
	return a.arrive < b.arrive;
}
bool cmp2(node a, node b){
	return a.start < b.start;
}
vector<tablenode> table;
void alloctable(int personid, int tableid){
	if(v[personid].arrive<=table[tableid].end){
		v[personid].start = table[tableid].end;
	}
	else v[personid].start = v[personid].arrive;
	table[tableid].end = v[personid].start + v[personid].p;
	table[tableid].num++;
}
int findnextvip(int vipid){
	vipid++;
	while(vipid<v.size() && v[vipid].vip==false){
		vipid++;
	}
	return vipid;
}
int main()
{
	int k, m, g;
	scanf("%d", &n);
	node t;
	int lower=8*3600, higher=21*3600;
	for(int i=0; i<n; i++){
		scanf("%d:%d:%d %d %d", &t.h, &t.m, &t.s, &t.p, &t.tag);
		t.arrive = t.h*3600+t.m*60+t.s;
		t.start = 21*3600;
		if(t.arrive>=higher) continue;
		if(t.p>120) t.p = 7200;
		else t.p = t.p*60;
		if(t.tag==1) t.vip = true;
		else t.vip = false;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp1);
	scanf("%d %d", &k, &m);//tables, vip_tables
	table.resize(k+1);
	for(int i=0; i<m; i++){
		scanf("%d", &g);//vip_tables_id
		table[g].vip = true;
	}
	int i=0, vipid = -1;//��ǰ�û���vip�û� 
	vipid = findnextvip(vipid);
	while(i<v.size()){
		int index=-1, minendtime = 0x3f3f3f3f;
		for(int j=1; j<=k; j++){//�ҵ��ĳ����Ĵ��� 
			if(table[j].end<minendtime){
				minendtime = table[j].end;
				index = j;
			}
		}
		if(table[index].end >= higher) break;
		if(v[i].vip==true && i<vipid){
			i++;
			continue;
		}
		if(table[index].vip==true){//vip���ڵ��û�Ҫ������ 
			if(v[i].vip==true){//vip���ڿ��Խ��룬��ʱҪ������û�Ҳ��vip�û� 
				alloctable(i,index);
				if(vipid==i)
					vipid = findnextvip(vipid);
				i++;
			}
			else{//vip���ڿ��Խ��룬����ʱҪ������û�����ͨ�û� 
				if(vipid<v.size()&&v[vipid].arrive<=table[index].end){//��һ��vip�û���Ҫ�õ�vip���� 
					alloctable(vipid,index);
					vipid = findnextvip(vipid);
				}
				else{//��һ��vip�û�����Ҫ�õ�vip���ڣ���ʱ����ͨ�û�����vip���� 
					alloctable(i,index);
					i++;
				}
			}
		}
		else{//��ͨ�������û�Ҫ������ 
			if(v[i].vip==false){
				alloctable(i,index);
				i++;
			}
			else{//����vip���ڵ��û�Ҫ�����ˣ���ǰҪ��ȥ����vip�û� 
				int vipindex=-1, minvipendtime=0x3f3f3f3f;
				for(int j=1; j<=k; j++){//�ҵ����Ҫ������vip���� 
					if(table[j].vip==true&&table[j].end<minvipendtime){
						minvipendtime = table[j].end;
						vipindex = j;
					}
				}
				if(vipindex!=-1&&v[i].arrive >= table[vipindex].end){//vip���ڿճ�����vip�û����Ƚ���vip���� 
					alloctable(i,vipindex);
					if(vipid==i)
						vipid = findnextvip(vipid);
					i++;
				}
				else{//vip����û�ճ���,vip�û�������ͨ���� 
					alloctable(i,index);
					if(vipid==i) vipid = findnextvip(vipid);
					i++;
				}
			}
		}
	}
	sort(v.begin(),v.end(),cmp2);
	for(int i=0; i<v.size()&&v[i].start<higher; i++){
		printf("%02d:%02d:%02d ", v[i].arrive/3600, v[i].arrive%3600/60, v[i].arrive%60);
		printf("%02d:%02d:%02d ", v[i].start/3600, v[i].start%3600/60, v[i].start%60);
		printf("%.0f\n", round((v[i].start-v[i].arrive)/60.0));
	}
	for(int i=1; i<=k; i++){
		if(i!=1) printf(" ");
		printf("%d", table[i].num);
	}
	return 0;
}
