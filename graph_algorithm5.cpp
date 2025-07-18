#include<bits/stdc++.h>
using namespace std;

map<char, vector<char> > graphFromEdgeList(vector<pair<char, char> > edgeList);

int shortestPath(map<char, vector<char> > &graph, char source, char destination);


int main()
{
    vector<pair<char, char> > edgeList;

    edgeList.push_back({'w','x'});
    edgeList.push_back({'x','y'});
    edgeList.push_back({'z','y'});
    edgeList.push_back({'z','v'});
    edgeList.push_back({'w','v'});

    map<char, vector<char> > graph = graphFromEdgeList(edgeList);

    cout<<shortestPath(graph,'w','z')<<endl;


    return 0;
}


map<char, vector<char> > graphFromEdgeList(vector<pair<char, char> > edgeList)
{
    map<char, vector<char> > graph;

    for(auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
        if(graph.find(it->first) == graph.end())
        {
            graph[it->first] = {it->second};
        }
        else
        {
            graph[it->first].push_back(it->second);
        }

        if(graph.find(it->second) == graph.end())
        {
            graph[it->second] = {it->first};
        }
        else
        {
            graph[it->second].push_back(it->first);
        }
    }

    return graph;
}

int shortestPath(map<char, vector<char> > &graph, char source, char destination)
{
    vector<char> visited;
    queue<pair<char, int> > q;

    q.push({source, 0});

    while(!q.empty())
    {
        pair<char, int> currentNode = q.front();
        q.pop();

        if(find(visited.begin(), visited.end(), currentNode.first) == visited.end())
        {
            if(currentNode.first == destination)
            {
                return currentNode.second;
            }

            for(auto it = graph[currentNode.first].begin(); it != graph[currentNode.first].end(); it++)
            {
                q.push({*it, currentNode.second + 1});
            }
            visited.push_back(currentNode.first);
        }

    }
    return -1;
}
