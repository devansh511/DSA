// To count # of subsets in an array whose difference is given.
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

ll countSubsetWithGivenDiff(vi a, ll diff)
{
    ll n = a.size(), sum = 0;
    for(ll i : a)
        sum += i;
    ll s1 = (diff + sum) / 2;
    ll dp[n + 1][s1 + 1];
    for(ll i = 0;i <= n;i++)
        dp[i][0] = 1;
    for(ll j = 1;j <= s1;j++)
        dp[0][j] = 0;
    for(ll i = 1;i <= n;i++)
    {
        for(ll j = 1;j <= s1;j++)
        {
            if(a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][s1];
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, diff; cin >> n >> diff;
    vi a(n, 0);
    for(ll i = 0;i < n;i++)
        cin >> a[i];
    cout << countSubsetWithGivenDiff(a, diff);    
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}