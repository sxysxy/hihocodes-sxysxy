#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <cctype>
using namespace std;
#define MAXN 1005
struct dinic{
  bool vis[MAXN];
  int dist[MAXN];
  struct edge{
    int from, to, rem;
  };vector<edge> edges;
  vector<int> G[MAXN];
  int source, sink;
public:
  dinic(int s, int t){source = s, sink = t;}
  void addedge(int u, int v, int c){
    edges.push_back((edge){u, v, c});
    edges.push_back((edge){v, u, 0});
    G[u].push_back(edges.size()-2);
    G[v].push_back(edges.size()-1);
  }
  bool bfs(){
    queue<int> q;
    memset(vis, false, sizeof(vis));
    vis[source] = true;
    dist[source] = 0;
    q.push(source);
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int i = 0; i < G[u].size(); i++){
        edge &e = edges[G[u][i]];
        if(!vis[e.to] && e.rem > 0){
          q.push(e.to);
          dist[e.to] = dist[u]+1, vis[e.to] = true;
        }
      } 
    }
    return vis[sink];
  }
  int dfs(int u, int f){
    if(u == sink || f == 0)return f;
    int cnt = 0;
    for(int i = 0; i < G[u].size(); i++){
      edge &e = edges[G[u][i]];
      int next;
      if(dist[e.to] == dist[u]+1 && (next = dfs(e.to, min(f, e.rem))) > 0){
        f-=next, cnt+=next, e.rem-=next, edges[G[u][i]^1].rem+=next;if(!f)break;
      }
    }
    return cnt;
  }
  int maxf(){
    int f = 0;
    while(bfs())f += dfs(source, 0x7fffffff);
    return f;
  }
};
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  dinic solver(0, 2*n+1);
  while(m--){
    int u, v;scanf("%d %d", &u, &v);
    solver.addedge(u, n+v, 1);
  }
  for(int i = 1; i <= n; i++)solver.addedge(0, i, 1), solver.addedge(i+n, 2*n+1, 1);
  printf("%d\n", n-solver.maxf());
  return 0;
}