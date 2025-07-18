#include<bits/stdc++.h>
using namespace std;

int numOfProvinces(vector<vector<int> > &isConnected);

void traverse(vector<vector<int> > &isConnected, int city, vector<bool> &visited);

int main()
{
    vector<vector<int> >isConnected = {{1,1,0},{1,1,0},{0,0,1}};

    cout<<numOfProvinces(isConnected)<<endl;

    return 0;
}


int numOfProvinces(vector<vector<int> > &isConnected)
{
    int numOfCities = isConnected.size();

    vector<bool>visited(numOfCities, false);

    int cnt = 0;

    for(int i = 0; i < numOfCities; i++)
    {
        if(visited[i] != true)
        {
            traverse(isConnected, i, visited);
            cnt++;
        }
    }

    return cnt;
}


void traverse(vector<vector<int> > &isConnected, int city, vector<bool> &visited)
{
    if(visited[city] == true)
    {
        return;
    }
    visited[city] = true;

    for(int i = 0; i < isConnected[city].size(); i++)
    {
        if(isConnected[city][i] == 1)
        {
            traverse(isConnected, i , visited);
        }
    }
}
