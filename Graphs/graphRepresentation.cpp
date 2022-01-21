#include <bits/stdc++.h>
#include <time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long, long long> pii;
#define endl "\n"
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ll long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for (ll i = 0; i < n; i++)
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fin(i, a, n)for (ll i = 0; i < n; i++){cin >> a[i];}
#define fout(i, a, n) for (ll i = 0; i < n; i++){cout << a[i] << " ";}
#define init(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl;
#define oj freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void yes()
{
    cout << "YES";
}
void no() { cout << "NO"; }


vector<vector<pii>> createMatrix(ll n, ll m)
{
    vector<vector<pair<ll, ll>>> adj(n + 1, vector<pair<ll, ll>>(n + 1));
    //Initialize the adjacency matrix to zero
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            adj[i][j].first = 0;
            adj[i][j].second = 0;
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        // Input the two nodes
        cin >> u >> v;
        adj[u][v].first = 1;
        //If undirected also fill adj[v][u] = 1
        adj[v][u].first = 1;
        // Assign weights if you wish to assign
    }
    return adj;
}

void createList(ll n, ll m, vector<ll> *adj)
{
    for(ll i = 1;i <= m;i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //    oj;
    //#endif
    clock_t tStart = clock();
    fio
    ll n, m;
    //Input no. of nodes and edges resp
    cin >> n >> m;
    vector<vector<pii>> adjacenyMatrix = createMatrix(n, m);
    vector<ll> adjacenyList[n + 1];
    createList(n, m, adjacenyList);
    for(ll i = 1;i <= n;i++)
    {
        cout << i << "->";
        vector<ll> tmp = adjacenyList[i];
        for(ll j = 0;j < tmp.size();j++)
        {
            cout << tmp[j] << ' ' ;
        }
        nl;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << '(' << adjacenyMatrix[i][j].first << ' ' << adjacenyMatrix[i][j].second << ')' << ' ';
        }
        nl;
    }
#ifndef ONLINE_JUDGE
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}
