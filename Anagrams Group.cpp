/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
// Space Complexity O(n)
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res; //result vector
        set<string> order;   //string keys (ordered charactors)
        if (!strs.empty()){
            multimap<string,string> mmp; //hash map storing all the strings
            multimap<string,string>::iterator iit;
            vector<string>::iterator it; //scan the string vector
            for (it = strs.begin(); it!= strs.end();it++){
                string ss =  *it;
                sort(ss.begin(),ss.end()); //sort the string (if isanagram, the sorted string would be the same)
                mmp.insert(pair<string,string>(ss,*it)); //store in the hash map
                order.insert(ss); //store the key.
            }
              
            pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret;
            set<string>::iterator oit;
            for (oit=order.begin(); oit!=order.end(); oit++){ // for each key loop
                if (mmp.count(*oit) > 1){                     // anagram only if the number >1
                    ret = mmp.equal_range((*oit));  //get all the pairs with the specific key
                    for (iit=ret.first; iit!=ret.second; ++iit){ 
                        res.push_back((*iit).second);
                    }
                }
                  
            }
        }
        return res;
    }
};