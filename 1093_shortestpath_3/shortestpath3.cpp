#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> G[100002];
vector<int> D[100002];
int vis[100002];
int dist[100002];
int main(){
    int n, m, s, t;scanf("%d %d %d %d", &n, &m, &s, &t);
    while(m--){
      int u, v, c;scanf("%d %d %d", &u, &v, &c);
      G[u].push_back(v);G[v].push_back(u);D[u].push_back(c);D[v].push_back(c);
    }
    queue<int> q;
    q.push(s);
    vis[s] = true;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i], c = D[u][i];
        if(dist[v] > dist[u]+c){
          dist[v] = dist[u]+c;
          if(!vis[v])q.push(v);
        }
      }
      vis[u] = false;
    }
    printf("%d\n", dist[t]);
    return 0;
}