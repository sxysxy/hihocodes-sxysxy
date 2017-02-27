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
int query(node *x, int l, int r, int L, int R){
  if(!x)return 0x7fffffff;
  if(l <= L && R <= r)return x->minv;
  int M = (L+R)>>1, ret = 0x7fffffff;
  if(l <= M)ret = min(ret, query(x->ls, l, r, L, M));
  if(r > M)ret = min(ret, query(x->rs, l, r, M+1, R));
  return ret;
}
void modify(node *&x, int p, int v, int L, int R){
  if(!x)x = new node();
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
  node *r = NULL;
  for(int i = 1, x; i <= n; i++){
    scanf("%d", &x);
    modify(r, i, x, 1, n);
  }
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