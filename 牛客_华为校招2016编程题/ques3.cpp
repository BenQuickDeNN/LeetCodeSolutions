#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
    enum PokerType
    {
        GEZI,
        DUIZI,
        SHUNZI,
        BOMB,
        KBOMB
    };
    enum PokerVal
    {
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,
        _10,
        _J,
        _Q,
        _K,
        _A,
        _2,
        _joker,
        _JOKER
    };
class Poker
{
public:
    
    vector<PokerVal> datas;
    void checkPokerType()
    {
        if (datas.size() == 1)
        {
            pokerType = GEZI;
        }
        else if (datas.size() == 2)
        {
            if ((datas[0] == _joker && datas[1] == _JOKER) ||
                (datas[0] == _JOKER && datas[1] == _joker))
                pokerType = KBOMB;
            else
                pokerType = DUIZI;
        }
        else if (datas.size() == 4)
            pokerType = BOMB;
        else if (datas.size() == 5)
            pokerType = SHUNZI;
    }
    PokerType pokerType = GEZI;
    bool isLargerThan(Poker poker)
    {
        if (pokerType == KBOMB)
            return true;
        else if (pokerType == BOMB)
            if (poker.pokerType == KBOMB)
                return false;
            else if (poker.pokerType == BOMB)
                return datas[0] > poker.datas[0];
            else
                return true;
        else
            if (poker.pokerType == KBOMB || poker.pokerType == BOMB)
                return false;
            else
                return datas[0] > poker.datas[0];
    }
    string toString()
    {
        string ret = "";
        for (size_t i = 0; i < datas.size(); i++)
        {
            if (i > 0) ret += ' ';
            PokerVal pv = datas[i];
            if (pv == _3) ret += '3';
            else if (pv == _4) ret += '4';
            else if (pv == _5) ret += '5';
            else if (pv == _6) ret += '6';
            else if (pv == _7) ret += '7';
            else if (pv == _8) ret += '8';
            else if (pv == _9) ret += '9';
            else if (pv == _10) ret += "10";
            else if (pv == _J) ret += 'J';
            else if (pv == _Q) ret += 'Q';
            else if (pv == _K) ret += 'K';
            else if (pv == _A) ret += 'A';
            else if (pv == _2) ret += '2';
            else if (pv == _joker) ret += "joker";
            else if (pv == _JOKER) ret += "JOKER";
        }
        return ret;
    }
};
int main()
{
    string str_in = "";
    string tmp;
    while (cin >> tmp)
    {
        str_in += tmp + ' ';
    }
    Poker poker[2];
    int pidx = 0;
    for (size_t i = 0; i < str_in.size(); i++)
    {
        char c = str_in[i];
        if (c == '-') pidx = 1;
        else if (c == '3') poker[pidx].datas.push_back(_3);
        else if (c == '4') poker[pidx].datas.push_back(_4);
        else if (c == '5') poker[pidx].datas.push_back(_5);
        else if (c == '6') poker[pidx].datas.push_back(_6);
        else if (c == '7') poker[pidx].datas.push_back(_7);
        else if (c == '8') poker[pidx].datas.push_back(_8);
        else if (c == '9') poker[pidx].datas.push_back(_9);
        else if (c == '1') 
        {
            poker[pidx].datas.push_back(_10);
            ++i;
        }
        else if (c == 'J') 
        {
            if (i < str_in.size() - 1)
                if (str_in[i + 1] == 'O')
                {
                    poker[pidx].datas.push_back(_JOKER);
                    i += 4;
                    continue;
                }
            poker[pidx].datas.push_back(_J);
        }
        else if (c == 'Q') poker[pidx].datas.push_back(_Q);
        else if (c == 'K') poker[pidx].datas.push_back(_K);
        else if (c == 'A') poker[pidx].datas.push_back(_A);
        else if (c == '2') poker[pidx].datas.push_back(_2);
        else if (c == 'j') 
        {
            poker[pidx].datas.push_back(_joker);
            i += 4;
        }
    }
    poker[0].checkPokerType();
    poker[1].checkPokerType();
    if (poker[0].isLargerThan(poker[1]))
        cout << poker[0].toString() << endl;
    else
        cout << poker[1].toString() << endl;
    return 0;
}