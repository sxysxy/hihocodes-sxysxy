#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <deque>
using namespace std;
const int MAXN = 1e5+10;
vector<int> G[MAXN];
int n, div_size;
int size[MAXN], wei[MAXN];
bool vis[MAXN];
int root;
void get_root(int u, int f){
  size[u] = 1; int son = 0;
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(f != to && !vis[to]){
      get_root(to, u);
      size[u] += size[to];
      if(size[son] < size[to])son = to;
    }
  }
  wei[u] = max(size[son], div_size-size[son]);
  if(!root || wei[root] > wei[u])root = u;
}
int deep[MAXN], deep_cnt;
void dfs(int u, int f, int d){
  deep[++deep_cnt] = d;
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(to != f && !vis[to]){
      dfs(to, u, d+1);
    }
  }
}
int ans;
void calc(int u){
  vis[u] = true;
  int max1 = 0, max2 = 0;
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(vis[to])continue;
    deep_cnt = 0;
    dfs(to, u, 1);
    sort(deep+1, deep+1+deep_cnt);
    if(deep[deep_cnt] > max1){
      max2 = max1;
      max1 = deep[deep_cnt];
    }else if(deep[deep_cnt] > max2)
      max2 = deep[deep_cnt];
  }
  ans = max(ans, max1+max2);
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(vis[to])continue;
    div_size = size[to];
    root = 0;
    get_root(to, 0);
    calc(root);
  }
}
int main(){
  int n; scanf("%d", &n);
  for(int i = 1; i < n; i++){
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v); G[v].push_back(u);
  }
  div_size = n;
  get_root(1, 0);
  calc(root);
  printf("%d\n", ans);
  return 0;
}