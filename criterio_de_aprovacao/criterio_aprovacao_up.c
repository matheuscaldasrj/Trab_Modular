/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Criterio de Aprovação
*
*  Arquivo gerado:              Criterio_Aprovacao.C
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: 	pg - Pedro Gabriel Serodio Sales
*               SaintL - Leonardo Abreu Santos
*	      	LL - Clayton Lucas Mendes Lima
*	         
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01 pg    29/09/2017  Início do desenvolvimento
*       0.02 pg/SaintL/LL  30/09/2017 Merge dos três integrantes
*       
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "criterio_aprovacao.h"
/***** Protótipos das funções encapuladas no módulo *****/
/*
*				A Completar
*
*****  Código das funções exportadas pelo módulo  *****/
/***************************************************************************
*
*  Inicio Função: Verifica_Criterio01
*		Deverá receber as notas G1, G2 do aluno, a média para a aprovação (sem prova final),
*		um ponteiro para gurdar a média final do aluno e outro para guardar se foi aprovado ou não.
*
*  ****/
CRI_tpCondRet CRI_Verifica_Criterio01(float G1, float G2, float *media_aluno, float media_aprovado, int *resultado ){
	if(G2<3){
		*media_aluno= (G1+(G2*3))/4;
	}
	else{  
		*media_aluno= ((G1*2)+(G2*3))/5;
	}
	if((*media_aluno)>=media_aprovado){
		*resultado=1;
		return CRI_CondRetOK;
	}
	else {
		*resultado=0;
		return CRI_CondRetOK;
	}
} /* Fim função: Verifica_Criterio01 
*
*		Retorna se o aluno foi aprovado ou não, e
*		qual foi a média final dele para o critério 1.
*/
/***************************************************************************
*
*  Inicio Função: Aplica Critério
*		Deverá receber o número do criterio a ser aplicado, os graus, a media para aprovação,
*	 e depois ponteiros, um para guardar sua média final e outro para guardar se foi aprovado ou não.
*
*  ****/
CRI_tpCondRet CRI_Aplica_Criterio(float G1, float G2, float G3, float *media_aluno, float media_aprovado, int *resultado, int num_criterio){
	switch(num_criterio){
		case 1:
			CRI_Verifica_Criterio01(G1,G2,media_aluno,media_aprovado,resultado);
			break;
	}
	return CRI_CondRetOK;
}
/* Fim função: Aplica Critério
*
*		Retorna se o aluno foi aprovado ou não, e
*		qual foi a média final dele para o critério inserido.
*/
/***************************************************************************
*
*  Função: CRI criterio 1
*  ****/
CRI_tpCondRet CRI_criterio1(float G1, float G2, float G3, float* media, int* situacao)
{
	float NF;

	NF = (G1 + G2)/2;
	*media = NF;

	if (G1 >= 3.0 && G2 >= 3.0 && NF >= 6.0)
	{
		*situacao = 1; /* Aprovado */
		return CRI_CondRetOK;
	}
	else
	{
		NF = (G1 + G2 + (G3*2))/4;
		*media = NF;

		if (NF >= 5.0)
		{
			*situacao = 1; /* Aprovado */
			return CRI_CondRetOK;
		}
		else
		{
			*situacao = 0; /* Reprovado */
			return CRI_CondRetOK;
		}
	}

	return CRI_CondRetErroEstrutura;
}
/* Fim função: CRI criterio 1 */
/***************************************************************************
*
*  Função: CRI criterio 2
*  ****/
CRI_tpCondRet CRI_criterio2(float G1, float G2, float G3, float G4, float* media, int* situacao)
{
	float NF, Gm, Gn, temp;

	NF = (G1 + G2 + G3)/3;

	if (( G1 >= 5.0 && G2 >= 5.0 && G3 >=5.0 ) || NF >= 6.0)
	{
		*media = NF;
		*situacao = 1; /* Aprovado */
		return CRI_CondRetOK;
	}
	else
	{
		if (G4 < 3.0)
		{
			NF = (G1 + G2 + G3 + (G4 * 3))/6;
			*media = NF;

			if (NF >= 5.0)
			{
				*situacao = 1; /* Aprovado */
				return CRI_CondRetOK;
			}
			else
			{
				*situacao = 0; /* Reprovado */
				return CRI_CondRetOK;
			}
		}
		else
		{
			if (G2 > G1)        /* Essa sequência de if ordena as notas de forma decrescente */
			{					/* Para o calculo da média */
				temp = G2;		/* Que utiliza as duas maiores notas e a G4 */
				G2 = G1;
				G1 = temp;
			}
				if (G3 > G2)
			{
				temp = G3;
				G3 = G2;
				G2 = temp;
			}	
			if (G2 > G1)
			{
				temp = G2;
				G2 = G1;
				G1 = temp;
			}

			Gm = G1; /* Gm = Maior nota */
			Gn = G2; /* Gn = Segunda maior nota */

			NF = (Gm + Gn + G4)/3;
			*media = NF;

			if (NF >= 5.0)
			{
				*situacao = 1; /* Aprovado */
				return CRI_CondRetOK;
			}
			else
			{
				*situacao = 0; /* Reprovado */
				return CRI_CondRetOK;
			}
		}
	}

	return CRI_CondRetErroEstrutura;

}
/* Fim função: CRI criterio 2 */
/***************************************************************************
*
*  Função: CRI criterio 3
*  ****/
CRI_tpCondRet Criterio_3 (float G1, float G2, float G3, float G4, float *media,int *situacao){
	 *media =(G1 + G2 + G3)/3;
	float maior1 = G1, maior2 = G2;

		if(maior1 < maior2 ){                             //Essa parte calcula os dois maiores valores entre G1 e G3
		maior1 = G2;
		maior2 = G1;
		}
	    if(maior2 < G3){
			maior2 = G3;
		}
		if(maior1 < G3){
			maior2 = maior1;
			maior1 = G3;
		}                                              //Essa parte calcula e retorna a media final do aluno
	if (G1 >= 3.0 && G2 >= 3.0 && G3 >= 3.0 && *media >= 5.0){
		*situacao = 1;
		return CRI_condRetOk;
	}
	else  if( G4 >= 3.0){

		*media = (maior1 + maior2 + G4)/3;
            
		

	}else if(G4 < 3.0){}
        *media = ((G1 + G2 + G3 + (G4 *3)))/6;
        
}
        if(*media >=5){
        *situacao = 1;
        return  CRI_condRetOk;
        }
        else{
            *situacao = 0;
        return CRI_condRetOk;
        }
        
        return CRI_CondRetErroEstrutura;
}/* Fim função: CRI criterio 3 */
/***************************************************************************
*
*  Função: CRI criterio 4
*  ****/
CRI_tpCondRet Criterio_4(float G1, float G2, float G3, float *media, int *situacao){
	 *media = (G1 + G2)/2;
	float maior1 = G1, maior2 = G2;

	    if(maior1 < maior2 ){                             //Essa parte calcula os dois maiores valores entre G1 e G3
		maior1 = G2;
		maior2 = G1;
		}
		if(maior2 < G3){
			maior2 = G3;			
		}
	    if(maior1 < G3){
			maior2 = maior1;
			maior1 = G3;			
		}
        
	 

	if(G1 >= 3.0 && G2 >= 3.0 && *media >=5.0) {                            //Essa parte calcula a media e indica a situaçao do aluno
		*situaçao = 1;
		return CRI_condRetOk;
	}
			else if(G1 >= 3.0 && G2>= 3.0 || ((G1 < 3.0 || G2 < 3.0) && G3 >=3.0)){

				*media = (maior1 + maior2)/2;

	}else

    if(G1 < 3.0 || G2 < 3.0 && G3 < 3.0)
	*media = (G1 + G2 + (G3*2))/4;

	
	if(*media >=5){
        *situacao = 1;
        return CRI_condRetOk;
        }
        else{
            *situacao = 0;
        return CRI_condRetOk;
        }
        
        return CRI_CondRetErroEstrutura;
		
}/* Fim função: CRI criterio 4 */