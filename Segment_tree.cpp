    #include<bits/stdc++.h>
    using namespace std;
    int fr[100005];
    int tree[1000005];
     int a[100005];
    void build(int start,int ends,int node)
    {
        if(start==ends)
        {
            tree[node]=fr[start];

        }
        else
        {


        int mid=(start+ends)/2;
        build(start,mid,(2*node));
        build(mid+1,ends,(2*node)+1);
        tree[node]=max(tree[(2*node)],tree[(2*node)+1]);
        }
    }
    int range(int start,int ends,int qlow,int qhigh,int node)

    {

    if(qhigh<qlow)
        return 0;
    if(start>qhigh || ends<qlow)
        return 0;
        if(start>=qlow && ends<=qhigh)
            return tree[node];
            int mid=(start+ends)/2;
        int p1=range(start,mid,qlow,qhigh,(2*node));
        int p2=range(mid+1,ends,qlow,qhigh,(2*node)+1);
        return max(p1,p2);
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
    	cin.tie(false);

        int n;
        cin>>n;
        while(n!=0)
        {
            int q;
            cin>>q;



        map<int,int> freq;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            fr[i]=freq[a[i]];
        }

        build(1,n,1);
        //cout<<"bfehbkv";
        int pos[n+1];
            pos[1]=1;
        int index=1;
        for(int i=1;i<n;i++)
        {
            if((i+1)>n)
                break;
            if(a[i]==a[i+1])
            {

                pos[i+1]=index;
            }
            else
            {

        index=i+1;
        pos[i+1]=index;
            }
        }

    /*for(int i=1;i<=n;i++)
    cout<<pos[i]<<" ";
    cout<<"\n";*/
            while(q--)
            {
                int low,high;
                cin>>low>>high;
                if(a[low]==a[high])
                    cout<<(high-low+1)<<"\n";
                else
                {


                int p=pos[low]+fr[low]-1;
                int r=pos[high];
               // cout<<p<<" "<<r;
       int ans=max((p-low+1),max((high-r+1),range(1,n,p+1,r-1,1)));
                cout<<ans<<"\n";
                }
            }
            cin>>n;

    }
    }
