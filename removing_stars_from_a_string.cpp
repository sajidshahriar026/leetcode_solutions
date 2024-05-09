#include<bits/stdc++.h>
using namespace std;

string removeStars(string s);


int main()
{
    string s = "erase*****";
    cout<<removeStars(s)<<endl;

    return 0;
}

string removeStars(string s)
{
    stack<char>chstack;

    for(auto i = s.begin();i != s.end(); i++)
    {
        if (*i != '*')
        {
            chstack.push(*i);
        }
        else
        {
            if (!chstack.empty())
            {
                chstack.pop();
            }
        }
    }

    s.clear();

    while(!chstack.empty())
    {
        s += chstack.top();
        chstack.pop();
    }

    reverse(s.begin(), s.end());

    return s;
}
