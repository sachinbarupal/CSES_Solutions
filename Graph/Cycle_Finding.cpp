#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define fn(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, n) for (int i = (a); i <= (n); ++i)
#define repI(i, a, n) for (int i = (a); i >= (n); ++i)
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)a.size())
#define N 1000010
inline int si()
{
    int a;
    cin >> a;
    return a;
}
inline char sc()
{
    char a;
    cin >> a;
    return a;
}

struct Edge
{
    int u, v, w;
};

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m + 1);

    fn(i, m)
    {
        edges[i].u = si();
        edges[i].v = si();
        edges[i].w = si();
    }

    vector<int> dist(n + 1, 0), par(n + 1, -1);
    int cycleStart = -1;
    fn(t, n)
    {
        fn(i, m)
        {
            auto [u, v, w] = edges[i];

            if (dist[u] + w < dist[v])
            {
                if (t == n - 1)
                {
                    cycleStart = v;
                }

                par[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }

    if (cycleStart == -1)
    {
        cout << "NO\n";
        return 0;
    }

    fn(i, n) cycleStart = par[cycleStart];
    vector<int> ans;
    int st = cycleStart;

    while (1)
    {
        ans.pb(st);
        st = par[st];
        if (st == cycleStart)
            break;
    }
    ans.pb(st);
    reverse(all(ans));
    cout << "YES\n";

    for (auto &x : ans)
        cout << x << " ";

    return 0;
}