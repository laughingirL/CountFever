using namespace std;
void primefactorize(); //�ֽ�������ģʽ
void hexconver(); //����ת��ģʽ
inline char hexnumtochar(const int n); //����ת�ɸ߽����е���ĸ
inline int hexchartonum(const char c); //���߽����е���ĸת����
void hexturn(unsigned __int64 n,const int h); //��ʮ������ת���������
void triangle(const bool degreemode,const bool fracoutmode,double *(mempoint[ ])); //��������ģʽ
inline short shape(const double a,const double b,const double c,const double A,const double B,const double C); //�жϲ���������ε���״
void lineout(const double x1,const double y1,const double x2,const double y2,const bool fracoutmode); //���ֱ�߷���
void pointout(const double x,const double y,const bool fracoutmode); //����������
double inputangle(const char angle,double *(p[ ]),const bool degreemode); //���������εĽ�
double inputside(const char side,double *(p[ ])); //���������εı߳�
void help(); //����
/*----------------------------------------------------------------------------------------------------------*/
void primefactorize()
{
	unsigned __int64 m,n,i,q=1;
	short k,p;
	bool t,t2;
	char tempnum[50];
	cout<<"����һ�������� : ( 1 -- 9999999999999999999 ) \n";
	do
	{
		n=0;
		cin.getline(tempnum,50,'\n');
		for(i=0;i<=strlen(tempnum)&&i<=18;i++)
			if(tempnum[i]>='0'&&tempnum[i]<='9')
			{
				n*=10;
				n+=tempnum[i]-48;
			}
			else break;
		if(n==0&&strlen(tempnum)>0)cout<<"�������������������������� :\n";
	}while(n==0);
	m=n;
	if(m==1)
	{
		cout<<"1�Ȳ�������Ҳ���Ǻ���\n";
		return;
	}
	t=t2=0;
	for(i=2;i*i<=m; )
	{
		k=0;
		p=1;
		while(n%i==0)
		{
			t=1;
			p++;
			k++;
			n/=i;
		}
		q*=p;
		if(k>0)
		{
		    if(t2==0)
			{
			    printf("%I64u = ",m);
			    t2=1;
			}
			else cout<<" * ";
			printf("%I64u",i);
			if(k>1)cout<<"^"<<k;
		}
		if(n==1)break;
		if(i>2)i+=2;
		else i++;
	}
	if(t==0)printf("%I64u������\n",m);
	else if(n==1)cout<<endl;
	else 
	{
		printf(" * %I64u\n",n);
		q*=2;
	}
	if(t)printf("%I64u �� %I64u ��Լ��\n",m,q);
}
/*----------------------------------------------------------------------------------------------------------*/
inline int hexchartonum(const char c)
{
	if(c>=48&&c<=57)return c-48;
	if(c>=65&&c<=90)return c-55;
	if(c>=97&&c<=122)return c-61;
	return -1;
}
/*----------------------------------------------------------------------------------------------------------*/
inline char hexnumtochar(const int n)
{
	if(n>=0&&n<=9)return n+48;
	if(n>=10&&n<=35)return n+55;
	return n+61;
}
/*----------------------------------------------------------------------------------------------------------*/
void hexturn(unsigned __int64 n,const int h)
{
	int i=n%h;
	n/=h;
	if(n>0)hexturn(n,h);
	cout<<hexnumtochar(i);
}
/*----------------------------------------------------------------------------------------------------------*/
void hexconver()
{
	int h1,ds,i,d=0,n[100]={0};
	unsigned __int64 number=0,m=1;
	char tempnum[100];
	cout<<"ѡ����������Ľ��� : ( 2 -- 62 )\n";
	cin.getline(tempnum,20,'\n');
	h1=atoi(tempnum);
	if(h1>62||h1<2)
	{
		cout<<"ѡ��ģʽ����\n";
		return;
	}
	ds=gauss(log(pow(2,63))/log(h1));
	cout<<"����һ�������� : ( 1λ�� -- "<<ds<<"λ�� , ���ִ�Сд )\n";
	do
	{
		for(i=0;i<100;i++)
			tempnum[i]='\0';
		cin.getline(tempnum,100,'\n');
		for(i=0;i<strlen(tempnum)&&i<ds;i++)
			if(hexchartonum(tempnum[i])>=0&&hexchartonum(tempnum[i])<h1)
			{
				d++;
				n[d]=hexchartonum(tempnum[i]);
			}
			else break;
		if(d==0&&strlen(tempnum)>0)cout<<"�������������������������� :\n";
	}while(d==0);
	cout<<"\n  ";
	for(i=1;i<=d;i++)
		cout<<hexnumtochar(n[i]);
	cout<<" ( "<<h1<<" ) \n";
	for(i=d;i>=1;i--)
	{
		number+=m*n[i];
		m*=h1;
	}
	for(i=2;i<=62;i++)
	{
		if(i==h1)continue;
		cout<<"= ";
		hexturn(number,i);
		cout<<" ( "<<i<<" ) \n";
	}
}
/*----------------------------------------------------------------------------------------------------------*/
void triangle(const bool degreemode,const bool fracoutmode,double *(mempoint[ ]))
{
	double A,B,C,a,b,c,p,s,h,m,R,r,temp,xa,ya,xb,yb,xc,yc,xi,yi,xo,yo,xg,yg,xh,yh,p2,q,ea,eb,ec,sha;
	short selectmode;
	cout<<"ѡ��һ��ģʽ: ( 1 -- 4 )\n1. a , b , c\n2. ��A , b , c\n3. ��A , ��B , c\n4. A(xA,yA) , B(xB,yB) , C(xC,yC)\n";
	cout<<setprecision(10);
	selectmode=int(inputvardata(mempoint,NULL,0));
	if(selectmode>4||selectmode<=0)
	{
		cout<<"ѡ��ģʽ����\n";
		return;
	}
	cout<<endl;
	if(selectmode==1)
	{
		a=inputside('a',mempoint);
		b=inputside('b',mempoint);
		c=inputside('c',mempoint);
		if(a+b<=c||b+c<=a||a+c<=b)
		{
			cout<<"��ѧ����\n";
			return;
		}
		A=acos((b*b+c*c-a*a)/(2*b*c))/PI*180;
		B=acos((a*a+c*c-b*b)/(2*a*c))/PI*180;
		C=acos((a*a+b*b-c*c)/(2*a*b))/PI*180;
		temp=(A+B+C-180)/3;
		A-=temp;
		B-=temp;
		C-=temp;
		shape(a,b,c,A,B,C);
		cout<<"��A = "<<A<<"��= ";
		fracout(A/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(A) = ";
		fracout(sin(A/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(A) = ";
		fracout(cos(A/180*PI),fracoutmode*2,NULL,12);
		cout<<"\n��B = "<<B<<"��= ";
		fracout(B/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(B) = ";
		fracout(sin(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(B) = ";
		fracout(cos(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\n��C = "<<C<<"��= ";
		fracout(C/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(C) = ";
		fracout(sin(C/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(C) = ";
		fracout(cos(C/180*PI),fracoutmode*2,NULL,12);
		cout<<endl;
	}
	else if(selectmode==2)
	{
		A=inputangle('A',mempoint,degreemode);
		b=inputside('b',mempoint);
		c=inputside('c',mempoint);
		a=sqrt(b*b+c*c-2*b*c*cos(A/180*PI));
		B=acos((a*a+c*c-b*b)/(2*a*c))/PI*180;
		C=acos((a*a+b*b-c*c)/(2*a*b))/PI*180;
		temp=(A+B+C-180)/3;
		A-=temp;
		B-=temp;
		C-=temp;
		shape(a,b,c,A,B,C);
		cout<<"a = ";
		fracout(a,fracoutmode*2,NULL,12);
		cout<<"\n��B = "<<B<<"��= ";
		fracout(B/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(B) = ";
		fracout(sin(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(B) = ";
		fracout(cos(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\n��C = "<<C<<"��= ";
		fracout(C/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(C) = ";
		fracout(sin(C/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(C) = ";
		fracout(cos(C/180*PI),fracoutmode*2,NULL,12);
		cout<<endl;
	}
	else if(selectmode==3)
	{
		A=inputangle('A',mempoint,degreemode);
		B=inputangle('B',mempoint,degreemode);
		c=inputside('c',mempoint);
		C=180-A-B;
		if(C<=0)
		{
			cout<<"MATH ERROR!\n";
			return;
		}
		b=c/sin(C/180*PI)*sin(B/180*PI);
		a=c/sin(C/180*PI)*sin(A/180*PI);
		shape(a,b,c,A,B,C);
		cout<<"b = ";
		fracout(b,fracoutmode*2,NULL,12);
		cout<<"\nc = ";
		fracout(c,fracoutmode*2,NULL,12);
		cout<<"\n��C = "<<C<<"��= ";
		fracout(C/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(C) = ";
		fracout(sin(C/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(C) = ";
		fracout(cos(C/180*PI),fracoutmode*2,NULL,12);
		cout<<endl;
	}
	else if(selectmode==4)
	{
		cout<<"����xA : \n";
		xa=inputvardata(mempoint,NULL,0);
		cout<<"����yA : \n";
		ya=inputvardata(mempoint,NULL,0);
		cout<<"����xB : \n";
		xb=inputvardata(mempoint,NULL,0);
		cout<<"����yB : \n";
		yb=inputvardata(mempoint,NULL,0);
		cout<<"����xC : \n";
		xc=inputvardata(mempoint,NULL,0);
		cout<<"����yC : \n";
		yc=inputvardata(mempoint,NULL,0);
		a=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
		b=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
		c=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
		if(a+b<=c||b+c<=a||a+c<=b)
		{
			cout<<"��ѧ����\n";
			return;
		}
		A=acos((b*b+c*c-a*a)/(2*b*c))/PI*180;
		B=acos((a*a+c*c-b*b)/(2*a*c))/PI*180;
		C=acos((a*a+b*b-c*c)/(2*a*b))/PI*180;
		temp=(A+B+C-180)/3;
		A-=temp;
		B-=temp;
		C-=temp;
		sha=shape(a,b,c,A,B,C);
		cout<<"ֱ��AB : ";
		lineout(xa,ya,xb,yb,fracoutmode);
		cout<<"ֱ��AC : ";
		lineout(xa,ya,xc,yc,fracoutmode);
		cout<<"ֱ��BC : ";
		lineout(xb,yb,xc,yc,fracoutmode);
		cout<<"a = ";
		fracout(a,fracoutmode*2,NULL,12);
		cout<<"\nb = ";
		fracout(b,fracoutmode*2,NULL,12);
		cout<<"\nc = ";
		fracout(c,fracoutmode*2,NULL,12);
		cout<<"\n��A = "<<A<<"��= ";
		fracout(A/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(A) = ";
		fracout(sin(A/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(A) = ";
		fracout(cos(A/180*PI),fracoutmode*2,NULL,12);
		cout<<"\n��B = "<<B<<"��= ";
		fracout(B/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(B) = ";
		fracout(sin(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(B) = ";
		fracout(cos(B/180*PI),fracoutmode*2,NULL,12);
		cout<<"\n��C = "<<C<<"��= ";
		fracout(C/180*PI,fracoutmode*2,NULL,12);
		cout<<"\nsin(C) = ";
		fracout(sin(C/180*PI),fracoutmode*2,NULL,12);
		cout<<"\ncos(C) = ";
		fracout(cos(C/180*PI),fracoutmode*2,NULL,12);
		cout<<endl;
		xg=(xa+xb+xc)/3;
		yg=(ya+yb+yc)/3;
		xi=(a*xa+b*xb+c*xc)/(a+b+c);
		yi=(a*ya+b*yb+c*yc)/(a+b+c);
		if(sha>1)
		{
			p2=(a*a+b*b+c*c)/2;
		    q=1/(1/(p2-a*a)+1/(p2-b*b)+1/(p2-c*c));
		    ea=q/(p2-a*a);
		    eb=q/(p2-b*b);
		    ec=q/(p2-c*c);
		    xh=ea*xa+eb*xb+ec*xc;
		    yh=ea*ya+eb*yb+ec*yc;
		    xo=((1-ea)*xa+(1-eb)*xb+(1-ec)*xc)/2;
		    yo=((1-ea)*ya+(1-eb)*yb+(1-ec)*yc)/2;
		}
		else
		{
			if(a>b&&a>c)
			{
				xo=(xb+xc)/2;
				yo=(yb+yc)/2;
				xh=xa;
				yh=ya;
			}
			else if(b>a&&b>c)
			{
				xo=(xa+xc)/2;
				yo=(ya+yc)/2;
				xh=xb;
				yh=yb;
			}
			else
			{
				xo=(xa+xb)/2;
				yo=(ya+yb)/2;
				xh=xc;
				yh=yc;
			}
		}
	}
	p=(a+b+c)/2;
	cout<<"�ܳ� = ";
	fracout(p*2,fracoutmode*2,NULL,12);
	cout<<endl;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"��� = ";
	fracout(s,fracoutmode*2,NULL,12);
	cout<<endl;
	if(selectmode==4)
	{
		cout<<"����(I)������ : ";
		pointout(xi,yi,fracoutmode);
		cout<<"ֱ��AI : ";
		lineout(xa,ya,xi,yi,fracoutmode);
		cout<<"ֱ��BI : ";
		lineout(xb,yb,xi,yi,fracoutmode);
		cout<<"ֱ��CI : ";
		lineout(xc,yc,xi,yi,fracoutmode);
	}
	r=s/p;
	cout<<"����Բ�뾶(r) = ";
	fracout(r,fracoutmode*2,NULL,12);
	cout<<endl;
	if(selectmode==4)
	{
		cout<<"����(O)������ : ";
		pointout(xo,yo,fracoutmode);
		cout<<"ֱ��AO : ";
		lineout(xa,ya,xo,yo,fracoutmode);
		cout<<"ֱ��BO : ";
		lineout(xb,yb,xo,yo,fracoutmode);
		cout<<"ֱ��CO : ";
		lineout(xc,yc,xo,yo,fracoutmode);
	}
	R=(a/sin(A/180*PI)+b/sin(B/180*PI)+c/sin(C/180*PI))/6;
	cout<<"���Բ�뾶(R) = ";
	fracout(R,fracoutmode*2,NULL,12);
	cout<<endl;
	if(selectmode==4)
	{
		cout<<"����(H)������ : ";
		pointout(xh,yh,fracoutmode);
		cout<<"ֱ��AH : ";
		lineout(xa,ya,xh,yh,fracoutmode);
		cout<<"ֱ��BH : ";
		lineout(xb,yb,xh,yh,fracoutmode);
		cout<<"ֱ��CH : ";
		lineout(xc,yc,xh,yh,fracoutmode);
	}
	h=2*s/a;
	cout<<"a���ϵĸ� = ";
	fracout(h,fracoutmode*2,NULL,12);
	cout<<endl;
	h=2*s/b;
	cout<<"b���ϵĸ� = ";
	fracout(h,fracoutmode*2,NULL,12);
	cout<<endl;
	h=2*s/c;
	cout<<"c���ϵĸ� = ";
	fracout(h,fracoutmode*2,NULL,12);
	cout<<endl;
	if(selectmode==4)
	{
		cout<<"����(G)������ : ";
		pointout(xg,yg,fracoutmode);
		cout<<"ֱ��AG : ";
		lineout(xa,ya,xg,yg,fracoutmode);
		cout<<"ֱ��BG : ";
		lineout(xb,yb,xg,yg,fracoutmode);
		cout<<"ֱ��CG : ";
		lineout(xc,yc,xg,yg,fracoutmode);
	}
	m=sqrt(2*b*b+2*c*c-a*a)/2;
	cout<<"a���ϵ����߳� = ";
	fracout(m,fracoutmode*2,NULL,12);
	cout<<endl;
	m=sqrt(2*a*a+2*c*c-b*b)/2;
	cout<<"b���ϵ����߳� = ";
	fracout(m,fracoutmode*2,NULL,12);
	cout<<endl;
	m=sqrt(2*b*b+2*a*a-c*c)/2;
	cout<<"c���ϵ����߳� = ";
	fracout(m,fracoutmode*2,NULL,12);
	cout<<endl;
}
/*----------------------------------------------------------------------------------------------------------*/
inline short shape(const double a,const double b,const double c,const double A,const double B,const double C)
{
	if(fabs(a*a+b*b-c*c)<1e-10||fabs(a*a+c*c-b*b)<1e-10||fabs(b*b+c*c-a*a)<1e-10||fabs(A-90)<1e-10||fabs(B-90)<1e-10||fabs(C-90)<1e-10)
	{
		cout<<"\n��ABC��ֱ��������\n";
		return 1;
	}
	if(A>=90||B>=90||C>=90)
	{
		cout<<"\n��ABC�Ƕ۽�������\n";
		return 3;
	}
	cout<<"\n��ABC�����������\n";
	return 2;
}
/*----------------------------------------------------------------------------------------------------------*/
void lineout(const double x1,const double y1,const double x2,const double y2,const bool fracoutmode)
{
	double k,b;
	if((fabs(x1-x2)<1e-10&&fabs(y1-y2)<20)||(x1==x2))
	{
		cout<<"X = ";
		fracout(x1,fracoutmode*2,NULL,12);
		cout<<endl;
		return;
	}
	k=(y2-y1)/(x2-x1);
	b=(y1-k*x1+y2-k*x2)/2;
	cout<<"Y = ";
	if(fabs(k)>1e-12)
	{
	    if(fabs(fabs(k)-1)>1e-12)
		{
			fracout(k,fracoutmode*2,NULL,12);
	        cout<<" X ";
		}
		else if(k>0)cout<<"X ";
		else cout<<"-X ";
	    if(b>1e-12)
		{
		    cout<<"+ ";
		    fracout(b,fracoutmode*2,NULL,12);
		}
	    else if(b<-(1e-12))
		{
		    b=fabs(b);
		    cout<<"- ";
		    fracout(b,fracoutmode*2,NULL,12);
		}
	    cout<<endl;
		return;
	}
	else
	{
		fracout(b,fracoutmode*2,NULL,12);
		cout<<endl;
	}
}
/*----------------------------------------------------------------------------------------------------------*/
void pointout(const double x,const double y,const bool fracoutmode)
{
	cout<<"( ";
	fracout(x,fracoutmode*2,NULL,12);
	cout<<" , ";
	fracout(y,fracoutmode*2,NULL,12);
	cout<<" )\n";
}
/*----------------------------------------------------------------------------------------------------------*/
double inputangle(const char angle,double *(p[ ]),const bool degreemode)
{
	double r;
	const double maxangle=degreemode?180.0:PI;
	cout<<"�����"<<angle<<" : ( ";
	if(degreemode)cout<<"�Ƕ���";
	else cout<<"������";
	cout<<" )\n";
	do
	{
		r=inputvardata(p,NULL,0);
		if(r<=0||r>=maxangle)degreemode?cout<<"�����Ƕȱ���Ϊ������С��180�㣡�������� :\n":cout<<"�������ȱ���Ϊ������С�ڦУ��������� :\n";
	}while(r<=0||r>=maxangle);
	if(!degreemode)return r*180/PI;
	return r;
}
/*----------------------------------------------------------------------------------------------------------*/
double inputside(const char side,double *(p[ ]))
{
	double r;
	cout<<"����"<<side<<" :\n";
	do
	{
		r=inputvardata(p,NULL,0);
		if(r<=0)cout<<"�����߳�����Ϊ�������������� :\n";
	}while(r<=0);
	return r;
}
/*----------------------------------------------------------------------------------------------------------*/
void help()
{
	cout<<"\nCount Fever 1.08 ���İ�\n";
	cout<<"���ߣ�������ѧ��Ϣ��ѧ����ѧԺ ���Ӻ�\n\n";
	ifstream infile;
	infile.open("help.txt",ios::in);
	if(!infile)
	{
		cerr<<"����Ŀ¼�в�����˵������ļ��޷���\n";
		return;
	}
}

