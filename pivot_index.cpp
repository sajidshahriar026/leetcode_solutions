#include<bits/stdc++.h>
using namespace std;



int pivotIndex(vector<int>& nums);

int main()
{
    vector<int>nums = {2,1,-1};
    cout<<pivotIndex(nums);

    return 0;
}


int pivotIndex(vector<int>& nums)
{
    int length = nums.size();

    int sum = 0;

    vector<int>preSum;
    for(int i = 0;i<length;i++)
    {
        sum += nums[i];
        preSum.push_back(sum);
    }

    vector<int>postSum;
    postSum.assign(length,0);
    sum = 0;


    for(int i = length-1;i>=0;i--)
    {
        sum += nums[i];
        postSum[i] = sum;
    }

    for(int i=0;i<length;i++)
    {
        if((preSum[i] - nums[i]) == (postSum[i] - nums[i]))
        {
            return i;
        }
    }
    return -1;
}
