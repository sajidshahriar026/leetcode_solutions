#include<bits/stdc++.h>
using namespace std;

vector<int>successfulPairs(vector<int>& spells, vector<int>& potions, long long success);
int getLeastPotionStrength(int spell, long long success);

vector<int>sucessfulPairsAlternateSolutions(vector<int>& spells, vector<int>& potions, long long success);


int main()
{
    vector<int>spells{3,1,2};
    vector<int>potions{8,5,8};
    long long success = 16;
//    int spell = 34914;
//    cout<<getLeastPotionStrength(spell, success);
//    cout<<success;

    vector<int>successful = successfulPairs(spells, potions, success);

    for(auto it = successful.begin();it!= successful.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;

    return 0;
}


vector<int>successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    sort(potions.begin(), potions.end());

    vector<int>pairs ;

    int lengthOfPotions = potions.size() - 1;


    for(auto it = spells.begin();it != spells.end();it++)
    {
        int leastStrength = getLeastPotionStrength(*it, success);

        int index = lower_bound(potions.begin(), potions.end(), leastStrength) - potions.begin();

        int number = lengthOfPotions - index + 1;

        pairs.push_back(number);
    }

    return pairs;

}

int getLeastPotionStrength(int spell, long long success)
{
    int leastStrength = success / spell;

    leastStrength = (success % spell) ? leastStrength + 1 : leastStrength;

    return leastStrength;
}


vector<int>sucessfulPairsAlternateSolutions(vector<int>& spells, vector<int>& potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int>pairs;

    for(auto it = spells.begin();it!=spells.end();it++)
    {
        int result = potions.end() - upper_bound(potions.begin(),potions.end(), (long long)ceil((success * 1.0)/(*it))-1);

        pairs.push_back(result);

    }
    return pairs;
}
