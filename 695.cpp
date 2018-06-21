class Solution {
    int nr, nc;
    int X[4]={1, -1, 0, 0};
    int Y[4]={0,0,1,-1};
    struct Node{
        int x, y;
    }node;
    vector<vector<int>> Grid;
    bool inq[60][60]={false};
    bool valid(int x, int y){
        if(x<0||x>=nr||y<0||y>=nc)
            return false;
        if(Grid[x][y]==0)
            return false;
        if(inq[x][y])
            return false;
        return true;
    }
    int BFS(int x, int y){
        int cnt=0;
        queue<Node> q;
        node.x=x, node.y=y;
        q.push(node);
        inq[x][y]=1;
        cnt++;
        while(!q.empty()){
            Node top=q.front();
            q.pop();
            for(int i=0; i < 4; i++){
                int newx=top.x+X[i];
                int newy=top.y+Y[i];
                if(valid(newx, newy)){
                    node.x=newx, node.y=newy;
                    q.push(node);
                    inq[newx][newy]=1;
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        Grid=grid;
        nr=grid.size();
        nc=grid[0].size();
        int maxA=0;
        for(int x=0; x<nr; x++){
            for(int y=0; y<nc; y++){
                if(valid(x, y)){
                    int a=BFS(x, y);
                    if(maxA<a)
                        maxA=a;
                }
            }
        }
        return maxA;
    }
};
