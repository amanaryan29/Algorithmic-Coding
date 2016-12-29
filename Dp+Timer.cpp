    #include <bits/stdc++.h>

    using namespace std;
    string s;
    int n;
    int dp[200005][20];
    int vis[200005][20]={0};
    int tmr=0;
    int func(int index,int hops)
    {
        if(index>=n)
            return 0;
        if(vis[index][hops]==tmr)
            return dp[index][hops];
       // vis[index][hops]=tmr;
        int sum=0;
        if(s[index]=='N')
            sum=max(func(index+1,hops)-1,func(index+ 1 + (1<<(hops)),hops+1)-1);
        else
           sum=max(func(index+1,hops)+1,func(index+ 1 + (1<<(hops)),hops+1)-1);
           vis[index][hops]=tmr;
            return dp[index][hops]=sum;
    }
     int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
        int test;
        cin>>test;
        while(test--)
        {
            tmr++;
            //memset(dp,-1,sizeof(dp));
            cin>>s;
            n = s.length();;
          cout<<func(0,0)<<"\n";
        }
    }
