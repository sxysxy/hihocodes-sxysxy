//TLE...
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
#include <cctype>
#include <vector>
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
const int x = 137;
typedef unsigned long long ULL;
#define MAXN 1000002
ULL hashv[MAXN], xp[MAXN], sh[MAXN];
ULL rhashv[MAXN], rsh[MAXN];
char s[MAXN];
int slen;
bool check(int len){
  for(int i = 0; i <= slen-len; i++)hashv[i] = sh[i]-sh[i+len]*xp[len],
                                    rhashv[i] = rsh[i]-rsh[i+len]*xp[len];
  sort(rhashv, rhashv+slen-len+1);
  for(int i = 0; i <= slen-len; i++)
    if(binary_search(rhashv, rhashv+slen-len+1, hashv[i]))return true;
  return false;
}
void work(){
  slen = read_string(s);
  for(int i = slen-1; ~i; i--)sh[i] = sh[i+1]*x+s[i];
  reverse(s, s+slen);
  for(int i = slen-1; ~i; i--)rsh[i] = rsh[i+1]*x+s[i];
  int l = 0, r = slen;
  int ans = 0;
  while(l <= r){
    int m = (l+r)>>1;
    if(check(m))ans = m, l = m+1; else r = m-1;
  }
  printf("%d\n", ans);
}
int main(){
  //freopen("test_data.txt", "r", stdin);
  int T = readint();
  xp[0] = 1;
  for(int i = 1; i <= MAXN-1; i++)xp[i] = xp[i-1]*x;
  while(T--)work();
  return 0;
}