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
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

void answer(ll);
int32_t main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll t, cases = 1;
    cin >> t;
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
    ll n, m, x, y, k;
    cin >> n;
    vi a(n);
    fin(i, a, n);
    sort(all(a));
    f(i, n) a[i] = a[n - 1] - a[i];
    // fout(i, a, n);nl;
    ll ans = 0, start = 1, prev = 0;
    f(i, n)
    {
        if(a[i])
        {
            a[i] += prev;
            if((a[i] % 3) == 0) ans += (a[i] / 3) * 2, prev = 0;
            else
            {
                ll rem = a[i] % 3;
                if(a[i] > 2) ans += ((a[i] / 3) * 2);
                prev = a[i] % 3;
                // if(start == 1)
                // {
                //     // if(rem == 1) start = 1, prev = 1;
                //     // else prev = 2, start = 1;
                //     prev = rem;
                // } 
                // else
                // {
                //     if(rem == 2) start = 1, prev = 2;
                //     else prev = 1, start = 2;
                // }
            }
        }
        else break;
        // pt(ans);
        // pt(prev);
        // pt(start);
    }
    // cout << ans;
    if(prev >= 3)
    {
        ans += (prev / 3) * 2;
        ll rem = prev % 3;
        if(rem == 1) ans++;
        else if(rem == 2) ans += 2;
    }
    else if(prev == 1) ans++;
    else if(prev == 2) ans += 2;
    cout << ans; 
//    cout << "Case #" << cases << ": " << ans;
}   