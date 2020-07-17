#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

int n,d,s[MAX],tree[MAX + 1],c;
char ope[11];
int lowbit(int t) {
    return t&-t;
}
void update(int x,int y) {
    while(x <= MAX) {
        tree[x] += y;
        x += lowbit(x);
    }
}
int getsum(int x) {
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
void printM() {
    int m = (c % 2 ? c / 2 + 1 : c / 2);///中间个数应该是第几个数
    int l = 0,r = MAX,mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(getsum(mid) < m)l = mid + 1;
        else r = mid;
    }
    printf("%d\n",l);
}
int main() {
    scanf("%d",&n);
    while(n --) {
        scanf("%s",ope);
        if(ope[1] == 'u') {
            scanf("%d",&d);
            update(s[c ++] = d,1);
        }
        else if(ope[1] == 'o') {
            if(!c) {
                printf("Invalid\n");
            }
            else {
                update(s[-- c],-1);
                printf("%d\n",s[c]);
            }
        }
        else {
            if(!c) {
                printf("Invalid\n");
            }
            else {
                printM();
            }
        }
    }
}
