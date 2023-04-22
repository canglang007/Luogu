#include<iostream>
#include<string.h>
using namespace std;
#define N 5000
int a[N],b[N],c[N];
void transfer(string s,int n[])
{
	int len=s.size();
	n[0]=len;
	for(int i=0;i<len;++i)
	{
		n[i+1]=s[len-i-1]-'0';
	}
}
void multi(int a[],int b[],int c[])
{
	int d[N]={0};
	for(int i=1;i<=a[0];++i)
	{
		for(int j=1;j<=b[0];++j)
		{
			d[i+j-1]+=a[i]*b[j];
			d[i+j]+=d[i+j-1]/10;
			d[i+j-1]=d[i+j-1]%10;
		}
	}
	int l=a[0]+b[0];
	while(d[l]==0&&l>1)
	{
		l--;
	}
	d[0]=l;
	memcpy(c,d,N*sizeof(int));
}
void print(int n[]){
	for(int i=n[0];i>=1;--i)
	    cout<<n[i];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	transfer(s1,a);
	transfer(s2,b);
	multi(a,b,c);
	print(c);
	
	return 0;
 } 
