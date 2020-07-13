#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	string class_name;
	int grade;
};
bool cmp1(node a, node b){
	return a.grade > b.grade;
}
bool cmp2(node a, node b){
	return a.grade < b.grade;
}
vector<node> v1, v2;
int main()
{
	char sex;
	node t;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> t.name >> sex >> t.class_name >> t.grade;
		if(sex=='F'){
			v1.push_back(t);
		}
		else{
			v2.push_back(t);
		}
	}
	sort(v1.begin(),v1.end(),cmp1);
	sort(v2.begin(),v2.end(),cmp2);
	bool flag = true;
	if(v1.size()==0){
		flag = false;
		printf("Absent\n");
	}
	else{
		cout << v1[0].name << " " << v1[0].class_name << endl;
	}
	if(v2.size()==0){
		flag = false;
		printf("Absent\n");
	}
	else{
		cout << v2[0].name << " " << v2[0].class_name << endl;
	}
	if(!flag) printf("NA\n");
	else{
		cout << v1[0].grade - v2[0].grade << endl; 
	}
	return 0;
}
