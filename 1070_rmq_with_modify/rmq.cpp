#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <malloc.h>
using namespace std;
struct node{
  node *ls, *rs;
  int minv;
  node(){
    ls = rs = NULL;
    minv = 0x7fffffff;
  }
  void pushup(){
    minv = 0x7fffffff;
    if(ls)minv = ls->minv;
    if(rs)minv = min(minv, rs->minv);
  }
};
node *build(int l, int r){
  if(l > r)return NULL;
  node *d = new node();
  if(l == r)scanf("%d", &d->minv);
  else{
    int m = (l+r)>>1;
    d->ls = build(l, m); d->rs = build(m+1, r);
    d->pushup();
  }
  return d;
}
int query(node *x, int l, int r, int L, int R){
  if(!x)return 0x7fffffff;
  if(l <= L && R <= r)return x->minv;
  int M = (L+R)>>1, ret = 0x7fffffff;
  if(l <= M)ret = min(ret, query(x->ls, l, r, L, M+1));
  if(r > M)ret = min(ret, query(x->rs, l, r, M+1, R));
  return ret;
}
void modify(node *x, int p, int v, int L, int R){
  if(!x)return;
  if(L == R && R == p)x->minv = v;
  else{
    int M = (L+R)>>1;
    if(p <= M)modify(x->ls, p, v, L, M);
    if(p > M)modify(x->rs, p, v, M+1, R);
    x->pushup();
  }
}
int main(){
  int n; scanf("%d", &n);
  node *r = build(1, n);
  int q; scanf("%d", &q);
  while(q--){
    int op, a, b; scanf("%d %d %d", &op, &a, &b);
    if(op == 0){
      printf("%d\n", query(r, a, b, 1, n));
    }else if(op == 1){
      modify(r, a, b, 1, n);
    }
  }
  return 0;
}