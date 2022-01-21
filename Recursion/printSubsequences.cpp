#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef vector<long long> vl;
typedef pair<long long , long long> pl;
typedef map<long long, long long> om;
typedef unordered_map<long long, long long> um;

#define mod 1000000007
#define endl "\n"
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define ll long long
#define nl cout << "\n"
#define f(i, n) for(ll i = 0;i < n;i++)
#define fo(i, k, n) for(ll i = k;i < n;i++)
#define fin(i, a, n) for(ll i = 0;i < n;i++){cin >> a[i];}
#define fout(i, a, n) for(ll i = 0;i < n;i++){cout << a[i] << " ";}
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll ceilval(ll x, ll y){ return (x + y - 1) / y;}
void Swap(ll &x, ll &y){x = x + y, y = x - y, x = x - y;}

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void reverse(){
        Node* current = head;
        Node* next = NULL, *prev = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->next;
            temp = temp->next;
        }
    }

    void push(int data){
        Node *temp = new Node(data);
        temp->data = data;
        head = temp;
    }
};

int main() 
{
    LinkedList list;
    list.push(20);
    list.push(4);
    list.push(15);
    list.push(85);

    cout << "Given linked list\n";
    list.print();

    list.reverse();

    cout << "\nReversed Linked list \n";
    list.print();
    return 0;
}