#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <string>
#include <vector>
using namespace std;
#define MAXS 26
#define BASE 'a'
struct node{
  int cnt;     //标号记录
  node *(next[26]);  //转移表
  node(){memset(this, 0, sizeof(node));}
}trie;
void insert(node *u, char *c){
  while(*c){
    if(!u->next[*c-BASE])u->next[*c-BASE] = new node;
    u->cnt++, u = u->next[*c-BASE]; c++;
  }
  u->cnt++;
}
int cnt(node *u, char *c){
  while(*c){
    if(!u->next[*c-BASE])return 0;
    u = u->next[*c-BASE];c++;
  }return u->cnt;
}
char tmp[20];
int main(){
  int n;scanf("%d", &n);
  while(n--)scanf("%s", tmp), insert(&trie, tmp);
  scanf("%d", &n);
  while(n--)scanf("%s", tmp), printf("%d\n", cnt(&trie, tmp));
  return 0;
}