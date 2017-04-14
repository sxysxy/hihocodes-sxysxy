// TLE...
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
    int len = 1;char c;
    while(!isalpha(c = readc()));str[0] = c;
    while(isalpha(c = readc()))str[len++] = c;
    str[len] = 0;
    return len;
  }
};using IO::read_string; using IO::readint;
#define MAXN 1000003
char str[MAXN+2];
char buf[MAXN*2+5];
int f[MAXN*2+5];
void work(){
  int slen = read_string(str);
  for(int i = 1; i <= slen; i++){
    buf[i<<1] = str[i-1];
    buf[i<<1|1] = '#';
  }
  buf[0] = '$';
  buf[1] = '#';
  int t = (slen<<1)+2;
  memset(f, 0, sizeof(int)*t);
  buf[t] = 0;
  int id = 0, maxp = 0;
  for(int i = 1; i < t; i++){
    if(maxp > i)f[i] = min(f[(id<<1)-1], maxp-i);
    else f[i] = 1;
    while(buf[i+f[i]] == buf[i-f[i]])f[i]++;
    if(f[i]+i > maxp){
      maxp = f[i]+i;
      id = i;
    }
  }
  int ans = 0;
  for(int i = 1; i < t; i++)ans = max(ans, f[i]-1);
  printf("%d\n", ans);
}
int main(){
  int T = readint();
  while(T--)work();
}