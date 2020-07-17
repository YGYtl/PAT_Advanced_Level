#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n;
    scanf("%d", &n);
    for( int i=1; i<=n; i++){
        long double a, b, c;
        scanf("%Lf %Lf %Lf", &a, &b, &c);
        printf("Case #%d: ", i);
        if(a+b>c) printf("yes\n");
        else printf("false\n");
    }
    return 0 ;
}
