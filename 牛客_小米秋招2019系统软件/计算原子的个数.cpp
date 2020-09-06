// 使用词法分析和语法分析
#include <queue>
#include <map>
using namespace std;
enum TokType
{
    ELEMENT,
    INTEGER
};
enum TokChar
{
    Cap
};
enum JumpState
{
    TOK_ELE,
    TOK_INT,
    STATE0,
    STATE1,
    STATE2
};
static const map<pair<JumpState, TokChar>, JumpState> JumpTable = {
    {STATE0, }
};
int main()
{
    return 0;
}