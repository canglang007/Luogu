#include<bits/stdc++.h>
using namespace std;
/*������󹫱�������С��Լ����˵��Ӱ�����ǵ����������������Ĵ����Ĳ�ͬ����ô���Կ���
y/x����������ֵ*/
//��������������P��Q��˵��һ�������Ǹ���������ӵģ����Ǳ仯������ �Լ�������ǲ�һ���� 
int main()
{
	int x,y;
	cin>>x>>y;
	int quo=y/x;
	int curs=2;
	int count=0;//��¼�����ĸ��� 
	if (y % x != 0)
	cout<<0;
	else{
	
	while(quo>1)//����1����ֽ���� 
	{
		
		if(quo%curs==0)
		{
			count++;
			while (quo % curs == 0)
                    quo /= curs;//���������ͳ�����,�� 
		}
		curs++;
		 
		 
	} 
	cout<<(1<<count);//ʹ��λ�������2���ݴ� �����ʽ�ӵĺ����Ƕ�1����countλ��Ҳ����2^count�� 
}
	return 0;
	}
	
