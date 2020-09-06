#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        const int n = str.size();
        string res = "";
        int curr = 0;
        int next = 1;
        while (next < n)
        {
            char c1 = str[curr];
            char c2 = str[next];
            if (c1 != c2)
            {
                res += c1;
                ++curr;
            }
            else
            {
                curr += 2;
            }
            next = curr + 1;
        }
        if (curr < n)
            res += str[curr];
        if (res.empty())
            cout << "no" << endl;
        else
            cout << res << endl;
    }
    return 0;
}