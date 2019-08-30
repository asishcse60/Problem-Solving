//Time complexity: O(ROW x COL)
/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.*/
public class Solution {
     public class Position{
        public int x {get; set;}
        public int y {get; set;}
    }

    int[] xx = new int[] { 0, 0, 1, -1};
    int[] yy = new int[] { 1, -1, 0, 0};
    public int NumIslands(char[,] grid) {
        int numOfRows = grid.GetLength(0);
        int numOfCols = grid.GetLength(1);
        int isLandCount = 0;
        for(int rowIndex = 0; rowIndex<numOfRows; rowIndex++){
        
            for(int colIndex = 0; colIndex<numOfCols; colIndex++){
              if(grid[rowIndex, colIndex] == '1'){
              
                  grid[rowIndex, colIndex] = '-';
                  isLandCount++;
                  VisitIsland(grid, numOfRows, numOfCols, rowIndex, colIndex);
              }
            
            }
        
        }
        return isLandCount;
    }
    
    public void VisitIsland(char[,] grid, int numOfRows, int numOfCols, int rowIndex, int colIndex){
    
          Queue queue = new Queue();
          Position pos = new Position();
          pos.x = rowIndex;
          pos.y = colIndex;
          queue.Enqueue(pos);
          while(queue.Count > 0){
          
               Position temp= (Position)queue.Dequeue();
               for(int i = 0; i<4; i++){
               
                   int x = xx[i] + temp.x;
                   int y = yy[i] + temp.y;
                   if(x>=0 && y>=0 && x<numOfRows && y<numOfCols){
                   
                      if(grid[x,y]=='1')
                      {
                       pos = new Position();
                       pos.x = x;
                       pos.y = y;
                       queue.Enqueue(pos);
                       grid[x, y] = '-';
                      }
                   }
               }
          }  
    
    }
}