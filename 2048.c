//protótipo do jogo 2048 em C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar(int jogo[][4]);
char menu();
void cima(int jogo[][4]);
void esquerda(int jogo[][4]);
void direita(int jogo[][4]);
void baixo(int jogo[][4]);
int gameover(int jogo[][4]);

void main()
{
    int jogo[4][4];
    char op;
    int i, j, fim = 0;

    inicializar(jogo); //inicializa o jogo para o usuario

    do
    {
        op = menu();
        switch (op)
        {
        case 'w':
            cima(jogo);
            break;
        case 'a':
            esquerda(jogo);
            break;
        case 'd':
            direita(jogo);
            break;
        case 's':
            baixo(jogo);
            break;
        }

        for (i = 0; i < 4; i++)  //verifica se o usuario venceu
            for (j = 0; j < 4; j++)
                if (jogo[i][j] == 2048)
                {
                    printf("\nVENCEU\n");
                    op = 'e';
                }

        fim = gameover(jogo); //verifica se o usuario perdeu
        if (fim > 0)
        {
            printf("\nGAME OVER\n");
            op = 'e';
        }

        for (i = 0; i < 4; i++) //imprime a matriz do jogo para o usuario
        {
            for (j = 0; j < 4; j++)
                printf("%d ", jogo[i][j]);
            printf("\n");
        }

    } while (op != 'e');
}

void inicializar(int jogo[][4])
{
    int i, j;
    int aux;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            jogo[i][j] = 0;

    srand(time(NULL)); // a cada execução o valor da "semente" será diferente
    i = rand() % 3;    // gerando valores aleatórios entre 0 e 3
    srand(time(NULL));
    j = rand() % 3;
    jogo[i][j] = 2;

    do
    {
        srand(time(NULL));
        i = rand() % 3;
        srand(time(NULL));
        j = rand() % 3;
        aux = jogo[i][j];
        if (aux == 0)
            jogo[i][j] = 2;
    } while (aux != 0);

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", jogo[i][j]);
        printf("\n");
    }
}

char menu()
{
    char op;
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nMENU\n");
    printf("w-mover para cima\na-mover para esquerda\nd-mover para direita\ns-mover para baixo\ne-sair do jogo\nopcao: ");
    fflush(stdin);
    scanf("%c", &op);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return op;
}

