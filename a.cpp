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
#define setBits(n) __builtin_popcount(n)
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

ll fn(vi &a, ll ind, ll m1, ll m2, ll c1, ll c2, ll &ans, vector<vector<vector<int>>> &dp)
{
    if(ind == 0)
    {
        return max(m1 * a[ind], m2 * a[ind]);
    }
    if(dp[ind][c1][c2] != -1)
        return dp[ind][c1][c2];
    ll pehla = (m1 * a[ind]) + fn(a, ind - 1, m1, m2, c1 + a[ind], c2, ans, dp);
    ll doosra = (m2 * a[ind]) + fn(a, ind - 1, m1, m2, c1, c2 + a[ind], ans, dp);
    ans = min(ans, max(pehla, doosra));
    return (dp[ind][c1][c2] = ans);
}


void answer(ll);
int32_t main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll t, cases = 1;
    // cin >> t;
    t = 1;
    while(t--)
    {
        answer(cases++);
        nl;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}
void answer(ll cases)
{
    ll n, m, x, y, k, m1, m2;
    cin >> m1 >> m2 >> n;
    vi a(n);
    fin(i, a, n);
    ll ans = INT_MAX;
    // vector<vector<vector<ll>>> dp(n, vector<vector<ll> (100000, vector<ll>(100000, -1)));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(1001, vector<int>(1001, -1)));
    // cout << dp[0][1][1];
    // cout << 1;
    cout << fn(a, n-1, m1, m2, 0, 0, ans, dp);

//    cout << "Case #" << cases << ": " << ans;
}