Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
public class Solution {
    public IList<string> Anagrams(string[] strs) {
         var dict= new Dictionary<string, List<string>>();
        for(int i = 0;i<strs.Length; i++){
            char [] ch = strs[i].ToCharArray();
            Array.Sort(ch);
            var key = new string(ch);
            if(!dict.ContainsKey(key)){
               dict.Add(key, new List<string>());
            }
            dict[key].Add(strs[i]);
        }
       return dict.Values.Where(o=>o.Count>1).SelectMany(i=>i).ToList();
    }
}