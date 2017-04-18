#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
int N[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int M[] = {0, 1,  12, 25, 28, 33, 45, 60, 35, 84, 97};
char name[] = "treedp_easy%d.%s";
int fa[120];
int findfa(int x){
  return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void init(){
  for(int i = 1; i <= 100; i++)fa[i] = i;
}
char buf[233];
void make(int id){
  sprintf(buf, name, id, "in");
  ofstream inf(buf);
  
  inf << N[id] << ' ' << M[id] << endl;
  for(int i = 0; i < N[id]; i++)
    inf << rand()%1000+1 << ' ';
  inf << endl;
  int cnt = 0;
  while(true){
    int x = rand()%N[id]+1, y = rand()%N[id]+1;
    if(x == y)continue;
    int u = findfa(x), v = findfa(y);
    if(u != v){
      cnt++;
      fa[u] = v;
      inf << x << ' ' << y << endl;
      if(cnt == N[id]-1)break;
    }
  }
  inf.close();
  sprintf(buf, "treedp.exe < treedp_easy%d.in > treedp_easy%d.ans", id, id);
  system(buf);
}
int main(){
  srand(time(NULL));
  for(int i = 1; i <= 10; i++){
    init(); make(i);
  }
  return 0;
}