#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
const int MAXN = 1e5+10;
const int MOD = 1e9+7;
int arr[MAXN], presum[MAXN];
int f[MAXN];
int main(){
  int n; 
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)scanf("%d", arr+i), presum[i] = arr[i]+presum[i-1];
  f[0] = 1;
  for(int i = 1; i <= n; i++)for(int j = 0; j < i; j++)
    if(presum[i]-presum[j] != 0)f[i] = (f[i]+f[j])%MOD;
  printf("%d\n", f[n]);
  return 0;
}