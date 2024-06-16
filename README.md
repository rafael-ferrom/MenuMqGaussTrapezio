Descrição do Projeto
Este projeto implementa dois métodos numéricos importantes:

Método dos Mínimos Quadrados com a eliminação de Gauss.
Método dos Trapézios para integração numérica.
Estrutura do Código
O código é dividido em várias partes, com funções específicas para diferentes tarefas:

Definições e Inclusões: As bibliotecas padrão são incluídas e uma estrutura Ponto é definida para armazenar coordenadas (x, y).
Funções Auxiliares:
gauss(float** matriz, int n): Implementa o método de eliminação de Gauss para resolver sistemas lineares.
sisteminha(float** matriz, int n, float* solucao): Resolve o sistema linear triangular superior resultante da eliminação de Gauss.
form_funcao(Ponto* pontos, int n, int grau): Calcula os coeficientes da função ajustada pelo método dos mínimos quadrados.
funcao(float x, float coeficientes[], int expo): Calcula o valor da função polinomial para um dado x.
trap(float a, float b, int inter, float coeficientes[], int expo): Implementa o método dos trapézios para calcular a integral de uma função polinomial.

Menu Principal
O programa oferece um menu com três opções:

Método dos Mínimos Quadrados + Gauss
Método dos Trapézios
Sair do Programa
Método dos Mínimos Quadrados + Gauss
Este método ajusta uma função polinomial aos dados fornecidos.

O programa solicita o número de pontos e suas coordenadas (x, y).
Em seguida, pede o grau da função desejada.
O programa então calcula e exibe os coeficientes da função ajustada.
Método dos Trapézios
Este método calcula a integral de uma função polinomial definida pelo usuário.

O programa solicita os limites de integração (a e b).
Pede o número de subintervalos (n).
Solicita o grau da função e seus coeficientes.
Calcula e exibe o valor da integral utilizando o método dos trapézios.
Estrutura das Funções

gauss e sisteminha: Trabalham em conjunto para resolver sistemas lineares.
form_funcao: Constrói o sistema linear de mínimos quadrados e resolve usando gauss e sisteminha.
funcao: Avalia a função polinomial em um ponto.
trap: Implementa a regra dos trapézios para integração numérica.

Exemplo de Uso

Ajuste de Função Polinomial

Escolha a opção 1 no menu.
Digite o número de pontos (e.g., 3).
Insira as coordenadas dos pontos (e.g., 1 1, 2 4, 3 9).
Digite o grau da função (e.g., 2).
O programa exibirá os coeficientes da função ajustada (e.g., 1.000 = A0, 2.000 = A1, 3.000 = A2).

Cálculo da Integral

Escolha a opção 2 no menu.
Digite os limites de integração (e.g., 0 para a e 1 para b).
Digite o número de subintervalos (e.g., 10).
Insira o grau da função (e.g., 2) e os coeficientes (e.g., 1 0 1 para x^2 + 1).
O programa exibirá o valor da integral (e.g., 0.333333).
Conclusão

Este programa oferece uma ferramenta para ajuste de funções e integração numérica, útil para estudantes e profissionais em matemática e engenharia. Com uma interface simples e funcionalidade robusta, facilita a aplicação de métodos numéricos clássicos.






