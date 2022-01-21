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

struct Node{
    ll val;
    struct Node* next;
    Node(ll value)
    {
        val = value;
        next = NULL;
    }
};

// Iterative (Done by own)
Node *reverseKGroups(Node *head, ll k)
{ 
    Node *last = head, *prev = NULL, *curr = head, *nLast = head, *nHead = NULL;
    ll c = 0;
    while(curr != NULL)
    {
        if(c == k)
        {
            if(nHead == NULL)
                nHead = prev;
            else
            {
                prev->next = last;
                last = nLast;
            }
            nLast = curr;
            prev = NULL;
            c = 0;
        }
        else
        {
            Node* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
            c++;
        }
    }
    if(nHead == NULL) // This will happen when k == n
        nHead = prev;
    else 
        last->next = prev;
    return nHead;
}

// Recursive (Apna College wle channel se dekha)
Node *reverseKGroupsRecursive(Node* head, ll k)
{
    ll c = 0;
    Node *prev = NULL, *curr = head;
    while(curr != NULL && c < k)
    {
        Node *t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
        c++;
    }
    if(curr != NULL)
        head->next = reverseKGroupsRecursive(curr, k);
    
    return prev;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n, k;
    cin >> n >> k;
    Node *head, *prev;
    f(i, n)
    {
        ll a;
        cin >> a;
        Node* t = new Node(a);
        if(!i)
            head = t;
        else 
            prev->next = t;
        prev = t;
    }
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    nl;
    // tmp = reverseKGroups(head, k);
    tmp = reverseKGroupsRecursive(head, k); 
    while(tmp != NULL)
    while(tmp != NULL)
    {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
//#ifndef ONLINE_JUDGE
//    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//#endif
    return 0;  
}