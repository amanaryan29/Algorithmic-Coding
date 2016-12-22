#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		string A,B;
		cin>>A>>B;
		int l1=A.length();
		int l2=B.length();
		A=A+'$'+B+B;
		int n=A.length();
		int L = 0, R = 0;
		int z[n+1];
		fill(z,z+n+1,0);
		for (int i = 1; i < n; i++)
		{
    		if (i > R)
    		{
        		L = R = i;
       		 while (R < n && A[R-L] == A[R])
        		{
            		R++;
        		}
        		z[i] = R-L;
        		R--;
    		}
    		else
    		{
        		int k = i-L;
        		if (z[k] < R-i+1)
        		{
            		z[i] = z[k];
        		}
        		else
        		{
            		L = i;
            		while (R < n && A[R-L] == A[R])
            		{
                		R++;
            		}
            		z[i] = R-L;
            		R--;
      		 	 }
    		}
    	}
    	int count1=0;
    	for(int i=l1+1;i<(l1+1+l2);i++)
    	{
    		if(z[i]==l1)
    			count1++;
    	}
    	cout<<count1<<"\n";
    	}
    }
