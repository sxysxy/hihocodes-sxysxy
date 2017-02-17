#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define MAXN 20005
int fa[MAXN], cd[MAXN];
int dfn[MAXN], low[MAXN];
int in[MAXN];
int tim;
vector<int> G[MAXN];
vector<int> cutv;
struct edge{int u, v;};
bool cmp(edge a, edge b){
  return a.u==b.u?a.v<b.v:a.u<b.u;
}
vector<edge>cute;
void tarjan(int u){
  dfn[u] = low[u] = ++tim;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if(!dfn[v]){
      fa[v] = u;
      cd[u]++;
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if(!fa[u] && cd[u] >= 2)
        cutv.push_back(u);
      if(fa[u] && low[v] >= dfn[u])
        cutv.push_back(u);
      if(low[v] > dfn[u])
        cute.push_back((edge){min(u, v), max(u, v)});
    }else if(v != fa[u]){
      low[u] = min(low[u], dfn[v]);
    }
  }
}
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--){
    int u, v;scanf("%d %d", &u, &v);
    G[u].push_back(v); G[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)if(!dfn[i])tarjan(i);
  if(cutv.size() == 0)
    puts("Null");
  else{
    sort(cutv.begin(), cutv.end());
    int p = unique(cutv.begin(), cutv.end()) - cutv.begin();
    for(int i = 0; i < p; i++)printf((i==p-1)?"%d\n":"%d ", cutv[i]);
  }
  if(cute.size())
  {
    sort(cute.begin(), cute.end(), cmp);
    for(int i = 0; i < cute.size(); i++)printf("%d %d\n", cute[i].u, cute[i].v);
  }
  return 0;
}