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

void printBrides(vector<int> adj[], vector<int> &low, vector<int> &vis, vector<int> &tin, int timer, int parent, int node)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto j : adj[node])
    {
        if(j == parent)
            continue;
        
        if(!vis[j])
        {
            printBrides(adj, low, vis, tin, timer, node, j);
            low[node] = min(low[node], low[j]);
            if(low[j] > tin[node])
                cout << node << " - " << j << endl;
        }
        else
            low[node] = min(tin[j], low[node]);
    }
}
int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0;i < m;i++)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> low(n + 1, -1), vis(n + 1, 0), tin(n + 1, -1);
    int timer = 0;
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
            printBrides(adj, low, vis, tin, timer, -1, i);
    }
    printBrides(adj, low, vis, tin, timer, -1, 1);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}