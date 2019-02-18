给定一张```$n$```个点的带权无向图，点从```$0~n-1$```标号，求起点```$0$```到终点```$n-1$```的最短Hamilton路径。Hamilton路径的定义是从```$0$```到```$n-1$```不重不漏地经过每个点恰好一次。  
**输入格式**  
第一行输入整数```$n$```。  
接下来```$n$```行每行```$n$```个整数，其中第```$i$```行第```$j$```个整数表示点```$i$```到```$j$```的距离（记为```$a[i,j]$```）。  
对于任意的```$x, y, z$```数据保证```$a[x,x]=0, a[x,y]=a[y,x]$```并且```$a[x,y]+a[y,z]>=a[x,z]$```。  
**输出格式**  
输出一个整数，表示最短Hamilton路径的长度。
```
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/*因为main中的变量定义在较小的栈空间中,
所以占用空间较大的变量应该定义在堆空间中*/

const int N = 20, M = 1 << 20;

int n;
int f[M][N], weight[N][N]; // f[状态][到达结点]

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> weight[i][j];
        }
    }

    memset(f, 0x3f, sizeof f); // 数组初始化为0x3f

    f[1][0] = 0;

    for (int i = 0; i < 1 << n; i ++){
        for (int j = 0; j < n; j ++){
            if (i >> j & 1){ // 保证当前点j在状态i中
                for (int k = 0; k < n; k ++){
                    if (i - (1 << j) >> k & 1){ // 保证k在上一状态(即去掉j之后的状态)中
                        f[i][j] = min(f[i][j], f[i -(1 << j)][k] + weight[k][j]);
                    }
                }

            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl; // 最终状态为n个位置全为1, 最后到达的点为n-1
}
```
