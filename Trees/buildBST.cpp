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

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//build BST from preorder
node* buildBST(int preorder[], int *preorderIdx, int key, int min, int max, int n) {
    if(*preorderIdx >= n)   
        return NULL;
    node *root = NULL;
    if(key > min && key < max){
        root = new node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root to left = buildBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        } 
        if(*preorderIdx < n){
            root to right = buildBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }

    }
    return root;
}

void preorder(node *root){
    if(root == NULL)    
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root to right);
}

int main() 
{
    OJ;
    int arr[] = {2,1,3};
    int preorderIdx = 0;
    node *root = buildBST(arr, &preorderIdx, 2, INT_MIN, INT_MAX, 3);
    preorder(root);
    return 0;  
}