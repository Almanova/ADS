#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> q;
    string s;
    while (cin >> s)
    {
        if (s == "push")
        {
            int x;
            cin >> x;
            q.push(x);
            cout << "ok" << endl;
        }
        else if (s == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else 
                cout << "error" << endl;
        }
        else if (s == "front")
        {
            if (!q.empty())
                cout << q.front() << endl;
            else 
                cout << "error" << endl;
        }
        else if (s == "size")
        {
            cout << q.size() << endl;
        }
        else if (s == "clear")
        {
            while (!q.empty())
                q.pop();
            cout << "ok" << endl;
        }
        else if (s == "exit")
        {
            cout << "bye";
            break;
        }
    }
}