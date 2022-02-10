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

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

typedef struct node node;

int height(node* root) {
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int diameter(node* root, int* ht) {
    if(root == NULL) 
        return 0;
    
    int lh = 0, rh = 0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);
    *ht = max(lh, rh) + 1;

    int currDiameter = lh + rh + 1;
    return max(currDiameter, max(ld, rd));
}

int main() 
{
    // OJ;
    node* root = new node(15);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(69);
    root->left->right = new node(9);
    root->right->left = new node(7);
    root->right->right = new node(3);
    // root->left->left->left = new node(16);
    // root->left->left->right = new node(10);
    // root->right->left->left = new node(25);
    // root->right->left->right = new node(32);
    int ht = 0;
    cout << "Height of the tree = " << height(root) << endl << "Diameter = " << diameter(root, &ht) << endl;
    return 0;  
}
/*
        5
      /    \
    4       6
   / \     / \ 
  69  9   7   3
 /  \    / \
16   10 25  32

*/