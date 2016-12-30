        #include<bits/stdc++.h>
        using namespace std;
        int main()
        {
        long long n,q;
        cin>>n>>q;
        while(n>0)
        {
        long long arr[n+1];
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
        cin>>arr[i];
        sum+=arr[i];
        }

        vector< bitset<61> > dp(sum+1LL);
        dp[0][0]=1;
        for(long long i=0;i<n;i++)
        {
        for(long long j=sum;j>=arr[i];j--)
        {

        dp[j]|=((dp[j-arr[i]])<<1LL);

        }

        }
        while(q--)
        {
        long long w;
        cin>>w;
        //cout<<dp[w]<<"\n";
        long long flag=0LL;
        for(long long i=1;i<=60;i++)
        {
        if(w>sum || w<=0LL)
        break;

        if(dp[w][i]!=0)
        {flag=1LL;
        cout<<i<<" ";
        }
        }
        if(flag==0LL)
        cout<<"That's impossible!";
        cout<<"\n";
        }
        cin>>n>>q;

        }
        }
