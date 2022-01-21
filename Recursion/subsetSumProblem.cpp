#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long , long long> pii;
typedef unordered_map<long long, long long> um;
typedef map<long long, long long> om;
typedef priority_queue<long long> max_heap;
typedef priority_queue<long long, vector<long long>, greater<long long> > min_heap;

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
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}


void printAllSubsets(vi a, vi &t, ll n, ll sum, ll &curr_sum, ll i)
{
    if(curr_sum > sum) // Only when array contains non negative numbers
        return;
    if(i == n)
    {
        if(curr_sum == sum)
        {
            fout(i, t, t.size());
            nl;
        }
        return;
    }
    // This will print subsets from starting.
    t.eb(a[i]);
    curr_sum += a[i];
    printAllSubsets(a, t, n, sum, curr_sum, i + 1);
    t.pop_back();
    curr_sum -= a[i];
    printAllSubsets(a, t, n, sum, curr_sum, i + 1);
}
bool printAnySubset(vi a, vi &t, ll n, ll sum, ll &curr_sum, ll i)
{
    if(curr_sum > sum) // Only when array contains non-negative numbers
        return 0;
    if(i == n)
    {
        if(sum == curr_sum)
            return true;
        else 
            return false; 
    }
    // This will print subset from last
    if(printAnySubset(a, t, n, sum, curr_sum, i + 1))
        return true;
    t.eb(a[i]);
    curr_sum += a[i];
    if(printAnySubset(a, t, n, sum, curr_sum, i + 1))
        return true;
    curr_sum -= a[i];
    t.pop_back();
    return false;
}

// Count number of subsequences
ll countSubsequences(vi a, ll n, ll sum, ll curr_sum, ll i, ll count)
{
    if(curr_sum > sum) // Works only when the array contains strictly non negative integers
        return 0;
    if(i == n)
    {
        if(curr_sum == sum)
            return 1;
        else 
            return 0;
    }
    return countSubsequences(a, n, sum, curr_sum + a[i], i + 1, count) + countSubsequences(a, n, sum, curr_sum, i + 1, count);
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, sum;
    cin >> n >> sum;
    vi a(n, 0), t;
    fin(i, a, n);
    // printAllSubsets(a, t, n, sum, curr_sum, 0);
    // if(printAnySubset(a, t, n, sum, curr_sum, 0))
    // {
    //     fout(i, t, t.size());
    // }
    // else 
    //     cout << "No subset found!";
    cout << countSubsequences(a, n, sum, 0, 0, 0);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}