#include<bits/stdc++.h>
using namespace std;


bool canVisitAllRooms(vector<vector<int> > &rooms);


int main()
{
    vector<vector<int> > rooms = {{1},{2},{3},{}};
    cout<<canVisitAllRooms(rooms);
    return 0;
}


bool canVisitAllRooms(vector<vector<int> > &rooms)
{
    int numOfRooms = rooms.size();

    int numOfVisitedRooms = 0;

    vector<int>visited;

    stack<int> s;

    s.push(0);

    while(!s.empty())
    {
        int currentNode = s.top();
        s.pop();

        if(find(visited.begin(), visited.end(), currentNode) == visited.end())
        {
            for(int i = 0; i < rooms[currentNode].size();i++)
            {
                s.push(rooms[currentNode][i]);
            }
            visited.push_back(currentNode);
            numOfVisitedRooms++;
        }
    }

    return numOfRooms == numOfVisitedRooms ? true : false;
}
