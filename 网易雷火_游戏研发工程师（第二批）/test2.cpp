#include "all.h"
struct tri
{
    int p1;
    int p2;
    int p3;
    bool set;
    tri()
    {
        p1 = 0;
        p2 = 0;
        p3 = 0;
        set = false;
    }
    void rotateAdjust()
    {
        while (p1 > p2 || p1 > p3)
        {
            int temp = p1;
            p1 = p2;
            p2 = p3;
            p3 = temp;
        }
    }
    void dirtAdjust()
    {
        int temp = p2;
        p2 = p3;
        p3 = temp;
    }
};

struct triss
{
    tri *tris;
    int n;
    void spread(tri *beg)
    {
        int i = findTri(beg->p1, beg->p2);
        if (i > 0)
        {
            if (beg->p1 == tris[i].p1 && beg->p2 == tris[i].p2)
                tris[i].dirtAdjust();
            if (beg->p1 == tris[i].p2 && beg->p2 == tris[i].p3)
                tris[i].dirtAdjust();
            if (beg->p1 == tris[i].p3 && beg->p2 == tris[i].p1)
                tris[i].dirtAdjust();
            tris[i].set = true;
            spread(&tris[i]);
        }
        i = findTri(beg->p2, beg->p3);
        if (i > 0)
        {
            if (beg->p2 == tris[i].p1 && beg->p3 == tris[i].p2)
                tris[i].dirtAdjust();
            if (beg->p2 == tris[i].p2 && beg->p3 == tris[i].p3)
                tris[i].dirtAdjust();
            if (beg->p2 == tris[i].p3 && beg->p3 == tris[i].p1)
                tris[i].dirtAdjust();
            tris[i].set = true;
            spread(&tris[i]);
        }
        i = findTri(beg->p1, beg->p3);
        if (i > 0)
        {
            if (beg->p1 == tris[i].p1 && beg->p3 == tris[i].p3)
                tris[i].dirtAdjust();
            if (beg->p1 == tris[i].p2 && beg->p3 == tris[i].p1)
                tris[i].dirtAdjust();
            if (beg->p1 == tris[i].p3 && beg->p3 == tris[i].p2)
                tris[i].dirtAdjust();
            tris[i].set = true;
            spread(&tris[i]);
        }
        return;
    }
    int findTri(int pm, int pn)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            if (tris[i].set)
                continue;
            if ((tris[i].p1 == pm || tris[i].p2 == pm || tris[i].p3 == pm) && (tris[i].p1 == pn || tris[i].p2 == pn || tris[i].p3 == pn))
            {
                return i;
            }
        }
        return 0;
    }
} tris;

int main()
{
    int p_num, tri_num;
    cin >> p_num >> tri_num;
    tris.tris = new tri[tri_num];
    tris.n = tri_num;
    for (int i = 0; i < tri_num; i++)
    {
        cin >> tris.tris[i].p1 >> tris.tris[i].p2 >> tris.tris[i].p3;
        tris.tris[i].rotateAdjust();
    }
    tris.tris[0].set = true;
    int set_num = 1;
    //n1第n个三角形的12两点连线，n2:23连线，n3:31连线
    tris.spread(&tris.tris[0]);
    for (int i = 0; i < tri_num; i++)
    {
        cout << tris.tris[i].p1 << ' ' << tris.tris[i].p2 << ' ' << tris.tris[i].p3 << endl;
    }
}