/*
Complexity : O(V + E) * log(n)
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/
public class Solution {


    public class NodeInfo{
        public string word{get;set;}
        public int dist{get;set;}
    }
    
    public int LadderLength(string beginWord, string endWord, ISet<string> wordDict) {
        if(!wordDict.Contains(endWord))
          wordDict.Add(endWord);
        return GetMinimumTransform(beginWord , endWord, wordDict);   
    }
    
    public int GetMinimumTransform(string beginWord , string endWord, ISet<string>wordDict){
        ISet<string> wordDict1 = new HashSet<string>();
        Queue queue = new Queue();
        NodeInfo node  = new NodeInfo();
        node.word = beginWord;
        node.dist = 0; 
        queue.Enqueue(node);
        wordDict1.Add(beginWord);
        while(queue.Count > 0){
          NodeInfo curNode = (NodeInfo)queue.Dequeue();
          if(curNode.word == endWord) return curNode.dist + 1;
          for(int i = 0; i<curNode.word.Length; i++){
              char[] temp = curNode.word.ToCharArray();
              for(char a = 'a'; a<='z'; a++){
                    temp[i] = a;
                    string str = new string(temp);
                    if(wordDict.Contains(str) && !wordDict1.Contains(str)){
                         node  = new NodeInfo();
                         node.word = str;
                         node.dist = curNode.dist + 1; 
                         queue.Enqueue(node);
                         wordDict1.Add(str);
                    }
              }
          
          }
        
        }
        
        return 0;
    
    }
}