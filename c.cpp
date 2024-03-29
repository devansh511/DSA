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
	ll n, m, x, y, k, H, M;
	cin >> n >> H >> M;
	vector<pii> a(n);
	f(i, n)
	{
		ll h, m; cin >> h >> m;
		a[i] = {(h - H + 24) % 24, m};
	}
	// sort(all(a));
	pii ans = {100, 100};
	f(i, n)
	{
		if(a[i].fi == 0 && a[i].sc < M) 
			ans = min(ans, {23, (a[i].sc - M + 60) % 60});
		else if(a[i].sc < M)
			ans = min(ans, {a[i].fi - 1, (a[i].sc - M + 60) % 60});
		else 
			ans = min(ans, {a[i].fi, a[i].sc - M});
	}
	cout << ans.fi << ' ' << ans.sc;
//    cout << "Case #" << cases << ": " << ans;
}