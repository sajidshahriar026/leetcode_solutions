#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h);

long long getTotalTime(vector<int> &piles, int eatingSpeed);

int main()
{
    vector<int> piles{30,11,23,4,20};
    int h = 5;

    cout<<minEatingSpeed(piles, h)<<endl;
    return 0;
}


int minEatingSpeed(vector<int> &piles, int h)
{

    int maxBanana = *max_element(piles.begin(), piles.end());

    int minBanana = 1;

    int ans = -1;

    while(maxBanana >= minBanana)
    {
        int mid = minBanana + (maxBanana - minBanana) / 2;

        long long totalTime = getTotalTime(piles, mid);

//        cout<<"mid: "<<mid<<" totalTime: "<<totalTime<<" maxBanana: "<<maxBanana<<" minBanana: "<<minBanana<<endl;



        if(totalTime <= h)
        {
            ans = mid;
            maxBanana = mid - 1;
        }
        else
        {
            minBanana = mid + 1;
        }


    }
    return ans;
}


long long getTotalTime(vector<int> &piles, int eatingSpeed)
{
    long long totalTime = 0;

    for(auto it = piles.begin(); it != piles.end(); it++)
    {
        int time = (int)ceil((*it * 1.0)/eatingSpeed);
        totalTime += (long long)time;
    }

    return totalTime;
}
