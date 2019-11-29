 int NumberOfIslands(vector<vector<char>>& grid) {
        
        if(grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> directions = {{-1,0}, {1,0},{0,-1},{0,1}};
        queue<pair<int, int>> q;
        int count = 0;
        
        for(int r=0; r<grid.size(); r++)
        {
            for(int c=0; c<grid[0].size(); c++)
            {
                if(grid[r][c] == '1')
                {
                    q.push({r,c});
                    while(!q.empty())
                    {
                        pair<int, int> curr = q.front();
                        q.pop();

                        int row = curr.first;
                        int col = curr.second;
                        grid[row][col] = '#'; //set to visited
                        for(int j=0; j<directions.size(); j++)
                        {
                            int nextRow = row + directions[j][0];
                            int nextCol = col + directions[j][1];

                            if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()) continue;
                            if(grid[nextRow][nextCol] == '1')
                            {
                                grid[nextRow][nextCol] = '#'; //set the neighbours visited here, otherwise we run the risk of reaching this neigbour by another node, which will cause a cycle.
                                q.push({nextRow, nextCol});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
int main()
{
    vector<vector<char>> grid{{
        '1','1','0','0','0'
    },{
        '1','1','0','0','0'
    },{
        '0','0','1','0','0'
    },{
        '0','0','0','1','1'
    }};
        
    int count = NumberOfIslands(grid);
    cout << "count :"<< count<<endl;
}
