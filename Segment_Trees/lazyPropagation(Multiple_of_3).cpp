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

struct node
{
    ll arr[3];
};

const ll maxN = 1e5;
node st[4 * maxN];
ll a[maxN], lazy[4 * maxN];

void build(ll si, ll ss, ll se)
{
    if(ss == se)
    {
        st[si].arr[0] = 1;
        st[si].arr[1] = 0;
        st[si].arr[2] = 0;
        return;
    }
    ll mid = ss + (se - ss) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si].arr[0] = st[2 * si].arr[0] + st[2 * si + 1].arr[0];
    st[si].arr[1] = st[2 * si].arr[1] + st[2 * si + 1].arr[1];
    st[si].arr[2] = st[2 * si].arr[2] + st[2 * si + 1].arr[2];
}

void shift(ll si)
{
    ll t = st[si].arr[2];
    st[si].arr[2] = st[si].arr[1];
    st[si].arr[1] = st[si].arr[0];
    st[si].arr[0] = t;
}

void update(ll si, ll ss, ll se, ll l, ll r)
{
    if(lazy[si])
    {
        ll add = lazy[si];
        lazy[si] = 0;
        if(ss != se)
            lazy[2 * si] += add, lazy[2 * si + 1] += add;
        
        add %= 3;
        f(i, add)
            shift(si);
    }
    if(l > se || r < ss)
        return;
    if(l <= ss && r >= se)
    {
        shift(si);
        if(ss != se)
            lazy[2 * si]++, lazy[2 * si + 1]++;
        return;
    }
    ll mid = ss + (se - ss) / 2;
    update(2 * si, ss, mid, l, r);
    update(2 * si + 1, mid + 1, se, l, r);
    st[si].arr[0] = st[2 * si].arr[0] + st[2 * si + 1].arr[0];
    st[si].arr[1] = st[2 * si].arr[1] + st[2 * si + 1].arr[1];
    st[si].arr[2] = st[2 * si].arr[2] + st[2 * si + 1].arr[2];
}

ll query(ll si, ll ss, ll se, ll l, ll r)
{
    if(lazy[si])
    {
        ll add = lazy[si];
        lazy[si] = 0;
        if(ss != se)
            lazy[2 * si] += add, lazy[2 * si + 1] += add;
        add %= 3;
        f(i, add)
            shift(si);
    }
    if(l > se || r < ss)
        return 0;
    
    if(l <= ss && r >= se)
        return st[si].arr[0];
    
    ll mid = ss + (se - ss) / 2;
    ll le = query(2 * si, ss, mid, l, r);
    ll ri = query(2 * si + 1, mid + 1, se, l, r);
    return le + ri;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, q; cin >> n >> q;
    build(1, 1, n);
    while(q--)
    {
        ll x, l, r;
        cin >> x >> l >> r;
        l++, r++;
        if(!x)
            update(1, 1, n, l, r);
        else
            cout << query(1, 1, n, l, r) << endl;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}