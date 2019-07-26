#include <iostream>
using namespace std;
const int n=100;
class Integerset
{
public:
	Integerset(int *b,int k1=0)
	{
	    if(k1!=0)
		{
			if(k1>n) cout<<"construct failled"<<endl;
			else 
			{
				a = new int[100];//不需要声明a,yinwei a wei ci lei de shujuchengyuan;
				int i;
				for(i=0;i<k1;i++)
					a[i]=b[i];
					
			}
		}//注意，没有分号；
		else a=NULL;//?
		k=k1;
	  }


	Integerset(int m=-1,int b=-1,int c=-1,int d=-1,int e=-1 )//a为指针，a[n]为数组元素；
	{
		a = new int[5];
		a[0]=m;
		a[1]=b;
		a[2]=c;
		a[3]=d;
		a[4]=e;
		k=5;
	}
	Integerset(Integerset &c1);
	~Integerset()
	{
		cout<<"Destructor callde;"<<endl;
	}
	void Delete();
	void operator=(Integerset &c2);
	friend Integerset operator||(Integerset c1,Integerset c2);
	friend Integerset operator&&(Integerset c1,Integerset c2);
	friend void operator+(Integerset c1,int x);//bufanhui Integerset xing de fanhuizhi,yunyong chongzai yunzuanfu fuzhi.
	friend void operator-(Integerset c1,int x);
	friend int operator>(Integerset c1,Integerset c2);
	friend int operator<(Integerset c1,Integerset c2);//guanxiyusuanfu:<>...
	friend int operator!(Integerset &c1);
	//friend void operator=(Integerset c1,Integerset c2);//???????weisha=buxing?
	friend ostream& operator<<(ostream& ,Integerset c1);
	//friend istream& operator>>(istream& ,Integerset c1);

private:
	int *a;
	int k;
};
Integerset::Integerset(Integerset &c1)
{
	a=new int [c1.k];
	for(int i=0;i<c1.k;i++)
	{
		a[i]=c1.a[i];
	}
	k=c1.k;
	cout<<"copy structrure fuction is  called "<<endl;
}
void Integerset::Delete()
{
	   delete []a;
};
Integerset operator||(Integerset c1,Integerset c2)//bingji
{
	int m=c1.k;//int i=c1.i+c2.i//a=new int[c1.k];//int *b	//for(int i=0;i<c1.k;i++)//{
	for(int i=0;i<c2.k;i++)
	{
		for(int n=0;n<c1.k;)
		{
			if(c2.a[i]!=c1.a[n])
				n++;
			else
				c2.a[i]=0;//you yuan han shu gai bian privte chengyuan de zhi;
				break;
		}
		if(c2.a[i]!=0) m++;
			//int*p[m]=new int (c2.a[i]);
	}
	int *c=new int[m];
	for(int i=0;i<c1.k;i++)
	{
		c[i]=c1.a[i];
	}
	for(int i=0,n=0;i<c2.k;)
	{
		if(c2.a[i]!=0)
		{
			n++;
			c[c1.k+n-1]=c2.a[i];
			i++;
		}
		else
		{
			i++;
		}
	}
	return (Integerset(c,m));//duibi,yiyang,yu p.
}
Integerset operator&&(Integerset c1,Integerset c2)
{
	int m=0;
	int n=0;
	for(int i=0;i<c2.k;i++)
	{//c2zhongyuan su a[i]
		for(int j=0;j<c1.k;j++)
		{
			if(c2.a[i]==c1.a[j])
			{
				m++;
				break;//break tiaochuxunhuan;
			}
		} 
	}
	int*p=new int[m];//yu p=...yi yang,p ye wei shou yuan su de dizhi.
	for(int j=0;j<c2.k;j++)
	{
		for(int i=0;i<c1.k;i++)
		{
			if(c2.a[j]==c1.a[i])
			{
				p[n]=c2.a[j];
				n++;
				break;
			}
		}
	}
    	return (Integerset(p,m));//p wei shou yuansu de dizhi.
}//wu fen hao.
//kong le cha ru yu shan chu.
int operator>(Integerset c1,Integerset c2)//flag=1,=
{
	int flag=1;
	if (c1.k!=c2.k) return 0;
	else 
	{
		for(int j=0;j<c1.k;j++)
		{			for(int i=0;i<c1.k;i++)
			{
				if(c2.a[j]!=c1.a[i]) 
					flag=0;
					break;
			}
			if(flag=0) break;
		}
		return flag;
	}
}
int operator<(Integerset c1,Integerset c2)
{
	int flag=0;
	if(c1.k!=c2.k) return 1;
	else
	{
		for(int j=0;j<c1.k;j++)
		{
			for(int i=0;i<c1.k;i++)
			{
				if(c2.a[j]!=c1.a[i])
					flag=1;
				    break;
			}
			if(flag=1)
				break;
		}
	return flag;
	};
}
int operator!(Integerset &c1)
{
	if(c1.a==NULL)
		return 0;
	else
		return 1;
}
void Integerset::operator=(Integerset &c2)//为啥不能用=？
{
	delete []a;
	a=new int[c2.k];
	for(int i=0;i<c2.k;i++)
	{
		a[i]=c2.a[i];//a shi cheng yuan.
	}
}
ostream& operator<<(ostream& output,Integerset c1)///?????????
{
	for(int i=0;i<c1.k;i++)
	{
		if(c1.a==NULL) output<<"---"<<endl;
		else if((i+1)%5==0) output<<c1.a[i]<<' '<<endl;
		else output<<c1.a[i]<<' ';
	}
	return output;
}

