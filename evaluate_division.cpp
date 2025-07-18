#include<bits/stdc++.h>
using namespace std;


vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values, vector<vector<string> >&queries);
void buildGraph(vector<vector<string> > &equations, vector<double> &values, unordered_map<string, vector<pair<string, double> > > &graph);

double evaluateDivision(unordered_map<string, vector<pair<string, double> > > &graph, string source, string destination);
double traverse(unordered_map<string, vector<pair<string, double> > > &graph, string source, string destination, map<string, bool> &visited, double result, int &flag);

int main()
{
    vector<vector<string> > equations = {{"a","b"},{"c","d"}};
    vector<double> values = {1.0, 1.0};

    vector<vector<string> > queries = {{"a","c"},{"b","d"},{"b","a"},{"d","c"}};


    vector<double> results = calcEquation(equations, values, queries);

    for(auto it = results.begin(); it != results.end(); it++)
    {
        cout<< *it<<' ';
    }
    cout<<endl;

    return 0;
}


vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values, vector<vector<string> >&queries)
{
    unordered_map<string, vector<pair<string, double> > > graph;
    vector<double>results;

    buildGraph(equations, values, graph);

//    for(auto it = graph.begin(); it != graph.end(); it++)
//    {
//        cout<<it->first<<": ";
//        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
//        {
//            cout<<'('<<it2->first<<','<<it2->second<<')';
//        }
//        cout<<endl;
//    }

    for(int i = 0; i < queries.size(); i++)
    {
        if(graph.find(queries[i][0]) != graph.end() && graph.find(queries[i][1]) != graph.end())
        {
            if(queries[i][0] == queries[i][1])
            {
                results.push_back(1.0);
            }
            else
            {
                double result = evaluateDivision(graph, queries[i][0], queries[i][1]);
                results.push_back(result);
            }

        }
        else
        {
            results.push_back(-1.0);
        }
    }


    return results;
}

void buildGraph(vector<vector<string> > &equations, vector<double> &values, unordered_map<string, vector<pair<string, double> > > &graph)
{
    for(int i = 0; i<equations.size(); i++)
    {
        graph[equations[i][0]].emplace_back(equations[i][1], values[i]);
        graph[equations[i][1]].emplace_back(equations[i][0], 1/values[i]);
    }
}


double evaluateDivision(unordered_map<string, vector<pair<string, double> > > &graph, string source, string destination)
{
    map<string, bool> visited;

    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        visited[it->first] = false;

    }
//
//    for(auto it = visited.begin(); it != visited.end(); it++)
//    {
//        cout<<it->first<<' '<<it->second;
//    }

    double result = 1.0;
    int flag = 0;

    result =  traverse(graph, source, destination, visited, result, flag);

    result = flag == 1 ? result : -1.0;

    return result;
}


double traverse(unordered_map<string, vector<pair<string, double> > > &graph, string source, string destination, map<string, bool> &visited, double result, int &flag)
{
    if(visited[source] == true)
    {
        return result;
    }

    visited[source] = true;

    if(source == destination)
    {
        flag = 1;
        return result;
    }

    for(auto it = graph[source].begin(); it!= graph[source].end(); it++)
    {
        result = traverse(graph, it->first, destination, visited, result * it->second , flag);
        if(flag == 1)
        {
            return result;
        }
        else
        {
            result = result / it->second;
        }
    }

    return result;

}
