#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars);

int main()
{
    vector<char> chars = {'a','a','b','b','b','b','c','c','c'};
    cout<<compress(chars);

    return 0;

}

int compress(vector<char>& chars)
{
    int length = chars.size();

    string comString;

    int c = 1;
    char uc =chars[0];

    for(int i = 1;i<length;i++)
    {
        if(uc == chars[i])
        {
            c++;
        }
        else if(uc!=chars[i])
        {
            comString.push_back(uc);
            if(c>1)
            {
                comString+= to_string(c);
            }
            uc = chars[i];
            c=1;
        }
    }

    comString.push_back(uc);
    if(c>1)
    {
        comString+= to_string(c);
    }

    chars.erase(chars.begin(),chars.end());

    for(auto si=comString.begin();si!=comString.end();si++)
    {
        chars.push_back(*si);
    }

    return comString.length();
}
