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

struct node
{
    int u;
    int v;
    int wt;
    node(int f, int s, int w)
    {
        u = f;
        v = s;
        wt = w;
    }
};
// typedef struct node node;


int findParent(int node, vector<int> &parent)
{
    if(node == parent[node])
        return node;
    
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rankNode)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
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

bool cmp(node& a, node& b)
{
    return (a.wt < b.wt);
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
    clock_t tStart = clock();
    fio
    int n, m;
    cin >> n >> m; 
    vector<node> edges;
    for(int i = 0;i < n;i++)
    {
        int u, v, wt; cin >> u >> v >> wt;
        edges.pb(node(u, v, wt));
    }
    sort(all(edges), cmp);
    vector<int> parent(n), rankNode(n, 0);
    for(int i = 0;i < n;i++)
        parent[i] = i;
    int cost = 0;
    vector<pair<int, int> > mstSet;
    for(auto i : edges)
    {
        if(findParent(i.u, parent) != findParent(i.v, parent))
        {
            cost += i.wt;
            mstSet.pb({i.u, i.v});
            unionSet(i.u, i.v, parent, rankNode);
        }
    }
    cout << cost;nl;
    for(auto i : mstSet)
        cout << i.first << " - " << i.ss << endl;
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}