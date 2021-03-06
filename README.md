# MyStack
Desafio de Engenharia

## Introdução

Os arquivos stack_ctr.c e stack_ctr.h implementam listas linkadas, alocando memória dinamicamente. Cada nó contém um ponteiro para o seu sucessor imediato na pilha. A pilha não contém limite de tamanho e ira dar overflow se não houver mais espaço no heap para criação de novos nós. 
Para consultar o menor item da pilha em O(1), o nó sempre armazena o endereço do menor item até o momento.

O arquivo main.c apenas utiliza as funções criando e manipulando duas pilhas. A saída do programa está no arquivo Terminal_output.txt.

## Funções 

Para usar as funções, é necessário criar o primeiro nó:

    node_s *ex_node = NULL;

### 1. Adicionando um item

+ Recebe o endereço do nó e o valor a ser adicionado.
+ Retorna 1 caso memória tenha sido alocada corretamente.

        int push(node_s \**node, float value); --> Adiciona um item ao topo da pilha
        Ex.: ok = push(&ex_node, 8.2); // Adiciona 8.2 ao topo da pilha 
        
### 2. Removendo um item

+ Recebe o endereço do nó.
+ Retorna 0 caso não hajam itens na pilha.

        int pop(node_s \**node);** --> Retira um item do topo da pilha
        Ex.: ok = pop(&ex_node); 


### 3. Consultando o item do topo 
 
+ Recebe o nó e o endereço de uma variável para controle.
+ Retorna o valor no topo da pilha

        float top(node_s *node, int *ok);
        Ex.: val = top(ex_node, &ok);  //ok será 0 se pilha estiver vazia



### 4. Consultando o item de menor valor

+ Recebe o endereço do nó e o endereço de uma variável para controle.
+ Retorna o menor valor da pilha até o momento

        float mini(node_s \**node, int *ok);    
        Ex.: val = min(&ex_node, &ok);  //ok será 0 se a pilha estiver vazia




