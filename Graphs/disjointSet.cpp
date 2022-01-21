#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vi;
typedef pair<long long, long long > pii;
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
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void yes(){cout << "YES";}
void no(){cout << "NO";}

vector<int> parent(100000, 0);
vector<int> rankNode(100000, 0);

void makeSet(int n)
{
    for(int i = 1;i < n;i++)
        parent[i] = i;
}
 
int findParent(int node)
{
    if(node == parent[node])
        return node;
    
    return parent[node] = findParent(parent[node]);
}

void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if(rankNode[u] < rankNode[v])
        parent[u] = v;
    else if(rankNode[v] < rankNode[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rankNode[u]++;
    }
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    ll n; cin >> n;
    makeSet(n);
    while(n--)
    {
        ll u, v; cin >> u >> v;
        unionSet(u, v);
    }
    // cout << parent[2];nl;
    // cout << parent[7];
    if(findParent(7) != findParent(3))
        cout << "Different Componenet";
    else 
        cout << "Same Component";
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}