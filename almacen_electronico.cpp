/*
  Name: Almacen de Productos Electronicos
  Copyright: 01
  Author: Fco Alejandro Azorin Gil
  Date: 27/01/12 17:19
  Description: Base de Datos
  
  Menu
  1. Dar de Alta
  2. Dar de Baja
  3. Buscar
  4. Entrada de producto
  5. Salida de producto
  6. Salir
  
  1.Estructura para dar de Alta
      - Nombre Producto
      - Tipo de Producto
      - Posicion en el Almacen (Estanteria y Altura de la Estanteria)(0-9)(0-9)
      - Stock = 0 inicialmente (conforme entren productos incrementa, conforme salen decrece, de un producto en concreto)
      
      Subestructura para el Tipo (Codigo 1 letra + 2 digitos aleatorios (0-99)) (No puede repetirse el codigo)
            - Elementos Pasivos (A)
            - Semiconductores (B)
            - Circuitos Integrados (C)
            
  2.Dar de Baja
  Se libera los codigos de producto y posicion (podemos poner el -1 para liberarlo)
  
  3.Buscar --> Por nombre o codigo
  
  4.Entrada y Salida de Productos --> Se indica el producto por nombre o codigo y se indica la cantidad.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


int semilla (void);
int aleatoria(int min,int max);

struct zona{
       int estanteria;
       int altura;
};


struct alta{
       char nombre[50];
       char codigo[3];
       struct zona posicion;
       int stock;
       int borrado;
}ficha[300];



int main()
{
    char op,cod;
    int n=0,m,off,ok,ok2,ok3,i,pr,z,s,r,t,x;
    char busname[50],buscode[3],numchar[2],bus;
    
    do
    {
         system("Cls");
         printf("\nSISTEMA DE DATOS DEL ALMACEN DE PRODUCTOS ELECTRONICOS\n------------------------------------------------------\n");
         printf("\n- MENU -\n--------\n");
         printf("\n1. Dar de Alta un Producto\n2. Dar de Baja un Producto\n3. Busqueda de Productos\n4. Entrada y Salida de Stock\n5. Salir\n");
         do
         {
               fflush(stdin);
               op=getch();
         }
         while(op!='1'&&op!='2'&&op!='3'&&op!='4'&&op!='5');
    
         if(op=='1')//Dar de Alta
         {

                    system("Cls");
                    printf("\nSistema de Introduccion de nuevos Productos en la Base de Datos\n---------------------------------------------------------------\n");

                    printf("\nIntroduzca el nombre del producto: ");
                    do
                    {
                          ok3=1;
                          fflush(stdin);
                          gets(ficha[n].nombre);
                          for(x=0;x<n;x++)
                          {
                                      pr=strcmp(ficha[n].nombre,ficha[x].nombre);
                                       if(pr==0)
                                       {
                                            ok3=0;
                                            printf("\nEl dato ya existe, ponga otro");
                                       }
                          } 
                    }
                    while(ok3==0);
                    printf("\nIntroduzca el codigo del Producto (en Mayus) siendo");
                    printf("\nElementos Pasivos    --> A\nSemiconductores      --> B\nCircuitos Integrados --> C");
                    do
                    {
                         fflush(stdin);
                         cod=getch();
                    }
                    while(cod!='A' && cod!='B' && cod!='C');

                    for(i=1;i<3;i++)
                       {
                            ficha[n].codigo[i]=aleatoria(48,57);
                       }
                    ficha[n].codigo[0]=cod;
                    printf("\n\nEl codigo es: %s",ficha[n].codigo);
                    do
                    {
                           ok=0;
                           printf("\n\nIntroduzca la ubicacion del producto");
                           printf("\nEstanteria: ");                           
                           
                           do
                           {     
                                fflush(stdin);
                                scanf("%d",&ficha[n].posicion.estanteria);                              
                           }
                           while(ficha[n].posicion.estanteria<0 || ficha[n].posicion.estanteria>9);
                           
                           printf("Altura: ");
                           do
                           {
                                fflush(stdin);
                                scanf("%d",&ficha[n].posicion.altura);
                           }
                           while(ficha[n].posicion.altura<0 || ficha[n].posicion.altura>9);
                           
                           for(m=0;m<n;m++)
                           {
                                    if(ficha[n].posicion.altura==ficha[m].posicion.altura && ficha[n].posicion.estanteria==ficha[m].posicion.estanteria)
                                    {
                                           ok=1;
                                    }
                           }
                           if(ok==1)
                           {
                                    printf("\nUbicacion Ocupada");
                           }
                    }
                    while(ok==1);
                    
                    ficha[n].stock=0;
                    ficha[n].borrado=0;
                    n++;
                    printf("\n\nSe ha introducido los datos satisfactoriamente");
                    getch();
         }
         if(op=='2')
         {
                system("Cls");
                printf("\nProceso de Baja de la Base de datos\n--------------------------------------");
                printf("\n\nEs aconsejable realizar la busqueda para estar seguro de la ficha deseada");
                printf("\nNO CONFUNDIR FICHA CON CODIGO DE PRODUCTO\n");
                printf("\nRegresar al menu para Buscar: <S> o <N>");
                do
                {
                      fflush(stdin);
                      bus=getch();
                }
                while(bus!='s' && bus!='S' && bus!='n' && bus!='N');
                
                if(bus=='N' ||bus=='n')
                {     
                     printf("\n\nAhora introduce el Numero de Ficha elegida para borrar: ");
                     fflush(stdin);
                     scanf("%d",&m);
                     ficha[m].borrado=1; 
                     if(ficha[m].borrado==1)
                     {
                          for(i=0;i<3;i++)
                          {
                             ficha[m].codigo[i]=aleatoria(48,49);
                             ficha[m].posicion.estanteria=(-1);
                             ficha[m].posicion.altura=(-1);
                          }
                     }
                             
                }                 
                    
         }
         if(op=='3')
         {
                  system("Cls");
                  printf("\nBusqueda de Productos\n---------------------\n");
                  printf("\n1. Busqueda por Nombre\n2. Busqueda por Codigo");
                  do
                  {
                         fflush(stdin);
                         op=getch();
                  }
                  while(op!='1'&&op!='2');
                  
                  if(op=='1')
                  {
                       ok2=1;
                       system("Cls");
                       printf("\nIntroduce el Nombre a buscar: ");
                       fflush(stdin);
                       gets(busname);

                       z=0;
                       for(m=0;m<n;m++)
                       {
                           ok2=strcmp(busname,ficha[m].nombre);
                           if(ficha[m].borrado!=1)
                           {   
                                   if(ok2==0)
                                   {

                                       system("Cls");
                                       printf("\nFICHA %d",m);
                                       printf("\n\nNombre: ");
                                       puts(ficha[m].nombre);
                                       printf("Codigo: %s",ficha[m].codigo);
                                       printf("\nUbicacion:\n    Estanteria --> %d\n    Altura--> %d",ficha[m].posicion.estanteria,ficha[m].posicion.altura);
                                       printf("\nStock: %d",ficha[m].stock);
                                       z++;
                                   
                                   }
                            }
                       }
                       if(ok2!=0 || z==0)
                       {
                                 printf("\nBusqueda sin resultados, repita la operacion");
                       }
                       getch();
                  }
                  if(op=='2')
                  {
                       ok2=1;
                       system("Cls");
                       printf("\nIntroduce el Codigo a buscar [FORMATO (Z99)]: ");
                       fflush(stdin);
                       gets(buscode);
 
                       z=0;                      
                       for(m=0;m<n;m++)
                       {
                           ok2=strcmp(buscode,ficha[m].codigo);
                           if(ficha[m].borrado!=1)
                           {
                                if(ok2==0)
                                {
                                       system("Cls");
                                       printf("\nFICHA %d",m);
                                       printf("\n\nNombre: ");
                                       puts(ficha[m].nombre);
                                       printf("Codigo: %s",ficha[m].codigo);
                                       printf("\nUbicacion:\n   Estanteria --> %d\n   Altura -----> %d",ficha[m].posicion.estanteria,ficha[m].posicion.altura);
                                       printf("\nStock: %d",ficha[m].stock);
                                       z++;
                                }
                           }
                       }
                       if(ok2!=0 || z==0)
                       {
                                 printf("\nBusqueda sin resultados, repita la operacion");
                       }
                       getch();
                  }                  
                    
         }
         if(op=='4')
         {
                    system("Cls");
                    printf("\n\nEs aconsejable realizar la busqueda para estar seguro de la ficha deseada");
                    printf("\nNO CONFUNDIR FICHA CON CODIGO DE PRODUCTO\n");
                    printf("\nEntrada y Salida de Stock\n-------------------------\n");
                    printf("\n1. Entrada de Stock\n2. Salida de Stock\n3. Volver\n");
                    do
                    {
                         fflush(stdin);
                         op=getch();
                    }
                    while(op!='1' && op!='2' && op!='3');
                    
                    if(op=='1')
                    {
                             ok2=1,s=0;
                             system("Cls");
                             printf("\nEntrada de Stock\n----------------\n");
                             printf("\nIntroducza el nombre del producto: ");
                             fflush(stdin);
                             gets(busname);
                             
                             for(m=0;m<n;m++)
                             {
                                   ok2=strcmp(busname,ficha[m].nombre);
                                   if(ficha[m].borrado!=1)
                                   {   
                                           if(ok2==0)
                                           {
                                                system("Cls");
                                                printf("\nFICHA %d",m);
                                                printf("\n\nNombre: ");
                                                puts(ficha[m].nombre);
                                                printf("Codigo: %s",ficha[m].codigo);
                                                printf("\nUbicacion:\n   Estanteria --> %d\n   Altura -----> %d",ficha[m].posicion.estanteria,ficha[m].posicion.altura);
                                                printf("\nStock: %d",ficha[m].stock);
                                                z++;
                                                t=m;
                                                printf("\n\nIntroduzca la Cantidad de Stock que entra: ");
                                                fflush(stdin);
                                                scanf("%d",&s);
                                   
                                           
                                                for(r=0;r<s;r++)
                                                {
                                                      ficha[t].stock++;
                                                }
                                                printf("\n\nCantidad introducidad correctamente");
                                           }
                                   }
                             }
                             if(ok2!=0 || z==0)
                             {
                                 printf("\nNo hay productos con ese nombre, repita la operacion");
                             }

                    }
                    if(op=='2')
                    {
                             ok2=1,s=0;
                             system("Cls");
                             printf("\nSalida de Stock\n----------------\n");
                             printf("\nIntroducza el nombre del producto: ");
                             fflush(stdin);
                             gets(busname);
                             
                             for(m=0;m<n;m++)
                             {
                                   ok2=strcmp(busname,ficha[m].nombre);
                                   if(ficha[m].borrado!=1)
                                   {   
                                           if(ok2==0)
                                           {
                                                system("Cls");
                                                printf("\nFICHA %d",m);
                                                printf("\n\nNombre: ");
                                                puts(ficha[m].nombre);
                                                printf("Codigo: %s",ficha[m].codigo);
                                                printf("\nUbicacion:\n   Estanteria --> %d\n   Altura -----> %d",ficha[m].posicion.estanteria,ficha[m].posicion.altura);
                                                printf("\nStock: %d",ficha[m].stock);
                                                z++;
                                                t=m;
                                                printf("\n\nIntroduzca la Cantidad de Stock que sale: ");
                                                fflush(stdin);
                                                scanf("%d",&s);
                                   
                                           
                                                for(r=0;r<s;r++)
                                                {
                                                      ficha[t].stock--;
                                                }
                                                printf("\n\nCantidad introducidad correctamente");
                                           }
                                   }
                             }
                             if(ok2!=0 || z==0)
                             {
                                 printf("\nNo hay productos con ese nombre, repita la operacion");
                             }                             
                    }
               getch();              
         }
         if(op=='5')
         {
                    off=1;
         }
    
    }
    while(off!=1);

    
return 0;    
}

//FUNCIONES
//Funcion Semilla
int semilla (void)       
{
    __asm__ __volatile__("rdtsc"); //Coge el ciclo del reloj del procesador
    
}

//Funcion Aleatoria
int aleatoria(int min,int max) 
{
int n;

     do
     {
         srand(semilla());
         n=rand();  
     }    
     while(min>n||n>max);
     
return n;
}

