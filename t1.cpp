#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int cur, m_val = -1, m_size = 0, pre_m = -1, pre_m_size = 0;
    while (cin >> cur)
    {
        if (m_val > cur)
            ++m_size;
        else
        {
            if (m_size > pre_m_size)
            {
                pre_m = m_val;
                pre_m_size = m_size;
            }
            m_size = 1;
            m_val = cur;
        }
    }
    if (cur == m_val)
    {
        if (pre_m_size > cur)
            cout << pre_m;
        else
            cout << pre_m;
    }
    else if (m_size > cur)
        cout << m_size;
    else
        cout << pre_m;
    return 0;
}