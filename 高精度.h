
/**
 * ���ַ���sת��Ϊ��int�͵����� 
 * @param s
 * @param n
 */
void transfer(string s, int n[]){
    int len = s.size();
 
    n[0] = len;//��0Ϊ����������ĳ��ȣ�
    for (int i = 0; i < len ; ++i) {
        n[i+1] = s[len - 1 - i] - '0';//�����������ţ�������λ���� 
    }
}


//�������ĺ��� 
void printResult(int c[]){
    for(int i=c[0];i>=1;i--){
        cout<<c[i];  //c[0]��λ���������������Ϊ����������� 
    }
}

/**
*
* @param a �ӷ�
* @param b ����
* @param c ��
* @param len ����c�ĳ���
*/
void add(int a[],int b[],int c[],int len){
    int d[len]={0};
    int m=max(a[0],b[0]);//���λ��Ϊa,b����� 
    for(int i=1;i<=m;i++){
        d[i]+=a[i]+b[i];
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

//�Ƚ��������Ĵ�С��ʹ�ô�����ȥС��
bool compare(int a[],int b[]){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }
    else{
        for(int i=a[0];i>=1;i--){
            if(a[i]!=b[i]){
                return a[i]>b[i];
            }
        }
        return 1;
    }
}

/**
*
* @param a
* @param b a,bΪ��������������
* @param c ��
* @param len ����c�ĳ���
*/
void sub(int a[], int b[], int c[], int len) {
    int d[len] = {0};
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;      //��ǰһλ����1 
        }
        d[i] = a[i] - b[i];
    }
 
    int l = a[0];           //lΪ���ֵĳ��� 
    while (d[l] == 0 && l > 1) {   //�����λ��0 
        l--;
    }
    d[0] = l;              //��¼Ŀǰ���ֵĳ��� 
    memcpy(c, d, len * sizeof(int));//������õ��Ľ�����Ƶ�����c 
}

/**
*
* @param a ������
* @param k ����
* @param c ��
* @param len ����c�ĳ���
*/
//һ��������һ��С�� 
void multipy(int a[],int k,int c[],int len){
    int d[len]={0};
    for(int i=1;i<=a[0];i++)
    {
        d[i]+=d[i]+a[i]*k;
        d[i+1]=d[i]/10;
        d[i]=d[i]%10;
    }
    int l=a[0]+1;   //��ֹ���ִ���10��λ 
    int t=d[l];
    while(t!=0){    //�п��ܻ����ȥ�ܶ� 
        d[l]=t%10;
        t/=10;
        l++;
    }
//ȥ��ǰ��0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=l;
    memcpy(c,d,len* sizeof(int));
}

/**
*
* @param a ������
* @param b ����
* @param c �˻�
* @param len ����c�ĳ���
*/
//�����������,ģ����ʽ�˷� 
void multiply_1(int a[],int b[],int c[],int len){
    int d[len]={0};
    for(int i=1;i<=a[0];i++) {
        for (int j = 1; j <= b[0]; j++)
        {
            d[i + j - 1] = a[i] * b[j] + d[i + j - 1];
            d[i+j]+= d[i + j - 1] / 10;//��λ
            d[i + j - 1] = d[i + j - 1] % 10;
        }
    }
    int l=a[0]+b[0];//����λ��������λ����� 
    while(d[l]==0&&l>1){//ȥ����λ��0 
        l--;
    }
    d[0]=l;
//����d����������c
    memcpy(c,d,len* sizeof(int));
}

/**
*
* @param a ������
* @param k ����
* @param c ��
* @param l
*/
//��������С���� 
void divide(int a[],int k,int c[],int len){
    int d[len]={0};
    int x=0; //�Ӹ�λ��ʼ��
    for(int i=a[0];i>=1;i--){
        d[i]=(x*10+a[i])/k;  //x����һλ���������������� 
        x=(x*10+a[i])%k;     //�������� 
    }
//����k��λ��
    int f=k;
    int size=0;
    while(f!=0){
        size++;
        f/=10;
    }
//size�ǳ���k��λ��
    int l=max(a[0]-size+1,1);//l���̵����λ���������1����Ϊ�˱�֤����� 
//ȥ��ǰ��0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=l;
//������d�����ݿ�����c
    memcpy(c,d,len* sizeof(int));
}


/**
* ������������Ƚϴ�С
* @param a ������
* @param b ����
* @param current �����λ������ǰλ��
* @return
*/
bool compareab(int a[],int b[],int current){
    if(a[0]-current+1>b[0]){
        return true; //���������ڳ��� 
    }else if(a[0]-current+1<b[0]){
        return false;//������С�ڳ��� 
    }else{
        for(int i=a[0],j=b[0];i>=current;i--,j--){//λ����ͬ�Ļ�����λ�ȴ�С 
            if(a[i]==b[j]){
                continue;
            }else{
                return a[i]>b[j];
            }
        }
        return 1;
    }
}

/**
* ��������Ϊ������ʵ���Ƕ������ 
* @param a ������
* @param b ����
* @param current �����λ������ǰλ��
* @return
*/
void deduce(int a[],int b[],int current){
    for(int i=current,j=1;i<=a[0];i++,j++){
        if(a[i]<b[j]){
            a[i]+=10;
            a[i+1]--;    //��ǰ���һλ 
        }
        a[i]=a[i]-b[j];
    }
    int len=a[0]; //�����Ժ�����λ��0ȥ��
    while(a[len]==0){
        len--;
    }
    a[0]=len; //
}

/**
*
* @param a
* @param b
* @param c
* @param len ����a������c�ĳ��ȣ�ͨ����������ǰ�a,b,c��������ĳ��ȶ����ó���ͬ
*/
void divide_1(int a[],int b[],int c[],int len){
    int d[len]={0};
    int a1[len];
//ʹ��a1���м��㣬��Ϊ�ڼ�������У��������ᱻ�ı䣬��˿���һ������
    memcpy(a1,a,len* sizeof(int));
    d[0]=1;//��ֹ����ı�����С�ڳ���������������
    for(int i=a[0]-b[0]+1;i>=1;i--){
        int t=0;
        while(compareab(a1,b,i)){   //ֻҪ�������ȳ�����Ļ��ͽ��г��� 
            deduce(a1,b,i);
            t++;//ÿ��һ�Σ���˵���̶���һ 
        }
        d[i]=t;
    }
    int l=max(a[0]-b[0]+1,1);
//ȥ��ǰ��0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=len;
//������d�����ݿ�����c
    memcpy(c,d,len* sizeof(int));
}
