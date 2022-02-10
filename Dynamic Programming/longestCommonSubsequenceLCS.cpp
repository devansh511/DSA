#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define f(i, n) for(ll i = 0;i < n;i++)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int LCaS(string a, string b, int n, int m){

	int dp[n + 1][m + 1];

	for(int i = 0;i <= n;i++)
		dp[i][0] = 0;
	
	for(int i = 1;i <= m;i++)
		dp[0][i] = 0;
		
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

int main() 
{
	clock_t tStart = clock();
	FIO
	OJ;
	ll t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		string rev_s;
		cin >> rev_s;
		cout << LCaS(s, rev_s, n, m);
		cout << endl;
	}
	printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;  
}