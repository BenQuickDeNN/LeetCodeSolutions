/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
*/
#include <iostream>
#include <vector>
using namespace std;
int drink(const int& n)
{
    if (n < 2) return 0;
    else if (n == 2) return 1; // 借一瓶
    int count = n / 3;
    int remain = n % 3;
    return count + drink(remain + count);
}
int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        // 递归 会 超内存
        // counts.emplace_back(drink(n));
        // 用循环求会超时
        
        int count = 0;
        int bottle;
        int remain;
        // 用循环会超时
        /*
        while (n > 1)
        {
            if (n == 2)
            {
                ++count;
                break;
            }
            bottle = n / 3;
            count += bottle;
            remain = n % 3;
            n = remain + bottle;
        }
        */
        cout << count << endl;
        
        // 只能推数学公式了

    }
    return 0;
}