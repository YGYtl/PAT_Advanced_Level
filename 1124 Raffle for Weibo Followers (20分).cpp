#include<bits/stdc++.h>
using namespace std;
int m, n, s;
vector<string> v;
map<string,bool> vis;
int main()
{
	string str, t;
	int c = 0, flag = 0;
	scanf("%d %d %d", &m, &n, &s);
	v.push_back(" ");
	for(int i=0; i<m; i++){
		cin >> str;
		v.push_back(str);
	}
	for(int i=s; i<v.size(); i++){
		str = v[i];
		c++;
		if(i==s){
			cout << str << endl;
			vis[str] = true;
			c = 0; flag = 1;
			continue;
		}
		if(c%n==0){
			t = str;
			while(vis[t]){
				i++;
				t = v[i];
			}
			if(vis[t]==false){
				cout << t << endl;
				vis[t] = true;
				flag = 1;
			}
			c = 0;
		}
	}
	if(flag == 0) printf("Keep going...");
	return 0;
}
