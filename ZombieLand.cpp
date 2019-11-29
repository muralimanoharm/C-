/*Zombies*/


class coordinates
{    
    public :
    int m_x;
    int m_y;
    coordinates(int _x,int _y)
    {
        m_x = _x;
        m_y = _y;
    }
};

vector<int> dir{0,1,0,-1,0};

queue<coordinates> collectZombieCoordinates(vector<vector<int>>& _grid)
{
    queue<coordinates> toRet;
    for(int i=0;i<_grid.size();i++)
    {
        for (int j=0;j<_grid[0].size();j++)
        {
            if(_grid[i][j] == 1)
            {
                toRet.push(coordinates(i,j));
            }
        }
    }
    return toRet;
}

int GetZombieInfection(vector<vector<int>>& _grid)
{
    int hours = 0;
    if(_grid.size() <= 0 && _grid[0].size() > 0)
    {
        return hours;
    }
    
    queue<coordinates> q =  collectZombieCoordinates(_grid);
    
    while(!q.empty())
    {
        int n =  q.size();
        for(int i=0;i<n;i++)
        {
            int x = q.front().m_x;
            int y = q.front().m_y;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int adjx = x + dir[j];
                int adjy = y + dir[j+1];
                if(adjx >= 0 && adjx < _grid.size() && adjy >= 0 && adjy < _grid[0].size() &&  _grid[adjx][adjy] == 0)
                {
                    _grid[adjx][adjy] = 1;
                    q.push(coordinates(adjx,adjy));
                    
                }
            }
        }
        if(q.empty())
        {
            return hours;
        }
        hours++;
    }
        
    return hours;
}

int main() {
    std::cout << "Hello Zombieeee world!\n";
    
    vector<vector<int>> grid{{0, 1, 1, 0, 1},
                             {0, 1, 0, 1, 0},
                             {0, 0, 0, 0, 1},
                             {0, 1, 0, 0, 0}};
    
    vector<vector<int>> grid1{{1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {0, 1, 1, 1, 1}};
  
    vector<vector<int>> grid2{{1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1}};
  
    int hours = GetZombieInfection(grid);
    cout << "hours :"<<hours<<endl;
    hours = GetZombieInfection(grid1);
    cout << "hours :"<<hours<<endl;
    hours = GetZombieInfection(grid2);
    cout << "hours :"<<hours<<endl;
}
