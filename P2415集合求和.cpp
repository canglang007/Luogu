#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long num=0,sum=0;
    while(1)
    {
    	int n;
    	
    	cin>>n;
    	sum+=n;
    	num++;
    	if(cin.get()=='\n')
			break;
	} 
	
	//cout<<(long long)(sum*pow(2,num-1))<<endl;
    const type_info& x_id = typeid((long long)(sum*pow(2,num-1)));
    const type_info& y_id = typeid((long long)sum*pow(2,num-1));
	cout<<x_id.name()<<endl;
	cout<<y_id.name()<<endl;
	return 0;
}
