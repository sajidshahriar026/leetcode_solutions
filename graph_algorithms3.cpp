#include<bits/stdc++.h>
using namespace std;

int connectedComponentsCount(map<int, vector<int> > &graph);
void depthFirstSearchUtil(map<int, vector<int> > &graph, int source, map<int, bool> &visited);



int main()
{
    map<int, vector<int> > graph;

    graph[3] = {};
    graph[4] = {6};
    graph[6] = {4,5,7,8};
    graph[8] = {6};
    graph[7] = {6};
    graph[5] = {6};
    graph[1] = {2};
    graph[2] = {1};

    cout<<connectedComponentsCount(graph)<<endl;

    return 0;
}


int connectedComponentsCount(map<int, vector<int> > &graph)
{
    map<int, bool> visited;

    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        visited[it->first] = false;
    }


    int cnt = 0;

    for(auto it = visited.begin(); it != visited.end(); it++)
    {
        if(it->second == false)
        {
            depthFirstSearchUtil(graph, it->first, visited);
            cnt++;
        }

    }

    return cnt;

}


void depthFirstSearchUtil(map<int, vector<int> > &graph, int source, map<int, bool> &visited)
{
    if(visited[source] == true)
    {
        return;
    }

    visited[source] = true;

    for(auto it = graph[source].begin(); it != graph[source].end(); it++)
    {
        depthFirstSearchUtil(graph, *it, visited);
    }

    return;
}
