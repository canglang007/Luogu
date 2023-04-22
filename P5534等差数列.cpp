#include<iostream>
using namespace std;
//需要考虑数据超int 的问题 ，n*n-1可能会很大 
int main()
{
	long long a1,a2,n;
	cin>>a1>>a2>>n;
	long long d=a2-a1;
	cout<<n*a1+d*(long long)(n*(n-1))/2<<endl;
	return 0;
}
