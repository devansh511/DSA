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
#define mp make_pair
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
void yes(){cout << "YES";}
void no(){cout << "NO";}

const ll maxN = 1e5;
ll a[maxN];
vi st[4 * maxN];

void build(ll si, ll ss, ll se)
{
    if(ss == se)
    {
        st[si].eb(a[ss]);
        return;
    }
    ll mid = ss + (se - ss) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    ll i = 0, j = 0;
    while(i < st[2 * si].size() && j < st[2 * si + 1].size())
    {
        if(st[2 * si][i] <= st[2 * si + 1][j])
            st[si].eb(st[2 * si][i++]);
        else 
            st[si].eb(st[2 * si + 1][j++]);
    }
    
    while(i < st[2 * si].size())
        st[si].eb(st[2 * si][i++]);
        
    while(j < st[2 * si + 1].size())
        st[si].eb(st[2 * si + 1][j++]);
    
}

ll query(ll si, ll ss, ll se, ll l, ll r, ll k)
{
    if(l > se || r < ss)
        return 0;
    
    if(l <= ss && r >= se)
    {
        ll ans = st[si].end() - upper_bound(all(st[si]), k);
        return ans;
    }

    ll mid = ss + (se - ss) / 2;
    ll le = query(2 * si, ss, mid, l, r, k), ri = query(2 * si + 1, mid + 1, se, l, r, k);
    return le + ri;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, q; cin >> n;;
    fo(i, 1, n + 1)
        cin >> a[i];
    cin >> q;
    build(1, 1, n);
    while(q--)
    {
        ll l, r, k; cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}