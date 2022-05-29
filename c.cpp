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
#define ull unsigned long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fop(a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define init(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define pt(val) cout << #val << "->" << val << endl;
#define setBits(n) __builtin_popcount(n)
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
int toint(string s){return atoi(s.c_str());}
ll toll(string s){return atoll(s.c_str());}
class Solution {
public:
    // double ff(double n)
    // {
    //     char str[40];
    //     sprintf(str, "%.2f", n);
    //     sscanf(str, "%f", &n);
    //     return n;
    // }
    string discountPrices(string s, int d) 
	{
        int n = s.size(), i = 0;
		string ans;
		while(i < n)
		{
			if(s[i] == ' ' && s[i + 1] == '$')
			{
				int j = i + 2;
                long long num = 0;
				string t;
				t += s[i];
				t += s[i + 1];
				while(j < n && s[j] != ' ' && isdigit(s[j]))
				{
                    long long ttt = s[j] - '0';
					num = num * 10LL + ttt;
					t += s[j++];
				}
				if(j == n || s[j] == ' ')
				{
					ans += ' ';
					ans += '$';
					double sub = (1.0 * (num * d)) / (1.0 * 100);
					double newp = 1.0 * (num) - sub;
					double fff = ceil(newp * 100.0) / 100.0;
                    string t = to_string(fff);
                    ans += t;
					// int k = 0;
					// while(k < t.size())
					// {
					// char cc = t[k];
					// if(cc == '.') break;
					// ans += cc;
					// k++;
					// }
					// ans += '.';
					// ans += t[k + 1];
					// ans += t[k + 2];
					i = j;
				}
            }
            else if(!i && i < n - 1 &&  s[i] == '$' && isdigit(s[i + 1]))
            {
                int j = i + 1;
                long long num = 0;
                string tt;
                tt += '$';
                while(j < n && s[j] != ' ' && isdigit(s[j]))
                {
                    long long ttt = s[j] - '0';
                    num = num * 10LL + ttt;
                    tt += s[j++];
                }
                if(j == n || s[j] == ' ')
                {
                    ans += '$';
                    double sub = (1.00 * (num * d)) / (1.00 * 100);
                    double newp = 1.00 * (num) - sub;
                    double fff = ceil(newp * 100.0) / 100.0;
                    string t = to_string(fff);
                    ans += t;
                    // int k = 0;
                    // while(k < t.size())
                    // {
                    //     char cc = t[k];
                    //     if(cc == '.') break;
                    //     ans += cc;
                    //     k++;
                    // }
                    // ans += '.';
                    // ans += t[k + 1];
                    // ans += t[k + 2];
                    i = j;
                }
                else ans += tt, i = j;
            }
			else ans += s[i++];
		}
		return ans;
    }
};