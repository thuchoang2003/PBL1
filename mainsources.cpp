
#include<stdio.h>
#include<math.h>
#include<windows.h>
typedef long long ll;
const long long maxn = 100;
int n,k,m,cnt;
float a[maxn][maxn],b[maxn],c[maxn][maxn];
float result = 0,Da;
int opt;


void swap1(float *x, float *y)
{
    float tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

float dt1(int n, float a[maxn][maxn]) // Tính định thức bằng phương pháp khai triển theo cột
{

    float sum = 0;
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    for(int pos = 0; pos < n; pos++)
    {
        float b[maxn][maxn],tmp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(i < pos) b[i][j-1] = a[i][j];
                else if(i > pos) b[i-1][j - 1] = a[i][j];
            }
        }
        if(pos % 2 == 0) tmp = 1;
        else tmp = -1;
        sum += a[pos][0]*dt1(n-1,b)*tmp;
    }
    return sum;
}

int vao1(int n, float a[maxn][maxn],float b[])
{

    FILE *fo;
    fo = fopen("output1.out","w");
    Da = dt1(n,a);
    if(Da == 0)
    {
        printf("KHONG LA HE CRAME!\n");
        return 0;
    }
    ll q = n;
    printf("\n CAC NGHIEM CUA HE PHUONG TRINH TUONG UNG THEO CACH <1> LA: \n");
    while(q--)
    {
        float x[maxn][maxn];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == cnt) x[i][j] = b[i];
                else x[i][j] = a[i][j];
            }
        }
        cnt++;
        printf("%.2f ",dt1(n,x)/Da);
        fprintf(fo,"%.2f ",dt1(n,x)/Da);

    }
    printf("\n");
    fclose(fo);
    printf("\n");
    cnt = 0;
}

void doidong(float a[maxn][maxn],int i, int k,int n)
{
    for(int j = 0; j <= n - 1; j++) swap1(&a[i][j],&a[k][j]);
}

float dt(float a[maxn][maxn],int n) // Tính định thức theo kiểu biến đổi về ma trận tam giác trên
{
    int dem = 0;
    for(int i = 0; i <= n - 2; i++) // bien doi ma tran A ve ma tran tam giac tren
    {
        if(a[i][i] == 0)
        {
            for(int k = i + 1; k <= n - 1; k++)
            {
                if(a[k][i] != 0 && a[i][k] != 0)
                {
                    doidong(a,i,k,n);
                    dem++;
                    break;
                }
            }
        }
        if(a[i][i] != 0)
        {
            for(int j = i + 1; j <= n - 1; j++)
            {
                float m = -a[j][i]/a[i][i];
                for(int k = i; k <= n - 1; k++) a[j][k] = a[j][k] + a[i][k]*m;
            }
        }
    }
    float result = 1;
    for(int i = 0; i < n; i++)
    {
        result *= a[i][i];
    }
    if(dem % 2 == 0) return result;
    else return -result;

}

int vao(int n, float a[maxn][maxn], float b[])
{
    FILE *fo;
    fo = fopen("output1.out","w");
    float c[maxn][maxn];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j];
        }
    }


    float dtA = dt(a,n);

    if(dtA == 0)
    {
        printf("KHONG PHAI HE CRAME \n");
        return 0;
    }

    int t = n,cnt = 0;
    printf("\n CAC NGHIEM CUA HE PHUONG TRINH TUONG UNG THEO CACH <2> LA: \n");
    while(t--)
    {
        float d[maxn][maxn];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == cnt) d[i][j] = b[i];
                else d[i][j] = c[i][j];
            }
        }
        cnt++;
        printf("%.2f ",dt(d,n)/dtA);
        fprintf(fo,"%.2f ",dt(d,n)/dtA);
    }
    fclose(fo);
    printf("\n");
    printf("\n");

}



void test1()
{
    FILE *fi;
    fi = fopen("test1.inp","r");
    fscanf(fi,"%d",&n);
    printf("\n He phuong trinh vua nhap tu file la:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(fi,"%f",&a[i][j]);
            if(j != n-1)
            printf("%5gx%d  +  ",a[i][j],j+1);
            else printf("%5gx%d  ",a[i][j],j+1);
        }
        fscanf(fi,"%f",&b[i]);
        printf("  = %5g\n",b[i]);
    }
    fclose(fi);

    printf("\n");
}
void test2()
{
    FILE *fi;
    fi = fopen("test2.inp","r");
    fscanf(fi,"%d",&n);
    printf("\n He phuong trinh vua nhap tu file la:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(fi,"%f",&a[i][j]);
            if(j != n -1)
            printf("%5gx%d  + ",a[i][j],j+1);
            else printf("%5gx%d  ",a[i][j],j+1);
        }
        fscanf(fi,"%f",&b[i]);
        printf("  = %5g\n",b[i]);
    }
    fclose(fi);
    printf("\n");

}
void test3()
{
    FILE *fi;
    fi = fopen("test3.inp","r");
    fscanf(fi,"%d",&n);
    printf("\n He phuong trinh vua nhap tu file la:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(fi,"%f",&a[i][j]);
            if(j != n - 1)
            printf("%5gx%d  +  ",a[i][j],j+1);
            else printf("%5gx%d  ",a[i][j],j+1);
        }
        fscanf(fi,"%f",&b[i]);
        printf("  = %5g\n",b[i]);
    }
    fclose(fi);
    printf("\n");

}
void test4()
{
    FILE *fi;
    fi = fopen("test4.inp","r");
    fscanf(fi,"%d",&n);
    printf("\n He phuong trinh vua nhap tu file la:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(fi,"%f",&a[i][j]);
            if(j != n - 1)
            printf("%5gx%d  +  ",a[i][j],j+1);
            else printf("%5gx%d  ",a[i][j],j+1);
        }
        fscanf(fi,"%f",&b[i]);
        printf("  = %5g\n",b[i]);
    }
    fclose(fi);
    printf("\n");
}

int main()
{

    do
    {
        printf("\t====== MENU ======\t\n");
        printf("0: Thoat chuong trinh!\n");
        printf("1: File test thu 1!\n");
        printf("2: File test thu 2!\n");
        printf("3: File test thu 3!\n");
        printf("4: File test thu 4!\n");
        printf("5: Giai he phuong trinh Crame -> Dinh Thuc -> Khai trien theo cot!\n");
        printf("6: Giai he phuong trinh Crame -> Dinh Thuc -> Bien doi ve ma tran tam giac!\n");
        printf("Chon option : ");
        scanf("%d",&opt);
        system("cls");
        if(opt == 0)
        {
            printf("Thoat chuong trinh!");
            break;
        }
        if(opt == 1) test1();
        if(opt == 2) test2();
        if(opt == 3) test3();
        if(opt == 4) test4();
        if(opt == 5)
        {
            vao1(n,a,b);
        }
        if(opt == 6)
        {
            vao(n,a,b);
        }

    }
    while(opt != 0);
    return 0;
}
