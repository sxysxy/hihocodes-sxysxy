#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 1000003
int f[MAXN][25];
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &f[i][0]);
    for(int k = 1; (1<<k) <= n; k++)
        for(int i = 1; i+(1<<k)-1 <= n; i++)
            f[i][k] = min(f[i][k-1], f[i+(1<<(k-1))][k-1]);
    int q; scanf("%d", &q);
    while(q--){
        int l, r; scanf("%d %d", &l, &r);
        int s = 0; while(1<<s <= r-l+1)s++; s--; 
        printf("%d\n", min(f[l][s], f[r-(1<<s)+1][s]));
    }
    return 0;
}