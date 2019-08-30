//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    string s;
    int numRows;
    cin>>s>>numRows;
    //string Convert(string s, int numRows)
        if(numRows == 1) {
            cout<<s<<endl;
            return 0;
        }
        List<List<char>>zigZagList = new List<List<char>>();
        for(int i = 0; i<numRows; i++)
         zigZagList.Add(new List<char>());
         int row = 0;
         bool up = false;
         for(int i = 0; i<s.Length; i++){
             zigZagList[row].Add(s[i]);
             if(up==true){
                 row--;
                 if(row < 0){
                  up = false;
                  row = 1;
                 }
             }
             else{
                 row++;
                 if(row >= numRows){
                     row = numRows - 2;
                     up = true;
                 }
             }
         }
         var text = string.Empty;
         for(int i = 0; i<zigZagList.Count; i++){
            for(int j = 0; j<zigZagList[i].Count; j++)
                text+=zigZagList[i][j];

         cout<<text<<endl;
         return 0;
    }
}