void operator+(Integerset c1,int x)
{
	for(int i=0;i<c1.k;i++)
	{
		if(x==c1.a[i])
		{
			cout<<"the number you wanted to insert into this group is aready existed"<<endl;
			break;
		}
		else
		{
			int *c=new int[c1.k+1];
			for(int i=0;i<c1.k;i++)
			{
				c[i]=c1.a[i];
			}
			c[c1.k]=x;
			c1=Integerset(c,c1.k+1);//用到了＝的重载运算符，全局函数，不需设为此函数的友元函数；且不需重建ｃ１；
			delete []c;
		}
	}
}
void operator-(Integerset c1,int x)
{
	int flag=1;
	int place;
	for(int i=0;i<c1.k;i++)
	{
		if(x==c1.a[i])
		{
			flag=0;
			place=i+1;
			break;
		}
	}
	if(flag) cout<<"the number you wanted to delete is not exisisted"<<endl;
	else
	{
		int *c=new int[c1.k-1];
		for(int i=0;i<place-1;i++)
		{
			c[i]=c1.a[i];
		}
		for(int i=place-1;i<c1.k-1;i++)
		{
			c[i]=c1.a[i+1];
		}
		c1=Integerset(c,c1.k-1);
		delete []c;
	}
} 
int main()
{
	int b[6]={1,2,3,12,13,14};
	int c[9]={1,2,3,4,5,6,7,8,9};
	Integerset c1(c,9);
	Integerset c2(b,6);
	Integerset c3=c1||c2;
	cout<<"c1 || c2="<<"{"<<endl<<c3<<endl<<"}"<<endl;
	Integerset c4=c1&&c2;
	cout<<"c1 && c2="<<"{"<<endl<<c4<<endl<<"}"<<endl;
	Integerset c10;
	c1+19;
	c10=c1;
	cout<<"c1+19="<<"{"<<endl<<c10<<endl<<"}"<<endl;
	Integerset c9;
	c1-1;
	c9=c1;
	cout<<"c1-1="<<"{"<<endl<<c9<<endl<<"}"<<endl;
	if(c1>c2) cout<<"c1==c2"<<endl;
	else cout<<"c1!=c2"<<endl;
	if(c1<c2) cout<<"c1!=c2"<<endl;
	else cout<<"c1==c2"<<endl;
	if(!c1) cout<<"C1 this group is not empty;"<<endl;
	else cout<<"C1 this group is empty;"<<endl;
	cout<<"please enter the numner you wanted to add to this goup;"<<endl;
	int q;
	cin>>q;
	c1+q;
	cout<<"after adding the number "<<q<<"; c1 is "<<"{ "<<c1
		<<" }"<<endl;
	Integerset c7(1,2,3,4);
	cout<<"c7"<<"{ "<<c7<<" }"<<endl;
	Integerset c8(c1);
	cout<<"c8"<<c8<<endl;
	return 0;
}





















				 











				




