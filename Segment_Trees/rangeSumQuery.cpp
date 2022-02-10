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

const ll maxN = 100005;
ll st[4 * maxN], lazy[4 * maxN], a[maxN];

void build(ll si, ll ss, ll se)
{
    if(ss == se)
    {
        st[si] = a[ss];
        return;
    }

    ll mid = ss + (se - ss) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si] = st[2 * si] + st[2 * si + 1];
}

void update(ll si, ll ss, ll se, ll l, ll r, ll val)
{
    if(lazy[si] != 0)
    {
        ll add = lazy[si];
        lazy[si] = 0;
        st[si] += (se - ss + 1) * add;
        if(ss != se)
            lazy[2 * si] += add, lazy[2 * si + 1] += add;
    }
    if(l > se || r < ss)
        return;
    if(ss >= l && se <= r)
    {
        ll add = (se - ss + 1) * val;
        st[si] += add;
        if(ss != se)
            lazy[2 * si] += val, lazy[2 * si + 1] += val;
        return; 
    }

    ll mid = ss + (se - ss) / 2;
    update(2 * si, ss, mid, l, r, val);
    update(2 * si + 1, mid + 1, se, l, r, val);
    st[si] = st[2 * si] + st[2 * si + 1];
}

ll querySum(ll si, ll ss, ll se, ll l, ll r)
{
    if(lazy[si] != 0)
    {
        ll add = lazy[si];
        lazy[si] = 0;
        st[si] += add * (se - ss + 1);
        if(ss != se)
            lazy[2 * si] += add, lazy[2 * si + 1] += add;
    }
    if(l > se || r < ss)
        return 0;
    if(l <= ss && r >= se)
        return st[si];
    
    ll mid = ss + (se - ss) / 2;
    return querySum(2 * si, ss, mid, l, r) + querySum(2 * si + 1, mid + 1, se, l, r);
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, q; cin >> n;
    fo(i, 1, n + 1)
        cin >> a[i];
    cin >> q;
    build(1, 1, n);
    while(q--)
    {
        ll x, l, r; cin >> x >> l >> r;
        if(!x)
        {
            ll val;
            cin >> val;
            update(1, 1, n, l, r, val);
        }
        else
            cout << querySum(1, 1, n, l, r) << endl;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}