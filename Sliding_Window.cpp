    #include<iostream>
    #include<algorithm>
    using namespace std;
    int main()
    {
    	int a[300001],n,m,i,max=0,s=0,k=0,flag=0,j,ans=0;
    	cin>>n>>m;
    	for(i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	for(i=0;i<n;i++)
    	{
    	if(s+a[i]==m)
    		{
    			flag=1;
    			break;
    		}
    	if(s+a[i]>m)
    	{
    		if(s>ans)
    		ans=s;
    		s=s+a[i];
    		while(s>m)
    		{
    			s-=a[k++];
    		}
    		if(s==m)
    		{
    			flag=1;
    			break;
    		}
    	}

    	else
    	s+=a[i];
    	//cout<<s<<endl;
    	}
    	if(flag==1)
    	cout<<m;
    	else
    	cout<<ans;

    }
