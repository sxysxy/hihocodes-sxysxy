#include <cstdio>
#include <algorithm>
using namespace std;
int f[200004];
int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        int v, w; scanf("%d %d", &v, &w);
        for(int j = m; j >= v; j--)
            f[j] = max(f[j], f[j-v]+w);
    }
    printf("%d\n", f[m]);
    return 0;
}