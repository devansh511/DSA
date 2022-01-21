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
    int val;
    struct Node* next;
    Node(int value)
    {
        val = value;
        next = NULL;
    }
};

typedef struct Node Node;

// Recursive Method
Node* reverseListRecursive(Node* head)
{
    if(!head || !head->next)
        return head;
    Node* nxt = reverseListRecursive(head->next);
    Node* newNext = head->next;
    newNext->next = head;
    head->next = NULL;
    return nxt;
}


// Iterative Method
Node* reverseListIterative(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL, *curr = head;
    while(curr != NULL)
    {
        Node* t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    return prev;
}

int main() 
{
//#ifndef ONLINE_JUDGE
//    oj;
//#endif
//    clock_t tStart = clock();
    fio
    ll n;
    cin >> n;
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
    // tmp = reverseListRecursive(head);
    tmp = reverseListIterative(head);
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