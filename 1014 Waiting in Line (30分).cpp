#include<bits/stdc++.h>
using namespace std;
int n, m, k, Q;
struct people{
	int nowtime;//���� 
	int dtime;//���� 
	int endtime;//���Ĵ���ʱ�� 
	int id;
};
deque<people> q[2100];
vector<people> v;
int main()
{
	int kk, qq;
	people t, t1, t2;
	int c = 8*60, cl = 8*60, cr=17*60;
	scanf("%d %d %d %d", &n, &m, &k, &Q);
	if(m==0) m = 1;
	for(int i=0; i<k; i++){
		scanf("%d", &t.dtime);//����ʱ�� 
		t.nowtime = cl;
		t.endtime = 1;
		t.id = i;
		v.push_back(t);
	}
	int o=0;
	for(int i=0; i<m&&o<k; i++){//�� 
		for(int j=0; j<n&&o<k; j++){//�� 
			if(i==0){
				t = v[o];
				t.endtime = t.nowtime+t.dtime;
				v[t.id] = t;
				q[j].push_back(t);
			}
			else{
				t = q[j].back();
				t1 = v[o];
				t1.endtime = t.endtime+t1.dtime;
				v[t1.id] = t1;
				q[j].push_back(t1);
			}
			o++;
		}
	}
	bool flag = true;
	while(o<k&&c<cr&&flag){//c�ǵ�ǰʱ�� 
		for(int i=0; i<n&&o<k&&flag; i++){
			if(q[i].empty()) continue;
			t = q[i].front();//�ѵ�һ���ó�������
			if(t.endtime==c&&q[i].size()<=m){//���Գ����Ļ� 
				q[i].pop_front();
				t = q[i].back();
				t1 = v[o++];
				if(t.endtime>=cr){
					t1.endtime=1;
					v[t1.id] = t1;
					q[i].push_back(t1);
					flag = false;
					break;
				}
				else t1.endtime = t.endtime + t1.dtime;
				v[t1.id] = t1;
				q[i].push_back(t1);
			}
		}
		c++;
	}
	for(int i=0; i<Q; i++){
		scanf("%d", &qq);
		if(v[qq-1].endtime!=1) printf("%02d:%02d\n", v[qq-1].endtime/60, v[qq-1].endtime%60);
		else printf("Sorry\n");
	}
	return 0;
}
