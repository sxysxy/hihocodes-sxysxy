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
  void pushup(){
    size = 1+lsz()+rsz();
    sum = val;
    if(ls)sum += ls->sum;
    if(rs)sum += rs->sum;
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
      ls->setval(v); 
      rs->setval(v);
    }
  }
};
int main(){
  
  return 0;
}
