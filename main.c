#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
typedef struct book
{
    char tit[30],aut[30],pub[30],isbn[30],cat[30];
    int num;
    int cur;
} book;
typedef struct adress
{
    char bui[20];
    char city [15];
    char str[30];
} adrs;
typedef struct bor
{
    int Id;
    char Fname[10];
    char lname[10];
    char email[30];
    long mob;
    adrs adr;
} bor;
typedef struct date1
{
    int day;
    int mon;
    long yr;

} datebor;
typedef struct date2
{
    int day;
    int mon;
    long yr;

} dateret;
typedef struct date3
{
    int day;
    int mon;
    long yr;

} dateretu;
void read(int);
void readall();
void add();
void del();
int ser();
void read_file();
void read_file1();
void ser1();
void save();
int menu1();
book f[100];
int n=0;
bor b[50];
int m=0;
void regis();
void savem();
int menu2();
void ser2();
int ser3();
void read_file2();
void ret();
int ser4();
int ser5();
void remove1();
datebor d1[50];
dateret d2[50];
dateretu d3[50];
int g=0;
void read_file3();
void borrow();
void overdue();
void pop();
void serisbn(int );
void serId(int);
int main()
{
    main_menu();

    return 0;
}
void add()
{
    int i;
    read_file();
    n=n+1;
    i=n-1;
    printf("%d %d\n",i,n);
    read(i);
    save();
}
void read_file()
{
    int  i=0;
    n=0;
    FILE *p;
    p=fopen("book.txt","r");
    if (p!=NULL)
    {
        while (!feof(p))
        {
            fscanf(p,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,&(f+i)->num,&(f+i)->cur);
            fscanf(p,"\n");
            n++;
            i++;
        }
        fclose(p);
    }
    else
        return 0;
}
void read(i)
{
    for (; i<n; i++)
    {
        printf("please enter the book number & the current number of books :\n");
        scanf("%d%d",&(f+i)->num,&(f+i)->cur);
        printf("please enter the book title :\n");
        gets((f+i)->cat);
        gets((f+i)->tit);
        printf("please enter the book author :\n");
        gets((f+i)->aut);
        printf("please enter the book publisher :\n");
        gets((f+i)->pub);
        printf("please enter the book isbn :\n");
        gets((f+i)->isbn);
        serisbn(i);
        printf("please enter the book category:\n");
        gets((f+i)->cat);
    }
}
int ser()
{

    int res,res1,res2,res3,i;
    char t[30];
    printf("the name,cat,isbn,author of book you want to search on it \n");
    getchar();
    gets(t);
    read_file();
    for (i=0; i<n; i++)
    {
        res=strcmp(t,(f+i)->tit);
        res1=strcmp(t,(f+i)->aut);
        res2=strcmp(t,(f+i)->isbn);
        res3=strcmp(t,(f+i)->cat);
        if(res==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res1==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res2==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res3==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else
            continue;
    }
    if (i==n)
        printf("not found!!!");
    return i;
}
void del ()
{
    int i,j;

    i=ser();
    if (i==n)
        exit(0);
    else
    {
        FILE *p;
        p=fopen("book.txt","a");
        n=n-1;
        j=i;
        for(; j<n; j++)
            fscanf(p,"%s,%s,%s,%s,%s,%d,%d \n",(f+j)->tit,(f+j)->aut,(f+j)->pub,(f+j)->isbn,(f+j)->cat,&(f+j)->num,&(f+j)->cur);
        for(; i<n; i++)
        {
            strcpy ((f+i)->tit,(f+(i+1))->tit);
            strcpy((f+i)->aut,(f+(i+1))->aut);
            strcpy((f+i)->pub,(f+(i+1))->pub);
            strcpy((f+i)->isbn,(f+(i+1))->isbn);
            strcpy((f+i)->cat,(f+(i+1))->cat);
            (f+i)->num=(f+(i+1))->num;
            (f+i)->cur=(f+(i+1))->cur;
        }
        fclose(p);
    }
}
void save()
{
    int i;
    FILE *p;
    p=fopen("book.txt","w");
    for (i=0; i<n; i++)
    {
        fprintf(p,"%s,%s,%s,%s,%s,%d,%d \n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
    }
    fclose(p);
}
void ser1()
{

    FILE *p;
    int res,res1,res2,res3,i=0;
    char t[30];
    printf("the name of book you want me to search on it\n");
    getchar();
    gets(t);
    p=fopen("book.txt","r");
    read_file();
    for (i=0; i<n; i++)
    {
        res=strcmp(t,(f+i)->tit);
        res1=strcmp(t,(f+i)->aut);
        res2=strcmp(t,(f+i)->isbn);
        res3=strcmp(t,(f+i)->cat);
        if(res==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res1==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res2==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
        else if(res3==0)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
            break;
        }
    }
    fclose(p);
    if (i==n)
        printf("not found!!!\n");
}
int menu1()
{

    printf("1-add book\n2-delete book\n3-search for book\n4-save book in a file\n5-read the books in a file and print it\n6-exit\n");
    int k;
    scanf("%d",&k);
    if(k==1)
    {
        add();
        menu1();
    }
    else if (k==2)
    {
        del();
        menu1();
    }
    else if (k==3)
    {
        ser1();
        menu1();
    }
    else if (k==4)
    {
        save();
        menu1();
    }
    else if (k==5)
    {
        read_file1();
        menu1();
    }


    else
        return 0;
}
void read_file1()
{
    int    i=0;
    n=0;
    FILE *p;
    p=fopen("book.txt","r");
    if (p!=NULL)
    {
        while (!feof(p))
        {
            fscanf(p,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,&(f+i)->num,&(f+i)->cur);
            fscanf(p,"\n");
            n++;
            i++;
        }
        fclose(p);
    }
    else
        return 0;
    for(i=0; i<n; i++)
    {
        printf("%s,%s,%s,%s,%s,%d,%d\n",(f+i)->tit,(f+i)->aut,(f+i)->pub,(f+i)->isbn,(f+i)->cat,(f+i)->num,(f+i)->cur);
    }
}
void regis()
{
    int k;
    read_file2();
    m++;
    printf("%d",m);
    for (k=m-1; k<m; k++)
    {
        printf("please enter the mobile \n");
        scanf("%ld",&b[k].mob);
        printf("please enter the Id \n");
        scanf("%d",&b[k].Id);
        serId(k);
        printf("please enter your first name\n");
        getchar();
        gets(b[k].Fname);
        printf("please enter your last name\n");
        gets(b[k].lname);
        printf("please enter ypur email\n");
        gets(b[k].email);
        printf("please enter your city\n");
        gets(b[k].adr.city);
        printf("please enter the number of your building\n");
        gets(b[k].adr.bui);
        printf("please enter your street\n");
        gets(b[k].adr.str);
    }
    savem();
}
void read_file2()
{
    m=0;
    int i=0;
    FILE *t;
    t=fopen("member.txt","r");
    if (t!=NULL)
    {
        while (!feof(t))
        {
            fscanf(t,"%[^,],%[^,],%d,%[^,],%[^,],%[^,],%ld,%s\n",b[i].Fname,b[i].lname,&b[i].Id,b[i].adr.bui,b[i].adr.str,b[i].adr.city,&b[i].mob,b[i].email);

            m++;
            i++;
        }
        fclose(t);
    }
    else
        return 0;
}
void savem()
{
    int j;
    FILE *t;
    t=fopen("member.txt","w");
    for (j=0; j<m; j++)
    {
        fprintf(t,"%s,%s,%d,%s,%s,%s,%ld,%s\n",b[j].Fname,b[j].lname,b[j].Id,b[j].adr.bui,b[j].adr.str,b[j].adr.city,b[j].mob,b[j].email);
    }
    fclose(t);
}
void ser2()
{
    int i=0;
    int l;
    printf(" please enter the id of member you want to search on: \n");
    scanf("%d",&l);

    read_file2();
    for (i=0; i<m; i++)
    {
        if(b[i].Id==l)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(b+i)->Fname,(b+i)->lname,(b+i)->adr.bui,(b+i)->adr.str,(b+i)->adr.city,(b+i)->mob,(b+i)->Id);
            break;
        }
    }
    if (i==m)
        printf("not found!!!\n");
}
void borrow()
{
    read_file3();
    g++;
    int k;
    k=ser3();
    int i;
    for (i=g-1; i<g; i++)
    {
        printf("please enter the day , month & year in this order \n");
        scanf("%d%d%d",&d1[i].day,&d1[i].mon,&d1[i].yr);
        d2[i].day=d1[i].day+15;
        d2[i].mon=d1[i].mon;
        d2[i].yr=d1[i].yr;
        if (d2[i].mon==12||d2[i].mon==1||d2[i].mon==3||d2[i].mon==5||d2[i].mon==7||d2[i].mon==8||d2[i].mon==10)
        {
            if (d2[i].day>31)
            {
                d2[i].mon=d1[i].mon+1;
                d2[i].day=d2[i].day-31;
            }
            if (d2[i].mon>12)
            {
                d2[i].mon=1;
                d2[i].yr=d1[i].yr+1;
            }
            else
            {
                d2[i].yr=d1[i].yr;
            }
        }
        else if  (d2[i].mon==4||d2[i].mon==6||d2[i].mon==9||d2[i].mon==11)
        {
            if (d2[i].day>30)
            {
                d2[i].mon=d1[i].mon+1;
                d2[i].day=d2[i].day-30;
            }
        }
        else
        {
            if (d2[i].day>28)
            {
                d2[i].mon=d1[i].mon+1;
                d2[i].day=d2[i].day-28;
            }
        }
    }
    read_file1();
    int h;
    h=ser();
    f[h].cur=f[h].cur-1;
    save();
    FILE *r;

    r=fopen("borrow.txt","a");
    for (i=0; i<g; i++)
        d3[i].day=0,d3[i].mon=0,d3[i].yr=0;

    for(i=g-1; i<g; i++)
        fprintf(r,"%d,%d/%d/%ld,%d/%d/%ld,%d/%d/%ld,%s\n",b[k].Id,d1[i].day,d1[i].mon,d1[i].yr,d2[i].day,d2[i].mon,d2[i].yr,d3[i].day,d3[i].mon,d3[i].yr,f[h].isbn);
    fclose(r);
}
void read_file3()
{
    int i=0;
    g=0;
    FILE *r;
    r=fopen("borrow.txt","r");
    if (r!=NULL)
    {
        while(!feof(r))
        {
            fscanf(r,"%d,%d/%d/%ld,%d/%d/%ld,%d/%d/%ld,%s",&b[i].Id,&d1[i].day,&d1[i].mon,&d1[i].yr,&d2[i].day,&d2[i].mon,&d2[i].yr,&d3[i].day,&d3[i].mon,&d3[i].yr,f[i].isbn);
            fscanf(r,"\n");
            g++;
            i++;
        }
        fclose(r);
    }
    else return 0;
}
int ser3()
{
    int i=0;
    int l;
    printf(" please enter the id of member you want to search on: \n");
    scanf("%d",&l);
    read_file2();
    for (i=0; i<m; i++)
    {
        if(b[i].Id==l)
        {
            printf("%s,%s,%s,%s,%s,%d,%d\n",(b+i)->Fname,(b+i)->lname,(b+i)->adr.bui,(b+i)->adr.str,(b+i)->adr.city,(b+i)->mob,(b+i)->Id);
            break;
        }
    }
    if (i==m)
        printf("not found!!!\n");
    return i;
}
int ser4()
{
    int i=0;
    int l;
    printf(" search by id : \n");
    scanf("%d",&l);
    read_file3();
    for (i=0; i<g; i++)
    {
        if(b[i].Id==l)
        {
            printf("%d,%d/%d/%ld,%d/%d/%ld,%s\n",b[i].Id,d1[i].day,d1[i].mon,d1[i].yr,d2[i].day,d2[i].mon,d2[i].yr,f[i].isbn);
            break;
        }
    }
    if (i==g)
        printf("not found!!!\n");
    return i;
}
void ret()
{
    int j;
    read_file3();
    j=ser4();
    printf("please enter the day , month & year of the returned book in this order\n ");
    scanf("%d%d%d",&d3[j].day,&d3[j].mon,&d3[j].yr);
    FILE *r;
    r=fopen("D:\\borrow.txt","w");
    for(j=0; j<g; j++)
        fprintf(r,"%d,%d/%d/%ld,%d/%d/%ld,%d/%d/%d,%s\n",b[j].Id,d1[j].day,d1[j].mon,d1[j].yr,d2[j].day,d2[j].mon,d2[j].yr,d3[j].day,d3[j].mon,d3[j].yr,f[j].isbn);
    fclose(r);
}
void remove1()
{
    int i,u,z;
    i=ser4();
    if (d3[i].day==0)
    {
        printf("cannot remove this id because he didn't return the books he borrowed \n");
        return 0;
    }
    else
    {
        u=ser5(i);
        FILE *t;
        m=0;
        read_file2();
        t=fopen("member.txt","w");
        m=m-1;
        for(; u<m; u++)
        {
            strcpy ((b+u)->Fname,(b+(u+1))->Fname);
            strcpy((b+u)->lname,(b+(u+1))->lname);
            strcpy((b+u)->adr.bui,(b+(u+1))->adr.bui);
            strcpy((b+u)->adr.str,(b+(u+1))->adr.bui);
            strcpy((b+u)->adr.city,(b+(u+1))->adr.city);
            strcpy((b+u)->email,(b+(u+1))->email);
            (b+u)->Id=(b+(u+1))->Id;
            (b+u)->mob=(b+(u+1))->mob;
        }
        printf("%d",m);
        for(u=0; u<m; u++)
            fprintf(t,"%s,%s,%d,%s,%s,%s,%ld,%s\n",b[u].Fname,b[u].lname,b[u].Id,b[u].adr.bui,b[u].adr.str,b[u].adr.city,b[u].mob,b[u].email);
        fclose(t);
    }
}
int ser5(j)
{
    int i=0;
    int l=b[j].Id;
    read_file2();
    for (i=0; i<m; i++)
    {
        if(b[i].Id==l)
        {
            printf("%s,%s,%s,%s,%s,%ld,%d\n",(b+i)->Fname,(b+i)->lname,(b+i)->adr.bui,(b+i)->adr.str,(b+i)->adr.city,(b+i)->mob,(b+i)->Id);
            break;
        }
    }
    if (i==m)
        printf("not found!!!\n");
    return i;
}
int menu2()
{
    int x;
    printf("1-register\n2-remove by Id\n3-exit\n");
    scanf("%d",&x);
    if (x==1)
    {
        regis();
        menu2();
    }
    else if (x==2)
    {
        remove1();
        menu2();
    }
    else
        return 0;
}
int menu3()
{
    int x;
    printf("1-borrow\n2-return\n3-exit\n");
    scanf("%d",&x);
    if (x==1)
    {
        borrow();
        menu3();
    }
    if (x==2)
    {
        ret();
        menu2();
    }
    else
        return 0;
}
void overdue()
{
    time_t rawtime;
    struct tm *info;
    char bufferd[3];
    char bufferm[3];
    char buffery[3];

    time( &rawtime );

    info = localtime( &rawtime );

    strftime(bufferd,3,"%d", info);
    strftime(bufferm,3,"%m", info);
    strftime(buffery,3,"%y", info);

    int day,mon,year;
    day=atoi(bufferd);
    mon=atoi(bufferm);
    year=atoi(buffery);
    printf("%d/%d/%d\n",day,mon,year);

    int i;
    read_file3();
    for (i=0; i<g; i++)
    {
        if(d3[i].day==0)
        {
            if (year>d2[i].yr)
                printf("%d,%s\n",b[i].Id,f[i].isbn);

            else if (mon>d2[i].mon)
                printf("%d,%s",b[i].Id,f[i].isbn);

            else if (day>d2[i].day)
                printf("%d,%s",b[i].Id,f[i].isbn);
        }
        else continue;
    }

}
void pop()
{
    read_file();
    int i,j,res[n],z;
    char tempa[30],tempt[30],tempi[30],tempc[30];

    for (i=0; i<n; i++)
    {
        res[i]=(f[i].num-f[i].cur);
    }
    for (j=0; j<n-1; j++)
    {
        for (i=0; i<n-1; i++)
        {
            if (res[i]<res[i+1])
            {
                strcpy(tempa,f[i].aut);
                strcpy(tempt,f[i].tit);
                strcpy(tempi,f[i].isbn);
                strcpy(tempc,f[i].cat);
                strcpy(f[i].aut,f[i+1].aut);
                strcpy(f[i].tit,f[i+1].tit);
                strcpy(f[i].isbn,f[i+1].isbn);
                strcpy(f[i].cat,f[i+1].cat);
                strcpy(f[i+1].cat,tempc);
                strcpy(f[i+1].aut,tempa);
                strcpy(f[i+1].tit,tempt);
                strcpy(f[i+1].isbn,tempi);
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%s,%s,%s,%s\n",f[i].aut,f[i].tit,f[i].isbn,f[i].cat);
}
void serisbn(i)
{
    int res,j;
    read_file();
    for (j=0; j<n; j++)
    {
        res=strcmp((f+i)->isbn,(f+j)->isbn);
        while (res==0)
        {
            printf("not Valid !!!!! \n Please enter another isbn\n");
            gets((f+i)->isbn);
            res=strcmp((f+i)->isbn,(f+j)->isbn);
        }
    }
    printf("Valid Isbn\n");
    n++;
}
void serId(k)
{
    int res,j;
    for (j=0; j<m-1; j++)
    {
        if (b[k].Id==b[j].Id)
            res=0;
        while (res==0)
        {
            printf("not Valid Id !!!!! \n Please enter another ID\n");
            scanf("%d",&b[k].Id);
            if (b[k].Id==b[j].Id)
                res=0;
            else break;
        }
    }
    printf("Valid ID\n");
}
void menu4()
{
    int i;
    printf("1-over due\n2-popular books\n3-exit\n");
    scanf("%d",&i);
    if (i==1)
    {
        overdue();
        menu4();
    }
    else if (i==2)
    {
        pop();
        menu4();
    }
    else
        return 0;

}
void main_menu ()
{
    int i;

    printf("1-books menu\n1-add book  2-delete book  3-search for book  4-print all books  5-save  6-exit\n");
    printf("***************************\n");
    printf("2-member menu\n1-registeration  2-remove\n");
    printf("***************************\n");
    printf("3-borrow&return menu\n1-borrow   2-return\n");
    printf("***************************\n");
    printf("4-extra\n1-overdue  2-popular books\n");
    scanf("%d",&i);
    if (i==1)
    {
        menu1();
        main_menu();
    }
    else if (i==2)
    {
        menu2();
        main_menu();
    }
    else if (i==3)
    {
        menu3();
        main_menu();
    }
    else if(i==4)
    {
        menu4();
        main_menu();
    }
    else exit(0);

}
