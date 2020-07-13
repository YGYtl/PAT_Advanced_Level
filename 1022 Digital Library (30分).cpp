#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id;
	string bookname, author, key_words, publisher, pyear;
};
map<string,set<int> > mp;
int main()
{
	int k;
	string str;
	scanf("%d", &n);
	node t;
	for(int i=0; i<n; i++){
		str = "";
		cin >> t.id; getchar();
		getline(cin,t.bookname);
		getline(cin,t.author);
		getline(cin,t.key_words);
		getline(cin,t.publisher);
		getline(cin,t.pyear);
		int l=0, r=0;
		string tstr=t.key_words;
		r = tstr.find(' ');
		while(r!=-1){
			str = tstr.substr(l,r);
			if(r+1<tstr.size()) tstr = tstr.substr(r+1);
			r = tstr.find(' ');
			mp[str].insert(t.id);
		}
		if(tstr.length()!=0) mp[tstr].insert(t.id);
		mp[t.bookname].insert(t.id);
		mp[t.author].insert(t.id);
		mp[t.publisher].insert(t.id);
		mp[t.pyear].insert(t.id);
	}
	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d: ", &k);
		getline(cin,str);
		cout << k << ": " << str << endl;
		if(mp.find(str)==mp.end()){
			cout << "Not Found" << endl;
		}
		else{
			set<int>::iterator it;
			for(it=mp[str].begin(); it!=mp[str].end(); it++) printf("%07d\n", *it);
		}
	}
	return 0;
}
