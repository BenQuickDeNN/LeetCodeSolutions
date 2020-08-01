#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
class Rect
{
public:
    int H;
    int W;
    int getMJ() const
    {
        return H * W;
    }
    int getKGB() const
    {
        return min(W / H, H / W);
    }
};
bool cmp(const Rect &a, const Rect &b)
{
    if (a.getMJ() != b.getMJ())
        return a.getMJ() < b.getMJ();
    if (a.getKGB() != b.getKGB())
        return a.getKGB() > b.getKGB();
    return a.W < b.W;
}
int main()
{
    int N;
    cin >> N;
    vector<Rect> rects(N);
    for (size_t n = 0; n < N; n++)
    {
        cin >> rects[n].W >> rects[n].H;
    }
    sort(rects.begin(), rects.end(),cmp);
    for (size_t n = 0; n < N; n++)
        if (n < N - 1)
        {
            // cout << rects[n].W << ' ' << rects[n].H << ' ';
            printf("%d %d ", rects[n].W, rects[n].H);
        }
        else
        {
            // cout << rects[n].W << ' ' << rects[n].H;
            printf("%d %d", rects[n].W, rects[n].H);
        }
    return 0;
}