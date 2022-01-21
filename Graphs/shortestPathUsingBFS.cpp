//Shortest Path in a unweighted graph with unit weights

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
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void yes(){cout << "YES";}
void no(){cout << "NO";}

void shortestPath(vector<int> adj[], int src, vector<int> dist)
{
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto i : adj[node])
        {
            if(dist[i] > dist[node] + 1)
            {
               dist[i] = dist[node] + 1;
               q.push(i);
            }
        }
    }
    for(int i : dist)
        cout << i << ' ';
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    int n, m; cin >> n >> m;
    vector<int> adj[m];
    vector<int> dist(m, INT_MAX);
    for(int i = 0;i < n;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    shortestPath(adj, 0, dist);
#ifndef ONLINE_JUDGE
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
    return 0;  
}