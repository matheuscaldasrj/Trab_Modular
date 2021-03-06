#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores:   mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      	  ngtgmp - Felipe Nogueira de Souza
	          LL - Clayton Lucas Mendes Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   ngtgmp   10/09/2017 Início do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementação de mais funções
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revisão do código
*		0.04   ngtgmp   01/10/2017 Reparos após testes e revisão
*
*  $ED Descrição do módulo
*     Este módulo implementa o módulo lista duplamente encadeada para ser utilizada pelos demais módulos do projeto "Sistema Acadêmico da turma 3wb".
*	  Uma lista(list) contém um cabeçalho, com um nó apontanto para o primeiro item da lista, um apontando para o último e outro apontando para o nó cursor.
*	  Nós(node(s)) são estrutura contendo o próximo nó e o anterior (duplamente encadeada) e contém um ponteiro para um valor (void*)
***************************************************************************/
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

#ifdef _DEBUG
   #include   "conta.h"
   #include   "cespdin.h"
   #include "IdTiposEspaco.def"
   #include    "generico.h"
#endif

typedef struct node Node;

typedef struct list List;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condições de retorno
*
*
***********************************************************************/
   typedef enum {
     LIS_CondRetOK = 0 ,
     /* Executou correto */
     LIS_CondRetListaVazia = 1,
     /* Estrutura list está deletada */
     LIS_CondRetFaltouMemoria = 2 ,
     /* Faltou memória ao alocar dados */
     LIS_CondRetCursorNoFinal = 3,
	 /* Impossível obter próximo */
	 LIS_CondRetCursorNoInicio = 4,
	 /* Impossível obter anterior*/
	 LIS_CondRetErroEstrutura  = 5
	 /* Erro de Estrutura */

   }LIS_tpCondRet;

   /***********************************************************************
*
*  $TC Tipo de dados: LIS Modos de deturpar
*
*
***********************************************************************/

#ifdef _DEBUG

   typedef enum {

         DeturpaCursorNulo      =  1 ,
               /* Anula ponteiro corrente */
		 DeturpaLastNulo	    =  2 ,
			   /* Anula ponteiro Last */
		 DeturpaFirstNulo		=  3 ,
			   /* Anula ponteiro First */
		 DeturpaNextNulo		=  4 ,
			   /* Anula ponteiro Next */
		 DeturpaPrevNulo	    =  5 ,
			   /* Anula ponteiro Prev */
		 DeturpaCursorLixo      =  6 ,
               /* Faz corrente apontar para lixo */
		 DeturpaLastLixo	    =  7 ,
			   /* Faz Last apontar para lixo */
		 DeturpaFirstLixo		=  8 ,
			   /* Faz First apontar para lixo */
		 DeturpaNextLixo		=  9 ,
			   /* Faz Next apontar para lixo */
		 DeturpaPrevLixo	    =  10 ,
			   /* Faz Prev apontar para lixo */

   } LIS_tpModosDeturpacao ;

