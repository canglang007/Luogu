#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if(n==2||n==3)
	   return 1;
	//������������6�����࣬�϶��Ǻ�����ֱ��ɸ�� 
	else if(n%6==0||n%6==2||n%6==3||n%6==4)
	   return 0;
	//��6��������������ж� 
	else
	   	for(int i=5;i<=sqrt(n);i+=6)
	   	    if (n % i == 0 || n % (i + 2) == 0) //i��i+2����6������� 
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
