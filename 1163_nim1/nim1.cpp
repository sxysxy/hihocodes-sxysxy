#include <cstdio>
int main(){
    int s = 0;
    int n;scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);s ^= x;
    }
    puts(s?"Alice":"Bob");
    return 0;
}