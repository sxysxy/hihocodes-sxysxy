#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>
using namespace std;
int d[1002][1002];
int main(){
    int n, m; scanf("%d %d", &n, &m);
    memset(d, 0x2f, sizeof(d));
    while(m--){
        int x, y, v; scanf("%d %d %d", &x, &y, &v);
        d[y][x] = d[x][y] = min(d[x][y], v);
    }
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            printf(j==n?"%d\n":"%d ", i==j?0:d[i][j]);
    return 0;
}