//Time Complexity: O(V+E)
/*Cycle finding*/
public class Solution {
    List<List<int>>adj = new List<List<int>>();

    int [] Visited;
    public bool CanFinish(int numCourses, int[,] prerequisites) {
        bool chk = true;
        if(prerequisites.GetLength(0)<=0) return true;
         Visited = new int[numCourses];
        for(int i = 0; i<numCourses; i++){
            adj.Add(new List<int>());
            Visited[i]=0;
        }
       
        for(int i = 0; i<prerequisites.GetLength(0); i++){
            adj[prerequisites[i,0]].Add(prerequisites[i,1]);
        }
        for(int i = 0; i<numCourses; i++){
            if(DFS(i) == false) return false;
              
        }
        return true;
    }
    
    public bool DFS(int curNode){
    
      if(Visited[curNode] > 0) return false;
      Visited[curNode] = 1;
      for(int i = 0; i<adj[curNode].Count; i++){
          if(DFS(adj[curNode][i]) == false)
                 return false;
      }
      Visited[curNode] = 0;
      return true;
    }
}