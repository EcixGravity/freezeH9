/*
京东第三题
#include <vector>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void ming_q_sort(vector<int>&, vector<int>&, int, int, int, int);

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> k;
    vector<int> split_num(k, 0);
    for (int i = 0; i < k; ++i)
    {
        cin >> split_num[i];
    }
    sort(split_num.begin(), split_num.end());
    ming_q_sort(arr, split_num, 0, n - 1, 0, k - 1);
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}

void ming_q_sort(vector<int>& arr, vector<int>& split_num, int arr_l, int arr_r, int s_l, int s_r)
{
    if (arr_l == arr_r || s_r < 0 || s_l >= split_num.size() || s_l >= s_r)
        return;
    int mid = s_l + (s_r - s_l) / 2, k = arr_l, split_node = -1;
    for (int i = arr_l; i <= arr_r; ++i)
    {
        if (arr[i] < split_num[mid])
            std::swap(arr[i], arr[k++]);
        if (arr[i] == split_num[mid])
            split_node = i;
    }
    std::swap(arr[k], arr[split_node]);
    ming_q_sort(arr, split_num, arr_l, k - 1, s_l, mid - 1);
    ming_q_sort(arr, split_num, k + 1, arr_r, mid + 1, s_r);

}



    

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct pair_hash
{
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p)
    {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_set<pair<int, int>, pair_hash> us;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (arr[i] * arr[j] >= k && us.find(make_pair(arr[i], arr[j])) != us.end())
            {
                ++res;
                us.insert(make_pair(arr[i], arr[j]));
                us.insert(make_pair(arr[j], arr[i]));
            }
    }
    cout << res * 2 << endl;
    return 0;
}

string str;
    cin >> str;
    stringstream ss(str.c_str());
    vector<int> array;
    while (getline(ss, str, ' '))
        array.push_back(std::stoi(str));
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct s {
    int a : 30;
    int b : 2;
    char c : 7;
};
int main()
{

    cout << sizeof(s);
    return 0;
}