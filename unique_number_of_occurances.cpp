#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurances(vector<int>& nums);

int main()
{
    vector<int>nums = {-3,0,1,-3,1,1,1,-3,10,0};
    cout<<uniqueOccurances(nums)<<endl;

    return 0;
}


bool uniqueOccurances(vector<int>& nums)
{
    map<int,int>mp;

    for(auto i=nums.begin();i!=nums.end();i++)
    {
        if(mp.find(*i) != mp.end())
        {
            mp[*i]++;
        }
        else{
            mp[*i] = 1;
        }
    }

    set<int>number;
    set<int>occurance;

    for(auto i = mp.begin();i!=mp.end();i++)
    {
        number.insert(i->first);
        occurance.insert(i->second);
    }

    return number.size() == occurance.size();
}
