//TLE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int x = 137;
typedef unsigned long long ULL;
#define MAXN 1000002
ULL hashv[MAXN], xp[MAXN], sh[MAXN];
ULL rhashv[MAXN], rsh[MAXN];
int n;
char s[MAXN];
bool check(int len){
  for(int i = 0; i < n-len+1; i++)hashv[i] = sh[i]-sh[i+len]*xp[len];
  for(int i = 0; i < n-len+1; i++)rhashv[i] = rsh[i]-rsh[i+len]*xp[len];
  for(int i = 0; i < n-len+1; i++)if(hashv[i] == rhashv[n-len-i])return true;
  return false;
}
void work(){
  scanf("%s", s);
  n = strlen(s);
  sh[n] = 0;
  rsh[n] = 0;
  for(int i = n-1; ~i; i--)
    sh[i] = sh[i+1]*x + s[i];
  for(int i = 0, j = n-1; i < n; i++, j--)
    rsh[j] = rsh[j+1]*x + s[i]; //reverse
  int l = 0, r = n;
  int ans = 0;
  /*
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m)){
      ans = m;
      l = m+1;
    }else r = m-1;
  }
  */
  //不满足单调性,不能二分答案...
  for(int i = 0; i <= n; i++)
    if(check(i))ans = i;
  printf("%d\n", ans);
}
int main(){
  //freopen("test_data.txt", "r", stdin);
  int T; scanf("%d", &T);
  xp[0] = 1;
  for(int i = 1; i <= MAXN-1; i++)xp[i] = xp[i-1]*x;
  while(T--)work();
  return 0;
}