#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
struct line{
  int x1, y1, x2, y2;
  int k;
  long long length(){
    return 1ll*(x2-x1)*(x2-x1)+1ll*(y2-y1)*(y2-y1);
  }
}ls[4];
bool cmpbylen(line a, line b){
  return a.length() < b.length();
}
int main(){
  int T;scanf("%d", &T);
  while(T--){
    for(int i = 0; i < 4; i++)
      scanf("%d %d %d %d", &ls[i].x1, &ls[i].y1, &ls[i].x2, &ls[i].y2);
    sort(ls, ls+4, cmpbylen);
    
  }
  return 0;
}