//To find minimum subset sum difference
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long , long long> pii;
typedef unordered_map<long long, long long> um;
typedef map<long long, long long> om;

#define endl "\n"
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define eb emplace_back
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
#define pt(val) cout << val << endl;
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

ll minSubsetDiff(vi a)
{
    ll n = a.size();
    ll sum = 0;
    for(ll i = 0;i < n;i++)
        sum += a[i];
    bool dp[n + 1][sum + 1];
    for(ll i = 0;i <= n;i++)
        dp[i][0] = true;
    for(ll j = 1;j <= sum;j++)
        dp[0][j] = false;
    for(ll i = 1;i <= n;i++)
    {
        for(ll j = 1;j <= sum;j++)
        {
            if(a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    vi possibleSum;
    for(ll i = 0; i <= sum;i++)
    {
        if(dp[n][i])
            possibleSum.eb(i);
    }
    ll i = 0, j = possibleSum.size() - 1, ans = LLONG_MAX;
    while(i < j)
        ans = min(ans, possibleSum[j--] - possibleSum[i++]);
    return ans;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n; cin >> n;
    vi a(n, 0);
    for(ll i = 0;i < n;i++)
        cin >> a[i];
    cout << minSubsetDiff(a);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}