#include<iostream>
#include<string.h>
using namespace std;

int a[2000],b[2000],c[2000];
void transfer(string s, int n[]){
    int len = s.size();
 
    n[0] = len;//��0Ϊ����������ĳ��ȣ�
    for (int i = 0; i < len ; ++i) {
        n[i+1] = s[len - 1 - i] - '0';//�����������ţ�������λ���� 
    }
}
void add(int a[],int b[],int c[],int len){
    int d[len]={0};
    int m=max(a[0],b[0]);//���λ��Ϊa,b����� 
    for(int i=1;i<=m;i++){
        d[i]+=a[i]+b[i];  //ǧ��ע�⣬���Ǽӵ� 
        d[i+1]=d[i]/10; //��λ
        d[i]=d[i]%10; //ȡ��λ�����µ���
    }
    int l=m+1;       //�����鳤�ȶ�һλ����Ϊ�ܿ����н�λ 
    while(d[l]==0&&l>1){     //�����λ��0 
        l--;
    }
    d[0]=l;//��0λ��¼���ĳ��� 
    memcpy(c,d,len* sizeof(int));//��d�е�ֵ���Ƶ�c�� 
}
void print(int n[]){
    for (int i = n[0]; i >= 1 ; i--) {
        cout<<n[i];
    }
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	transfer(s1,a);
	transfer(s2,b);
	add(a,b,c,2000);
	print(c);
	return 0;
 } 
