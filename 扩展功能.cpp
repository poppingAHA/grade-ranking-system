/*实践项目二：高考成绩排名系统（扩展要求）
基本功能同前
增加扩展要求
（1）能按准考证号的某位值来进行文理分科，如浙江的某考生的准考证号为“16000000150001”，其中第十位为“1”代表文科，为“5”代表理科。
（2）按相应的文理科规则进行排名，如文科按总分、语文、综合、数学、外语，理科按总分、数学、综合、语文、外语。
    名次号可用“1－”或“5－”分别代表文科排名和理科排名。
要求：
（1）源程序代码有良好的设计风格；
（2）采用模块化程序设计方法；
（3）提交作业时，请直接复制源程序代码，否则视为无效作业；
（4）如果代码过长，可以仅复制与扩展要求相关的部分。      */

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
    //准考证号、姓名、语文、数学、外语、综合、总分及排名
}stu[N];
void cal(int i){  //计算总分和排序分
    int k; //标志文科和理科
    stu[i].score=stu[i].chinese+stu[i].math+stu[i].english+stu[i].zonghe;
    k=stu[i].num[9];
    if(k=='1'){        //文科
        stu[i].pxf=stu[i].score+stu[i].chinese*0.001+stu[i].zonghe*0.000001+stu[i].math*0.000000001+stu[i].english*0.000000000001;
        //文科的排序分=总分+语文*0.001+综合*0.000001+数学*0.000000001+英语*0.000000000001
    }
    if(k=='5'){        //理科
        stu[i].pxf=stu[i].score+stu[i].math*0.001+stu[i].zonghe*0.000001+stu[i].chinese*0.000000001+stu[i].english*0.000000000001;
        //理科的排序分=总分+数学*0.001+综合*0.000001+语文*0.000000001+英语*0.000000000001
    }
}
int input(){  //输入考生信息
    int i;
    int n; //考生人数
    int m; //检测准考证号
    char k; //标志文科和理科
    printf("请输入考生人数：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("请输入第%d位考生的准考证号（14位数字），姓名（汉字），语文，数学，英语，综合分数：\n",i+1);
        scanf("%s%s%f%f%f%f",stu[i].num,stu[i].name,&stu[i].chinese,&stu[i].math,&stu[i].english,&stu[i].zonghe);
        m=strlen(stu[i].num);
        k=stu[i].num[9];
        if(m!=14||(k!='1'&&k!='5')){ //输入的准考证号不是14位;或者准考证号第十位不是1也不是5
            printf("输入的准考证号有误！务必输入14位标准高考准考证号！\n");
            i=i-1;
        }else{
            cal(i);
        }
    }
    return n;
}
int lookup(int n){ //按准考证号查找
    int i;
    int f=0; //是否存在该考生的信息
    char num[14]; //考生准考证号
    printf("请输入考生的准考证号（14位）：\n");
    scanf("%s",num);
    for(i=0;i<n;i++){
        if(strcmp(num,stu[i].num)==0){
            f=1;       //存在该考生的信息
            return i;    //返回该数组元素的下标
        }
    }
    if(f==0){        //不存在该考生的信息
        printf("不存在该考生的信息！\n");
        return -1;
    }
}
void pri(int i){     //输出考生信息
    printf("准考证号：%s 姓名：%s\n",stu[i].num,stu[i].name);
    printf("语文：%.2f 数学：%.2f 英语：%.2f 综合：%.2f\n",stu[i].chinese,stu[i].math,stu[i].english,stu[i].zonghe);
}
void amend(int n){   //修改考生信息
    int i;
    int t; //要修改的信息的选项
    i=lookup(n);     //调用查询考生信息函数
    if(i!=-1){
      pri(i);
      printf("请选择需要修改的信息：（1、准考证号；2、姓名；3、语文；4、数学；5、英语；6、综合）\n");
      scanf("%d",&t);
      switch(t){
        case 1:
            printf("请输入修改后的准考证号：\n");
            scanf("%s",stu[i].num);
            break;
        case 2:
            printf("请输入修改后的姓名：\n");
            scanf("%s",stu[i].name);
            break;
        case 3:
            printf("请输入修改后的语文成绩：\n");
            scanf("%f",&stu[i].chinese);
            break;
        case 4:
            printf("请输入修改后的数学成绩：\n");
            scanf("%f",&stu[i].math);
            break;
        case 5:
            printf("请输入修改后的英语成绩：\n");
            scanf("%f",&stu[i].english);
            break;
        case 6:
            printf("请输入修改后的综合成绩：\n");
            scanf("%f",&stu[i].zonghe);
            break;
      }
      printf("修改成功！\n");
      cal(i);  //计算总分和排序分
      pri(i);  //输出修改后的考生信息
    }
}
int del(int n){  //删除考生信息
    int i,j;
    int d; //是否删除
    i=lookup(n);   //调用查询考生信息函数
    if(i!=-1){
        pri(i); //输出该考生信息
        printf("确认删除该考生信息？1、确认；2、取消\n");
        scanf("%d",&d);
        switch(d){
            case 1:
                for(j=i;j<n;j++){
                    stu[j]=stu[j+1];
                }
                n--;    //考生人数减一
                printf("删除成功！\n");
                break;
            case 2:
                printf("已取消删除该考生信息。\n");
                break;
        }
    }
    return n;
}
void pri2(int k,int i){    //k标志文科和理科
    k=stu[i].num[9];
    printf("%-16s%-10s%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f\t",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].zonghe,stu[i].score);
    if(k=='1'){
        printf("1-%d\n",stu[i].sort);   //文科名次
    }else if(k=='5'){
        printf("5-%d\n",stu[i].sort);   //理科名次
    }
}
void mysort(int n){
    int arts=0;  //文科生的名次
    int sciences=0;  //理科生的名次
    char k;   //标志文科和理科
    int i,j;
    struct student t;
    for(i=0;i<n;i++){              //计算总分
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
    printf("准考证号\t姓名  \t语文\t数学\t英语\t综合\t总分\t名次\n");
    for(i=0;i<n;i++){
        k=stu[i].num[9];
        if(k=='1'){  //文科
            arts++;
            stu[i].sort=arts;
        }
        if(k=='5'){  //理科
            sciences++;
            stu[i].sort=sciences;
        }
        pri2(k,i);
    }
}
void main(){
    int choice;
    int k=0;      //用于判断是否执行了第一步
    int n;   //输入的考生人数
    int i;   //被查询的数组元素的下标
    do{
        //菜单：成绩的输入、修改、删除、排名及按准考号查询
        printf("----------高考成绩排名系统----------\n");
        printf("1.输入考生的信息\n");
        printf("2.修改考生的信息\n");
        printf("3.删除有误的考生信息\n");
        printf("4.按总分成绩进行排名\n");
        printf("5.输入考生的准考证号查询成绩\n");
        printf("0.退出系统\n");
        printf("------------------------------------\n");
        printf("请选择：");
        scanf("%d",&choice);
        if(choice==1){
           n=input();
           k=k+1;
        }
        if(choice==2){
           if(k!=0){
            amend(n);
           }else{
            printf("请先选择第一步的操作！\n");
           }
        }
        if(choice==3){
           if(k!=0){
            n=del(n);
           }else{
            printf("请先选择第一步的操作！\n");
           }
        }
        if(choice==4){
           if(k!=0){
            mysort(n);
           }else{
            printf("请先选择第一步的操作！\n");
           }
        }
        if(choice==5){
           if(k!=0){
            i=lookup(n);
            if(i!=-1){
                printf("查询成功！该考生的信息如下：\n");
                pri(i);    //输出考生信息
            }
           }else{
            printf("请先选择第一步的操作！\n");
           }
        }
        if(choice==0){
           exit(0);
        }
    }while(choice!=0);
}
