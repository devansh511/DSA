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
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}
int toint(string s){return atoi(s.c_str());}
ll toll(string s){return atoll(s.c_str());}
ll poww(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1) ans = (ans * a);
        a = (a * a);
        b >>= 1;
    }
    return ans;
}
ll btod(string s)
{
    ll res = 0, c = 0;
    for(ll i = s.length() - 1;i >= 0; i--)  res += poww(2, c++) * (s[i] - '0');
    return res;
}
string dtob(ll a)
{
    string ans;
    while(a)
    {
        string t = to_string(a % 2);
        ans += t[0];
        a >>= 1;
    }
    reverse(all(ans));
    return ans;
}

int32_t main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    int n = btod("10011"), m = btod("11010");
    cout << m << ' ' << n;
    // cout << (m % n);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}