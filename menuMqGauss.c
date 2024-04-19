#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef struct 
{
    float x;
    float y;
} Ponto;

void gauss(float** matriz, int n);
void sisteminha(float** matriz, int n, float* solucao);
void form_funcao(Ponto* pontos, int n, int grau);
float funcao(float x, float coeficientes[], int expo);
float trap(float a, float b, int inter, float coeficientes[], int expo);

main()
{
	Ponto* pontos;
	
	int op, inter, expo, n, grau, i,j;
	float a, b;
	
	do
	{
		
		printf("\nMenu\n 1- Metodo minimos quadrados + Gauss\n 2- Metodo dos trapezios\n 3- Sair do programa\n");
		scanf("%i",&op);
		fflush(stdin);
		
		switch(op)
		{
			
	case 1:
		printf("Digite o numero de pontos: ");
    	scanf("%d", &n);
    	fflush(stdin);

    	pontos = (Ponto*)malloc(n * sizeof(Ponto));

    	for (i = 0; i < n; i++) 
		{
        printf("Digite as coordenadas do ponto %d (x y): ", i + 1);
        scanf("%f %f", &pontos[i].x, &pontos[i].y);
        fflush(stdin);
    	}//for

    
    	printf("Digite o grau da funcao que deseja obter (Ex: reta/parabola): ");
    	scanf("%d", &grau);
    	fflush(stdin);

    
    	form_funcao(pontos, n, grau);
				
		break;
		
	case 2:
			
		printf("Digite o limite inferior da integral (a): ");
    	scanf("%f", &a);
    	fflush(stdin);
    
    	printf("Digite o limite superior da integral (b): ");
    	scanf("%f", &b);
    	fflush(stdin);
    
    	printf("Digite o numero de subintervalos (n): ");
    	scanf("%d", &inter);
    	fflush(stdin);
    
    	printf("Digite o grau da função: ");
    	scanf("%d", &expo);
    	fflush(stdin);

    	float coeficientes[expo + 1];
    	for (j = 0; j <= expo; j++) 
		{
        printf("Digite o coeficiente de x^%d: ", j);
        scanf("%f", &coeficientes[j]);
        fflush(stdin);
    	}//for

    	float resultado = trap(a, b, inter, coeficientes, expo);
    	printf("Resultado = %f\n", resultado);
		break;
				
		}//switch
		
	}while(op != 3);
}//main

void gauss(float** matriz, int n) 
{
    int i, j, k;
    float fator;

    for (i = 0; i < n - 1; i++) 
	{
        if (matriz[i][i] == 0.0) 
		{
            printf("Erro: divisao por zero encontrada.\n");
            exit(1);
        }//if
        
        for (j = i + 1; j < n; j++) 
		{
            fator = matriz[j][i] / matriz[i][i];
            
            for (k = i; k < n + 1; k++) 
			{
                matriz[j][k] -= fator * matriz[i][k];
            }//forter
        }//forsec
    }//forp
}//gauss


void sisteminha(float** matriz, int n, float* solucao) 
{
    int i, j;
    float soma;

    solucao[n - 1] = matriz[n - 1][n] / matriz[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--) 
	{
        soma = 0.0;

        for (j = i + 1; j < n; j++) 
		{
            soma += matriz[i][j] * solucao[j];
        }//forsec

        solucao[i] = (matriz[i][n] - soma) / matriz[i][i];
    }//forpri
}//sisteminha


void form_funcao(Ponto* pontos, int n, int grau) 
{
    int i, j, k;
    float** matriz;
    float* resp;

    matriz = (float**)malloc((grau + 1) * sizeof(float*));
    for (i = 0; i <= grau; i++) 
	{
        matriz[i] = (float*)malloc((grau + 2) * sizeof(float));
    }//foralocação
    resp = (float*)malloc((grau + 1) * sizeof(float));

    
    for (i = 0; i <= grau; i++) 
	{
        for (j = 0; j <= grau; j++) 
		{
            matriz[i][j] = 0.0;
            for (k = 0; k < n; k++) 
			{
                matriz[i][j] += pow(pontos[k].x, i + j);
            }//fortri
        }//forsec1
        matriz[i][grau + 1] = 0.0;
        for (k = 0; k < n; k++) 
		{
            matriz[i][grau + 1] += pontos[k].y * pow(pontos[k].x, i);
        }//forsec2
    }//forpri

    
    gauss(matriz, grau + 1);
    sisteminha(matriz, grau + 1, resp);

    
    printf(" Resposta :\n ");
    for (i = 0; i <= grau; i++) 
	{
        printf("%.3f", resp[i]);
        if (i <= grau) 
		{
            printf(" = A%d \n ", i);
        }//if
    }//for
    printf("\n");

}//form_funcao

float funcao(float x, float coeficientes[], int expo) 
{
    float resultado = 0.0;
    for (int i = 0; i <= expo; i++) 
	{
        resultado += coeficientes[i] * pow(x, i);
    }//for
    
    return resultado;
    
}//funcao

float trap(float a, float b, int inter, float coeficientes[], int expo) 
{
    float h = (b - a) / inter; 
    float soma = funcao(a, coeficientes, expo) + funcao(b, coeficientes, expo); 

    
    for (int i = 1; i < inter; i++) 
	{
        float x = a + i * h;
        soma += 2 * funcao(x, coeficientes, expo);
    }//for

    float resp = (h / 2) * soma;
    
    return resp;
    
}//trap