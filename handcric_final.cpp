#include"iostream"
#include"stdlib.h"
using namespace std;

int p1=0,h=8;

/*Code for hard*/
int predict(int w)
{
	int cc=0;
	if(h==w)
	{
		cc++;
	}
	else 
	{
		h=w;
		cc=1;
		return 0;
	}
	if(cc==2)
	{
		return 1;
	}
}

/*Code for input*/
int in()
{
	int z;
	cin>>z;
	while(z>6||z<0)
	{
		cout<<"\n\nEnter value between 0 and 6:";
		cin>>z;	
	}
	return z;
}

/*Code for bat/feild*/
int oppt()
{
	int s=3;
	cout<<"\n\nEnter your option:";
	cin>>s;
	while(s!=1&&s!=2)
	{
		cout<<"\n\nEnter a valid option....\n\nEnter your option:";
		cin>>s;
	}
}

/*Code for toss */
int toss()
{
	int t=10;
	while(t!=1&&t!=0)
	{
		cout<<"\n\nOdd(1) Or Even(0)\n\n";
		cin>>t;
	}
	int a=t;
	cout<<"\n\nEnter a number :";
	t=in();
	t=t+(rand()%6);
	if(t%2==a)
	{
		cout<<"\n\nYou have won the toss!!!\n\n";
		return 1;
	}
	else
	{
		cout<<"\n\nSystem has won the toss!!!\n\n";
		return 0;
	}
}

/*code for player1 batting*/
int pbat(int score,int ing)
{
	int c=0,b1,b2,flag=0,temp=0;
	cout<<"\n\n--------------------player 1 is Batting--------------------\n\n\nplayer1\t\tsystem\t\tscore\n";
	if(ing==1)
	{	
		while(1)
		{	
			if(flag==0)
			{	
				b2=(rand()%6+1);
			}
			else
			{
				b2=temp;
			}
			cout<<"Bat:";
			b1=in();
			temp=b1;
			flag=predict(b1);
			if(b1==b2)
			{
				cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
				cout<<"\n\nOUT\n\nYour score :"<<c;
				break;
			}
			c=c+b1;
			cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
		}
	}
	else
	{
		while(1)
		{		
			b2=(rand()%6+1);
			cout<<"Bat:";
			if(flag==0)
			{	
				b2=(rand()%6+1);
				temp=b2;
			}
			else
			{
				b2=temp;
			}
			if(b1==b2)
			{
				cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
				cout<<"\n\nOUT\n\nYour score :"<<c;
				break;
			}
			c=c+b1;
			cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
			if(score<c)
			{
				cout<<"player1 wins!!!!!!!!!!!!!";
				p1++;
				break;
			}
		}
	}
	return c;
}

/*code of system batting*/
int sysbat(int score,int ing)
{
	int c=0,b1,b2;
	cout<<"\n\n--------------------system is Batting--------------------\n\n\nplayer1\t\tsystem\t\tsystem score\n";
	if(ing==0)
	{	
		while(1)
		{		
			b2=(rand()%6+1);
			cout<<"Bowl:";
			b1=in();
			if(b1==b2)
			{
				cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
				cout<<"\n\nOUT!!!!!!!!!!!\n\nSystem score :"<<c;
				break;
			}
			c=c+b2;
			cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
		}
	}
	else
	{
		while(1)
		{		
			b2=(rand()%6+1);
			cout<<"Bowl:";
			b1=in();
			if(b1==b2)
			{
				cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
				cout<<"\n\nOUT\n\nSystem score :"<<c;
				break;
			}
			c=c+b2;
			cout<<"\n\n"<<b1<<"\t\t"<<b2<<"\t\t"<<c<<"\n\n\n";
			if(score<c)
			{
				cout<<"System wins!!!!!!!!!!!!!\n\n";
				break;
			}
		}
	}
	return c;
}

