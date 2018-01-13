    #include<bits/stdc++.h>
    #define ll long long int
    #define mod 1000000007
    #define sf(n) scanf("%lld",&(n))
    #define pf(n) printf("%lld\n",(n))
    using namespace std;
    ll a[10][10]={{1,4,4,3,4,3,3,2,3,3},{0,1,1,0,1,0,1,0,0,0},{0,1,0,1,0,1,0,0,0,1},{0,0,1,0,1,0,0,0,1,0}
    ,{0,1,0,1,0,0,0,1,0,1},{0,0,1,0,0,0,1,0,1,0},{0,1,0,0,0,1,0,1,0,0},{0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,1,0,0,0,1},{0,0,1,0,1,0,0,0,1,0}};
    ll b[10][10]={{1,4,4,3,4,3,3,2,3,3},{0,1,1,0,1,0,1,0,0,0},{0,1,0,1,0,1,0,0,0,1},{0,0,1,0,1,0,0,0,1,0}
    ,{0,1,0,1,0,0,0,1,0,1},{0,0,1,0,0,0,1,0,1,0},{0,1,0,0,0,1,0,1,0,0},{0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,1,0,0,0,1},{0,0,1,0,1,0,0,0,1,0}};
    ll c[10]={4,1,1,1,1,1,1,1,1,1};
    void reg()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                a[i][j]=b[i][j];
        }
    }
    void mul(ll mat[][10])
    {
        ll d[10][10];
        memset(d,0,sizeof(d));
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<10;k++)
                {
                    d[i][j]=(d[i][j]%mod+(a[i][k]%mod*mat[k][j]%mod)%mod)%mod;

                }
            }
        }
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                a[i][j]=d[i][j];
        }
    }
    void power(ll n)
    {
        if(n==0|| n==1)
            return;
        power(n/2);
        mul(a);
        if(n%2==1)
        mul(b);
    }
    int main()
    {
        ll t;
        sf(t);
        while(t--)
        {
            reg();
            ll n;
            sf(n);
            if(n==0)
                pf((0LL));
            else if(n==1)
                pf((4LL));
            else
            {
                power(n-1);
                ll ans=0;
                for(int i=0;i<10;i++)
                    ans=(ans%mod+(a[0][i]%mod*c[i]%mod)%mod)%mod;
                pf(ans);
            }

        }
    }
