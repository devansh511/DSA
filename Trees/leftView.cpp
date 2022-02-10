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

void leftView(node* root) {

}

int main() 
{
    OJ;
    return 0;  
}