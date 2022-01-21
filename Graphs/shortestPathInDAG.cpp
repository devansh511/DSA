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
#define FF first
#define SS second
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
    freopen("output.txt", "w", stdout)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void yes(){cout << "YES";}
void no(){cout << "NO";}

void toposort(vector<pii> adj[], vi &vis, stack<ll> &st, ll node)
{
    vis[node] = 1;
    for(auto j : adj[node])
    {
        if(!vis[j.first])
        {
            toposort(adj, vis, st, j.first);
        }
    }
    st.push(node);
}

void shortestPath(vector<pii> adj[], vi &dist, stack<ll> &st, ll src)
{
    dist[src] = 0;
    while(!st.empty())
    {
        ll node = st.top();
        st.pop();
        if(dist[node != INT_MAX])
        {
            for(auto j : adj[node])
            {
                if(dist[j.first] > dist[node] + j.second)
                    dist[j.first] = dist[node] + j.second;
            }
         }
    }
    f(i, dist.size())
        cout << dist[i] << ' ';
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    ll n, m;
    cin >> n >> m;
    vector<pii> adj[n];
    vi vis(n, 0), dist(n, INT_MAX);
    stack<ll> st;
    f(i, m)
    {
        ll u, v, wt; 
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    toposort(adj, vis, st, 0);
    shortestPath(adj, dist, st, 0);
#ifndef ONLINE_JUDGE
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
    return 0;
}