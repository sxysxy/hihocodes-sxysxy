#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <list>
#include <cctype>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
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
const int MAXN = 2e6+2;
int go[MAXN][26], link[MAXN], len[MAXN];
int last, cnt;
inline void reset(){
  last = cnt = 1;
  memset(go[1], 0, sizeof(go[1]));
}
inline int clear(int x){
  memset(go[x], 0, sizeof go[0]);
  link[x] = 0, len[x] = 0;
  return x;
}
void expand(int c){
  int cur = clear(++cnt); len[cur] = len[last]+1;
  int p;
  for(p = last; p && !go[p][c]; p = link[p])go[p][c] = cur;
  if(!p)link[cur] = 1;
  else{
    int q = go[p][c];
    if(len[q] == len[p]+1)link[cur] = q;
    else{
      int clone = clear(++cnt);
      memcpy(go[clone], go[q], sizeof go[0]); len[clone] = len[p]+1;
      link[clone] = link[q];
      for(; p && go[p][c] == q; p = link[p])go[p][c] = clone;
      link[cur] = link[q] = clone;
    }
  }
  last = cur;
}
char str[MAXN];
int main(){
 // freopen("test_data.txt", "r", stdin);
  int T = readint();
  while(T--){
    reset();
    int n = read_string(str);
    for(int i = 0; i < n; i++)expand(str[i]-'a');
    int mlen = 0, st = 1;
    int ans = 0;
    for(int i = n-1; ~i; i--){
      int c = str[i]-'a';
      if(go[st][c]){
        mlen++, st = go[st][c];
      }else{
        while(st && !go[st][c])st = link[st];
        if(!st)st = 1, mlen = 0;
        else mlen = len[st]+1, st = go[st][c];
      }
      ans = max(ans, mlen);
    }
    printf("%d\n", ans);
  }
  return 0;
}