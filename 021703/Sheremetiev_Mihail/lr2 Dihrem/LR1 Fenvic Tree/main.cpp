#include <iostream>
#include <vector>
#define endl '\n'
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
const int N = 1e6;
long long t[N], a[N];
int n, k;
long long sum(int r)
{
    long long res = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

void update(int i, long long v)
{
    for (int j = i; j <= n; j = j | (j + 1))
    {
        t[j] += v;
    }
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif // _DEBUG
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'A')
        {
            update(l, r - a[l]);
            a[l] = r;
        }
        else {
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
}