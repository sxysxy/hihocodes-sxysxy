#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
#include <queue>
#include <vector>
#include <windows.h>
using namespace std;
int main(){
  while(true){
    system("make_data.exe > tmp.txt");
    system("part_baoli.exe < tmp.txt > a.txt");
    system("part.exe < tmp.txt > b.txt");
    if(system("fc a.txt b.txt /W")){
      puts("WA"); break;
    }
    puts("AC");
  }
  return 0;
}