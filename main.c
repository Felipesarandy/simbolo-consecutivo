#include <stdio.h>
#include <string.h>
#define TAMANHO 100

char verificador(char *msg);

char verificador(char *msg)
{
    for (int i = 0; i < strlen(msg) - 1; i++)
    {
        if (msg[i] == msg[i + 1])
            return msg[i];
    }
    return ' ';
}

int main()
{
    char simbolo;
    char mensagem[TAMANHO];
    int opcao;

    do
    {
        printf("\n===MENU===\n");
        printf("1 - Inserir Mensagem\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite a mensagem (max %d caracteres): ", TAMANHO);
            scanf("%s", mensagem);

            if (strlen(mensagem) < 2)
            {
                printf("Erro: A mensagem deve ter pelo menos 2 caracteres.\n");
                break;
            }

            simbolo = verificador(mensagem);

            if (simbolo != ' ')
            {
                printf("Primeiro simbolo consecutivo: %c\n", simbolo);
                break;
            }

            else
                printf("Nenhum simbolo consecutivo encontrado.\n");
        }

        else if (opcao == 0)
            printf("Encerrando o programa.\n");

        else
            printf("Opcao invalida. Tente novamente.\n");
    }
    while (opcao != 0);

    return 0;
}
