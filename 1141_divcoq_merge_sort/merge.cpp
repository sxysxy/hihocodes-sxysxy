#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
using namespace std;
#define N 100002
int a[N], b[N];
long long ans = 0;
void merge(int l, int r){
  if(l >= r)return; int m = (l+r)>>1;
  merge(l, m); merge(m+1, r);
  int i = l, j = m+1, k = l;
  while(i <= m && j <= r){
    if(a[i]>a[j]){
      ans += m-i+1;
      b[k++] = a[j++];
    }else b[k++] = a[i++];
  }
  while(i <= m)b[k++] = a[i++];
  while(j <= r)b[k++] = a[j++];
  for(int p = l; p <= r; p++)a[p] = b[p];
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)scanf("%d", a+i);
  merge(1, n);
  printf("%lld\n", ans);
  return 0;
}