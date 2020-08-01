#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int N;
    cin >> N;
    // 求互质个数
    int huzhi = N;
    for (int i = 2; i <= N; i++)
        for (int j = 2; j <= i; j ++)
            if (i % j == 0 && N % j == 0)
            {
                --huzhi;
                break;
            }
    float fx = (float)huzhi / (float)N;
    printf("%.6f\n", fx);
    return 0;
}