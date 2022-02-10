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

struct Node 
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie 
{
    private:
        Node* root;
    public: 
        Trie()
        {
            root = new Node();
        }

        void insert(string word)
        {
            Node* node = root;
            for(ll i = 0; i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    node->put(word[i], new Node());
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        bool search(string word)
        {
            Node* node = root;
            for(ll i = 0; i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    return false;
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        bool startsWith(string word)
        {
            Node* node = root;
            for(ll i = 0; i < word.length(); i++)
            {
                if(!node->containsKey(word[i]))
                    return false;
                node = node->get(word[i]);
            }
            return true;
        }
};

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("apps");
    obj->insert("apxl");
    obj->insert("bat");
    obj->insert("bac");
    cout << obj->search("apple");nl;
    cout << obj->startsWith("ap");nl;
    cout << obj->search("de");nl;
    cout << obj->startsWith("bd");
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}