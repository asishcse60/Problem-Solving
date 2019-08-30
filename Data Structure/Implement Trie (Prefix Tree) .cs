/*
Complexity : O(number of character)
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.*/
class TrieNode {
    // Initialize your data structure here.
    public bool isWordEnd{get;set;}
    public TrieNode [] children;
    private char curChar{get;set;}
    public TrieNode() {
        children = new TrieNode[26];
    }
    public TrieNode(char ch){
       this.curChar = ch;
       children = new TrieNode[26];
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void Insert(String word) {
        TrieNode curNode = root;
        for(int i = 0; i<word.Length; i++){
         char c = word[i];
         if(curNode.children[c - 'a'] == null)   {
            curNode.children[c - 'a'] = new TrieNode(c); 
         }
            curNode = curNode.children[c - 'a'];
        }
        curNode.isWordEnd = true;
    }

    // Returns if the word is in the trie.
    public bool Search(string word) {
        TrieNode curNode = root;
        int i;
        for(i = 0; i<word.Length; i++){
           char c = word[i];
           if(curNode.children[c - 'a'] == null)
                break;
           curNode = curNode.children[c - 'a'];     
        }
        if(i == word.Length && curNode.isWordEnd == true){
        
             return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public bool StartsWith(string word) {
        TrieNode curNode = root;
        int i;
        for(i = 0; i<word.Length; i++){
           char c = word[i];
           if(curNode.children[c - 'a'] == null)
                break;
           curNode = curNode.children[c - 'a'];     
        }
        if(i == word.Length){
             return true;
        }
        return false;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.Insert("somestring");
// trie.Search("key");