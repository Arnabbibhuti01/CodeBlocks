#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        bool ok = false;
        int l = 0;
        int r = n - 1;
        while (r >= l)
        {
            int m = (l + r) / 2;
            if (x == v[m])
            {
                ok = true;
                break;
            }
            else if (x > v[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
