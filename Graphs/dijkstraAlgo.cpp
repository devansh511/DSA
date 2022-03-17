//Dijkstra Algo
//It is used to find the shortest path between one source node and all the other nodes of a graph.

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
void shortestPath(vector<pii> adj[], ll src, vi dist)
{
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        ll node =  pq.top().ss;
        pq.pop();
        for(auto j : adj[node])
        {
            if(dist[j.ff] > dist[node] + j.ss)
            {
                dist[j.ff] = dist[node] + j.ss;
                pq.push({dist[j.ff], j.ff});
            }
        }
    }
    for(ll i = 1;i < dist.size();i++)
        cout << dist[i] <<' ';
}
int main()
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    ll n, m; cin >> n >> m;
    vector<pii> adj[n + 1];
    vi dist(n + 1, INT_MAX);
    for(ll i = 0; i < m;i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }
    shortestPath(adj, 1, dist);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;
}

