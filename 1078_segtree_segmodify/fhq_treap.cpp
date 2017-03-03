#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
struct node{
  node *ls, *rs;
  int fix, size;
  LL val, sum;
  LL lazy;
  node(LL v):val(v), sum(v), fix(rand()), size(1){
    ls = rs = NULL;
    lazy = -1;
  }
  inline int lsz(){return ls?ls->size:0;}
  inline int rsz(){return rs?rs->size:0;}
  node *pushup_basic(){
    if(!this)return NULL;
    size = 1+lsz()+rsz();
    return this;
  }
  node *pushup(){
    if(!this)return NULL;
    pushup_basic();
    sum = val;
    if(ls)sum += ls->sum;
    if(rs)sum += rs->sum;
    return this;
  }
  void setval(LL v){
    if(!this)return;
    val = v;
    sum = v*size;
    lazy = v;
  }
  void pushdown(){
    if(!this)return;
    if(~lazy){
      ls->setval(lazy); 
      rs->setval(lazy);
      lazy = -1;
    }
  }
};
node *merge(node *x, node *y){
  if(!x)return y->pushup_basic(); 
  if(!y)return x->pushup_basic();
  if(x->fix < y->fix){
    x->pushdown();
    x->rs = merge(x->rs, y);
    return x->pushup();
  }else{
    y->pushdown();
    y->ls = merge(x, y->ls);
    return y->pushup();
  }
}
typedef pair<node*, node*>droot;
droot split(node *x, int k){
  droot r(NULL, NULL);
  if(!x)return r;
  x->pushdown();
  int s = x->ls?x->ls->size:0;
  if(s >= k){
    r = split(x->ls, k);
    x->ls = r.second;
    r.second = x->pushup();
  }else{
    r = split(x->rs, k-s-1);
    x->rs = r.first;
    r.first = x->pushup();
  }
  return r;
}
LL tmp[100003];
node* build(LL *a, int n){
  node *x = new node(a[0]);
  for(int i = 1; i < n; i++)x = merge(x, new node(a[i]));
  return x;
}
int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++)scanf("%lld", tmp+i);
  node *root = build(tmp, n);
  int q; scanf("%d", &q);
  while(q--){
    int op; scanf("%d", &op);
    if(op == 1){
      int l, r; LL v; scanf("%d %d %lld", &l, &r, &v);
      droot p = split(root, l-1);
      droot p2 = split(p.second, r-l+1);
      p2.first->setval(v);
      root = merge(p.first, merge(p2.first, p2.second));
    }else if(op == 0){
      int l, r; scanf("%d %d", &l, &r);
      droot p = split(root, l-1);
      droot p2 = split(p.second, r-l+1);
      printf("%lld\n", p2.first->sum);
      root = merge(p.first, merge(p2.first, p2.second));
    }
  }
  return 0;
}
