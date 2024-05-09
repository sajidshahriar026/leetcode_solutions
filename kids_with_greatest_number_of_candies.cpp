#include<bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

int main()
{

}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int maxCandies = *max_element(candies.begin(),candies.end());

    vector<bool>isMaxCandies;

    vector<int>::iterator it;

    for(it=candies.begin();it!=candies.end();it++)
    {
        if((*it + extraCandies) >= maxCandies)
        {
            isMaxCandies.push_back(true);
        }
        else
        {
            isMaxCandies.push_back(false);
        }
    }

    return isMaxCandies;
}
