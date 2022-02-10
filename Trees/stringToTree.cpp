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

int start = 0;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node *constructTree(string s)
{
    if(start >= s.length()) return NULL;

    bool negative = false;

    if(s[start] == '-') negative = true;

    int num = 0;
    while(start < s.length() && isdigit(s[start]))
    {
        num = num * 10 + (s[start] - '0');
        start++;
    }
    if(negative) num = -num;

    node *root = new node(num);

    if(start >= s.length()) return root;

    if(start < s.length() && s[start] == '(')
    {
        start++;
        root->left = constructTree(s);
    }

    if(start < s.length() && s[start] == ')')
    {
        start++;
        return root;
    }

    if(start < s.length() && s[start] == '(')
    {
        start++;
        root->right = constructTree(s);
    }

    if(start < s.length() && s[start] == ')')
    {
        start++;
        return root;
    }
    return root;
}
void inorder(node* root){
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
    node *root = constructTree("5(3(1)(4))(9(6)(23))");
    inorder(root);
    //printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;  
}