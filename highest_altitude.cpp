#include<bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain);

int main()
{
    vector<int> gain = {-5,1,5,0,-7};

    cout<<largestAltitude(gain);

    return 0;
}


int largestAltitude(vector<int>& gain)
{
    int length = gain.size();

    int sum = 0;
    int maxAlt = sum;

    for(int i = 0;i<length;i++)
    {
        sum += gain[i];

        maxAlt = (sum > maxAlt) ? sum : maxAlt;
    }

    return maxAlt;
}

