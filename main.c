#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};

typedef struct Node node;

int tam;
int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);


int main()
{
    node *FILA = (node*)malloc(sizeof(node));
    if (!FILA)
    {
        printf("Sem mem�ria dispon�vel!\n");
        exit(1);
    }
    else
    {
        inicia(FILA);
        int opt;
        do
        {
            opt = menu();
            opcao(FILA, opt);
        }while(opt);

        free(FILA);
    }

    return 0;
}

int menu(void)
{
    int opt;
    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar fila\n");
    printf("2. Exibir fila\n");
    printf("3. Adicionar Elemento na Fila\n");
    printf("4. Retirar Elemento da Fila\n");
    printf("Opcao: \n");
    scanf("%d", &opt);
    return opt;
}

void opcao(node *FILA, int op)
{
    node *tmp;
    switch (op)
    {
        case 0:
            libera(FILA);
            break;

        case 1:
            libera(FILA);
            inicia(FILA);
            break;

        case 2:
            exibe(FILA);
            break;

        case 3:
            insere(FILA);
            break;

        case 4:
            tmp = retira(FILA);

            if (tmp != NULL)
            {
                printf("Retirado: %3d\n\n", tmp->num);
                libera(tmp);
            }
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

void inicia(node *FILA)
{
    FILA->prox = NULL;
    tam = 0;
}

int vazia(node *FILA)
{

}

