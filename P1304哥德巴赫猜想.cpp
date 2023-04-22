#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if(n==2||n==3)
	   return 1;
	else if(n%6==0||n%6==2||n%6==3||n%6==4)
	   return 0;
	else
	   	for(int i=5;i<=sqrt(n);i+=6)
	   	    if (n % i == 0 || n % (i + 2) == 0)
			    return 0;
	return 1; 
}
int main()
{
	int N;
	cin>>N;
	for(int i=4;i<=N;i+=2)
	{
		
		//te==特别注意这里的限定条件并不是j^2<=N,而是一半（因为是加法）如98=19+79,19明显过了根号了
		//乘法开方，加法取半 
		for(int j=2;j<=N/2;j++)
		{
			if(isprime(j)&&isprime(i-j))
			{
				cout<<i<<"="<<j<<'+'<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
}

