    //***meet in the middle************AC
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);
    #define f(i,s,e) for(i=s;i<=e;i++)
    #define INF 10000000000
    #define PII pair<ll, int>;
    #define mp make_pair
    #define pb push_back
    ll power(ll x,ll y)
    {
        if(y==0) return 1;
        ll ans=x;
        for(ll z=2;z<=y;z++)
            ans=ans*x;
        return ans;
    }
    int main()
    {
        ll t,tc=0;
        cin>>t;while(t--)
        {
            tc++;
            string str;
            ll N,flag=0;
            ll i,j;
            scanf("%lld",&N);
            ll sum=0;
            ll n=N/2;
            //ll m=power(2,n);
            ll arr[N+5];
            vector<pair<ll,ll> > arr1,arr2;
            vector<pair<ll,ll> > :: iterator itr;
            for(i=1;i<=N;i++)
            {
                scanf("%lld",&arr[i]);
                sum+=arr[i];
            }
            if (sum%2 || N%2)
            {
                str="No";
                printf("Case %lld: ",tc);
                cout<<str<<endl;
                flag=0;
                continue;
            }
            ll req=sum/2;
            ll x=power(2,n);
            ll bit=log2(x-1)+1;
            //memset(arr1,0,sizeof(arr1));
            //memset(arr2,0,sizeof(arr2));
            //cout<<"mishra"<<endl;
            for(i=0;i<x;i++)
            {
                ll suum=0,cnt=0;
                for(j=0;j<bit;j++)
                {
                    if( i & (1 << j) /*&& arr1[i].size()>0*/ )
                    { //cout<<i<<" "<<j<<endl;
    //                    itr=arr1[i].begin();
    //                    //itr--;
    //                    arr1[i].clear();
    //                    arr1[i].pb({itr->first+arr[j+1],itr->second+1});
                          suum+=arr[j+1];
                          cnt++;
                    }
                }
                arr1.pb({suum,cnt});
            }
            //cout<<"walnut"<<endl;
            for(i=0;i<x;i++)
            {
                ll suum=0,cnt=0;
                for(j=0;j<bit;j++)
                {
                    if( i & (1 << j) /*&& arr2[i].size()>0*/ )
                    {
    //                    itr=arr2[i].begin();
    //                    //itr--;
    //                    arr2[i].clear();
    //                    arr2[i].pb({itr->first+arr[j+1],itr->second+1});
                          suum+=arr[j+1+n];
                          cnt++;
                    }

                }
                //arr2[i].pb({itr->first+arr[j+1],itr->second+1});
                arr2.pb({suum,cnt});
            }
            //cout<<"aman"<<endl;
            sort(arr2.begin(),arr2.end());
            //for(i=0;i<arr1.size();i++) cout<<arr1[i].first<<" "<<arr1[i].second<<"      ";cout<<endl;
           // for(i=0;i<arr2.size();i++) cout<<arr2[i].first<<" "<<arr2[i].second<<"      ";cout<<endl;
            bool f=0;
            //cout<<arr1.size()<<" "<<arr2.size()<<endl;
            for(i=0;i<arr1.size() and !f;i++)
            {
                ll a=arr1[i].first;
                ll num=arr1[i].second;
                ll b=req-a;
                ll low=0;
                //ll high=x-1;
                ll high=arr2.size()-1;
                while(low+1<high and !f)
                {
                    //cout<<b<<"   "<<low<<"       "<<high<<endl;
                    //cout<<i<<"   "<<f<<endl;
                    ll mid=(low+high)/2;
                    if(arr2[mid].first<b) low=mid;
                    else if(arr2[mid].first>b) high=mid;
                    else if(arr2[mid].first==b and arr2[mid].second+num==n )
                            f=1;
                    else
                    {
                        for(j=mid+1;arr2[j].first==b and !f;j++)
                            if(arr2[mid].second+num==n)
                                f=1;
                        for(j=mid-1;arr2[j].first==b and !f;j--)
                            if(arr2[mid].second+num==n)
                                f=1;
                        break;
                    }
                }
            }
            if(f) str="Yes";
            else str="No";
            printf("Case %lld: ",tc);
            cout<<str<<endl;
        }
    }
