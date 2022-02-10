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
#define FF first
#define SS second
#define ll long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(i, a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fout(i, a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct node
{
    int data;
    struct node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;

    tree(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// typedef struct node node;
// typedef struct tree tree;
//a function to construct a Avl tree from a sorted linked list
tree* buildTree(node* head, node* tail)
{
    if(head == tail) return NULL;

    node* first = head;
    node* second = head;

    while(second != tail && second->next != tail)
    {
        first = first to next;
        second = second to next to next;
    }

    tree *root = new tree(first->data);

    root->left = buildTree(head, first);
    root->right = buildTree(first to next, tail);

    return root;
}

void inorder(tree* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() 
{
    //clock_t tStart = clock();
    FIO
    OJ;
    node *head = NULL;
    node *ele;
    int n;
    cin >> n;
    while(n--)
    {
        int tmp; 
        cin >> tmp;
        if(head == NULL) 
        {
            head = new node(tmp);
            ele = head;
        }
        else
        {
            node *newNode = new node(tmp);
            ele->next = newNode;
            ele = newNode;
        }
    }
    tree *root = buildTree(head, NULL);
    inorder(root);
    //printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;  
}