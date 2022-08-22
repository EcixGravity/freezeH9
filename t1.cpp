#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using std::queue;
using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n, c1, c2;
    cin >> n;
    unordered_map< int, int> path;
    unordered_map<int, vector<int> > map;
    for (int i = 0; i < n; ++i)
    {
        cin >> c1 >> c2;
        map[c1].emplace_back(c2);
    }
    cin >> c1 >> c2;
    if (c1 == c2 || c1 == 1 || c2 == 1)
    {
        cout << std::min(c1, c2) << endl;
        return 0;
    }
    ++path[c1];
    ++path[c2];
    // bfs  
    queue<int> q;
    q.push(c1);
    q.push(c2);
    while (!q.empty())
    {
        int o = q.front();
        q.pop();
        for (auto t : map[o])
        {
            if (++path[t] == 2)
            {
                cout << t << endl;
                return 0;
            }
            q.push(t);
        }
    }
    cout << 1 << endl;
    return 0;
}