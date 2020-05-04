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
  string a,b;
  cin >> a >> b;
  if(a.size()<b.size()) 
    swap(a,b);
  int c = b.size(), d = a.size(); 

  if(a==b){
    cout << a;
    return 0;
  }
  if(c==d){
    cout << a << b;
    return 0;
  }
size_t found = a.find(b);
if (found!=string::npos){
  cout << a;
  return 0;
}
  for(int i=0; i<c; i++){
    if(a.substr(0,i+1)==b.substr(c-i-1, i+1)){
      cout << b.substr(0, c-i-1) << a << endl;
      return 0;
    }
    if(a.substr(d-i-1, i+1)==b.substr(0, i+1)){
          cout << a << b.substr(i+1, c-i-1) <<endl;
      return 0;
    }
  }
  
  cout << a << b << endl;;

    return 0;
}
