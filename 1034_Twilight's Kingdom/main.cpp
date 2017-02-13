#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
namespace IO{
  char buf[1<<18], *fs, *ft;
  inline char readc(){
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin)),fs==ft)?EOF:*fs++;
  }
  inline int readint(){
    char c; int r;
    while(c = readc()){if(c >= '0' && c <= '9'){r = c^0x30;break;}}
    while(isdigit(c = readc()))r = (r<<3)+(r<<1)+(c^0x30);
    return r;
  }
  inline int read_string(char *str){
    int len = 1;char c;
    while(!isalpha(c = readc()));str[0] = c;
    while(isalpha(c = readc()))str[len++] = c;
    str[len] = 0;
    return len;
  }
};using IO::read_string; using IO::readint;
struct node{
  node *ls, *rs;
  int si;
  node(){memset(this, 0, sizeof(node));}
  inline int _SUM(){return this?this->si:0;}
  inline void pushup(){si = ls->_SUM() + rs->_SUM();}
};
#define MAXN 100003
int mi[MAXN], ri[MAXN], t[MAXN<<2];
node *build(int l, int r){
  if(l > r)return NULL;
  node *d = new node();
  if(l == r){
    scanf("%d %d %d", &d->si, mi+l, ri+l);
    t[l] = 0;
  }else{
    int m = (l+r)>>1;
    d->ls = build(l, m); d->rs = build(m+1, r);
    d->pushup();
  }
  return d;
}
void update(node *x, int l, int r, int L, int R, int tm){
  if(!x)return;
  if(L == R && (L >= l && L <= r)){
    int tmp = (tm-t[L])*ri[L];
    x->si = min(x->si+tmp, mi[L]);
  }else{
    int M = (L+R)>>1;
    if(l <= M)update(x->ls, l, r, L, M, tm);
    if(r > M)update(x->rs, l, r, M+1, R, tm);
    x->pushup();
  }
}
long long query(node *x, int l, int r, int L, int R){
  if(!x)return 0;
  if(L >= l && r >= R)return x->si;
  long long ret = 0; int M = (L+R)>>1; 
  if(l <= M)ret += query(x->ls, l, r, L, M);
  if(r > M)ret += query(x->rs, l, r, M+1, R);
  return ret;
}
void setime(node *x, int l, int r, int L, int R, int tm){
  if(!x)return;
  if(L == R && (L >= l && L <= r)){
    t[L] = tm; x->si = 0;
  }else{
    int M = (L+R)>>1;
    if(l <= M)setime(x->ls, l, r, L, M, tm);
    if(r > M)setime(x->rs, l, r, M+1, R, tm);
    x->pushup();
  }
}
#define MOD 1000000007
int main(){
  int n, m;
  scanf("%d", &n);
  node *rt = build(1, n);
  scanf("%d", &m);
  long long ans = 0;
  while(m--){
    int t, l, r; scanf("%d %d %d", &t, &l, &r);
    update(rt, l, r, 1, n, t);
    ans = (ans+query(rt, l, r, 1, n))%MOD;
    setime(rt, l, r, 1, n, t);
  }
  printf("%lld\n", ans);
  return 0;
}
