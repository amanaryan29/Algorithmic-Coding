    #include<iostream>
    #include<string>
    using namespace std;
    int update(int index,int val,int BITree[],int n)
    {
    	while(index<=n)
    	{
    		BITree[index]+=val;
    		index+=index&(-index);
    	}
    }
    int BITsum(int index,int BITree[])
    {
    	int sum=0;
    	while(index>0)
    	{
    		sum+=BITree[index];
    		index-=index&(-index);
    	}
    	return sum;
    }
    int main()
    {
    	int n,q,a,b,suma=0,sumb=0,i;
    	string s;
    	cin>>n>>q;
    	int BITree[1000001]={0};
    	while(q--)
    	{
    		cin>>s;
    		cin>>a>>b;
    		if(s.compare("add")==0)
    		{
    			update(a,b,BITree,n);
    		}
    		if(s.compare("find")==0)
    		{
    		  suma=BITsum(a-1,BITree);
    		    sumb=BITsum(b,BITree);
    		  	cout<<(sumb-suma)<<endl;
    		}

    	}
    }