void cima(int jogo[][4])
{
    int i, j, k, aux;
    int teste = 0;

    for (j = 0; j < 4; j++)
        for (i = 0; i < 3; i++)
            if (jogo[i][j] != 0)
            {
                k = i + 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[k][j])
                    {
                        jogo[i][j] += jogo[k][j];
                        jogo[k][j] = 0;
                        aux++;
                        teste++;
                    }
                    else if (jogo[k][j] == 0)
                    {
                        k++;
                        if (k > 3)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    for (j = 0; j < 4; j++)
        for (i = 1; i <= 3; i++)
            if (jogo[i][j] != 0)
            {
                aux = 0;
                k = 0;
                do
                {
                    if (jogo[k][j] == 0)
                    {
                        jogo[k][j] = jogo[i][j];
                        jogo[i][j] = 0;
                        aux++;
                        teste++;
                    }
                    else
                    {
                        k++;
                        if (k == i)
                            aux++;
                    }
                } while (aux == 0);
            }

    if (teste > 0)
        do
        {
            srand(time(NULL));
            i = rand() % 3;
            srand(time(NULL));
            j = rand() % 3;
            aux = jogo[i][j];
            if (aux == 0)
                jogo[i][j] = 2;
        } while (aux != 0);
    else
        printf("\nnenhuma acao feita\n\n");
}

void esquerda(int jogo[][4])
{
    int i, j, k, aux;
    int teste = 0;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            if (jogo[i][j] != 0)
            {
                k = j + 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[i][k])
                    {
                        jogo[i][j] += jogo[i][k];
                        jogo[i][k] = 0;
                        aux++;
                        teste++;
                    }
                    else if (jogo[i][k] == 0)
                    {
                        k++;
                        if (k > 3)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    for (i = 0; i < 4; i++)
        for (j = 1; j <= 3; j++)
            if (jogo[i][j] != 0)
            {
                aux = 0;
                k = 0;
                do
                {
                    if (jogo[i][k] == 0)
                    {
                        jogo[i][k] = jogo[i][j];
                        jogo[i][j] = 0;
                        aux++;
                        teste++;
                    }
                    else
                    {
                        k++;
                        if (k == j)
                            aux++;
                    }
                } while (aux == 0);
            }

    if (teste > 0)
        do
        {
            srand(time(NULL));
            i = rand() % 3;
            srand(time(NULL));
            j = rand() % 3;
            aux = jogo[i][j];
            if (aux == 0)
                jogo[i][j] = 2;
        } while (aux != 0);
    else
        printf("\nnenhuma acao feita\n\n");
}

void direita(int jogo[][4])
{
    int i, j, k, aux;
    int teste = 0;

    for (i = 0; i < 4; i++)
        for (j = 3; j > 0; j--)
            if (jogo[i][j] != 0)
            {
                k = j - 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[i][k])
                    {
                        jogo[i][j] += jogo[i][k];
                        jogo[i][k] = 0;
                        aux++;
                        teste++;
                    }
                    else if (jogo[i][k] == 0)
                    {
                        k--;
                        if (k < 0)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    for (i = 0; i < 4; i++)
        for (j = 2; j >= 0; j--)
            if (jogo[i][j] != 0)
            {
                aux = 0;
                k = 3;
                do
                {
                    if (jogo[i][k] == 0)
                    {
                        jogo[i][k] = jogo[i][j];
                        jogo[i][j] = 0;
                        aux++;
                        teste++;
                    }
                    else
                    {
                        k--;
                        if (k == j)
                            aux++;
                    }
                } while (aux == 0);
            }

    if (teste > 0)
        do
        {
            srand(time(NULL));
            i = rand() % 3;
            srand(time(NULL));
            j = rand() % 3;
            aux = jogo[i][j];
            if (aux == 0)
                jogo[i][j] = 2;
        } while (aux != 0);
    else
        printf("\nnenhuma acao feita\n\n");
}

void baixo(int jogo[][4])
{
    int i, j, k, aux;
    int teste = 0;

    for (j = 0; j < 4; j++)
        for (i = 3; i > 0; i--)
            if (jogo[i][j] != 0)
            {
                k = i - 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[k][j])
                    {
                        jogo[i][j] += jogo[k][j];
                        jogo[k][j] = 0;
                        aux++;
                        teste++;
                    }
                    else if (jogo[k][j] == 0)
                    {
                        k--;
                        if (k < 0)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    for (j = 0; j < 4; j++)
        for (i = 2; i >= 0; i--)
            if (jogo[i][j] != 0)
            {
                aux = 0;
                k = 3;
                do
                {
                    if (jogo[k][j] == 0)
                    {
                        jogo[k][j] = jogo[i][j];
                        jogo[i][j] = 0;
                        aux++;
                        teste++;
                    }
                    else
                    {
                        k--;
                        if (k == i)
                            aux++;
                    }
                } while (aux == 0);
            }

    if (teste > 0)
        do
        {
            srand(time(NULL));
            i = rand() % 3;
            srand(time(NULL));
            j = rand() % 3;
            aux = jogo[i][j];
            if (aux == 0)
                jogo[i][j] = 2;
        } while (aux != 0);
    else
        printf("\nnenhuma acao feita\n\n");
}

int gameover(int jogo[][4])
{
    int i, j, k;
    int aux = 0;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (jogo[i][j] == 0)
                return 0;

    //CIMA
    for (j = 0; j < 4; j++)
        for (i = 0; i < 3; i++)
            if (jogo[i][j] != 0)
            {
                k = i + 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[k][j])
                    {
                        aux++;
                        return 0;
                    }
                    else if (jogo[k][j] == 0)
                    {
                        k++;
                        if (k > 3)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    //ESQUERDA
    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            if (jogo[i][j] != 0)
            {
                k = j + 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[i][k])
                    {
                        aux++;
                        return 0;
                    }
                    else if (jogo[i][k] == 0)
                    {
                        k++;
                        if (k > 3)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    //DIREITA
    for (i = 0; i < 4; i++)
        for (j = 3; j > 0; j--)
            if (jogo[i][j] != 0)
            {
                k = j - 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[i][k])
                    {
                        aux++;
                        return 0;
                    }
                    else if (jogo[i][k] == 0)
                    {
                        k--;
                        if (k < 0)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    //BAIXO
    for (j = 0; j < 4; j++)
        for (i = 3; i > 0; i--)
            if (jogo[i][j] != 0)
            {
                k = i - 1;
                aux = 0;
                do
                {
                    if (jogo[i][j] == jogo[k][j])
                    {
                        aux++;
                        return 0;
                    }
                    else if (jogo[k][j] == 0)
                    {
                        k--;
                        if (k < 0)
                            aux++;
                    }
                    else
                        aux++;
                } while (aux == 0);
            }

    return 1;
}
