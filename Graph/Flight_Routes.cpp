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
    int n = si(), m = si(), k = si();

    vector<pair<int, int>> adj[n + 1];
    fn(i, m) adj[si()].pb({si(), si()});

    vector<multiset<int>> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1].insert(0);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > *dist[u].rbegin())
            continue;

        for (auto [v, w] : adj[u])
        {
            if (sz(dist[v]) < k)
            {
                dist[v].insert(d + w);
                pq.push({d + w, v});
            }
            else if (*dist[v].rbegin() > d + w)
            {
                dist[v].erase(prev(dist[v].end()));
                dist[v].insert(d + w);
                pq.push({d + w, v});
            }
        }
    }

    for (auto &x : dist[n])
        cout << x << " ";
    return 0;
}