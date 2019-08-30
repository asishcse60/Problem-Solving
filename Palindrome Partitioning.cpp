/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
bool isPalin(string s){
    for(int i = 0; i<s.size();i++)
     if(s[i]!=s[s.size()-i-1]) return 0;
    return 1; 
}
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> >v1,v2;
        vector<string>v;
        if(s.size()==0) return v1;
        else if(s.size()==1){
            v.push_back(s);
            v1.push_back(v);
            return v1;
        }
        for(int i = 1; i<=s.size();i++){
            if(isPalin(s.substr(0,i))){
                v2 = partition(s.substr(i,s.size()-i));
                if(v2.size()==0){
                    v.push_back(s.substr(0,i));
                    v1.push_back(v);
                }
                else{
                    for(int j = 0;j<v2.size();j++){
                        v2[j].insert(v2[j].begin(),s.substr(0,i));
                        v1.push_back(v2[j]);
                    }
                }
            }
        }
        return v1;
    }
};