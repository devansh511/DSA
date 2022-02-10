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
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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
void yes(){cout << "YES";}
void no(){cout << "NO";}

ll st[400001], a[100005];
void buildSTree(ll idx, ll start, ll end)
{
    if(start == end)
    {
        st[idx] = a[start];
        return;
    }
    ll mid = start + ((end - start) / 2);
    buildSTree((2 * idx), start, mid);
    buildSTree((2 * idx) + 1, mid + 1, end);
    st[idx] = min(st[(2 * idx)], st[(2 * idx) + 1]);
}

// Minimum range query
ll answerQuery(ll idx, ll segStart, ll segEnd, ll qStart, ll qEnd)
{
    if(qEnd < segStart || qStart > segEnd)
        return 1000000000;
    if(segStart >= qStart && segEnd <= qEnd)
        return st[idx];
    ll mid = segStart + ((segEnd - segStart) / 2);
    ll left = answerQuery((2 * idx), segStart, mid, qStart, qEnd);
    ll right = answerQuery((2 * idx) + 1, mid + 1, segEnd, qStart, qEnd);
    return min(left, right);
}
int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    // fio
    ll n, q; 
    cin >> n;
    for(ll i = 1;i <= n;i++)
        cin >> a[i];
    // fout(i, a, n + 1);nl;
    buildSTree(1, 1, n);
    cin >> q;
    while(q--)
    {
        ll le, ri; cin >> le >> ri;
        cout << answerQuery(1, 1, n, le + 1, ri + 1);nl;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}