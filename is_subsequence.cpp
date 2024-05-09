#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t);

int main()
{
    string s = "axc";
    string t = "ahbgdcccc";

    cout<<isSubsequence(s,t)<<endl;
}

bool isSubsequence(string s, string t)
{
    int sl = s.size();
    int tl = t.size();

    int i,j = 0;

    for(i=0;i<tl;i++)
    {
        if(t[i] == s[j])
        {
            j++;
            if (j == sl)
            {
                return true;
            }
        }
    }

    return (j == sl);
}
