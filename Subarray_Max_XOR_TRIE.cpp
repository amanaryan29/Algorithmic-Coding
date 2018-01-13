/*Subham Sanghai*/
#include<bits/stdc++.h>
using namespace std;
int nodes[5000000][3];//nodes[x][0] stores nodes corresponding to 0 th bit,
//nodes[x][1] stores nodes corresponding to 1 th bit,
//nodes[x][2] stores the xor value for that nodes
int indexs=1;
int inserts(int value)
{
	int prev=0;
	for(int i=63;i>=0;i--)
	{
		int setvalue=(value&(1<<i));//Checks if that particular bit of the number is set or not
		if(setvalue>0)
		setvalue=1;
		if(nodes[prev][setvalue]==-1)//if there is no nodes at that place,then insert new nodes
			{
				nodes[prev][setvalue]=indexs;

				prev=indexs;
                 nodes[prev][2]=value;
				indexs++;

			}
			else
			{


				prev=nodes[prev][setvalue];
			}


	}
}
int query(int value)
{
int prev=0;
int flag=0;
	for(int i=63;i>=0;i--)
	{
		int setvalue=(value&(1<<i));//Checks if that particular bit of the number is set or not
			if(setvalue>0)
		setvalue=1;
		if((nodes[prev][1-setvalue])!=-1) //check if the opposite bit has an exisiting nodes,because if it is present then we can maximise our xor
		{

			prev=nodes[prev][1-setvalue];

		}
		else
		{
			prev=nodes[prev][setvalue];

		}

	}

	return nodes[prev][2];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ma=0;
		int count1=0;
		memset(nodes,-1,sizeof(nodes));
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		inserts(0);
		int p=0;
		for(int i=0;i<n;i++)
		{
			p=p^a[i];
			inserts(p);
			int vaall=p^query(p);

			ma=max(ma,vaall);
		}
		cout<<ma<<"\n";

	}
}
