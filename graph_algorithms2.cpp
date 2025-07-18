#include<bits/stdc++.h>
using namespace std;


map<char, vector<char> > graphFromEdgeList(const vector<pair<char, char> > &edgeList);


void printEdgeList(const vector<pair<char, char> > &edgeList);
void printAdjacencyList(const map<char, vector<char> > &graph);


bool hasPathRecursive(map<char, vector<char> > &graph, char source, char destination);
bool hasPathRecursiveUtil(map<char, vector<char> > &graph, char souce, char destination, vector<char> &visited);

int main()
{
    vector<pair<char, char> > edgeList;
    edgeList.push_back({'i','j'});
    edgeList.push_back({'k', 'i'});
    edgeList.push_back({'m', 'k'});
    edgeList.push_back({'k','l'});
    edgeList.push_back({'o','n'});

    printEdgeList(edgeList);

    map<char, vector<char> > graph = graphFromEdgeList(edgeList);

    cout<<endl;
    printAdjacencyList(graph);

    cout<<endl;

    cout<<hasPathRecursive(graph,'i','o')<<endl;
    cout<<hasPathRecursive(graph,'i','m')<<endl;

    return 0;
}

/**
* @param edgeList -> a vector of pairs representing relationship between two vertices
* @return an adjacency list which represents the graph is a map where key is a vertex and value is a vector which contains
*         the neighbor vertices of the key vertex

*/
map<char, vector<char> > graphFromEdgeList(const vector<pair<char, char> > &edgeList)
{
    map<char, vector<char> >graph;

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

void printEdgeList(const vector<pair<char, char> > &edgeList)
{
    for(auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }

    return;
}

void printAdjacencyList(const map<char, vector<char> > &graph)
{
    for(auto it = graph.begin();it != graph.end();it++)
    {
        cout<<it->first<<':';

        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            cout<<*it2<<' ';
        }
        cout<<endl;
    }

}


bool hasPathRecursive(map<char, vector<char> > &graph, char source, char destination)
{
    vector<char> visited;

    return hasPathRecursiveUtil(graph, source, destination, visited);

}



bool hasPathRecursiveUtil(map<char, vector<char> > &graph, char source, char destination, vector<char> &visited)
{
    if(source == destination)
    {
        return true;
    }

    if(find(visited.begin(), visited.end(), source) != visited.end())
    {
        return false;
    }

    visited.push_back(source);

//    map<char, vector<char> > :: iterator it;

    for(auto it = graph[source].begin(); it != graph[source].end(); it++)
    {
        if(hasPathRecursiveUtil(graph, *it, destination,visited))
        {
            return true;
        }
    }
    return false;
}
