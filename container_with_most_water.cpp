#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height);

int main()
{
    vector<int>height = {1,1};
    cout<<maxArea(height)<<endl;
    return 0;
}


int maxArea(vector<int>& height)
{
    int length = height.size();
    int left = 0;
    int right = length-1;

    int area = INT_MIN;

    while(left<right)
    {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int w = right-left;

        int t = w * h;

        if(t > area)
        {
            area = t;
        }

        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return area;
}
