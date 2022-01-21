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

void findMin(vi &arr, ll i, ll &mn)
{
    if(i == 0)
    {
        if(arr[i] > mn)
            mn = i;
        return;
    }
    if(mn < arr[i])
        mn = i;
    findMin(arr, i - 1, mn);
}

void sort(vi &arr, ll n)
{
    if(n == 1)
        return;
    ll mn = LLONG_MIN;
    findMin(arr, n - 1, mn);
    swap(arr[mn], arr[n - 1]);
    sort(arr, n - 1);
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    // fio
    ll n;
    cin >> n;
    vi a(n, 0);
    f(i, n)
        a[i] = rand();
    // fout(i, a, n);nl;
    clock_t tStart = clock();    
    sort(a, n);
    clock_t tEnd = clock();
    fout(i, a, n);
//#ifndef ONLINE_JUDGE
   printf("\nTime taken: %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}