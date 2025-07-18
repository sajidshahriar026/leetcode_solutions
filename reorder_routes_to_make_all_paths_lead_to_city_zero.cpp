#include<bits/stdc++.h>
using namespace std;

int minReorder(int n, vector<vector<int> > &connections);

void graphFromEdgeList(vector<vector<int> > &edgeList, unordered_map<int, vector<pair<int,bool> > >&graph);

void traverse(unordered_map<int, vector<pair<int, bool> > > &graph, int source, vector<bool> &visited, int &changes);



int main()
{
    vector<vector<int> > connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout<<minReorder(6, connections);

}


int minReorder(int n, vector<vector<int> > &connections)
{
    unordered_map<int, vector<pair<int, bool> > > graph;

    graphFromEdgeList(connections, graph);

    int changes = 0;

    vector<bool>visited(n, false);


    traverse(graph, 0, visited, changes);

    return changes;

}

void graphFromEdgeList(vector<vector<int> > &edgeList, unordered_map<int, vector<pair<int, bool> > > &graph)
{
    for(auto edge : edgeList)
    {
        int source = edge[0];
        int destination = edge[1];

        graph[source].emplace_back(destination, true);
        graph[destination].emplace_back(source, false);

    }
}

void traverse(unordered_map<int , vector<pair<int, bool> > > &graph, int source, vector<bool> &visited, int &changes)
{

    if(visited[source] == true)
    {
        return;
    }

    visited[source] = true;

    for(auto neighbor : graph[source])
    {
        if(neighbor.second && !visited[neighbor.first])
        {
            changes++;
        }
        traverse(graph, neighbor.first, visited, changes);
    }

}