/*				MAIN			*/
int main()
{
	int score1=0,score2=0,x=0,ing=0,no=0,m=1,tos=0;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n----------------------------------------------------------------HaNd CrIcKeT!!!!!!!!---------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"--------------------------------------Menu--------------------------------------\n";
	cout<<"1.Triseries\n2.Fiveseries\n3.Your wish\n\nEnter the choise:";
	cin>>m;
	while(m>3||m<0)
	{
		cout<<"Enter a valid Choise..........\n\n";
		cout<<"--------------------------------------Menu--------------------------------------\n";
		cout<<"1.Triseries\n2.Fiveseries\n3.Your wish\n\nEnter the choise:";
		cin>>m;
	}
	
/*Code for Your wish*/
	if(m==3)
	{
		char n='y';
		while(n=='y'||n=='Y')
		{
			tos=toss();
			if(tos==1)
			{
				cout<<"Enter the option 1.batting (or) 2.bowling\n";
				x=oppt();
			}
			else
			{
				x=2;
			}
			no++;
			if(x==1)
			{
				ing=1;
				score1=pbat(score2,ing);
				score2=sysbat(score1,ing);
				if(score2<score1)
				{
					cout<<"\n\nPlayer 1 wins!!!!!!\n\n";
					p1++;
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}
			else if(x==2)
			{
				ing=0;
				score2=sysbat(score1,ing);
				score1=pbat(score2,ing);
				if(score2>score1)
				{
					cout<<"\n\nSystem wins!!!!!!\n\n";
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}
			cout<<"\n\nWant To Play One More Match??\nPress y for next match\n";
			cin>>n;
		}
						cout<<"\n\n\nTotal Number of Matches:"<<no<<"\nNo of Matches Won by Payer1:"<<p1<<"\nNo of Matches Won by system:"<<(no-p1);
	}

/*Code for Triseries*/
	else if(m==1)
	{
		no=3;
		while(no>0)
		{
			tos=toss();
			if(tos==1)
			{
				cout<<"Enter the option 1.batting (or) 2.bowling\n";
				x=oppt();
			}
			else
			{
				x=2;
			}
			no--;
			if(x==1)
			{
				ing=1;
				score1=pbat(score2,ing);
				score2=sysbat(score1,ing);
				if(score2<score1)
				{
					cout<<"\n\nPlayer 1 wins!!!!!!\n\n";
					p1++;
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}
			else if(x==2)
			{
				ing=0;
				score2=sysbat(score1,ing);
				score1=pbat(score2,ing);
				if(score2>score1)
				{
					cout<<"\n\nSystem wins!!!!!!\n\n";
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}

		}
						cout<<"\n\n\nTotal Number of Matches:"<<3<<"\nNo of Matches Won by Payer1:"<<p1<<"\nNo of Matches Won by system:"<<(3-p1);
	}
	
	
/*Code for Fiveseries*/
	else if(m==2)
	{
		no=5;
		while(no>0)
		{
			tos=toss();
			if(tos==1)
			{
				cout<<"Enter the option 1.batting (or) 2.bowling\n";
				x=oppt();
			}
			else
			{
				x=2;
			}
			no--;
			if(x==1)
			{
				ing=1;
				score1=pbat(score2,ing);
				score2=sysbat(score1,ing);
				if(score2<score1)
				{
					cout<<"\n\nPlayer 1 wins!!!!!!\n\n";
					p1++;
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}
			else if(x==2)
			{
				ing=0;
				score2=sysbat(score1,ing);
				score1=pbat(score2,ing);
				if(score2>score1)
				{
					cout<<"\n\nSystem wins!!!!!!\n\n";
				}
				else if(score1==score2)
				{
					cout<<"\n\nThe MATCH is a DRAW!!!!!!!\n\n";
				}
			}

		}
						cout<<"\n\n\nTotal Number of Matches:"<<5<<"\nNo of Matches Won by Payer1:"<<p1<<"\nNo of Matches Won by system:"<<(5-p1);
	}
	else
	{
		cout<<"WrOnG OpTiOn!!!!!!";
	}

	cout<<"\n\n\n\t\t\t\t\t\tTHANKYOU FOR PLAYING!!!!!!!!!!!!!!!!!!!!!!!!\n\n\t\t\t\t\t\t\t\tDeveloped by ViJaY\n\n";
	
	return 0;
}
