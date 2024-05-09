#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s);

int main()
{
    string s = "a good   example";

    cout<<reverseWords(s)<<endl;


    return 0;
}

string reverseWords(string s)
{
    string word;
    vector<string>words;

    for(int i=0;s[i];i++)
    {
        if(s[i] == ' ')
        {
            if (word.length() != 0)
            {
                words.push_back(word);
                word.clear();
            }
        }
        else{
            word.push_back(s[i]);
        }
    }

    if(word.length() != 0)
    {
        words.push_back(word);
    }

    int length = words.size();
    s.clear();

    for(int i = length-1;i > 0;i--)
    {
        s+=words[i] + ' ';
    }
    s +=words[0];

    return s;
}
