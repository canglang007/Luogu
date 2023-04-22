#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if(n==2||n==3)
	   return 1;
	//如果这个数不在6的两侧，肯定是合数，直接筛掉 
	else if(n%6==0||n%6==2||n%6==3||n%6==4)
	   return 0;
	//对6的两侧的数进行判断 
	else
	   	for(int i=5;i<=sqrt(n);i+=6)
	   	    if (n % i == 0 || n % (i + 2) == 0) //i和i+2就是6两侧的数 
			    return 0;
	return 1; 

}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime(i)&&n%i==0)
		{		
		    cout<<n/i;
		    break;
		}		   
	}	
  return 0;   
}
