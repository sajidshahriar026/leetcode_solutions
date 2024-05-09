#include<bits/stdc++.h>
using namespace std;


void moveZeros(vector<int>& nums);

int main()
{
    vector<int>nums = {0};

    for(auto i = nums.begin();i != nums.end(); i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;
    moveZeros(nums);

    for(auto i = nums.begin();i != nums.end(); i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;


}

void moveZeros(vector<int>& nums)
{
//    int length = nums.size();
//
//    int zeroPosition;
//    int right = length-1;
//    int i = right;
//
//    while(i>=0)
//    {
//        if(nums[i] != 0)
//        {
//            i--;
//        }
//        else if(nums[i] == 0)
//        {
//            zeroPosition = i;
//            if(zeroPosition == right)
//            {
//                right--;
//            }
//            else if(zeroPosition != right)
//            {
//                while(zeroPosition < right)
//                {
//                    swap(nums[zeroPosition], nums[zeroPosition+1]);
//                    zeroPosition++;
//                }
//                right--;
//            }
//            i--;
//        }
//    }
//    return;

    int snowBallSize = 0;
    int length = nums.size();

    for(int i=0;i<length;i++)
    {
        if (nums[i] == 0)
        {
            snowBallSize++;
        }
        else if(snowBallSize>0)
        {
            int t = nums[i];
            nums[i] = 0;
            nums[i-snowBallSize] = t;
        }
    }

    return ;
}
