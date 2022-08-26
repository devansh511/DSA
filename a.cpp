#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<time.h>
using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vi;
typedef pair<long long , long long> pii;
typedef unordered_map<long long, long long> um;
typedef map<long long, long long> om;
typedef priority_queue<long long> max_heap;
typedef priority_queue<long long, vector<long long>, greater<long long> > min_heap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define eb emplace_back
#define pb push_back
#define fi first
#define sc second
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fout(a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define init(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define pt(val) cout << #val << "->" << val << endl;
#define sz(a) int(a.size())
#define setBits(n) __builtin_popcount(n)
#define yes cout << "YES"
#define no cout << "NO"
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vi sieve(ll n){vector<bool> p(n+1, true);p[0]=p[1]=false;vi primes;for(ll i=2;i<=n;i++){if(p[i]){primes.push_back(i);for(ll j=i*i;j<=n;j+=i)p[j]=false;}}return primes;}
ll poww(ll a,ll b){ll ans=1;while(b){if(b&1)ans=(ans * a);a=(a*a);b>>=1;}return ans;}
ll powm(ll a,ll b,ll m){ll ans=1;while(b){if(b&1)ans=((ans%m)*(a%m))%m;a=((a%m)*(a%m))%m;b>>=1;}return ans;}
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
int toint(string s){return atoi(s.c_str());}
ll toll(string s){return atoll(s.c_str());}

void dfs(vi *adj, ll node, vector<bool>& vis, ll &nodes)
{
    vis[node] = true;
    nodes++;
    for(auto &i : adj[node])
    {
        if(!vis[i]) 
            dfs(adj, i, vis, nodes);
    }
}

int32_t main() 
{
    ll n; cin >> n;
    vi a(n);
    fin(a, n);
    vi adj[n + 1];cop
    f(i, n)
    {
        adj[a[i]].pb(i + 1);
    }
    vector<bool> vis(n + 1, false);
    ll mx = 0, c = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(a[i] == i) continue;
        if(!vis[i]) 
        {
            ll nodes = 0;
            dfs(adj, i, vis, nodes);
            mx = max(mx, nodes);
            c++;
        }
    }
    c == 1 ? cout << mx : cout << mx * 2;
    return 0;  
}   