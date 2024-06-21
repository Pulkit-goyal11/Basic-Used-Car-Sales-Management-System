#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

void Line()
{
	cout<<endl<<"<______________________________________________>"<<endl;
}

class car{

	private:

	int rcnumber,age;
	char carname[25], newowner[26],carnum[25],oldowner[25],brand[15],type[10],rem[100];
	float distance,oldprice,newprice;

	public:

	void Feed_Info()
	{       clrscr();
		Line();

		cout<<endl<<"Brand of car to be sold:";
		gets(brand);
		cout<<endl<<"Type of car to be sold (name):";
		gets(type);
		cout<<endl<<"which car to be sold (name):";
		gets(carname);
		cout<<endl<<"who is selling(Seller):";
		gets(oldowner);
		cout<<endl<<"RC number:";
		cin>>rcnumber;
		cout<<endl<<"Car number {FULL}::";
		gets(carnum);
		cout<<endl<<"whom to be sold(Buyer):";
		gets(newowner);
		cout<<endl<<"Distance Travelled in total(in Km):";
		cin>>distance;
		cout<<endl<<"SHOWROOM price:";
		cin>>oldprice;
		cout<<endl<<"Years used( or old)in years:";
		cin>>age;

	}
	int rrcno()
	{return (rcnumber);
	}


	void save()
	{
		ofstream carfile;

		carfile.open("car.dat",ios::app|ios::binary);


	       carfile<<endl<<	"Brand of car to be sold:"<<brand<<endl;

	       carfile<<endl<<	"Type of car to be sold (name):"<<type;

	       carfile<<endl<<	"which car to be sold (name):"<<carname;

	       carfile<<endl<<"who is selling(Seller):"<<oldowner;

	       carfile<<endl<<	"RC number:"<<rcnumber;

	       carfile<<endl<<	"Car number {FULL}::"<<carnum;

	       carfile<<endl<<	"whom to be sold(Buyer):"<<newowner;

	       carfile<<endl<<	"Distance Travelled in total(in Km):"<<distance;

	       carfile<<endl<<	"SHOWROOM price::"<<oldprice;

	       carfile<<endl<<"Years used( or old)in years::"<<age;

	       carfile<<endl<<"Buyer's remark::"<<rem;
	       Line();

		carfile<<"NEW Price to be Paid:"<<newprice;

	       Line();

		carfile.close();

		cout<<endl<<"Done";
	}

	void modify(int);

	void CalcPrice()
	{

		if(distance<=2000||age<3)
		{
		  newprice=oldprice*0.8;
		}
		else if((distance<=5000&&distance>=2000)||(age<=5&&age>=3))
		{
			newprice=oldprice*0.6;
		}
		else if((distance<15000&&distance>5000)||(age<=11&&age>5))
		{
			newprice=oldprice*0.5;
		}
		else
		{
			newprice=oldprice*0.3  ;
		}

		Line();

		cout<<endl;
	}

	void Show_Price()
	{       clrscr();
		Line();
		cout<<endl<<"Brand of car to be sold:";
		puts(brand);
		cout<<endl<<"Type of car to be sold (name):";
		puts(type);
		cout<<endl<<"which car to be sold (name):";
		puts(carname);
		cout<<endl<<"who is selling(Seller):";
		puts(oldowner);
		cout<<endl<<"RC number:";
		cout<<rcnumber;
		cout<<endl<<"Car number {FULL}::";
		puts(carnum);
		cout<<endl<<"whom to be sold(Buyer):";
		puts(newowner);
		cout<<endl<<"Distance Travelled in total(in Km):";
		cout<<distance;
		cout<<endl<<"SHOWROOM price:";
		cout<<oldprice;
		cout<<endl<<"Years used( or old)in years:";
		cout<<age;

		Line();

		cout<<"NEW Price to be Paid:"<<newprice;

		Line();

	}
       void estage()

       {     clrscr();
	     Line();

		int x;

		cout<<"RULE::Estimated Age is as per rules of Pollution control department"<<endl<<endl;

		x=15-age;

		cout<<endl<<"Estimated age is::"<<x   ;

		Line();

		cout<<endl;
		}

	void remark()
	{clrscr();
	 cout<<endl<<"ENTER THE BUYER REMARK::"<<endl ;
	  gets(rem);
	}
	void alter()
	{  cout<<"\nEnter new carname:";
	   gets(carname);
	   cout<<"\nEnter new owner:";
	   gets(newowner);
	   cout<<"\nEnter new carnum:";
	   gets(carnum);
	   cout<<"\nEnter new age:";
	   cin>>age;
	}


};
void car::modify(int n)
	{car b;
	ifstream r("car.dat",ios::binary|ios::in);
	ofstream w("car1.dat",ios::binary|ios::out);
	while(r.read((char*)&b,sizeof(b)))
	{ if(n==b.rrcno())
	   { r.alter();
	     w.write((char*)&b,sizeof(b));
	     cout<<"Update success";
	   }
	  else
	  { w.write((char*)&b,sizeof(b));
	  }



	w.close();
	r.close();
	remove("car.dat");
	rename ("car1.dat","car.dat");
	}

void main()
{
	int yo;
	char choice,ch,ch1;

	car c1;
	do{clrscr();

	c1.Feed_Info();

	c1.CalcPrice();

	c1.estage();

	c1.remark();

	c1.Show_Price();


	cout<<endl<<"IS THE SECOND HAND CAR SOLD ? (Y/N)"<<endl;
	cin>>ch;



	if(ch=='Y'||ch=='Y')
	{  c1.save();
	}
	cout<<"\nwant to modify(y/n)";
	cin>>ch1;

	if(ch1=='y'||ch1=='Y')
	{ cout<<"which car you want to modify(rcno)";
	cin>>yo;
	  c1.modify(yo);

	}

	cout<<"\nIs there any other car to be sold?(y/n)";
	cin>>choice;
	}while(choice=='y'||choice=='Y');

	cout<<"___________________________THANK YOU__________________________";

	getch();
}
