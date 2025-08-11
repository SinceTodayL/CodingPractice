#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i + 1 << " " << i << " ";
        }
        cout << endl;
    }
    return 0;
}
