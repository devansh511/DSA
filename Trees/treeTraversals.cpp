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
vi preorder1, inorder1, postorder1;


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

//recursive
void preorder(node* root) {
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder1.PB(root->data);
    preorder(root->left);
    preorder(root->right);
}

//iterative
void preorderIter(node* root)
{
    if(!root)   return;
    stack<node*> s;
    s.push(root);

    while(s.size())
    {
        node* tmp = s.top();
        s.pop();

        cout << tmp->data << " ";

        if(tmp->right)
            s.push(tmp->right);
        if(tmp->left)
            s.push(tmp->left);

    }

}


//recursive
void inorder(node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder1.PB(root->data);
    inorder(root->right);
}

//iterative
void inorderIter(node* root)
{
    if(!root)   return;
    stack<node*> s;
    node* t = root;
    while(t || s.size())
    {
        if(t)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.top();
            s.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }

}

//recursive
void postorder(node* root) {
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    postorder1.PB(root->data);
}

//iterative
void postorderIter(node* root)
{
    if(!root)   return;
    stack<node*> s;
    stack<int> st;
    node* t = root;
    s.push(t);
    while(s.size())
    {
        t = s.top();
        st.push(t->data);
        s.pop();
        if(t->left)
            s.push(t->left);
        if(t->right)
            s.push(t->right);
    }

    while(st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int search1(vi inorder1, int lo, int hi, int data) {
    for(int i = lo;i <= hi;i++){
        if(inorder1[i] == data)
            return i;
    }
    return -1;
}

node* buildTreePre(vi preorder1, vi inorder1, int lo, int hi) {
    if(lo > hi)
        return NULL;
    static int idx = 0;
    int ele = preorder1[idx];
    idx++;
    node* curr = new node(ele);
    if(lo == hi){
        return curr;
    }
    int pos = search1(inorder1, lo, hi, ele);
    curr->left = buildTreePre(preorder1, inorder1, lo, pos - 1);
    curr->right = buildTreePre(preorder1, inorder1, pos + 1, hi);
    return curr;
}

node* buildTreePost(vi postorder1, vi inorder1, int lo, int hi) {
    if(lo > hi)
        return NULL;
    static int idx = hi;
    int ele = preorder1[idx];
    idx--;
    node* curr = new node(ele);
    if(lo == hi){
        return curr;
    }
    int pos = search1(inorder1, lo, hi, ele);
    curr->right = buildTreePre(preorder1, inorder1, pos + 1, hi);
    curr->left = buildTreePre(preorder1, inorder1, lo, pos - 1);
    return curr;
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
    preorder(root);
    cout << endl;
    preorderIter(root);
    cout << endl;
    inorder(root);
    cout << endl;
    inorderIter(root);
    cout << endl;
    postorder(root);
    cout << endl;
    postorderIter(root);
    cout << endl;
    node* root1 = buildTreePost(preorder1, inorder1, 0, 6);
    cout << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;  
}