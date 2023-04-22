#include<iostream>
using namespace std;
 struct Student{
 	
 	int num;
 	int distance;
 	string name;
 }s1[152];
 
 int main()
{
	int i=0;
	//输入部分 
	
	while(1)
	{
		cin>>s1[i].num>>s1[i].distance>>s1[i].name;
	
		if(s1[i].distance==0)
		    break;	
		i++	;	
	}
	int cost[i+1];
	for(int k=0;k<i;k++)
	{
		cost[k]=0; 
	}
	for(int j=0;j<i;j++)
	{
		
		for(int k=0;k<i;k++)
		{
			int prime;
		    if(k<i)//之前的
			    prime=-1;
			else if(k>i)
			    prime=1;
			else
			    prime=0;
			cost[j]+=abs(s1[j].distance-s1[k].distance)*s1[k].num; 
		}
	}
	int min_cost=cost[0];
	int j;
	int num=0;
	for(j=0;j<i-1;j++) 
	{
	    if(cost[j+1]<cost[j])
	    {
		
		    min_cost=cost[j+1];
		    num=j+1;//更新num的所在位置 
		}
		else if(cost[j+1]==cost[j])
		{
			if(s1[j+1].distance<s1[j].distance)
			{ 
			    min_cost=cost[j+1];
			    num=j+1; 
			    }  
		}
	} 
	for(int x=0;x<i;x++)
	    cout<<s1[x].name<<cost[x]<<endl;
	//cout<<s1[j].name<<' '<<min_cost<<endl;
	return 0;
}
	
	
