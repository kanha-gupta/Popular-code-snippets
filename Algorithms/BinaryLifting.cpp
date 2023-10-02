#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<ll> adj[200005];
ll MAX_BITS = 21;
ll table[200005][22];
ll level[200005];

void Build_Table(ll node, ll parent)
{
    table[node][0] = parent;
    if (parent != -1)
    {
        level[node] = level[parent] + 1;
    }
    for (int bit = 1; bit < MAX_BITS; bit++)
    {
        if (table[node][bit - 1] != -1)
        {
            table[node][bit] = table[table[node][bit - 1]][bit - 1];
        }
        else
        {
            table[node][bit] = -1;
        }
    }
    for (auto adjNode : adj[node])
    {
        if (adjNode != parent)
        {
            Build_Table(adjNode, node);
        }
    }
}
ll uplift(ll node, ll levels)
{
    for (int i = 20; i >= 0; i--)
    {
        if (node == -1 || levels == 0)
        {
            return node;
        }
        if (levels >= (1 << i))
        {
            levels -= (1 << i);
            node = table[node][i];
        }
    }
    return node;
}
ll LCA_BinarySearch(ll node1, ll node2) // O(Log(N) ^ 2)
{
    if (level[node1] < level[node2])
    {
        swap(node1, node2);
    }
    ll LevelsToUpLift = level[node1] - level[node2];
    node1 = uplift(node1, LevelsToUpLift);
    ll low = 0, high = level[node1];
    while (low < high)
    {
        ll mid = (low + high) / 2;
        ll Dummy_node1 = uplift(node1, mid);
        ll Dummy_node2 = uplift(node2, mid);
        if (Dummy_node1 == Dummy_node2)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return uplift(node1, low);
}
ll LCA(ll node1, ll node2) // Log(N)
{
    if (level[node1] < level[node2])
    {
        swap(node1, node2);
    }
    ll LevelsToUplift = level[node1] - level[node2];
    node1 = uplift(node1, LevelsToUplift);
    if (node1 == node2)
    {
        return node1;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (table[node1][i] != table[node2][i])
        {
            node1 = table[node1][i];
            node2 = table[node2][i];
        }
    }
    return uplift(node1, 1);
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    level[1] = 0;
    Build_Table(1, -1);
    while (q--)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        ll Ancestor = LCA(n1, n2);
        ll ans = level[n1] + level[n2] - 2 * level[Ancestor];
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
