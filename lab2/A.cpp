#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
  
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e6 + 555;
const double PI = acos(-1.0);
struct Node
{
	Node * prev; 
	Node * next;
	int val;
	Node(int _val){
		val = _val;
		next = NULL;
		prev = NULL;
	}
};
Node * head, * tail;
int cnt = 0;
void push_back(int x){
	Node * n = new Node(x);
	if(cnt == 0){
		head = tail = n;
	}
	else{
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
	cnt++;
}
void push_front(int x){
	Node * n = new Node(x);
	if(cnt == 0){
		head = tail = n;
	}
	else{
		n->next = head;
		head->prev = n;
		head = n;
	}
	cnt++;
}
int mx(){
	Node * cur = head;
	int to = 0;
	while(cur != NULL){
		if(to > cur->val) to = cur->val;
		cur = cur->next;
	}
	return to;
}

void solve()
{
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		push_back(t);
	}
	int m, n;
	cin >> m >> n;
	int cnt = 0;
	Node * no = head;
	int a = 0, b = 0;
	while(no != NULL){
		cnt++;
		if(cnt == m) a = no->val;
		if(cnt == n) b = no->val;
		no = no->next;
	}
	no = head;
	cnt = 0;
	while(no != NULL){
		cnt++;
		if(cnt == m) no->val = b;
		else if(cnt == n) no->val = a;
		no = no->next;
	}
	no = head;
	while(no != NULL){
		cout << no->val << " ";
		no = no->next;
	}
}

  
int main()
{
    Red;
    solve();
    return 0;
}