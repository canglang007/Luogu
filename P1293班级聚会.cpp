#include<iostream>
using namespace std;
 struct Student{
 	
 	int num;
 	int distance;
 	string name;
 }s1[152];
 //ѭ�����������Ҫ�� 
int main()
{
	int i=0;
	//���벿�� 
	
	while(1)
	{
		cin>>s1[i].num>>s1[i].distance>>s1[i].name;
	
		if(s1[i].distance==0)
		    break;	
		i++	;	
	}
	 
	//��ʱ��iΪ����ĸ���-1����Ϊ�±��Ǵ�0��ʼ�ģ� 
	int sum=i+1; 

	//����ÿ��������Ϊ�ٰ�صĻ��� 
	
	long long cost, min_cost=0x7ffffff;
	int num=0;
	for(int k=0;k<sum;k++)
	{
		cost=0;
		for(int m=0;m<sum;m++)
		{ 
		    
			cost+=abs(s1[m].distance-s1[k].distance)*s1[m].num;
		} 
		if(cost<=min_cost)
		{
		
		    min_cost=cost;
			num=k; 
		}
	}

    cout<<s1[num].name<<' '<<min_cost<<endl;
	return 0;
}
