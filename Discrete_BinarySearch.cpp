#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            sort(a,a+n);
            int ans=0;
        int start=0;
        int ends=a[n-1];
        while(start<=ends)
        {
            int mid=(start+ends)/2;
            int k=a[0];
            int count1=1;
            for(int i=1;i<n;i++)
            {
                if((a[i]-k)>=mid)
                {
                    count1++;
                    k=a[i];
                }
            }
            if(count1>=c)
            {
                ans=max(ans,mid);
                start=mid+1;
            }
            else
                ends=mid-1;

            }
            cout<<ans<<endl;
    }
}
