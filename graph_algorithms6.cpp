#include<bits/stdc++.h>
using namespace std;


int islandCount(vector<vector<char> > &grid);

void traverse(vector<vector<char> > &grid,int rowIndex, int colIndex, int rowNum,int colNum, vector<vector<bool> > &visited);


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
    cout<<islandCount(grid)<<endl;

    return 0;
}


int islandCount(vector<vector<char> > &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<bool> > visited(row, vector<bool>(col, false));
    int cnt = 0;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(visited[i][j] != true && grid[i][j] == 'L')
            {
                traverse(grid, i, j,row, col, visited);
                cnt++;
            }
        }
    }

    return cnt;

}

void traverse(vector<vector<char> > &grid, int rowIndex, int colIndex, int rowNum, int colNum, vector<vector<bool> > &visited)
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

    traverse(grid, rowIndex + 1, colIndex, rowNum, colNum, visited);
    traverse(grid, rowIndex - 1, colIndex, rowNum, colNum, visited);
    traverse(grid, rowIndex, colIndex + 1, rowNum, colNum, visited);
    traverse(grid, rowIndex, colIndex - 1, rowNum, colNum, visited);


}
