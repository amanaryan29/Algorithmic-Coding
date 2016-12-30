    #include<bits/stdc++.h>
    using namespace std;
    int dp[10][100];
    int arr[10];
    int a[105];
    int sieve()
    {
        fill(a,a+100,0);
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=10;i++)
        {
            if(a[i]==0)
            {
                for(int j=i*i;j<=100;j+=i)
                {
                    a[j]=1;
                }
            }
        }
    }

      int rec(int i,int s,bool check)
      {
          int r;
                if(i<=-1)
          {
              if(a[s]==0)
                return 1;
              else
                return 0;
          }
          if(!check && dp[i][s]!=-1)
            return dp[i][s];
            if(check==true)
            {
                r=arr[i];
            }
            else
                r=9;
                int ans=0;
          for(int j=0;j<=r;j++)
          {
              ans+=rec(i-1,s+j,check&&(j==r));
          }
          if(!check)
            dp[i][s]=ans;
          return ans;
      }
      int digits(int i)
    {
        int k=0;
      while(i!=0)
      {
          int d=i%10;
          arr[k++]=d;
          i=i/10;
      }
     return  rec(k-1,0,true);
      }
    int main()
    {
        int t;
        cin>>t;
        sieve();
        memset(dp,-1,sizeof(dp));
        while(t--)
        {

            int f,l;
            cin>>f>>l;
            cout<<digits(l)-digits(f-1)<<"\n";
        }
    }
