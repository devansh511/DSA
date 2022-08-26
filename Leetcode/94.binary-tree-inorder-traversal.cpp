/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
#define ull unsigned long long
#define mod 1000000007
#define nl cout << "\n"
#define to ->
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fop(a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define init(arr, val) memset(arr, val, sizeof(arr))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define pt(val) cout << #val << "->" << val << endl;
#define sz(a) int(a.size())
#define setBits(n) __builtin_popcount(n)
vi sieve(ll n){vector<bool> p(n+1, true);p[0]=p[1]=false;vi primes;for(ll i=2;i<=n;i++){if(p[i]){primes.push_back(i);for(ll j=i*i;j<=n;j+=i)p[j]=false;}}return primes;}
ll poww(ll a,ll b){ll ans=1;while(b){if(b&1)ans=(ans * a);a=(a*a);b>>=1;}return ans;}
ll powm(ll a,ll b,ll m){ll ans=1;while(b){if(b&1)ans=((ans%m)*(a%m))%m;a=((a%m)*(a%m))%m;b>>=1;}return ans;}
ll cceil(ll a, ll b){ return (a + b - 1) / b;}
int toint(string s){return atoi(s.c_str());}
ll toll(string s){return atoll(s.c_str());}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node = root;
        while(node)
        {
            if(!node->left) 
            {
                ans.push_back(node->val);
                node = node->right;
            }
            else
            {
                TreeNode* t = node->left;
                while(t->right && t->right != node) t = t->right;
                if(!t->right) t->right = node, node = node->left;
                else 
                {
                    ans.push_back(node->val);
                    t->right = nullptr;
                    node = node->right;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

