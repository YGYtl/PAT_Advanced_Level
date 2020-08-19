#include<bits/stdc++.h>
using namespace std;
int p, m, n, cnt;
struct node{
	string name;
	int p, mid, final, g;
	node(){
		p = mid = final = g = -1;
	}
};
map<string,node> student;
set<string> st;
vector<node> v;
bool cmp(node a, node b){
	if(a.g!=b.g) return a.g > b.g;
	else return a.name < b.name;
}
int main()
{
	string str;
	double score; cnt = 0;
	node t;
	scanf("%d %d %d", &p, &m, &n);
	for(int i=0; i<p; i++){
		cin >> str >> score;
		if(score<200||score>900) continue;
		st.insert(str);
		student[str].name = str;
		student[str].p = score;
	}
	for(int i=0; i<m; i++){
		cin >> str >> score;
		st.insert(str);
		student[str].name = str;
		student[str].mid = score;
	}
	for(int i=0; i<n; i++){
		cin >> str >> score;
		st.insert(str);
		student[str].name = str;
		student[str].final = score;
		if(student[str].mid<student[str].final) student[str].g = int(student[str].final);
		else student[str].g = int(student[str].mid*0.4 + student[str].final*0.6 + 0.5);
	}
	set<string>::iterator it;
	for(it=st.begin(); it!=st.end(); it++){
		t = student[*it];
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(t.p<200||t.g<60||t.g>100) continue;
		cout << t.name << " " << t.p << " " << t.mid << " " << t.final << " " << t.g << endl;
	} 
	return 0;
}
