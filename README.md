# PI-Estrutura_de_Dados_Ciclo02


Este código em C implementa um sistema de gerenciamento de produtos usando uma lista duplamente encadeada. Cada produto é representado por um nó da lista com a estrutura Produto, que contém campos como id, nome, preço, estoque, e vendas, além de ponteiros proximo e anterior para permitir navegação bidirecional na lista.

O programa oferece um menu interativo com as seguintes opções:

1. Adicionar Produto: Permite que o usuário insira os detalhes de um novo produto (ID, nome, preço e estoque inicial), que é adicionado ao final da lista.

2. Registrar Venda: Solicita o ID de um produto e a quantidade vendida, atualizando o estoque e as vendas do produto, desde que haja estoque suficiente.

3. Exibir Relatório: Exibe uma lista de todos os produtos com suas informações, incluindo o lucro total obtido com as vendas.

4. Sair: Encerra o programa e libera a memória alocada para os produtos da lista.

O código é organizado para facilitar o gerenciamento de produtos, permitindo adicionar, registrar vendas e gerar relatórios sobre o estoque e as vendas, mantendo as referências entre os elementos por meio de uma lista duplamente encadeada.
