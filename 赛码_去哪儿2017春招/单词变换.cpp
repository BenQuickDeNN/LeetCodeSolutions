#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int dfs(const vector<vector<int>>& dists, const int & src, const int & dst)
{
    if (src == dst)
        return 0;
   	int minCost = INT_MAX;
    for (int i = 0; i < dists[src].size(); ++i)
    {
        if (i == src)
            continue;
       	minCost = min(minCost, 1 + dfs(dists, i, dst));
    }
    return minCost;
}
int main()
{
    string src;
    cin >> src;
    string dst;
    cin >> dst;
    vector<string> strs(1, src);
    string buf;
    while (cin >> buf)
    {
        if (buf == "end") break;
        strs.emplace_back(buf);
    }
   	const int n = strs.size();
    vector<vector<int>> dists(n, vector<int>(n, 0));
    int dstIdx = -1;
    for (int i = 0; i < n; ++i)
    {
        const string & str1 = strs[i];
        if (dst == str1)
            dstIdx = i;
        for (int j = 0; j < n; ++j)
        {
            const string & str2 = strs[j];
            const int mn = min(str1.size(), str2.size());
            for (int k = 0; k < mn; ++k)
                dists[i][j] += str1[k] != str2[k];
        }
    }
    if (dstIdx == -1)
        return 0;
    cout << dfs(dists, 0, dstIdx);
    return 0;
}