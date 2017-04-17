//RE
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
const int MAXN = 1e5+10;
struct node{
  int l, r, ls, rs;
  int lazy, val;
  inline void setv(int v){
    val = v, lazy = v;
  }
}ns[MAXN<<2]; int _nd;
int build(int l, int r){
  int cur = ++_nd;
  node &d = ns[cur];
  d.l = l, d.r = r;
  if(l+1 == r)return cur;
  if(l < r){
    int m = (l+r)>>1;
    d.ls = build(l, m); d.rs = build(m, r);
  }
  return cur;
}
inline void pushdown(node &d){
  if(d.lazy){
    if(d.ls)ns[d.ls].setv(d.lazy); 
    if(d.rs)ns[d.rs].setv(d.lazy);
    d.lazy = 0;
  }
}
void modify(int c, int l, int r, int v){
  if(!c)return;
  node &d = ns[c]; 
  if(d.l == l && d.r == r)d.setv(v);
  else{
    pushdown(d);
    if(l >= ns[d.rs].l)modify(d.rs, l, r, v);
    else if(r <= ns[d.ls].r)modify(d.ls, l, r, v);
    else{
      modify(d.ls, l, ns[d.ls].r, v);
      modify(d.rs, ns[d.rs].l, r, v);
    }
  }
}
bool vis[MAXN];
void query(int c){
  if(!c)return;
  if(ns[c].lazy){
    vis[ns[c].lazy] = true;
    return;
  }
  query(ns[c].ls); query(ns[c].rs);
}
int a[MAXN<<1], lim;
int rl[MAXN], rr[MAXN];
inline int getv(int x){
  return lower_bound(a+1, a+lim, x)-a;
}
int main(){
 // freopen("test_data.txt", "r", stdin);
  int n, L;
  scanf("%d %d", &n, &L);
  if(n == 0){
    puts("0"); return 0;
  }
  int m = 0;
  for(int i = 1; i <= n; i++){
    scanf("%d %d", rl+i, rr+i);
    a[++m] = rl[i]; a[++m] = rr[i];
  }
  a[++m] = L;
  sort(a+1, a+1+m);
  lim = unique(a+1, a+1+m)-a;
  m = a[lim-1];
  build(1, m);
  for(int i = 1; i <= n; i++)
    modify(1, getv(rl[i]), getv(rr[i]), i);
  int ans = 0;
  query(1);
  for(int i = 1; i <= n; i++)ans += vis[i];
  printf("%d\n", ans);
  return 0;
}