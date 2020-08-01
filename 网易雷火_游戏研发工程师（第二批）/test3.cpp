#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int dfs(const vector<int>& ddl, const vector<int>& cost,
 vector<bool> & path, const int& idx, const int & day)
{
    if (path[idx])
        return 0;
    path[idx] = true;
    int ret = cost[idx] + day - ddl[idx];
    if (ret < 0) ret = 0;
    int minCost = INT_MAX;
    bool ok = false;
    for (int i = 0; i < ddl.size(); i++)
    {
        if (!path[i])
        {
            ok = true;
            minCost = min(minCost, dfs(ddl, cost, path,i,day + cost[idx]));
        }
    }
    if (!ok)
        minCost = 0;
    ret += minCost;
    path[idx] = false;
    return ret;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ddl(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ddl[i] >> cost[i];
    }
    if (n == 0)
        cout << 0 << endl;
    // 深度优先搜索
    int minCost = INT_MAX;
    vector<bool> path(n, false);
    for (int i = 0; i < n; i++)
        minCost = min(minCost, dfs(ddl, cost, path, i, 0));
    cout << minCost << endl;
    return 0;
}