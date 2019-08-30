#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long int n,c=9;
	    cin>>n;
	    if(n<10)
	    cout<<n<<endl;
	    else
	    {
	        int i;
	        for(i=2;c<=n;i++)
	        c+=(i)*9*pow(10,i-1);
	        i--;
	        c-=(i)*9*pow(10,i-1);
	        int s=pow(10,i-1);
	        int d=(n-c)%i;
	        s--;
	        s+=(n-c)/i;
	        if(d==0)
	        cout<<s%10<<endl;
	        else
	        {
	            s++;
	            d=pow(10,i-d);
	            s/=d;
	            cout<<s%10<<endl;
	        }
	    }
	}
	return 0;
}