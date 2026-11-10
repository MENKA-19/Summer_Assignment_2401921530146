class Solution {
public:
   void DFS(int r,int c,vector<vector<int>>& image,vector<vector<int>>& Ans,int color,int iniColor,int delRow[],int delCol[]){
        Ans[r][c] = color;
       
        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<4;i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && image[nrow][ncol] == iniColor && Ans[nrow][ncol] != color){
                DFS(nrow,ncol,image,Ans,color,iniColor,delRow,delCol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        vector<vector<int>> Ans = image;

        int iniColor = image[sr][sc];

        DFS(sr,sc,image,Ans,color,iniColor,delRow,delCol);

        return Ans;
        
    }
};