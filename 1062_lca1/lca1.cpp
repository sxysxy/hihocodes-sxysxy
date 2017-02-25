#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

/* //啧。。写了个树剖不想说啥
map<string, int> table;
map<int, string> untable;
vector<int> G[202];
int size[202], parent[202], son[202], deep[202], col[202];
void dfs(int u, int f, int d, int c){
  size[u] = 1;
  parent[u] = f;
  deep[u] = d;
  col[u] = c;
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u].size(); if(to == f)continue;
    dfs(to, u, d+1, c);
    size[u] += size[to];
    if(size[son[u]] < size[to])son[u] = to;
  }
}
int top[202];
void dfs(int u, int t){
  top[u] = t;
  if(son[u])dfs(son[u], t);
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(to == parent[u] || to == son[u])continue;
    dfs(to, to);
  }
}
int lca(int u, int v){
  int t1 = top[u], t2 = top[v];
  while(t1 != t2){
    if(deep[t1] < deep[t2]){
      swap(t1, t2);
      swap(u, v);
    }
    u = parent[t1];
    t1 = top[u];
  }
  return deep[u] < deep[v]?u:v;
}
int indeg[202];
int cnt = 0;
void addedge(string &a, string &b){
  if(!table[a]){
    table[a] = ++cnt;
    untable[cnt] = string(a);
  }
  if(!table[b]){
    table[b] = ++cnt;
    untable[cnt] = string(b);
  }
  int u = table[a];
  int v = table[b];
  G[u].push_back(v);
  indeg[v]++;
}
int main(){
  //ios::sync_with_stdio(false);
  freopen("test_data.txt", "r", stdin);
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    string f, s; cin >> f >> s;
    addedge(f, s);
  }
  int c = 0;
  for(int i = 1; i <= cnt; i++){
    if(!indeg[i]){
      dfs(i, i, 0, ++c);
      dfs(i, i);
    }
  }
  int q; cin >> q;
  while(q--){
    string u, v;
    cin >> u >> v;
    int x = table[u], y = table[v];
    if(col[x] != col[y])cout << -1 << '\n';
    else cout << untable[lca(x, y)] << '\n';
  }
  cout << endl;
  return 0;
}
*/