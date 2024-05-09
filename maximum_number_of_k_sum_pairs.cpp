#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k);

int main()
{
    vector<int>nums = {3,1,3,4,3};
    int k = 6;
    cout<<maxOperations(nums,k);



    return 0;
}

int maxOperations(vector<int>& nums, int k)
{
    map<int,int>comPos;

    int length = nums.size();

    int op = 0;

    for(int i = 0;i<length;i++)
    {
        int complement = k - nums[i];
        //if the element is not the map,add it

        if(comPos.find(nums[i]) != comPos.end())
        {
            comPos[nums[i]]++;
        }
        else
        {
            comPos[nums[i]] = 1;
        }


        if(comPos.find(nums[i]) != comPos.end() && comPos.find(complement) != comPos.end())
        {
            if(complement!=nums[i])
            {
                if(comPos[nums[i]] > 0 && comPos[complement] > 0)
                {
                    op++;
                    comPos[nums[i]]--;
                    comPos[complement]--;
                }
            }
            else{
                if(comPos[nums[i]]>1)
                {
                    op++;
                    comPos[nums[i]] -= 2;
                }
            }



        }

//        cout<<"Map contents after iteration "<<i<<":"<<endl;
//        for(auto i = comPos.begin();i!=comPos.end();i++)
//        {
//            cout<<i->first<<' '<<i->second<<endl;
//        }
//
//        cout<<"Number of operations: "<<op<<endl;;


    }

    return op;
}
