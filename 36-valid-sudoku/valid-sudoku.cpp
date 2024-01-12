class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         int flag=0;
         for(int i = 0;i<9;i++){
             for(int j = 0;j<9;j++){
                 char x=board[i][j];
                 if(x!='.'){
                     int p[2]={i/3,j/3};
                     for(int a1=0;a1<9;a1++)
                     {
                         if(board[i][a1]==x && a1!=j)
                            return false;
                            
                         if(board[a1][j]==x && a1!=i)
                            return false;
                     if(board[3*p[0]+a1%3][3*p[1]+a1/3]==x && (3*p[0]+a1%3!=i || 3*p[1]+a1/3!=j))
                            return false;

                     }
                 }
             }
         }
         //if(flag==0)
        return true;
        
    }
};