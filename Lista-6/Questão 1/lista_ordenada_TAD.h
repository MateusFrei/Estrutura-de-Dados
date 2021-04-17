
typedef struct reg_lista tipo_lista;

tipo_lista* criarListaVazia();
int listaVazia(tipo_lista*);
void inserirElementoOrdenado(tipo_lista*, int);
int excluirElementoOrdenado(tipo_lista*, int);
int quantidadeElementosLista(tipo_lista*);
int* obterElementosLista(tipo_lista*);
tipo_lista* apagarLista(tipo_lista*);
//////EX - 01

float calcular_media(tipo_lista* );
int verificar_profundidade(tipo_lista*, int );
int comparar(tipo_lista*, tipo_lista*);