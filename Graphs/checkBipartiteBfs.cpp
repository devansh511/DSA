#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long , long long> pii;
typedef unordered_map<long long, long long> um;
typedef map<long long, long long> om;
typedef priority_queue<long long> max_heap;
typedef priority_queue<long long, vector<long long>, greater<long long> > min_heap;

#define endl "\n"
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define eb emplace_back
#define pb push_back
#define fi first
#define sc second
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
#define pt(val) cout << #val << "->" << val << endl;
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

// Using BFS
bool isBipartiteBfs(vector<ll> adj[], vector<ll> &color, ll s)
{
    queue<ll> q;
    q.push(s);
    color[s] = 1;
    while(q.size())
    {
        ll node = q.front();
        q.pop();
        for(auto &i : adj[node])
        {
            if(color[i] == -1)
            {
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if(color[i] == color[node])
                return false;
        }
    }
    return true;
}


int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, m; // n -> No. of vertices, m -> No. of edges
	cin >> n >> m;
	vector<ll> adj[n + 1], DFS;
    vector<ll> color(n + 1, -1);
	for(ll i = 0;i < m;i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
    }
    for(ll i = 1;i <= n;i++)
    {
        if(color[i] == -1)
        {
            if(!isBipartiteBfs(adj, color, i))
            {
                cout << false;
                return 0;
            }        
        }
    }
    cout << true;
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}