#include<bits/stdc++.h>
using namespace std;
vector<int> a, b;
int n, g;
int judge(){
	int t;
	t = b[0];
	for(int i=1; i<n; i++){
		if(b[i]>=t){
			g = i;
			t = b[i];
		}
		else break;
	}
	for(int i=g+1; i<n; i++){
		if(a[i]!=b[i]) return 1;//Merge
	}
	return 2;//Insert
}

void solve1(){
	printf("Merge Sort\n");
	bool f = true;
	int t = 1;
	while(f){
		f = false;
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]){
				f = true;
				break;
			}
		}
		t*=2;
		for(int i=0; i<n; i+=t){
			if(i+t<n) sort(a.begin()+i,a.begin()+i+t);
			else sort(a.begin()+i,a.begin()+n);
		}
	}
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", a[i]);
	}
}

void solve2(){
	printf("Insertion Sort\n");
	sort(b.begin(),b.begin()+g+2);
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", b[i]);
	}
}

int main()
{
	int k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		a.push_back(k);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		b.push_back(k);
	}
	g = 0;
	int flag = judge();
	if(flag==2) solve2();
	else solve1();
	return 0;
}
