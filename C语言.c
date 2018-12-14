#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Hotel
{
    int room;
    char capacity[10];
    char level[10];
    int price;
    char use[10];
};
int num=0;
struct Hotel rooms[1000];
void Input(struct Hotel rooms[])
{
    int i,n,x=0;
    printf("输入要添加房间数据的个数\n");
    scanf("%d",&n);
    for(i=num;x<n;i++,x++)
    {
    printf("请输入房间号: ");
    scanf("%d",&rooms[i].room);

    printf("请输入房间容量: ");
    scanf("%s",rooms[i].capacity);

    printf("请输入房间档次: ");
    scanf("%s",rooms[i].level);

    printf("请输入房间价格: ");
    scanf("%d",&rooms[i].price);

    printf("请输入房间是否已用: ");
    scanf("%s",&rooms[i].use);
    num++;
    }
    printf("\n添加数据成功\n按回车键继续......\n");
    getchar();
    getchar();
}
void Output(struct Hotel rooms[])
{
  int i;
  printf("%10s %10s %10s %10s %10s\n","房间号","房间容量","房间档次","房间价格","房间是否已用");
printf("--------------------------------------------------------------\n");
  for(i=0;i<num;i++)
  {
printf("%8d %8s %10s %10d %10s\n",rooms[i].room,rooms[i].capacity,rooms[i].level,rooms[i].price,rooms[i].use);
    }
printf("--------------------------------------------------------------\n");
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Search(struct Hotel rooms[])
{
    int i,n=0,id;
    printf("输入你要查找的房间号:");
    scanf("%d",&id);
    printf("\n");
    for(i=0;i<num;i++)
    {
        if(rooms[i].room==id)
        {
            n=1;
            printf("%8s %8s %8s %8s %8s\n","房间号","房间容量","房间档次","房间价格","房间是否已用");
            printf("--------------------------------------------------------------\n");
            printf("%10d%8s%8s%10d%8s\n",rooms[i].room,rooms[i].capacity,rooms[i].level,rooms[i].price,rooms[i].use);
            printf("--------------------------------------------------------------\n");
        }
    }
    if(n==0)
    {
      printf("未找到该房间信息\n");
    }
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Delete(struct Hotel rooms[])
{
    int i,n=0,id;
    printf("输入你要删除的房间号:");
    scanf("%d",&id);
    printf("\n");
    for(i=0;i<num;i++)
    {
        if(rooms[i].room==id)
        {
            n=1;
            printf("%8s %8s %8s %8s %8s\n","房间号","房间容量","房间档次","房间价格","房间是否已用");
            printf("--------------------------------------------------------------\n");
            printf("%10d%8s%8s%10d%8s\n",rooms[i].room,rooms[i].capacity,rooms[i].level,rooms[i].price,rooms[i].use);
            printf("--------------------------------------------------------------\n");
            printf("是否要删除该房间数据(1/n)?");
            getchar();
            if(getchar()=='1')
            {
                for(n=i;n<num-1;n++)
                {
                    rooms[n]=rooms[n+1];
                }
                num--;
                printf("\n删除成功");
            }
        }
    }
    if(n==0)
    {
        printf("未找到该房间信息\n");
    }
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Sort(struct Hotel rooms[])
{
    struct Hotel a;
    int i,j;
    for(j=0;j<num-1;j++)
    {
        for(i=0;i<num-1-j;i++)
        {
            if(rooms[i].room>rooms[i+1].room)
            {
                a=rooms[i];
                rooms[i]=rooms[i+1];
                rooms[i+1]=a;
            }
        }
    }
}
void readinfo()
{
    int i;
    FILE *fp;
    system("color F9");
    if((fp=fopen("HotelDate.txt","r"))==NULL)
    {
        printf("无法找到数据文件\n是否创建新文件(1/n)?\n");
        getchar();
        if(getchar()=='1')
        {
            fp=fopen("HotelDate.txt","a");
        }
    }
    for(i=0;i<1000;i++)
    {
        fscanf(fp,"%d %s %s %d %s %d",&rooms[i].room,rooms[i].capacity,rooms[i].level,&rooms[i].price,rooms[i].use,&num);
    }
}
void writeinfo()
{
    int i;
    FILE *fp;
    if((fp=fopen("HotelDate.txt","wb"))==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    for(i=0;i<num;i++)
    {
        fprintf(fp,"%d %s %s %d %s %d ",rooms[i].room,rooms[i].capacity,rooms[i].level,rooms[i].price,rooms[i].use,num);
    }
    fclose(fp);
}
int main()
{
    int n;
    readinfo();
    while(1)
    {
        printf("            |-----宾馆信息管理系统----|\n");
        printf("            | 1.添加房间信息          |\n");
        printf("            | 2.删除房间信息          |\n");
        printf("            | 3.按房间号查询房间信息  |\n");
        printf("            | 4.显示全部房间信息      |\n");
        printf("            | 5.退出并保存            |\n");
        printf("            |-------------------------|\n");
        printf("             请选择(1--5):");
        scanf("%d",&n);
        printf("\n");
        switch(n)
        {
        case 1:
            Input(rooms);
            Sort(rooms);
            system("cls");
            break;
        case 2:
            Delete(rooms);
            system("cls");
            break;
        case 3:
            Search(rooms);
            system("cls");
            break;
        case 4:
            Output(rooms);
            system("cls");
            break;
        case 5:
            writeinfo();
            exit(0);
        }
        system("cls");
    }
}
