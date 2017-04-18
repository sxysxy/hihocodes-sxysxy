#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
const int MAXN = 1e5+10;
const int MOD = 1e9+7;
int arr[MAXN], presum[MAXN];
int f[MAXN];
map<int, int> g;
int main(){
  int n; 
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)scanf("%d", arr+i), presum[i] = arr[i]+presum[i-1];
  f[0] = 1;
  int fsum = 1;
  g[0] = 1;
  for(int i = 1; i <= n; i++){
    f[i] = (fsum-g[presum[i]]+MOD)%MOD;
    if(g.count(presum[i]))g[presum[i]] = (g[presum[i]]+f[i])%MOD;
    fsum = (fsum+f[i])%MOD;
  }
  printf("%d\n", f[n]);
  return 0;
}