#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
using namespace std;
int d[255][255];
int vis[255];
int dist[255];
int main(){
    int n, m, s, t; scanf("%d %d %d %d", &n, &m, &s, &t);
    while(m--){
        int x, y, v; scanf("%d %d %d", &x, &y, &v);
        d[y][x] = d[x][y] = min(d[x][y]?d[x][y]:0x3f3f3f3f, v);
    }
    queue<int> q;
    q.push(s);
    vis[s] = true;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int v = 1; v <= n; v++)if(d[u][v]){
        if(dist[v] > dist[u]+d[u][v]){
          dist[v] = dist[u]+d[u][v];
          if(!vis[v])q.push(v);
        }
      }
      vis[u] = false;
    }
    printf("%d\n", dist[t]);
    return 0;
}