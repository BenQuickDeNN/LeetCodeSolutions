#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int weight;
    vector<int> people;
    while (cin >> weight)
    {
        people.emplace_back(weight);
    }
    const int limit = weight;
    people.pop_back();
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1;
    int count = 0;
    while (left <= right)
    {
        const int w_l = people[left];
        const int w_r = people[right];
        if (w_l + w_r <= limit)
        {
            ++left;
            --right;
            ++count;
        }
        else if (w_r <= limit)
        {
            --right;
            ++count;
        }
        else if (w_l <= limit)
        {
            ++left;
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}