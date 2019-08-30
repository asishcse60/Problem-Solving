//Time Complexity of the above solution is O(MN)
//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

//A region is captured by flipping all 'O's into 'X's in that surrounded region.
public class Solution {
    public class Position{
        public int x {get; set;}
        public int y {get; set;}
    }
    Queue queue = new Queue();
    int[] xx = new int[] { 0, 0, 1, -1};
    int[] yy = new int[] { 1, -1, 0, 0};
    
    public void Solve(char[,] board) {
        
        int numOfrows = board.GetLength(0);
        int numOfCols = board.GetLength(1);
        if(numOfrows <=2) return;
        for(int rowIndex = 0; rowIndex<numOfrows; rowIndex++){
            for(int colIndex = 0; colIndex<numOfCols; colIndex++){
            
             if(board[rowIndex, colIndex]=='O' && (rowIndex == 0 || colIndex==0 || rowIndex==(numOfrows-1)||colIndex==(numOfCols-1))){
                 board[rowIndex, colIndex] = '-';
                 Position pos = new Position();
                 pos.x = rowIndex;
                 pos.y = colIndex;
                 queue.Enqueue(pos);
             }
            
            }
        }
        TraverseBoard(board, numOfrows, numOfCols);
        for(int rowIndex = 0; rowIndex<numOfrows; rowIndex++){
            for(int colIndex = 0; colIndex<numOfCols; colIndex++){
              if(board[rowIndex, colIndex]!='X')
              board[rowIndex, colIndex] = board[rowIndex, colIndex]=='O'?'X':'O';
            }
         }
        
    }
    
    public void TraverseBoard(char[,] board, int numOfrows, int numOfCols){
    
        while(queue.Count > 0){
            Position temp = (Position) queue.Dequeue();
            for(int i = 0; i<4; i++){
              int x = xx[i] + temp.x;  
              int y = yy[i] + temp.y;
              if(x >= 0 && y>=0 && x<numOfrows && y<numOfCols){
                if(board[x,y]=='O'){
                  board[x,y] = '-';
                 Position pos = new Position();
                 pos.x = x;
                 pos.y = y;
                 queue.Enqueue(pos);
                }
              }
            }
        }
    }
 }