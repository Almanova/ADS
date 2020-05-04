#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> 
#include <vector>
#include <map>
#include <set>
#include <queue>  
#include <stack> 
#include <limits.h> 
using namespace std; 
#define ss second
#define f first 
#define ll long long 
#define pb push_back
#define make_pair mp

const int mx = 1e5+100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int p, a;
  cin >> p >> a; 
  int lol = 100500;
  int tr = 0;

  while(a-min(a,tr)){
  //    cout << 2;
   while(p == max(p,a)) {
     p = p-a;
    }
    int pa = p;
    p = a;
    a = pa;
  }
  cout << p+a << endl;
    return 0;
}