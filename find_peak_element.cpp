#include<bits/stdc++.h>
using namespace std;


int findPeakElement(vector<int> &nums);

int main()
{

    vector<int> nums{1,2,3,1};
    cout<<findPeakElement(nums)<<endl;

    return 0;
}

int findPeakElement(vector<int> &nums)
{
    int high = nums.size() - 1;

    int low = 0;

    int ans = -1;


    while(high >= low)
    {
        int mid = low + (high - low) / 2;

        if(mid == 0 || nums[mid] > nums[mid-1])
        {
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < nums[mid - 1])
        {
            high = mid - 1;
        }

    }
    return ans;
}
