#include<bits/stdc++.h>
using namespace std;

string convert(string exp)
{
  int i,j,k;
  string res="";
  stack<int> st;
  for(i=0;i<exp.length();)
  {
     if(isalpha(exp[i]))
     {
         int l=res.length();
        if(l!=0)
         {if((res[l-1]=='+' || res[l-1]=='-'))
           res+=exp[i];
          else
          {
              if(st.empty() || st.top()==0)
             res+='+';
            else
             res+='-';
             res+=exp[i];
          }
         }
         else
         {
            if(st.empty() || st.top()==0)
             res+='+';
            else
             res+='-';
             res+=exp[i];
         }
         i++;
     }
     else
     if(exp[i]=='+' || exp[i]=='-')
     {
        if(st.empty() || st.top()==0)
        {
          if(isalpha(exp[i+1]))
          {
              res+=exp[i];
              i++;
          }
          else
          {
             if(exp[i]=='+')
              st.push(0);
             else
              st.push(1);
             i+=2;
          }
        }
        else
        {
          if(isalpha(exp[i+1]))
          {
              if(exp[i]=='+')
               res+='-';
              else
               res+='+';
               i++;
          }
          else
          {
              if(exp[i]=='+')
               st.push(1);
              else
               st.push(0);
              i+=2;
          }
        }
     }
     else
     if(exp[i]=='(')
     {
        st.push(0);
        i++;
     }
     else
     if(exp[i]==')')
     {
         st.pop();
         i++;
     }
  }
 return res;
}

string eval(string s)
{
    vector<int> pos(26,0);
	vector<int> neg(26,0);
	string res="";
	int i,j,k;
	for(i=0;i<s.length()-1;i+=2)
	{
	  if(s[i]=='+')
	  {
	      pos[s[i+1]-'a']++;
	  }
	  else
	  {
	      neg[s[i+1]-'a']++;
	  }
	}
	for(i=0;i<26;i++)
	{
	   int p,n;
	   p=pos[i];
	   n=neg[i];
	   if(p>n)
	   {
	    int diff=p-n;
	    if(diff!=0)
	    {
	     res+='+';
	     res+=to_string(diff);
	     res+='a'+i;
	    }
	   }
	   else
	   {
	   int diff=n-p;
	   if(diff!=0)
	   {
	     res+='-';
	     res+=to_string(diff);
	     res+='a'+i;
	   }
	   }
	}
 return res;
}

int main()
 {
	//code
	int i,j,k,t,T;
	cin>>T;
	for(t=0;t<T;t++)
	{
	    string e1,e2;
	    cin>>e1>>e2;
	    string s1,s2;
	    s1=convert(e1);
	    s2=convert(e2);
	    //cout<<s1<<" "<<s2<<"\n";
	    string f1="",f2="";
	    f1=eval(s1);
	    f2=eval(s2);
	    //cout<<f1<<" "<<f2<<"\n";
	    if(f1==f2)
	     cout<<"YES\n";
	    else
	     cout<<"NO\n";
	}
	return 0;
}