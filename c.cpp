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
#define setBits(n) __builtin_popcount(n)
#define oj \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// string a = to_string(num / 10), b = to_string(num % 10);
// char const *c = a.c_str(), *d = b.c_str();
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
void yes(){cout << "YES";}
void no(){cout << "NO";}

int32_t main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.length(), m = t.length();
    unordered_map<char, int> st;
    queue<char> q;
    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        if(st.find(c) != st.end())
        {
            cout << "New Language Error";
            return 0;
        }
        st.insert({c, i});
        q.push(c);
    }
    int j = 0;
    while(j < m)
    {
        int i = j, cnt = 0;
        bool flag = false;
        unordered_map<char, int> ans;
        while(j < m)
        {
            char c = t[i];
            if(c == ' ')
            {
                flag = true;
                cnt++;
                j++;
                continue;
            }
            if(!flag)
            {

            }
            else 
            {
                break;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        char c = t[i];
        if(c == ' ')
        {

        }
        if(st.find(c) != st.end())
            ans[c] += 1;
        else if(st.find(tolower(c)) != st.end())
            ans[tolower(c)] += 1;
        else if(st.find(toupper(c)) != st.end())
            ans[toupper(c)] += 1;
    }
    string res;
    while(!q.empty())
    {
        char c = q.front();
        q.pop();
        if(ans.find(c) != ans.end())
        {
            int cnt = ans[c];
            while(cnt--)
                res += c;
        }
    }
    cout << res;
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}
