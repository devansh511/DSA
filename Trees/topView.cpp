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

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
  public:
    // function should return the topView of the binary tree
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root)   return ans;
        queue<pair<Node*, int>> q;
        map<int, vector<int>> mp;
        mp.clear();
        int dist = 0;
        q.push(make_pair(root, dist));
        mp[dist].push_back(root->data);
        while(q.size())
        {
            Node *tmp = q.front().first;
            int d = q.front().second;
            q.pop();
            if(tmp->left) 
            {
                q.push(make_pair(tmp->left, d - 1));
                mp[d - 1].push_back(tmp->left->data);
            }
            if(tmp->right) 
            {
                q.push(make_pair(tmp->right, d + 1));
                mp[d + 1].push_back(tmp->right->data);
            }
        }
        for(auto i : mp)
        {
            //replace i.second[0] with i.second[i.second.size() - 1] to print the bottom view.
            ans.push_back(i.second[0]);
        }
        return ans;
    }

};

int main() 
{
    OJ;
    return 0;  
}