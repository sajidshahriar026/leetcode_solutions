#include<bits/stdc++.h>
using namespace std;


int largestComponent(map<int, vector<int> > &graph);
void depthFirstSearchUtil(map<int, vector<int> > &graph, int source, map<int, bool> &visited, int &cnt);


int main()
{

    map<int, vector<int> > graph;

    graph[0] = {8,1,5};
    graph[1] = {0};
    graph[5] = {0,8};
    graph[8] = {0,5};
    graph[2] = {3,4};
    graph[3] = {2,4};
    graph[4] = {3,2};


    cout<<largestComponent(graph)<<endl;

    return 0;
}


int largestComponent(map<int, vector<int> > &graph)
{
    map<int, bool> visited;

    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        visited[it->first] = false;
    }

    int maxCount = numeric_limits<int> :: min();

    for(auto it = visited.begin(); it != visited.end(); it++)
    {
        int cnt = 0;

        if(it->second == false)
        {
            depthFirstSearchUtil(graph,it->first,visited,cnt);

            maxCount = cnt > maxCount ? cnt : maxCount;
        }

    }

    return maxCount;
}

void depthFirstSearchUtil(map<int, vector<int> > &graph, int source, map<int, bool> &visited, int &cnt)
{
    if(visited[source] == true)
    {
        return;
    }

    visited[source] = true;

    cnt++;

    for(auto it = graph[source].begin(); it != graph[source].end(); it++)
    {
        depthFirstSearchUtil(graph, *it, visited, cnt);
    }

    return;
}

