#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int f[2][100002];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        int c = i&1;
        int nd, va; scanf("%d %d", &nd, &va);
        for(int j = 0; j <= m; j++){
            if(j < nd)f[c][j] = f[c^1][j];
            else f[c][j] = max(f[c^1][j], f[c^1][j-nd]+va);
        }
    }
    printf("%d\n", f[n&1][m]);
    return 0;
}