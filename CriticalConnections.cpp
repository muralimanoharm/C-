

void DepthFirstSearch(int _node,vector<bool>& _isVisited,vector<int>& _dis,vector<int>& _low, int& _time,int _parentNode,vector<vector<int>>& _adj, vector<vector<int>>& _result)
{
    //Mark the current Node as visited
    _isVisited[_node] = true;
    
    //Initialize Discover Time and low value
    _dis[_node] = _low[_node] = ++_time;
    
    //Go through all nodes adjacent to the main node
    for(auto currentNode:_adj[_node])
    {
        //Process DFS for the current Node (v) if it is not visited
        if(!_isVisited[currentNode])
        {
            //DFS from the current node
            DepthFirstSearch(currentNode,_isVisited,_dis,_low,_time,_node,_adj,_result);
            
            //Check if the subtree rooted from currentNode(v) has a connection
            //to ancestors of u
            _low[_node] = min(_low[_node],_low[currentNode]);
            
            //If the lowest vertex rechable from the subtree
            //under V is below u in dfs tree then u-v is a bridge
            
            if(_low[currentNode] > _dis[_node])
            {
               _result.push_back({_node,currentNode});
            }
            
        }else if(currentNode != _parentNode)
       {
            _low[_node] = min(_low[_node],_dis[currentNode]);
       }
    }
}

vector<vector<int>> FindCriticalConnections(int _totalNodes, vector<vector<int>>& _edges)
{
    vector<vector<int>> result;
    vector<vector<int>> adj(_totalNodes+1,vector<int>());
    vector<int> dis(_totalNodes+1,-1);
    vector<int> low(_totalNodes+1,-1);
    vector<bool> isVisited(_totalNodes+1,false);
    int time=0;
    for(auto currNode:_edges)
    {
        adj[currNode[0]].push_back(currNode[1]);
        adj[currNode[1]].push_back(currNode[0]);
    }
    
    for(int node=1;node<=_totalNodes;node++)
    {
        if(!isVisited[node])
        {
            DepthFirstSearch(node,isVisited,dis,low,time,0,adj,result);
        }
    }
    //dfs()
    
    return result;
}

int main()
{
        vector<vector<int>> edges{{1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {6, 7}, {6, 9}, {7, 8}, {8, 9}};
        cout << "size :"<<edges.size()<<endl;
    
        vector<vector<int>> result ={{}};
        result = FindCriticalConnections(9,edges);
        
        for(auto bridges:result)
        {
            cout<<bridges[0]<<":"<<bridges[1]<<endl;
        }
}
