#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout<<longestOnes(nums, k);

    return 0;
}


int longestOnes(vector<int>& nums, int k)
{
    int length = nums.size();

    int left = 0;
    int right = 0;
    int cnt = 0;
    int maxCount = INT_MIN;
    int flippedZeros = 0;


    while(right<length)
    {
        if(flippedZeros < k)
        {
            if(nums[right] == 0)
            {
                flippedZeros++;
            }
            cnt++;
            maxCount = (cnt > maxCount) ? cnt : maxCount;
            right++;

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
                    flippedZeros--;
                }
                cnt--;
                left++;
            }

            maxCount = (cnt > maxCount) ? cnt : maxCount;
        }
//        cout<<"count: "<<cnt<< " maxCount: "<<maxCount<<" flippedZeros: "<<flippedZeros<<" left index: "<<left<<" right index: "<<right<<endl;

    }



    return maxCount;
}
