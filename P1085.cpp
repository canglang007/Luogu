#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[8];
	for(int i=1;i<=7;i++)
	{
		int c,b;
		cin>>c>>b;
		a[i]=c+b;//学习时间之和 
	} 
	int max=a[1];
	for(int i=1;i<=7;i++)
	{
		if(a[i]>max)
		{
		    max=a[i];
		}
	} 
	 if(max<=8)
	     cout<<0;
	 else
	 {
	 	for(int i=1;i<=7;i++)
	 	{
	 		if(a[i]==max)
	 		{			 
	 		    cout<<i;
	 		    break;
	 		}
	 		    
		 }
	 }
  return 0;
   
}
