/*ʵ����Ŀ�����߿��ɼ�����ϵͳ����չҪ��
��������ͬǰ
������չҪ��
��1���ܰ�׼��֤�ŵ�ĳλֵ����������ֿƣ����㽭��ĳ������׼��֤��Ϊ��16000000150001�������е�ʮλΪ��1�������Ŀƣ�Ϊ��5��������ơ�
��2������Ӧ������ƹ���������������Ŀư��ܷ֡����ġ��ۺϡ���ѧ�������ư��ܷ֡���ѧ���ۺϡ����ġ����
    ���κſ��á�1������5�����ֱ�����Ŀ����������������
Ҫ��
��1��Դ������������õ���Ʒ��
��2������ģ�黯������Ʒ�����
��3���ύ��ҵʱ����ֱ�Ӹ���Դ������룬������Ϊ��Ч��ҵ��
��4�����������������Խ���������չҪ����صĲ��֡�      */

#include<stdio.h>
#include<stdlib.h>
#define N 100
struct student{
    char num[20];
    char name[10];
    float chinese;
    float math;
    float english;
    float zonghe;
    float score;
    int sort;
    double pxf;
    //׼��֤�š����������ġ���ѧ������ۺϡ��ּܷ�����
}stu[N];
void cal(int i){  //�����ֺܷ������
    int k; //��־�Ŀƺ����
    stu[i].score=stu[i].chinese+stu[i].math+stu[i].english+stu[i].zonghe;
    k=stu[i].num[9];
    if(k=='1'){        //�Ŀ�
        stu[i].pxf=stu[i].score+stu[i].chinese*0.001+stu[i].zonghe*0.000001+stu[i].math*0.000000001+stu[i].english*0.000000000001;
        //�ĿƵ������=�ܷ�+����*0.001+�ۺ�*0.000001+��ѧ*0.000000001+Ӣ��*0.000000000001
    }
    if(k=='5'){        //���
        stu[i].pxf=stu[i].score+stu[i].math*0.001+stu[i].zonghe*0.000001+stu[i].chinese*0.000000001+stu[i].english*0.000000000001;
        //��Ƶ������=�ܷ�+��ѧ*0.001+�ۺ�*0.000001+����*0.000000001+Ӣ��*0.000000000001
    }
}
int input(){  //���뿼����Ϣ
    int i;
    int n; //��������
    int m; //���׼��֤��
    char k; //��־�Ŀƺ����
    printf("�����뿼��������");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("�������%dλ������׼��֤�ţ�14λ���֣������������֣������ģ���ѧ��Ӣ��ۺϷ�����\n",i+1);
        scanf("%s%s%f%f%f%f",stu[i].num,stu[i].name,&stu[i].chinese,&stu[i].math,&stu[i].english,&stu[i].zonghe);
        m=strlen(stu[i].num);
        k=stu[i].num[9];
        if(m!=14||(k!='1'&&k!='5')){ //�����׼��֤�Ų���14λ;����׼��֤�ŵ�ʮλ����1Ҳ����5
            printf("�����׼��֤�������������14λ��׼�߿�׼��֤�ţ�\n");
            i=i-1;
        }else{
            cal(i);
        }
    }
    return n;
}
int lookup(int n){ //��׼��֤�Ų���
    int i;
    int f=0; //�Ƿ���ڸÿ�������Ϣ
    char num[14]; //����׼��֤��
    printf("�����뿼����׼��֤�ţ�14λ����\n");
    scanf("%s",num);
    for(i=0;i<n;i++){
        if(strcmp(num,stu[i].num)==0){
            f=1;       //���ڸÿ�������Ϣ
            return i;    //���ظ�����Ԫ�ص��±�
        }
    }
    if(f==0){        //�����ڸÿ�������Ϣ
        printf("�����ڸÿ�������Ϣ��\n");
        return -1;
    }
}
void pri(int i){     //���������Ϣ
    printf("׼��֤�ţ�%s ������%s\n",stu[i].num,stu[i].name);
    printf("���ģ�%.2f ��ѧ��%.2f Ӣ�%.2f �ۺϣ�%.2f\n",stu[i].chinese,stu[i].math,stu[i].english,stu[i].zonghe);
}
void amend(int n){   //�޸Ŀ�����Ϣ
    int i;
    int t; //Ҫ�޸ĵ���Ϣ��ѡ��
    i=lookup(n);     //���ò�ѯ������Ϣ����
    if(i!=-1){
      pri(i);
      printf("��ѡ����Ҫ�޸ĵ���Ϣ����1��׼��֤�ţ�2��������3�����ģ�4����ѧ��5��Ӣ�6���ۺϣ�\n");
      scanf("%d",&t);
      switch(t){
        case 1:
            printf("�������޸ĺ��׼��֤�ţ�\n");
            scanf("%s",stu[i].num);
            break;
        case 2:
            printf("�������޸ĺ��������\n");
            scanf("%s",stu[i].name);
            break;
        case 3:
            printf("�������޸ĺ�����ĳɼ���\n");
            scanf("%f",&stu[i].chinese);
            break;
        case 4:
            printf("�������޸ĺ����ѧ�ɼ���\n");
            scanf("%f",&stu[i].math);
            break;
        case 5:
            printf("�������޸ĺ��Ӣ��ɼ���\n");
            scanf("%f",&stu[i].english);
            break;
        case 6:
            printf("�������޸ĺ���ۺϳɼ���\n");
            scanf("%f",&stu[i].zonghe);
            break;
      }
      printf("�޸ĳɹ���\n");
      cal(i);  //�����ֺܷ������
      pri(i);  //����޸ĺ�Ŀ�����Ϣ
    }
}
int del(int n){  //ɾ��������Ϣ
    int i,j;
    int d; //�Ƿ�ɾ��
    i=lookup(n);   //���ò�ѯ������Ϣ����
    if(i!=-1){
        pri(i); //����ÿ�����Ϣ
        printf("ȷ��ɾ���ÿ�����Ϣ��1��ȷ�ϣ�2��ȡ��\n");
        scanf("%d",&d);
        switch(d){
            case 1:
                for(j=i;j<n;j++){
                    stu[j]=stu[j+1];
                }
                n--;    //����������һ
                printf("ɾ���ɹ���\n");
                break;
            case 2:
                printf("��ȡ��ɾ���ÿ�����Ϣ��\n");
                break;
        }
    }
    return n;
}
void pri2(int k,int i){    //k��־�Ŀƺ����
    k=stu[i].num[9];
    printf("%-16s%-10s%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f\t",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].zonghe,stu[i].score);
    if(k=='1'){
        printf("1-%d\n",stu[i].sort);   //�Ŀ�����
    }else if(k=='5'){
        printf("5-%d\n",stu[i].sort);   //�������
    }
}
void mysort(int n){
    int arts=0;  //�Ŀ���������
    int sciences=0;  //�����������
    char k;   //��־�Ŀƺ����
    int i,j;
    struct student t;
    for(i=0;i<n;i++){              //�����ܷ�
        cal(i);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(stu[j].score<stu[j+1].score){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    printf("׼��֤��\t����  \t����\t��ѧ\tӢ��\t�ۺ�\t�ܷ�\t����\n");
    for(i=0;i<n;i++){
        k=stu[i].num[9];
        if(k=='1'){  //�Ŀ�
            arts++;
            stu[i].sort=arts;
        }
        if(k=='5'){  //���
            sciences++;
            stu[i].sort=sciences;
        }
        pri2(k,i);
    }
}
void main(){
    int choice;
    int k=0;      //�����ж��Ƿ�ִ���˵�һ��
    int n;   //����Ŀ�������
    int i;   //����ѯ������Ԫ�ص��±�
    do{
        //�˵����ɼ������롢�޸ġ�ɾ������������׼���Ų�ѯ
        printf("----------�߿��ɼ�����ϵͳ----------\n");
        printf("1.���뿼������Ϣ\n");
        printf("2.�޸Ŀ�������Ϣ\n");
        printf("3.ɾ������Ŀ�����Ϣ\n");
        printf("4.���ֳܷɼ���������\n");
        printf("5.���뿼����׼��֤�Ų�ѯ�ɼ�\n");
        printf("0.�˳�ϵͳ\n");
        printf("------------------------------------\n");
        printf("��ѡ��");
        scanf("%d",&choice);
        if(choice==1){
           n=input();
           k=k+1;
        }
        if(choice==2){
           if(k!=0){
            amend(n);
           }else{
            printf("����ѡ���һ���Ĳ�����\n");
           }
        }
        if(choice==3){
           if(k!=0){
            n=del(n);
           }else{
            printf("����ѡ���һ���Ĳ�����\n");
           }
        }
        if(choice==4){
           if(k!=0){
            mysort(n);
           }else{
            printf("����ѡ���һ���Ĳ�����\n");
           }
        }
        if(choice==5){
           if(k!=0){
            i=lookup(n);
            if(i!=-1){
                printf("��ѯ�ɹ����ÿ�������Ϣ���£�\n");
                pri(i);    //���������Ϣ
            }
           }else{
            printf("����ѡ���һ���Ĳ�����\n");
           }
        }
        if(choice==0){
           exit(0);
        }
    }while(choice!=0);
}
