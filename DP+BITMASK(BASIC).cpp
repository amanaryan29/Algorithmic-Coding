        #include<bits/stdc++.h>
        using namespace std;
         int n;
         int arr[22][22];
        long long int dp[22][1050000];
        long long int solve(int ind, int mask)
        {
            if(ind==n)
                return 1;
                if(dp[ind][mask]!=-1)
                    return dp[ind][mask];
            long long int ans=0;
            for(long long int i=0;i<n;i++)
            {
                if(arr[ind][i]==1)
                {
                    if((mask&(1<<i))==0)
                    {
                       ans=ans+solve(ind+1,(mask|(1<<i)));
                    }
                }
            }
            return dp[ind][mask]=ans;
        }
         int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(false);
            int t;
            cin>>t;
            while(t--)
            {
                memset(dp,-1,sizeof(dp));
                cin>>n;
                for( int i=0;i<n;i++)
                {
                    for( int j=0;j<n;j++)
                        cin>>arr[i][j];
                }
                long long int r=solve(0,0);
                cout<<r<<"\n";
            }
            return 0;
        }
