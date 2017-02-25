//TLE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int f[2][100001];
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    int nd, va; scanf("%d %d", &nd, &va);
    int cur = i&1;
    for(int j = 0; j <= m; j++){
      int t = 0;
      for(int k = 0; k*nd <= m; k++){
        if(j < k*nd)f[cur][j] = f[cur^1][j];
        else t = max(t, f[cur^1][j-k*nd]+k*va);
      }
      f[cur][j] = max(f[cur^1][j], t);
    }
  }
  printf("%d\n", f[n&1][m]);
  return 0;
}