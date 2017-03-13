#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <vector>
using namespace std;
#define MAXN 20003
const int x = 457;
typedef unsigned long long ULL;
ULL xp[MAXN], ha[MAXN], hv[MAXN];
int a[MAXN];
int n, k;
bool check(int m){
  for(int i = 0; i <= n-m; i++)
    hv[i] = ha[i]-ha[i+m]*xp[m];
  sort(hv, hv+n-m+1);
  int cnt, maxc = 0;
  for(int i = 0; i <= n-m; i++){
    if(!i || hv[i] != hv[i-1])cnt = 0;
    maxc = max(maxc, ++cnt);
  }
  return maxc >= k;
}
int main(){
  scanf("%d %d", &n, &k);
  xp[0] = 1;
  for(int i = 1; i <= n; i++)xp[i] = x*xp[i-1];
  for(int i = 0; i < n; i++)scanf("%d", a+i);
  for(int i = n-1; ~i; i--)ha[i] = ha[i+1]*x+a[i];
  int l = 0, r = n;
  int ans = 0;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m))ans = m, l = m+1;
    else r = m-1;
  }
  printf("%d\n", ans);
  return 0;
}
