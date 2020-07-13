#include<bits/stdc++.h>
using namespace std;
struct node{
	string name, pwd;
};
node ans;
bool judge(string name, string password){
	ans.name = name;
	bool flag = true;
	for(int i=0; i<password.length(); i++){
		if(password[i]=='l'){
			password[i] = 'L';
			flag = false;
		}
		else if(password[i]=='0'){
			password[i] = '%';
			flag = false;
		}
		else if(password[i]=='1'){
			password[i] = '@';
			flag = false;
		}
		else if(password[i]=='O'){
			password[i] = 'o';
			flag = false;
		}
	}
	ans.pwd = password;
	return flag;
}
vector<node> v;
int main()
{
	int n, count=0;
	scanf("%d", &n);
	string name, pwd;
	for(int i=0; i<n; i++){
		cin >> name >> pwd;
		if(judge(name,pwd)){
			count++;
		}
		else{
			v.push_back(ans);
		}
	}
	if(count==n&&n>1) printf("There are %d accounts and no account is modified\n", count);
	else if(count==n&&count==1) printf("There is 1 account and no account is modified\n");
	else{
		printf("%d\n", v.size());
		for(int i=0; i<v.size(); i++){
			cout << v[i].name << " " << v[i].pwd << endl;
		}
	}
	return 0;
}
