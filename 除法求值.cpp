#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 图的搜索问题，有向图
        // 对 a / b = 2.0，以a为起始节点建立一条指向b的值为2.0的边，同时建立一条以b为起点指向a的值为1 / 2.0的边
    }
};