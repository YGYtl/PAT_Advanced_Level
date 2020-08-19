#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {
    int temp = 0;
    for(int i = 1; temp <= n; i++) {
        v.push_back(temp);
        temp = pow(i, p);
    }
}
void dfs(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
                ans = tempAns;
                maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init(); 
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}
