/*BIT*/
#include<bits/stdc++.h>
using namespace std;
long long bit[200005];
long long n;
void update(long long x,long long val)
{
    while(x<=n)
    {
        bit[x]+=val;

        x+=(x&(-x));
    }
}
long long query(long long x)
{
    long long s=0;
    while(x>0)
    {
        s+=bit[x];
        x-=(x&(-x));
    }
    return s;
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {

        cin>>n;
memset(bit,0,sizeof(bit));
        vector<pair<long long,long long> > v,v2;
        long long arr[n+1];
        for(long long i=1;i<=n;i++)
        {
            cin>>arr[i];
            v.push_back(make_pair(arr[i],i));
        }
        sort(v.begin(),v.end());
        long long counts=1;
       v2.push_back(make_pair(v[0].second,1));
        for(long long i=0;i<v.size();i++)
        {
            if(i+1==v.size())
                break;
            if(v[i].first==v[i+1].first)
            {
                v2.push_back(make_pair(v[i+1].second,counts));
            }
            else
            {


                counts++;
                 v2.push_back(make_pair(v[i+1].second,counts));
            }
        }
  long long ans=0;



       long long ma= v2[(v2.size()-1)].second;

        sort(v2.begin(),v2.end());
        for(long long i=v2.size()-1;i>=0;i--)
        {

            ans+=query(v2[i].second-1); //CHECKING IF HOW MANY NUMBERS FROM (PRESENT NO.+1) TO MAX HAVE ALREADY ARRIVED .THEREFORE CONTRIBUTING TO ANS (INVERSIONS)
//cout<<ans<<"\n";

            update(v2[i].second,1);

        }
        cout<<ans<<"\n";
    }
}
