//题目链接:https://www.acwing.com/problem/content/description/93/

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
