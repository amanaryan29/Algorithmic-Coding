    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {


        int n,t;
        cin>>n>>t;
        while(n!=0 || t!=0)
        {



        int time[n+1][n+1],toll[n+1][n+1];
        int dp[1005][55];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            cin>>time[i][j];
        }
    }
     for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            cin>>toll[i][j];
        }
    }
    memset(dp,500000,sizeof(dp));
    for(int i=0;i<=t;i++)
        dp[i][0]=0;
    for(int i=0;i<=t;i++)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-time[k][j]>=0)
                dp[i][j]=min(dp[i][j],toll[k][j]+dp[i-time[k][j]][k]);
    }
        }
    }

    int times=0;
    if(dp[t][n-1]>=500000)
        cout<<-1<<"\n";
    else
    {


    for(int i=t;i>=1;i--)
    {

         if(dp[i][n-1]==dp[t][n-1])
        {
           continue;
        }
        else if(dp[i][n-1]!=dp[t][n-1])
        {
           times=i+1;
            break;
        }

    }

        cout<<dp[t][n-1]<<" "<<times<<endl;

        }
        cin>>n>>t;
        }
    }
