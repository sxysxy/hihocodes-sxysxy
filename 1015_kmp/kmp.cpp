#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
char p[10003], t[1000003];  //用std::string+cin会被卡到TLE...
int f[10003];
int main(){
  int T; scanf("%d", &T);
  while(T--){
    scanf("%s %s", p, t);
    int plen = strlen(p), tlen = strlen(t);
    f[1] = 0;
    for(int i = 1; i < plen; i++){
      int j = f[i];
      while(j && p[i] != p[j])j = f[j];
      f[i+1] = p[i] == p[j]? j+1:0;
    }
    int j = 0, cnt = 0;
    for(int i = 0; i < tlen; i++){
      while(j && p[j] != t[i])j = f[j];
      if(p[j] == t[i])j++;
      if(j == plen)cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}