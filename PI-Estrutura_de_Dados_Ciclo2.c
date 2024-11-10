#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int id;
    char nome[50];
    float preco;
    int estoque;
    int vendas;
    struct Produto* proximo;
    struct Produto* anterior;
} Produto;

Produto* criarProduto(int id, char nome[], float preco, int estoque) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    novoProduto->id = id;
    strcpy(novoProduto->nome, nome);
    novoProduto->preco = preco;
    novoProduto->estoque = estoque;
    novoProduto->vendas = 0;
    novoProduto->proximo = NULL;
    novoProduto->anterior = NULL;
    return novoProduto;
}

void adicionarProduto(Produto** lista, Produto* novoProduto) {
    if (*lista == NULL) {
        *lista = novoProduto;
    } else {
        Produto* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoProduto;
        novoProduto->anterior = atual;
    }
}

void registrarVenda(Produto* lista, int id, int quantidade) {
    Produto* atual = lista;
    while (atual != NULL) {
        if (atual->id == id) {
            if (atual->estoque >= quantidade) {
                atual->estoque -= quantidade;
                atual->vendas += quantidade;
                printf("Venda registrada: %d unidades de %s\n", quantidade, atual->nome);
            } else {
                printf("Estoque insuficiente para %s\n", atual->nome);
            }
            return;
        }
        atual = atual->proximo;
    }
    printf("Produto nao encontrado.\n");
}

void exibirRelatorio(Produto* lista) {
    Produto* atual = lista;
    float totalLucro = 0;
    printf("Relatorio de produtos:\n");
    printf("ID | Nome         | Preco | Estoque | Vendas | Lucro\n");
    printf("------------------------------------------------------\n");
    while (atual != NULL) {
        float lucro = atual->vendas * atual->preco;
        totalLucro += lucro;
        printf("%d  | %-12s | %.2f | %7d | %6d | %.2f\n", atual->id, atual->nome, atual->preco, atual->estoque, atual->vendas, lucro);
        atual = atual->proximo;
    }
    printf("------------------------------------------------------\n");
    printf("Lucro total: %.2f\n", totalLucro);
}

void liberarMemoria(Produto* lista) {
    Produto* atual = lista;
    while (atual != NULL) {
        Produto* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Produto* listaProdutos = NULL;
    int opcao, id, estoque, quantidade;
    float preco;
    char nome[50];

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar produto\n");
        printf("2. Registrar venda\n");
        printf("3. Exibir relatorio\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o ID do produto: ");
            scanf("%d", &id);
            printf("Digite o nome do produto: ");
            scanf(" %[^\n]s", nome);  // %[^\n]s lê até encontrar uma nova linha
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            printf("Digite o estoque inicial do produto: ");
            scanf("%d", &estoque);
            Produto* novoProduto = criarProduto(id, nome, preco, estoque);
            adicionarProduto(&listaProdutos, novoProduto);
            printf("Produto adicionado com sucesso!\n");
        }
        else if (opcao == 2) {
            printf("Digite o ID do produto para registrar a venda: ");
            scanf("%d", &id);
            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidade);
            registrarVenda(listaProdutos, id, quantidade);
        }
        else if (opcao == 3) {
            exibirRelatorio(listaProdutos);
        }
        else if (opcao == 4) {
            liberarMemoria(listaProdutos);
            printf("Saindo do programa.\n");
            break;
        }
        else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
