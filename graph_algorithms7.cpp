#include<bits/stdc++.h>
using namespace std;

int minIsland(vector<vector<char> > &grid);

void traverse(vector<vector<char> > &grid,int rowIndex, int colIndex, int rowNum, int colNum, vector<vector<bool> > &visited, int &cnt);

int main()
{
    vector<vector<char> > grid {
        {'W','L','W','W','W'},
        {'W','L','W','W','W'},
        {'W','W','W','L','W'},
        {'W','W','L','L','W'},
        {'L','W','W','L','L'},
        {'L','L','W','W','W'}
    };
    cout<<minIsland(grid)<<endl;


    return 0;
}





int minIsland(vector<vector<char> > &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    int minCount = numeric_limits<int> :: max();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(visited[i][j] != true && grid[i][j] == 'L')
            {
                int cnt = 0;
                traverse(grid, i, j, row, col, visited, cnt);

                minCount = minCount > cnt ? cnt : minCount;
            }
        }
    }

    return minCount;


}


void traverse(vector<vector<char> > &grid, int rowIndex, int colIndex, int rowNum, int colNum, vector<vector<bool> > &visited, int &cnt)
{
    if(rowIndex < 0 || rowIndex >= rowNum || colIndex < 0 || colIndex >= colNum || visited[rowIndex][colIndex] == true)
    {
        return;
    }

    visited[rowIndex][colIndex] = true;

    if(grid[rowIndex][colIndex] == 'W')
    {
        return;
    }

    cnt++;

    traverse(grid,rowIndex + 1 ,colIndex, rowNum, colNum, visited, cnt);
    traverse(grid,rowIndex - 1 ,colIndex, rowNum, colNum, visited, cnt);
    traverse(grid,rowIndex ,colIndex + 1, rowNum, colNum, visited, cnt);
    traverse(grid,rowIndex ,colIndex - 1, rowNum, colNum, visited, cnt);

}
