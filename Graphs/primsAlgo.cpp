#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long, long long > pii;
#define endl "\n"
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(i, a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fout(i, a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define init(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void yes(){cout << "YES";}
void no(){cout << "NO";}

// Brute Force
void buildMstBrute(vector<pii> adj[], ll src, ll n)
{
    vector<ll> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    mst[src] = 1;
    key[src] = 0;
    
    for(ll j = 0; j < n - 1; j++) // n - 1 because we will have n - 1 edges in the MST so will traverse for n - 1 times
    {
        ll mn = INT_MAX, node = 0;
        for(ll i = 0; i < n; i++)
            if(key[i] < mn)
                mn = key[i], node = i;
        
        mst[node] = 1;
        for(auto &it : adj[node])
        {
            if(!mst[it.first] && it.second < key[it.first])
                parent[it.first] = node, key[it.first] = it.second;
        }
    }
     
    for(ll i = 1; i < n; i++)
        cout << parent[i] << '-' << i << "\n";
}

// Optimized
void buildMst(vector<pii> adj[], ll src, ll nodes)
{
    ll parent[nodes];
    ll weights[nodes];
    bool mst[nodes];
    memset(weights, mod, sizeof(weights));
    memset(mst, false, sizeof(mst));
    weights[src] = 0;
    parent[src] = -1;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 0});
    while(!pq.empty())
    {
        ll u = pq.top().ss;
        pq.pop();
        mst[u] = true;
        for(auto j : adj[u])
        {
            if((mst[j.ff] == false) && (j.ss < weights[j.ff]))
            {
                parent[j.ff] = u;
                weights[j.ff] = j.ss;
                pq.push({j.ss, j.ff});
            }
        }
    }
    for(ll i = 1;i < nodes;i++)
        cout << parent[i] << "->" << i << endl;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    ll n, m; cin >> n >> m;
    vector<pii> adj[n];
    for(ll i = 0; i < m;i++)
    {
        ll u, v, wt; 
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }
    buildMst(adj, 0LL, n);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}