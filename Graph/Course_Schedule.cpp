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
#ifndef ONLINE_JUDGE
#define Error(x...)                          \
    {                                        \
        cout << "(" << #x << ")" << " = ( "; \
        printIt(x);                          \
    }
#else
#define Error(x...) 42
#endif
template <typename T1>
void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2)
{
    cout << t1 << " , ";
    printIt(t2...);
}
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

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif
    int n = si(), m = si();

    vector<int> adj[n + 1];
    vector<int> inDeg(n + 1);
    fn(i, m)
    {
        int a = si(), b = si();
        adj[a].pb(b);
        inDeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!inDeg[i])
            q.push(i);

    vector<int> topo;

    while (!q.empty())
    {
        int a = q.front();
        q.pop();

        topo.pb(a);

        for (auto &b : adj[a])
        {
            inDeg[b]--;
            if (!inDeg[b])
                q.push(b);
        }
    }

    if ((int)topo.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto &x : topo)
        cout << x << " ";

    return 0;
}