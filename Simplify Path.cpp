/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        path.push_back('/');
        int sz = path.size() , ptr = 0, lst = 0;
        for(int i = 0; i<sz; i++){
            
            if(path[i] == '/'){
                if(i>=2 && path[i-1]=='.' && path[i-2] == '.'){
                    while(--ptr>-1)
                      if(path[ptr]=='/') break;
                    ptr = (ptr<0)?0:ptr;  
                }
                else if(i>=1 && path[i-1]!='/' && path[i-1]!='.'){
                    for(int j = lst; j<i; j++) 
                        path[ptr++] = path[j];
                }lst = i;
            }
        }
        if(ptr==0) {path = "/"; ptr++;}
        path.resize(ptr);
        return path;
    }
};