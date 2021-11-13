#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    vector<int> fsa(string _str) {
        vector<int> res;
        string tmp = "";
        int state = 0;
        const int n = _str.size();
        for (int i = 0; i < n; i++) {
            char c = _str.at(i);
            if (isdigit(c) && state == 0) {
                state = 1;
                tmp += c;
            } else if (isdigit(c) && state == 1) {
                tmp += c;
            } else if (state == 1) {
                state = 0;
                res.emplace_back(stoi(tmp));
                tmp = "";
            }
        }
        if (!tmp.empty()) {
            res.emplace_back(stoi(tmp));
        }
        return res;
    }
public:
    bool areNumbersAscending(string s) {
        bool res = true;
        vector<int> datas = fsa(s);
        for (int i = 1; i < datas.size(); i++) {
            if (datas[i - 1] >= datas[i]) {
                res = false;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.areNumbersAscending("hello world 5 x 5");
    return 0;
}