#include <vector>

using namespace std;

class Bank {
    vector<long long> bs;
    int n = 0;
    bool isExist(int acc) {
        if (acc > n || acc < 1) {
            return false;
        }
        return true;
    }
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        bs.resize(n);
        for (int i = 0; i < balance.size(); ++i) {
            bs[i] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (isExist(account1) && isExist(account2)) {
            if (bs[account1 - 1] < money) {
                return false;
            }
            bs[account1 - 1] -= money;
            bs[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (!isExist(account)) {
            return false;
        }
        bs[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!isExist(account)) {
            return false;
        }
        if (bs[account - 1] < money) {
            return false;
        }
        bs[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */