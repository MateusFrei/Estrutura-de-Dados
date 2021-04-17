typedef struct reg_lista tipo_lista;

//A
tipo_lista* criarListaVazia();
//B
void incluir_dado(tipo_lista*, int);
//C
void remover_elemento(tipo_lista*,int);
//D
int verificar_vazia(tipo_lista*);
//E
int quantidadeElementos(tipo_lista*);
//F
void apagar_lista(tipo_lista*);
//G
int* obter_elementos(tipo_lista*);
//H
void concatenacao(tipo_lista*, tipo_lista*);