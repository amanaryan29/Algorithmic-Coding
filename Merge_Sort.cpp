    /*MERGE SORT*/
    #include<iostream>
    using namespace std;
    long long int s;
    long long int mergesort(long long int *left,long long int leftsize,long long int *right,long long int rightsize,long long int *A)
    {
    long long int	i=0;
    long long int	j=0;
    long long int	k=0;
    	while(i<leftsize && j<rightsize)
    	{
    		if((*(left+i))<(*(right+j)))
    		{
    			*(A+(k++))=*(left+(i++));

    		}
    			else
    		{
    			s+=(leftsize-i);
    			*(A+(k++))=*(right+(j++));


    		}

    	}
    	while(i<leftsize)
    	{
    		*(A+(k++))=*(left+(i++));
    }
    	while(j<rightsize)
    	{
    	*(A+(k++))=*(right+(j++));
    }

    }
    void merge(long long int *A,long long int n)
    {
    long long	int *left,*right,i,j;
    	//cout<<n<<endl;
        if(n<2)
        return;
        else
        {
        long long int	mid=(n/2);
        	left=new long long int[mid];
        	right=new long long int[n-mid];
        	for(i=0;i<mid;i++)
        	*(left+i)=*(A+i);         //Size of left array :mid
        	for(j=0;j<(n-mid);j++)  //Size of right array:(n-mid)
        	*(right+j)=*(A+(j+mid));
        	merge(left,mid);
        	merge(right,(n-mid));
        	mergesort(left,mid,right,(n-mid),A);
        }
    }
    int main()
    {
    long long	int n,i,t;
    //	cout<<"Enter the size of array";
    cin>>t;
    while(t--)
    {
    	s=0;
    	cin>>n;

    long long 	int *a;
    a=new long long int[n];
    	for(i=0;i<n;i++)
    	cin>>(*(a+i));


    	merge(a,n);

    	cout<<s<<endl;
    }

    }
