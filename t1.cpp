
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