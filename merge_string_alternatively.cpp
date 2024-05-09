#include<bits/stdc++.h>
using namespace std;


string mergeStringAlternatively(string s1, string s2);

int main()
{

}

string mergeStringAlternatively(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    string mergedString;

    string::iterator i1, i2;

    for(i1=s1.begin(),i2=s2.begin();i1!=s1.end() && i2!=s2.end();i1++,i2++)
    {
        mergedString.push_back(*i1);
        mergedString.push_back(*i2);
    }

    if(l1>l2)
    {
        for(;i1!=s1.end();i1++)
        {
            mergedString.push_back(*i1);
        }
    }
    else
    {
        for(;i2!=s2.end();i2++)
        {
            mergedString.push_back(*i2);
        }
    }

    return mergedString;

}
