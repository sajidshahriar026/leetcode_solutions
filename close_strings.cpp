#include<bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2);


int main()
{
    string word1 = "aaabbbbccddeeeeefffff";
    string word2 = "aaaaabbcccdddeeeeffff";

    cout<<closeStrings(word1, word2);

    return 0;
}

bool closeStrings(string word1, string word2)
{
    if(word1.length() != word2.length())
    {
        return false;
    }
    else
    {
        map<char,int>occ1;
        map<char,int>occ2;

        for(auto i = word1.begin();i!=word1.end();i++)
        {
            if(occ1.find(*i)!=occ1.end())
            {
                occ1[*i]++;
            }
            else
            {
                occ1[*i] = 1;
            }
        }

        for(auto i = word2.begin();i!=word2.end();i++)
        {
            if(occ2.find(*i) != occ2.end())
            {
                occ2[*i]++;
            }
            else
            {
                occ2[*i] = 1;
            }
        }
        set<char>schar1;
        set<char>schar2;
        multiset<int>socc1;
        multiset<int>socc2;

        for(auto i = occ1.begin();i!=occ1.end();i++)
        {
            socc1.insert(i->second);
            schar1.insert(i->first);
        }
        for(auto i = occ2.begin();i!=occ2.end();i++)
        {
            socc2.insert(i->second);
            schar2.insert(i->first);
        }


        return (socc1 == socc2) && (schar1 == schar2);
    }
}
