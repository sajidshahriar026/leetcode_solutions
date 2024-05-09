#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>findDifference(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int>nums1 = {1,2,3,3};
    vector<int>nums2 = {1,1,2,2};

    vector<vector<int>>answer = findDifference(nums1, nums2);

    for(auto i = answer.begin();i!=answer.end();i++)
    {
        for(auto j = i->begin();j!= i->end();j++)
        {
            cout<< *j <<' ';
        }
        cout<<endl;
    }

}

vector<vector<int>>findDifference(vector<int>& nums1, vector<int>& nums2)
{
    map<int,pair<int,int>>dict;

    for(auto i=nums1.begin();i!=nums1.end();i++)
    {
        if(dict.find(*i)==dict.end())
        {
            dict[*i].first = 1;
            dict[*i].second = -1;
        }
    }

    for(auto i=nums2.begin();i!=nums2.end();i++)
    {
        if(dict.find(*i)!=dict.end())
        {
            dict[*i].second = 2;
        }
        else
        {
            dict[*i].first = -1;
            dict[*i].second = 2;
        }
    }

    vector<int>ans1;
    vector<int>ans2;

    for(auto i = dict.begin();i!=dict.end();i++)
    {
        if(i->second.first == 1 && i->second.second==-1)
        {
            ans1.push_back(i->first);
        }
        else if(i->second.first == -1 && i->second.second== 2)
        {
            ans2.push_back(i->first);
        }
    }

    vector<vector<int>> answer;
    answer.push_back(ans1);
    answer.push_back(ans2);

    return answer;
}
