#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <unordered_map>

using namespace std;

int prefixSum[1000000];

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    for (int i = 0;i < n;i ++) {
        int x = 0;
        if(s[i] == '1') x = 1;
        
        if(i == 0){
            prefixSum[i] = x;
        }else{
            prefixSum[i] = x + prefixSum[i - 1];
        }
    }


    int l = 0;
    int r = n - 1;
    double ans = 0.0;

    while(r - l + 1 >= k){
        double ones = prefixSum[r];
        if(l != 0){
            ones -= prefixSum[l - 1];
        }
    
        ans = max(ans, ones / (r - l + 1));

        if(prefixSum[r] - prefixSum[l] > prefixSum[r - 1] - prefixSum[l - 1]){
            l ++;
        }else{
            r --;
        }
    }

    cout << ans;
    return 0;
}