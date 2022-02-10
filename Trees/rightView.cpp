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

    node(int val) {
        data = val;
        left = right = NULL;
    }
};
typedef struct node node;

void rightView(node* root) {
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0;i < n;i++) {
            node* fnt = q.front();
            q.pop();
            
            if(i == n - 1){
                cout << fnt->data << " ";
            }   
            if(fnt->left)
                q.push(fnt->left);
            if(fnt->right)
                q.push(fnt->right);
       }

    }

}

void leftView(node* root) {
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0;i < n;i++) {
            node* fnt = q.front();
            q.pop();
            
            if(i == 0){
                cout << fnt->data << " ";
            }   
            if(fnt->left)
                q.push(fnt->left);
            if(fnt->right)
                q.push(fnt->right);
       }

    }

}

int main() 
{
    OJ;
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(69);
    root->left->right = new node(9);
    root->right->left = new node(7);
    root->right->right = new node(3);
    root->left->left->left = new node(16);
    root->left->left->right = new node(10);
    root->right->left->left = new node(25);
    root->right->left->right = new node(32);
    rightView(root);
    cout << endl;
    leftView(root);
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