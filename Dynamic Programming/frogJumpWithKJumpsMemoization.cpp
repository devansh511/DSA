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

ll frogJumpWithKJumps(vi &h, ll n, ll k, vi &dp)
{
    if(n == 1)
        return dp[n] = 0;

    if(dp[n] != -1)
        return dp[n];
    
    ll ans = INT_MAX;
    for(ll i = 1; i <= k; i++)
    {
        if(n - i > 0)
        {
            if(dp[n - i] != -1)
                ans = min(ans, dp[n - i] + abs(h[n - i - 1] - h[n - 1]));
            else 
                ans = min(ans, frogJumpWithKJumps(h, n - i, k, dp) + abs(h[n - i - 1] - h[n - 1]));
        }
    }
    return dp[n] = ans;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, k;
    cin >> n >> k;
    vi h(n, 0), dp(n + 1, -1);
    fin(i, h, n);
    cout << frogJumpWithKJumps(h, n, k, dp);
//#ifndef ONLINE_JUDG
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}