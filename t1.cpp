/*
//t1
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

*/

// t2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int val;
    cin >> val;
    vector<int> arr(val, 0), pre_sum(val + 1, 0), s_pre_sum(val + 1, 0);
    for (int i = 0; i < val; ++i)
        cin >> arr[i];
    vector<int> s_arr(arr);
    sort(s_arr.begin(), s_arr.end());
    for (int i = 1; i <= val; ++i)
    {
        pre_sum[i] = pre_sum[i - 1] + arr[i - 1];
        s_pre_sum[i] = s_pre_sum[i - 1] + s_arr[i - 1];
    }

    int res = 0;
    for (int i = 0; i < val - res; ++i)
        for (int j = i + 1; j < val; ++j)
            if (s_pre_sum[j + 1] - s_pre_sum[i] == pre_sum[j + 1] - pre_sum[i])
                if (*max_element(arr.begin() + i, arr.begin() + j + 1) -*min_element(arr.begin() + i, arr.begin() + j + 1) == j - i)
                    res = max(res, j - i + 1);
    cout << res << endl;
    return 0;
}