#include<bits/stdc++.h>
using namespace std;
//sscanf（a, “%d”, &b） 从字符串数组a中读取b
//sprintf（a, “%d”, b）将b输出到字符数组a
bool judge(string s)
{
	int f1=0, f2=0, f3=0, f4=0;//-,.,qt 
	for(int i=0; i<s.length(); i++){
		if(s[i]=='-') f1++;
		else if(s[i]=='.') f2++;
		else if(s[i]<'0'||s[i]>'9') f3++;
		else if(f2) f4++;
	}
	if(f1>1||f2>1||f3>0||(f1==1&&s[0]!='-')||f4>2) return false;
	return true;
}
double getnum(string s){
	int i = 0, k = 1, f = 0;
	double ans = 0, kk = 1;
	if(s[0]=='-'){
		i++; k = -1;
	}
	for(; i<s.length(); i++){
		if(s[i]=='.') f = 1;
		else{
			ans = ans*10 + s[i]-'0';
			if(f) kk*=0.1;
		}
	}
	if(kk<0.01) return 1001;
	return ans*k*kk;
}
int main()
{
	int n, c=0;
	double ans = 0;
	string s;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> s;
		if(judge(s)&&s.length()<=8){
			double tg = getnum(s);
			if(tg<-1000||tg>1000){
				cout << "ERROR: " << s << " is not a legal number" << endl;
			}
			else{
				c++;
				ans += tg;
			}
		}
		else{
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
	}
	if(c==0) printf("The average of 0 numbers is Undefined\n");
	else if(c==1) printf("The average of %d number is %.2f\n", c, ans);
	else printf("The average of %d numbers is %.2f\n", c, ans/c);
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
char a[1000], b[1000];
int main()
{
	int n;
	cin >> n;
	double d = 0, sum = 0;
	int cnt = 0;
	while (n--){
		scanf("%s", a);
		sscanf(a, "%lf", &d);
		sprintf(b, "%.2lf", d);
		
		int l = strlen(a);
		int flag = 0;
		for (int i = 0; i<l; i++) {
			if (a[i] != b[i]) {
				flag = 1;
				break;
			}
		}
		
		if (flag || d > 1000 || d < -1000) {
			printf("ERROR: %s is not a legal number\n", a);
		} else {
			sum += d;
			cnt++;
		}
	
	if (cnt == 0) printf("The average of 0 numbers is Undefined");
	else if(cnt == 1) printf("The average of %d number is %.2lf", cnt, sum/cnt);
	else printf("The average of %d numbers is %.2lf", cnt, sum/cnt);
	
	
	return 0;
}
*/
