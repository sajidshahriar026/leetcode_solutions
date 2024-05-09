#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums,int k);

int main()
{
    vector<int>nums = {5};
    int k = 1;

    cout<<findMaxAverage(nums,k);

    return 0;
}

double findMaxAverage(vector<int>& nums, int k)
{
    int sum = 0;
    double avg;
    double maxAvg;

    int length = nums.size();


    for(int i = 0;i<k;i++)
    {
        sum += nums[i];
    }

    avg = (double)sum/(double)k;
    maxAvg = avg;


    int left = 0;
    int right = k;


    while(right < length)
    {
        sum = sum - nums[left] + nums[right];
        avg =(double)sum/(double)k;

        if(maxAvg < avg)
        {
            maxAvg = avg;
        }

        left++;
        right++;
    }

    return maxAvg;
}
