#include<bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate);

int main()
{
    string senate = "RDD";
    cout<<predictPartyVictory(senate)<<endl;

    return 0;
}

string predictPartyVictory(string senate)
{
    int direCount = 0;
    int radiantCount = 0;
    int bannedRadiant = 0;
    int bannedDire = 0;

    queue<char>q;

    for(auto i=senate.begin();i!=senate.end();i++)
    {
        q.push(*i);
        if(*i == 'R')
        {
            radiantCount++;
        }
        else
        {
            direCount++;

        }
    }

    while(radiantCount != 0 && direCount != 0)
    {
        char c = q.front();
        q.pop();

        if(c == 'R')
        {
            if(!bannedRadiant)
            {
                direCount--;
                bannedDire++;
                q.push(c);
            }
            else
            {
                bannedRadiant--;
            }
        }
        else
        {
            if(!bannedDire)
            {
                radiantCount--;
                bannedRadiant++;
                q.push(c);
            }
            else
            {
                bannedDire--;
            }
        }
    }

    return (radiantCount > direCount) ? "Radiant" : "Dire";


}
