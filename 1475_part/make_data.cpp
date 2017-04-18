#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <ctime>
using namespace std;
int main(){
  srand(time(NULL));
  int n = rand()%10000+1;
  printf("%d\n", n);
  for(int i = 1; i <= n; i++)
    printf("%d ", rand()%20000-10000);
  return 0;
}