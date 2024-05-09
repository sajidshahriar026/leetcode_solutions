#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums);


int main()
{
    vector<int>nums = {2,1,5,0,4,6};
    cout<<increasingTriplet(nums)<<endl;
}

bool increasingTriplet(vector<int>& nums)
{
    int minOne = INT_MAX;
    int minTwo = INT_MAX;

    vector<int>::iterator it;

    for(it=nums.begin();it!=nums.end();it++)
    {
        if(*it<minOne)
        {
            minOne = *it;
        }
        if(*it>minOne)
        {
            minTwo = (*it < minTwo) ? *it : minTwo;
        }
        if(*it>minTwo)
        {
            return true;
        }
    }
    return false;
}
