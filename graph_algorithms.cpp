#include<bits/stdc++.h>
using namespace std;


vector<char> depthFirstSearch(map<char, vector<char> > &graph, char source);
vector<char> breadthFirstSearch(map<char, vector<char> > &graph, char source);

vector<char>depthFirstSearchRecursive(map<char, vector<char> > &graph, char source);
void depthFirstSearchUtil(map<char, vector<char> > &graph, char source, vector<char> &visited);

void printNodes(vector<char> &v);

/**
    hasPath() is a dfs implementation
*/
bool hasPath(map<char, vector<char> > graph, char source, char destination);

/**
    hasPath2() is a bfs implementation
*/

bool hasPath2(map<char, vector<char> > graph, char source, char destination);

int main()
{
/**
    Part 1 : the traversal strategies
*/
//    map<char, vector<char> >graph;
//
//    graph['a'] = {'b','c'};
//    graph['b'] = {'d'};
//    graph['c'] = {'b','e'};
//    graph['d'] = {'f'};
//    graph['e'] = {};
//    graph['f'] = {};
//
//
//    vector<char>traversedNodes = depthFirstSearch(graph,'a');
//    vector<char>traversedNodes3 = depthFirstSearchRecursive(graph, 'a');
//
//    vector<char>traversedNodes2 = breadthFirstSearch(graph,'a');
//
//    printNodes(traversedNodes);
//    printNodes(traversedNodes3);
//    printNodes(traversedNodes2);


/**
    Part 2 : has Path problem
*/

    map<char, vector<char> > graph2;

    graph2['f'] = {'g', 'i'};
    graph2['g'] = {'h'};
    graph2['h'] = {};
    graph2['i'] = {'g', 'k'};
    graph2['j'] = {'i'};
    graph2['k'] = {};

    cout<<hasPath(graph2, 'j','f')<<endl;
    cout<<hasPath(graph2, 'j','k')<<endl;
    cout<<hasPath(graph2, 'f','k')<<endl;

    cout<<hasPath2(graph2, 'j','f')<<endl;
    cout<<hasPath2(graph2, 'j','k')<<endl;
    cout<<hasPath2(graph2, 'f','k')<<endl;


    return 0;
}


vector<char> depthFirstSearch(map<char, vector<char> > &graph, char source)
{
    stack<char> st;

    vector<char> visited;

    st.push(source);

    while(!st.empty())
    {
        char currentNode = st.top();
        st.pop();

         //if the node is not visited add all the neighbor nodes to stack and add the node to visited
         if(find(visited.begin(),visited.end(),currentNode) == visited.end())
        {
            for(auto it = graph[currentNode].begin(); it != graph[currentNode].end(); it++)
            {
                st.push(*it);
            }
            visited.push_back(currentNode);
        }

    }

    return visited;

}

vector<char> breadthFirstSearch(map<char, vector<char> > &graph, char source)
{
    queue<char> q;

    vector<char> visited;

    q.push(source);

    while(!q.empty())
    {
        char currentNode = q.front();
        q.pop();

        if(find(visited.begin(),visited.end(),currentNode) == visited.end())
        {
            for(auto it = graph[currentNode].begin(); it != graph[currentNode].end(); it++)
            {
                q.push(*it);
            }
            visited.push_back(currentNode);
        }


    }

    return visited;
}

vector<char> depthFirstSearchRecursive(map<char, vector<char> > &graph, char source)
{
    vector<char> visited;

    depthFirstSearchUtil(graph, source, visited);

    return visited;
}

void depthFirstSearchUtil(map<char, vector<char> > &graph, char source, vector<char> &visited)
{
    if(find(visited.begin(), visited.end(), source) != visited.end())
    {
        return;
    }

    visited.push_back(source);

    for(auto it = graph[source].begin(); it != graph[source].end(); it++)
    {
        depthFirstSearchUtil(graph,*it, visited);
    }


}


void printNodes(vector<char> &v)
{
    for(auto it = v.begin(); it!= v.end(); it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;

    return;
}

bool hasPath(map<char, vector<char> > graph, char source, char destination)
{
    stack<char> st;

    vector<char> visited;

    st.push(source);

    while(!st.empty())
    {
        char currentNode = st.top();
        st.pop();

        if(currentNode == destination)
        {
            return true;
        }

        if(find(visited.begin(),visited.end(),currentNode) == visited.end())
        {
            for(auto it = graph[currentNode].begin();it != graph[currentNode].end(); it++)
            {
                st.push(*it);
            }

            visited.push_back(currentNode);
        }
    }

    return false;

}

/**
* @param graph -> adjacency list that represents the graph
* @param source -> the source vertex from which we try to find the path
* @param destination -> the destination vertex to which we try to find the path
* @return true if a path from source to destination exists false otherwise
* it is a bfs implementation
*/
bool hasPath2(map<char, vector<char> > graph, char source, char destination)
{

    queue<char> q;

    vector<char> visited;

    q.push(source);

    while(!q.empty())
    {
        char currentNode = q.front();
        q.pop();

        if(currentNode == destination)
        {
            return true;
        }

        if(find(visited.begin(),visited.end(),currentNode) == visited.end())
        {
            for(auto it = graph[currentNode].begin();it != graph[currentNode].end(); it++)
            {
                q.push(*it);
            }

            visited.push_back(currentNode);
        }
    }

    return false;
}
