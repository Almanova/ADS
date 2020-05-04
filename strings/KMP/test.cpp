#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int l=0, r=-1;
    vector<vector<int> > p(2,vector<int>(n,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
        for(int i=0;i<n;i++)
        {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            while(i-p[z][i]-1>=0 && i+p[z][i]+1-!z<n && s[i-p[z][i]-1]==s[i+p[z][i]+1-!z]) p[z][i]++;
            if(i+p[z][i]-!z>r) {
                l=i-p[z][i];
                r=i+p[z][i]-!z;
            }
        }
    }
    for (int i = 0; i < n; i++) 
        cout << p[0][i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << p[1][i] << " ";
}

// #include <bits/stdc++.h>
// using namespace std;
// #define SIZE 100000 + 1

// int P[SIZE * 2];

// // Transform S into new string with special characters inserted.
// string convertToNewString(const string &s) {
//     string newString = "@";

//     for (int i = 0; i < s.size(); i++) {
//         newString += "#" + s.substr(i, 1);
//     }

//     newString += "#$";
//     return newString;
// }

// string longestPalindromeSubstring(const string &s) {
//     string Q = convertToNewString(s);
//     int c = 0, r = 0;                // current center, right limit

//     for (int i = 1; i < Q.size() - 1; i++) {
//         // find the corresponding letter in the palidrome subString
//         int iMirror = c - (i - c);

//         if(r > i) {
//             P[i] = min(r - i, P[iMirror]);
//         }

//         // expanding around center i
//         while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
//             P[i]++;
//         }

//         // Update c,r in case if the palindrome centered at i expands past r,
//         if (i + P[i] > r) {
//             c = i;              // next center = i
//             r = i + P[i];
//         }
//     }

//     // Find the longest palindrome length in p.

//     int maxPalindrome = 0;
//     int centerIndex = 0;

//     for (int i = 1; i < Q.size() - 1; i++) {

//         if (P[i] > maxPalindrome) {
//             maxPalindrome = P[i];
//             centerIndex = i;
//         }
//     }

//     cout << maxPalindrome << "\n";
//     return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
// }

// int main() {
//     string s = "abbaxyzyx";
//     cout << longestPalindromeSubstring(s);
//     return 0;
// }