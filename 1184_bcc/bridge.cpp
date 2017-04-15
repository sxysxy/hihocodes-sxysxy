#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <functional>
using namespace std;
const int MAXN = 2e4+10;
int fa[MAXN], cd[MAXN], dfn[MAXN], low[MAXN];
struct edge{
  int u, v;
  bool ok;
  bool operator<(const edge &e)const{
    return u==e.u?v<e.v:u<e.u;
  }
  bool operator==(const edge &e)const{
    return u==e.u&&v==e.v;
  }
};
vector<edge> edges;
vector<int> G[MAXN];
void addedge(int u, int v){
  edges.push_back((edge){u, v, true});
  edges.push_back((edge){v, u, true});
  int k = edges.size();
  G[u].push_back(k-2); G[v].push_back(k-1);
}
int dfn_tim;
void tarjan(int u){
  dfn[u] = low[u] = ++dfn_tim;
  for(int i = 0; i < G[u].size(); i++){
    edge &e = edges[G[u][i]];
    int v = e.v;
    if(!dfn[v]){
      fa[v] = u;
      cd[u]++;
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if(low[v] > dfn[u]){
        e.ok = false;
        edges[G[u][i]^1].ok = false;
      }
    }else if(v != fa[u])
      low[u] = min(low[u], dfn[v]);
  }
}
int col[MAXN], meta[MAXN];
void dfs(int u, int c){
  col[u] = c;
  if(!meta[c] || meta[c] > u)meta[c] = u;
  for(int i = 0; i < G[u].size(); i++){
    edge &e = edges[G[u][i]];
    if(e.ok && !col[e.v])dfs(e.v, c);
  }
}
int main(){
  //freopen("test_data.txt", "r", stdin);
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int u, v; scanf("%d %d", &u, &v);
    addedge(u, v);
  }
  for(int i = 1; i <= n; i++)if(!dfn[i])tarjan(i);
  int c = 0;
  for(int i = 1; i <= n; i++)if(!col[i])dfs(i, ++c);
  printf("%d\n", c);
  for(int i = 1; i <= n; i++)printf("%d ", meta[col[i]]);
  return 0;
}