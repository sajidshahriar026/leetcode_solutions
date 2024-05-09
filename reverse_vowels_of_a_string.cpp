#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s);

int main()
{
    string s = "leetcode";

    cout<<reverseVowels(s)<<endl;
}

string reverseVowels(string s)
{
    vector<char>cv;
    vector<int>pos;

    for(int i= 0;s[i];i++)
    {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cv.push_back(s[i]);
            pos.push_back(i);
        }

    }

    vector<char>::reverse_iterator ci;
    vector<int>::iterator it;

    for(ci=cv.rbegin(),it=pos.begin();ci!=cv.rend(),it!=pos.end();ci++,it++)
    {
        s[*it] = *ci;
    }
    return s;
}



