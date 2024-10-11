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
    fn(i, m) adj[si()].pb(si());

    vector<int> vis(n + 1), curr;
    vector<int> ans;
    function<bool(int)> f = [&](int u)
    {
        if (vis[u] == 2)
        {
            bool push = false;
            for (auto &node : curr)
            {
                if (node == u)
                    push = true;
                if (push)
                    ans.pb(node);
            }
            ans.pb(u);

            return true;
        }

        if (vis[u] == 1)
            return false;

        vis[u] = 2;
        curr.pb(u);
        for (auto &v : adj[u])
        {
            if (f(v))
                return true;
        }
        curr.pop_back();
        vis[u]--;

        return false;
    };

    rep(i, 1, n)
    {
        if (!vis[i] && f(i))
        {

            cout << sz(ans) << "\n";

            for (auto &x : ans)
                cout << x << " ";

            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}