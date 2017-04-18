#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
using namespace std;
const int MAXN = 1e2+3;
int N, M;
int V[MAXN];
int size[MAXN];
int f[MAXN][MAXN];
vector<int> G[MAXN];
void dfs(int u, int fa){
  f[u][1] = V[u];
  size[u] = 1;
  for(int i = 0; i < G[u].size(); i++){
    int to = G[u][i]; if(to == fa)continue;
    dfs(to, u);
    size[u] += size[to];
    for(int j = min(size[u], M); ~j; j--){
      for(int k = 0; k <= size[to] && k < j; k++){
        f[u][j] = max(f[u][j], f[u][j-k]+f[to][k]);
      }
    }
  }
}
int main(){
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++)scanf("%d", V+i);
  for(int i = 1, x, y; i < N; i++){
    scanf("%d %d", &x, &y);
    G[x].push_back(y); G[y].push_back(x);
  }
  dfs(1, 0);
  printf("%d\n", f[1][M]);
  return 0;
}
