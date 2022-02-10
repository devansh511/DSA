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

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

typedef struct node node;
queue<node*> q;
void levelOrder(node* root) {
    if(root == NULL)
        return;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* ele = q.front();
         q.pop();
        if(ele != NULL){
            cout << ele->data << " ";
            if(ele->left != NULL){
                q.push(ele->left);
            }
            if(ele->right != NULL) {
                q.push(ele->right);
            }
        }
        else if(!q.empty()){
            
            q.push(NULL);
            cout << endl;
        }

    }
}

//Diagonal Traversal
vector<int> diagonal(node *root)
{
   // your code here
   vector<int> ans;
   if(!root) return ans;
   node* curr = root;
   deque<node*> q;

   while(curr)
   {
       ans.push_back(curr->data);

       if(curr->left) q.push_front(curr->left);

       if(curr->right) curr = curr->right;
       else
       {
            if(q.size())
            {
                curr = q.back();
                q.pop_back();
            }
            else break;
       }
   }
   return ans;
}

//Sum at kth level
int sumAtKthLevel(node* root, int k) {
    if(root == NULL) {
        return -1;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0, sum = 0;
    while(!q.empty()) {
        node* ele = q.front();
        q.pop();
        if(ele != NULL) {
            if(level == k)
                sum += ele->data;
            if(ele->left != NULL) 
                q.push(ele->left);
            if(ele->right != NULL) 
                q.push(ele->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main() 
{
    OJ;
    node* root = new node(5);
    root->left = new node(2);
    root->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(10);
    root->left->right = new node(3);
    root->right->right->left = new node(8);
    // levelOrder(root);
    // cout << endl;
    // cout << sumAtKthLevel(root, 2);
    vector<int> ans = diagonal(root);
    for(auto i : ans) cout << i << " ";
    return 0;  
}