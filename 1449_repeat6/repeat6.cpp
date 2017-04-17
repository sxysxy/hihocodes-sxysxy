//AC
//Big force makes qiji.
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
const int MAXN = 2e6+2;
int cnt = 1, last = 1;
int link[MAXN], len[MAXN], next[MAXN][26];
int size[MAXN];
void expand(int c){
  int cur = ++cnt; len[cur] = len[last]+1;
  size[cur] = 1;
  int p; 
  for(p = last; p && !next[p][c]; p = link[p])
    next[p][c] = cur;
  if(!p)link[cur] = 1;
  else{
    int q = next[p][c];
    if(len[q] == len[p]+1)link[cur] = q;
    else{
      int clone = ++cnt;
      link[clone] = link[q];
      len[clone] = len[p]+1;
      memcpy(next[clone], next[q], sizeof next[0]);
      for(; p && next[p][c] == q; p = link[p])
        next[p][c] = clone;
      link[q] = link[cur] = clone;
    }
  }
  last = cur;
}
int rank[MAXN], buk[MAXN];
char buf[MAXN>>1];
int ans[MAXN>>1];
struct node{
  int ls, rs, l, r, maxv, minv;
  int lazy;
  void setv(int v){
    lazy = maxv = minv = v;
  }
}ns[MAXN]; int _nd = 1;
inline void pushup(node &d){
  d.maxv = std::max(ns[d.ls].maxv, ns[d.rs].maxv);
  d.minv = std::min(ns[d.ls].minv, ns[d.rs].minv);
}
inline void pushdown(node &d){
  if(d.lazy){
    if(d.ls)ns[d.ls].setv(d.lazy);
    if(d.rs)ns[d.rs].setv(d.lazy);
    d.lazy = 0;
  }
}
int build(int l ,int r){
  if(l > r)return 0;
  int c = _nd++;
  node &d = ns[c];
  d.l = l, d.r = r;
  if(l == r)d.maxv = d.minv = 0;
  else{
    int m = (l+r)>>1;
    d.ls = build(l, m); d.rs = build(m+1, r);
    pushup(d);
  }
  return c;
}
void update(int c, int l, int r, int v){ //let a[i] = max(a[i], v) (i = l..r)
  if(!c)return;
  node &d = ns[c];
  if(d.minv >= v)return;
  if(d.l == l && d.r == r){
    if(d.maxv < v)
      d.setv(v);
    else{
      pushdown(d);
      update(d.ls, ns[d.ls].l, ns[d.ls].r, v); 
      update(d.rs, ns[d.rs].l, ns[d.rs].r, v);
      if(d.l != d.r)
      pushup(d);
    }
  }else{
    pushdown(d);
    if(l >= ns[d.rs].l)update(d.rs, l, r, v);
    else if(r <= ns[d.ls].r)update(d.ls, l, r, v);
    else{
      update(d.ls, l, ns[d.ls].r, v); update(d.rs, ns[d.rs].l, r, v);
    }
    pushup(d);
  }
}
int query(int c, int p){
  if(!c)return 0;
  node &d = ns[c];
  if(d.l == p && d.r == p)return d.maxv;
  else{
    pushdown(d);
    if(p <= ns[d.ls].r)return query(d.ls, p);
    else if(p >= ns[d.rs].l)return query(d.rs, p);
  }
}
int main(){
  //freopen("test_data.txt", "r", stdin);
  scanf("%s", buf);
  int slen = 0;
  for(int i = 0; buf[i]; i++, slen++)expand(buf[i]-'a');
  for(int i = 1; i <= cnt; i++)buk[len[i]]++;
  for(int i = 1; i <= cnt; i++)buk[i] += buk[i-1];
  for(int i = cnt; i; i--)rank[buk[len[i]]--] = i;
  for(int i = cnt; i; i--)size[link[rank[i]]] += size[rank[i]];
  build(1, slen);
  for(int i = 2; i <= cnt; i++){
    int minlen = len[link[i]]+1;
    int maxlen = len[i];
    update(1, minlen, maxlen, size[i]);
  }
  for(int i = 1; i <= slen; i++)
    printf("%d\n", query(1, i));
  return 0;
}