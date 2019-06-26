#include<iostream>
using namespace std;

int main()
{
	int i,j,c,b,s,d;
	cout<<"Please enter the size of the house:";
	cin>>b;
	cout<<"\n\n";
	if(b%2==1)
	{
		b=b+1;
	}	
	s=b/2;
	d=b/4+1;
	c=s-1;
	for(i=3;i<=s;i++)
	{
		cout<<" ";
	}
	cout<<"HOUSE\n\n";
	for(i=0;i<=s;i++)
	{
		for(j=0;j<=b;j++)
		{
			if(j<=c||j>=(b-c))
				cout<<" ";
			else
				cout<<"-";
		}
		cout<<endl;
		c=c-1;
	}
	for(i=0;i<=s;i++)
	{
		for(j=0;j<=b;j++)
		{
			if(i==s)
			{
				cout<<"-";
			}
			else if((j==d||j==(b-d))&&i>(d-1))
			{
				cout<<"|";
			}
			else if(i==(d-1)&&(j>=d)&&(j<=b-d))
			{
				cout<<"-";
			}
			else if(((j==0)||(j==b))&&(i!=s))
			{
				cout<<"|";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"\n\n\n";
	return 0;
}
