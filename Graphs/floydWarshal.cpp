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
#define MAX 1e9
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

void floydWarshall(vector<vi> &graph)
{
    int n = graph.size();
    vector<vi> dist = graph;
    vector<vi> pred(n, vi(n, MAX));

    for(int k = 0; k < n; k++)
    {
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
                if(dist[r][k] + dist[k][c] < dist[r][c])
                    dist[r][c] = dist[r][k] + dist[k][c], pred[r][c] = k;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == MAX)
                cout << "INF ";
            else 
                cout << dist[i][j] << ' ';
        }
        nl;
    }
    nl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(pred[i][j] == MAX)
                cout << "INF ";
            else 
                cout << pred[i][j] << ' ';
        }
        nl;
    }
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    int n;
    cin >> n;
    vector<vi> graph(n, vi(n, MAX));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    floydWarshall(graph);
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}