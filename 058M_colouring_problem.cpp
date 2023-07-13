bool safe(int col, bool graph[101][101], int m, int n, int node, vector<int> colour){
        //checking each and every node
        for(int k=0; k<n; k++){
            //checking adjecent nodes of graph
            if(k!=node && graph[k][node]==1 && colour[k]==col){
                return false;
            }
            
        }
        return true;
    }
    
    bool solve(bool graph[101][101], int m, int n, int node, vector<int> colour){
        if(node==n){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(safe(i, graph, m, n, node, colour)){
                colour[node]=i;
                if(solve(graph, m, n, node+1, colour)){
                    return true;
                }
                //backtracking
                colour[node]=0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colour(n,0);
        int node=0;
        if(solve(graph, m, n, node, colour)){
            return true;
        }
        
        return false;
    }
