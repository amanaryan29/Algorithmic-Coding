    #include<bits/stdc++.h>
    using namespace std;
    string arr,brr;
    int n,m;
    int dp[2005][2005];

    int func(int i,int j)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
            if(dp[i][j]!=-1)
                return dp[i][j];
        if(arr[i-1]==brr[j-1])
            return dp[i][j]=func(i-1,j-1);
        else
            return dp[i][j]=1+min(func(i-1,j),min(func(i,j-1),func(i-1,j-1)));

    }
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            memset(dp,-1,sizeof(dp));
            cin>>arr>>brr;
            n=arr.length();
            m=brr.length();
            cout<<func(n,m)<<endl;

        }
    }
