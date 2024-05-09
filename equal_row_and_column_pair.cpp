#include<bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid);

int main()
{
    vector<vector<int> > grids = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout<<equalPairs(grids);

    return 0;
}

int equalPairs(vector<vector<int>> & grids)
{
    int length = grids.size();

    map<vector<int>, int> rocc;
    map<vector<int>, int> cocc;

    int c=0;

    vector<int>rc;

    for(int row=0;row<length;row++)
    {
        rc.clear();

        for(int column=0;column<length;column++)
        {
            rc.push_back(grids[row][column]);
        }

        if(rocc.find(rc) != rocc.end())
        {
            rocc[rc]++;
        }
        else
        {
            rocc[rc] = 1;
        }
    }

    rc.clear();

    for(int column = 0;column<length;column++)
    {
        rc.clear();
        for(int row=0;row<length;row++)
        {
            rc.push_back(grids[row][column]);
        }

        if(cocc.find(rc)!=cocc.end())
        {
            cocc[rc]++;
        }
        else
        {
            cocc[rc] = 1;
        }
    }

    for(auto i=rocc.begin();i!=rocc.end();i++)
    {
        if(cocc.find(i->first) != cocc.end())
        {
            c += i->second * cocc[i->first];
        }
    }



    return c;
}