#endif
/***********************************************************************
*
*  $FC Função: LIS create List
*
*  $ED Descrição da função
*    Cria uma lista vazia
*
***********************************************************************/
LIS_tpCondRet createList(List** l);
/***********************************************************************
*
*  $FC Função: LIS del
*
*  $ED Descrição da função
*    Deleta uma lista já criada
*
***********************************************************************/
LIS_tpCondRet del(List* l);
/***********************************************************************
*
*  $FC Função: LIS clear
*
*  $ED Descrição da função
*    Limpa uma lista criada para zero nós
*
***********************************************************************/
LIS_tpCondRet clear(List* l);
/***********************************************************************
*
*  $FC Função: LIS push back
*
*  $ED Descrição da função
*    Insere um elemento no final da List
*
***********************************************************************/
LIS_tpCondRet push_back(List* l, void* val);
/***********************************************************************
*
*  $FC Função: LIS push front
*
*  $ED Descrição da função
*    Insere um elemento no começo da List
*
***********************************************************************/
LIS_tpCondRet push_front(List* l, void* val);
/***********************************************************************
*
*  $FC Função: LIS pop back
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o último elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_back(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop front
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o primeiro elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_front(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop cursor
*
*  $ED Descrição da função
*    Remove o nó cursor da lista e retorna a referência para seu valor.
*	 Caso o nó cursor seja o último nó, o cursor se torna o anterior, caso seja o primeiro
*	 o cursor se torna o seguinte. Em qualquer outro caso o cursor se torna o próximo.
*
***********************************************************************/
LIS_tpCondRet pop_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS get val cursor
*
*  $ED Descrição da função
*    Atualiza o parâmetro val para o valor no nó cursor.
*
***********************************************************************/
LIS_tpCondRet get_val_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS list size
*
*  $ED Descrição da função
*    Atualiza o parametro size para o tamanho da lista.
*
***********************************************************************/
LIS_tpCondRet list_size(List* l, unsigned int* size); //retorna a quantidade de elementos na List
/***********************************************************************
*
*  $FC Função: LIS first
*
*  $ED Descrição da função
*    Atualiza para o primeiro nó da lista
*
***********************************************************************/
LIS_tpCondRet first(List* l);
/***********************************************************************
*
*  $FC Função: LIS next
*
*  $ED Descrição da função
*    Atualiza o cursor para o próximo nó
*
***********************************************************************/
LIS_tpCondRet next(List* l);//atualiza o cursor para o próximo nó
/***********************************************************************
*
*  $FC Função: LIS prev
*
*  $ED Descrição da função
*    Atualiza o cursor para o nó anterior
*
***********************************************************************/
LIS_tpCondRet prev(List* l);//atualiza o cursor para o nó anterior
/***********************************************************************
*
*  $FC Função: LIS Deturpar Lista
*
*  $ED Descrição da função
*     Provoca uma determinada falha numa lista.
*     Serve como controle de teste da função LIS_VerificarLista
*
*  $EP Parâmetros
*     pListParm   - Ponteiro para a cabeça da lista a ser deturpada
*     ModoDeturpar     - Ação de deturpação (ver definição de LIS_tpModosDeturpacao)
*
*  $FV Valor retornado
*     LIS_CondRetOk
*     LIS_CondRetListaInexistente
*     LIS_CondRetCorrenteIndefinido - caso não se tenha chamado a função
*                                      LIS_AvancarElementoCorrente antes de
*									   uma ação que deturpe um elemento da lista
*     LIS_CondRetAcaoDeturpInexistente
*
***********************************************************************/

#ifdef _DEBUG

   LIS_tpCondRet LIS_DeturparLista( void * pListParm , LIS_tpModosDeturpacao ModoDeturpar ) ;

#endif

/***********************************************************************
*
*  $FC Função: LIS Verificar No de Lista
*
*  $ED Descrição da função
*     Avalia se um no de uma lista está estruturalmente correta.
*     Retorna o primeiro erro encontrado.
*
*  $EP Parâmetros
*     pNoParm    - Ponteiro para no da lista a ser verificada
*
*  $FV Valor retornado
*     Verificar os valores retornados citados anteriormente.
*     Apenas o primeiro erro é retornado.
*     A prioridade de retorno segue a ordem da declaração, então
*         LIS_Verificar_ListaValida só é retornado se não for
*         encontrada nenhuma das condições de erro anteriores.
*     No caso de erros relativos à elementos, todos os elementos são
*         avaliados e, somente após a passagem por todos os elementos,
*         as condições seguintes de retorno são verificadas.
*
***********************************************************************/

#ifdef _DEBUG

  LIS_tpCondRet VerificarNo( void* pNoParm );

#endif

#undef LISTA_EXT

/********** Fim do módulo de definição: LIS  Lista duplamente encadeada **********/

#else
#endif
