    #include<bits/stdc++.h>
    using namespace std;
    long long dp[1000006];
    long long  rec(long long n)
    {
        if(n<=0)
            return 0;
            if( n<=1000000)
            {

            if(dp[n]!=-1)
                return dp[n];
            }
            if(n<=1000000)
            return dp[n]=max(n,rec(n/2)+rec(n/3)+rec(n/4));
              else
            return max(n,rec(n/2)+rec(n/3)+rec(n/4));

    }
    int main()
    {
        long long n;
        memset(dp,-1,sizeof(dp));
        while(cin>>n)
        {
            cout<<rec(n)<<"\n";
                }
    }
