#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums);



int main()
{
    vector<int>nums = {-1,1,0,-3,3};
    vector<int>product = productExceptSelf(nums);

    vector<int>::iterator i;

    for(i=product.begin();i!=product.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;
    return 0;
}


vector<int>productExceptSelf(vector<int>& nums)
{
    int length = nums.size();

    vector<int>product;

    int prefix = 1;

    product.push_back(prefix);

    for(int i = 1; i < length; i++)
    {
        prefix *=  nums[i-1];
        product.push_back(prefix);
    }

    int postfix = 1;

    for(int i = length-2;i>=0;i--)
    {
        postfix *= nums[i+1];
        product[i] *= postfix;
    }

    return product;
}


