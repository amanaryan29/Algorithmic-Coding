#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,s,t;
	string arr;
	cin>>arr;
	while(arr!="00e0")
	{
		 int sa=((int) arr[0])-48;
		int sb=((int) arr[1])-48;
		int sc=((int) arr[3])-48;
		s=((sa*10)+sb)*pow(10,sc);
		t=log(s)/log(2);
		a=s-pow(2,t);
		cout<<(2*a)+1<<endl;
		cin>>arr;
	}
}
