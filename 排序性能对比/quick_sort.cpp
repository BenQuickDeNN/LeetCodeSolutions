#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "configure.hpp"
#include "timer.hpp"

using namespace std;
void qsort(vector<int>& arr, const int& low, const int& high)
{
    if (low >= high) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /* 从左向右找比key大的值 */
        while (arr[++i] <= key)
            if (i == high) break;
        /* 从右向左找比key小的值 */
        while (arr[--j] >= key)
            if (j == low) break;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    /* 替换中枢值 */
    swap(arr[low], arr[j]);
    /* 如此一来，中枢左边的值都比中枢右边的小 */
    qsort(arr, low, j - 1);
    qsort(arr, j + 1, high);
}
int main()
{
    vector<int> arr(LEN);
    /* 快速排序 */
    Timer timer;
    timer.start();
    qsort(arr, 0, arr.size() - 1);
    printf("quick_sort elapsed %.3f us\n", timer.end_us());
    // for (const int& ele : arr)
        // cout << ele << ' ';
    // cout << endl;
    return 0;
}