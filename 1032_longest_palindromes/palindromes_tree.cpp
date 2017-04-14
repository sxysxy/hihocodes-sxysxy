//AC...！
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>
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
    int len = 2;char c;
    while(!isalpha(c = readc()));str[1] = c-'a';
    while(isalpha(c = readc()))str[len++] = c-'a';
    str[len] = 0;
    return len-1;
  }
};using IO::read_string; using IO::readint;
#define MAXN 1000003
#define MAXS 26
char str[MAXN+1];
int len[MAXN];
int fail[MAXN];
int trans[MAXN][MAXS];
int tot, sum, last, slen;
inline int find(int x){
  while(tot-len[x] == 1 || str[tot-len[x]-1] != str[tot])x = fail[x];
  return x;
}
inline void clear(int x){memset(trans[x], 0, sizeof(int)*MAXS);}
void work(){
  slen = read_string(str);
  sum = 1;
  len[0] = 0, len[1] = -1;
  fail[0] = 1;
  clear(0), clear(1);
  last = 1;
  for(int i = 1; i <= slen; i++){
    tot = i;
    int c = find(last);
    if(!trans[c][str[i]]){
      clear(++sum);
      len[sum] = len[c]+2;
      fail[sum] = trans[find(fail[c])][str[i]];
      trans[c][str[i]] = sum;
    }
    last = trans[c][str[i]];
  }
  int ans = 0;
  for(int i = sum; i >= 2; i--)ans = max(ans, len[i]);
  printf("%d\n", ans);
}
int main(){
  int T = readint();
  while(T--)work();
  return 0;
}