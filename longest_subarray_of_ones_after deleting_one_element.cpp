#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums);

int main()
{
    vector<int>nums = {1,1,1};
    cout<<longestSubarray(nums);
    return 0;
}


int longestSubarray(vector<int>& nums)
{
    int length = nums.size();

    int left = 0;
    int right = 0;

    int cnt = 0;
    int maxCount = INT_MIN;
    int zeroCount = 0;

    while(right<length)
    {
        if(zeroCount < 1)
        {
            if(nums[right] == 0)
            {
                zeroCount++;
            }
            cnt++;
            right++;

            maxCount = (cnt > maxCount) ? cnt : maxCount;
        }
        else
        {
            if(nums[right] == 1)
            {
                cnt++;
                right++;
            }
            else
            {
                if(nums[left] == 0)
                {
                    zeroCount--;
                }
                cnt--;
                left++;
            }

            maxCount = (cnt > maxCount) ? cnt : maxCount;

        }
    }

    return maxCount-1;
}
