public class Solution {
    List<List<int>>adj = new List<List<int>>();

   
   public int[] FindOrder(int numCourses, int[,] prerequisites) {
         int [] Indegree = new int[numCourses];
         List<int>ans = new List<int>();
        if(prerequisites.GetLength(0) == 0) return ans.ToArray();
       
        for(int i = 0; i<numCourses; i++){
            adj.Add(new List<int>());
            Indegree[i]= 0;
        }
       
        int temp = numCourses;
        for(int i = 0; i<prerequisites.GetLength(0); i++){
            adj[prerequisites[i,0]].Add(prerequisites[i,1]);
            Indegree[prerequisites[i,1]]++;
        }
        Queue queue = new Queue();
        
        for(int i = 0; i<numCourses; i++){
          if(Indegree[i] == 0){
            queue.Enqueue(i); 
          }
        }
        while(queue.Count>0){
           int curNode = (int)queue.Dequeue();
           ans.Add(curNode);
           temp--;
           for(int i = 0; i<adj[curNode].Count; i++)
           {
               Indegree[adj[curNode][i]]--;
               if(Indegree[adj[curNode][i]] == 0)
                queue.Enqueue(adj[curNode][i]);
           }
        }
        if(temp==0)
              return ans.ToArray();
           
        else
              return new int[numCourses];
    }
}