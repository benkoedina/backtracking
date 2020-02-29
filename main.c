#include <stdio.h>
#include <stdlib.h>

void kiir( int *, int);
void kiir_matrix( int, int**);
void kombinacio( int *, int, int, int);
void kombinacio_forward_checking( int *, int, int, int);
int megfelel(int *, int);
int** forward_checking(int*,int,int,int);
int megfelel_frw(int *a, int k);
void kiir_frw( int *a, int n);

int ertekadas=0;
int stop=0;

int main()
{
    int *a, n,m,megoldas;

    printf("**********Kombinacio*********");
    printf("\n");
    printf("Kerem az n es m szamot: ");
    scanf("%i%i", &n, &m);
    printf("\n");
    printf("1)Nyers backtracking");
    printf("\n");
    printf("2)Backtracking + MVR + forward checking");
    printf("\n");
    printf("3)Backtracking + MVR + AC-3");
    printf("\n");

    scanf("%i", &megoldas);
    a=(int*)malloc((m+1)*sizeof(int));
    if(!a)
    {
        printf("hiba1");
        return 0;
    }
    if(megoldas==1)
    {
          kombinacio(a,n,m,0);
          printf("\n");
          printf("Ertekadasok szama: %i", ertekadas);
          printf("\n");

    }
    if(megoldas==2)
    {
          kombinacio_forward_checking(a,n,m,0);
          printf("\n");
          printf("Ertekadasok szama: %i", ertekadas);
          printf("\n");

    }


    free(a);

    return 0;
}

void kiir( int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%i", a[i]);
    }
    printf("\n");
}

void kiir_frw( int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%i", a[i]);
    }
    printf("\n");
}

void kombinacio(int *a, int n,int m, int k)
{
    int i;
    if(k==m)
    {
        kiir(a,m);
        stop=1;
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            if(stop==1)
            {
                break;
            }
            a[k]=i;
            ertekadas++;
            if(megfelel(a,k))
            {

                kombinacio(a,n,m,k+1);

            }
        }

    }

}
void kombinacio_forward_checking(int *a, int n,int m, int k)
{
    int i;
    int **tomb;
    if(k==m+1)
    {
        kiir_frw(a,m);
        stop=1;
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            if(stop==1)
            {
                break;
            }
            a[k]=i;
            ertekadas++;
            tomb=forward_checking(a,i,n,m);
            kiir_matrix(m,tomb);

            if(megfelel_frw(a,k))
            {

                kombinacio_forward_checking(a,n,m,k+1);

            }
        }

    }

}
int megfelel(int *a, int k)
{
    int i;
    for(i=0; i<k; i++)
    {
        if(a[k]<=a[i])
        {
            return 0;
        }
    }
    return 1;
}
int megfelel_frw(int *a, int k)
{
    int i;
    for(i=0; i<k; i++)
    {
        if(a[k]<=a[i])
        {
            return 0;
        }
    }
    return 1;
}
int** forward_checking(int *a,int p,int n,int m)
{
    int** lista;
    lista=(int**)malloc((m+1)*sizeof(int*));
    if(!lista) {puts("HIBA"); return 13;}

    int i,j;
    for(i=1; i<=m; i++){
        lista[i] =(int*)calloc((m+1),sizeof(int));

    }

    for(i=p+1;i<=m;i++)
    {

        for(j=1;j<=m;j++)
        {
            if((i==p+1) && (a[p]+j<=n))
            {
            lista[i][j]=a[p]+j;
            }
            else
            {
                if(lista[i-1][j]+1<=n)
                {
                lista[i][j]=lista[i-1][j]+1;
                }

            }
        }
    }
    return lista;
}
void kiir_matrix(int m,int**lista)
{
    int i,j;
    for(i=1; i<=m; i++)
    {
        for(j=1;j<=m;j++)
        {

        printf("%i ", lista[i][j]);
        }
        printf("\n");
    }
printf("\n");
}
