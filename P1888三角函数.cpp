#include<iostream>
using namespace std;
int gcd(int a,int b){//最大公约数 
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int max1=(a>b)?a:b; 
	int max=(max1>c)?max1:c;
	int min1=(a>b)?b:a;
	int min=(min1>c)?c:min1;
	cout<<min/gcd(max,min)<<'/'<<max/gcd(max,min)<<endl; 
	return 0;
 } 
