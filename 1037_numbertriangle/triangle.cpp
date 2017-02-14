#include <cstdio>
int t[111][111];
int f[111][111];
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &t[i][j]);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            ans = max(ans, f[i][j] = max(f[i-1][j], f[i-1][j-1])+t[i][j]);
    printf("%d", ans);
    return 0;
}