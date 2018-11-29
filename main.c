# include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <ctype.h>
#define casaBranca 176
#define casaPreta 178
#define TAM 8

int pBranco = 12, pPreto = 12;

typedef struct historico {
    int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    char nome1[20];
} Historico;

Historico hist[5];
int histIndex = 0;


//Função que cria o tabuleiro recebendo como parametro a matriz através de ponteiros
void criarTabuleiro(int *pointerTabuleiro){
    int i, j;

    for(i=0; i<TAM; i++){
//      Desenha o tabuleiro com os respectivo desenhos
        for(j=0; j<TAM; j++){
            if(i==0 || i==2){
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=66;
            } else {
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            }
        } else if(i==1){
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            } else {
            *(pointerTabuleiro + j + i*TAM)=66;
            }
        } else if(i==3){
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            } else {
            *(pointerTabuleiro + j + i*TAM)=casaBranca;
            }
        } else if(i==4){
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=casaBranca;
            } else {
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            }
        } else if(i==5 || i==7){
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            } else {
            *(pointerTabuleiro + j + i*TAM)=80;
            }
        } else {
            if(j%2==0){
            *(pointerTabuleiro + j + i*TAM)=80;
            } else {
            *(pointerTabuleiro + j + i*TAM)=casaPreta;
            }
    }
        }
    }
     printf("\n\n");
}
// aki imprimi o tabuleiro, recebendo a matriz alterada, nomes e quantidade de peças
void imprimirTabuleiro(int *pointerTabuleiro){
int t,y;

system("cls");
printf("\n\t\t ************* JOGO DA DAMA *************\n\n");
printf("\t\t\t   0  1  2  3  4  5  6  7");
  for(t=0; t<TAM; t++){
      printf("\n\t\t\t%d ",t);
      for(y=0; y<TAM; y++){
        if(*(pointerTabuleiro + y + t*TAM)=='B'||*(pointerTabuleiro + y + t*TAM)=='P'){
            printf(" %c ",*(pointerTabuleiro + y + t*TAM));
        }else{
        printf("%c%c%c",*(pointerTabuleiro + y + t*TAM),*(pointerTabuleiro + y + t*TAM),*(pointerTabuleiro + y + t*TAM));
        }
      }
  }

}

void inicial(){
    printf("\n\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________                    ____________________\n");
    printf("\t__________________     BEM - VINDO    ____________________\n");
    printf("\t__________________         AO         ____________________\n");
    printf("\t__________________   JOGO  DE  DAMA   ____________________\n");
    printf("\t__________________                    ____________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n");
}

void sair(){

    int s;
    printf("Realmente deseja sair? \n");
    printf("1 - Sim\n2 - Não ");
    printf("\nAlternativa desejada: ");
    scanf("%d",&s);
    if(s==1){
        system("pause");
    }else{
    system("cls");
    menu();
    }
}
//função que armazena os nomes dos jogadores e aki cria e imprime o tabuleiro
void jogar(){
    char player1[100],player2[100];
    int tabuleiro[TAM][TAM];
    system("cls");
    fflush(stdin);
    printf("Player 1\n");
    printf("Digite seu nome: ");
    gets(player1);
    printf("Player 2\n");
    printf("Digite seu nome: ");
    gets(player2);
    char *nome1 = player1;
    char *nome2 = player2;
    int jogada=0;
    int cont=0;
    criarTabuleiro(tabuleiro);

    while(pPreto > 0 && pBranco > 0){
    imprimirTabuleiro(tabuleiro);
    contarPecas(tabuleiro, nome1, nome2);
        if(jogada%2==0){
        coordenadas(tabuleiro, 1,nome1,nome2);
        system("pause");
      } else {
        coordenadas(tabuleiro, 2,nome1,nome2);
        system("pause");
      }

    if(pBranco ==2 && pPreto==2){
     if(cont==3){
      imprimirTabuleiro(tabuleiro);
      contarPecas(tabuleiro, nome1, nome2);
    printf("\n\n DEU EMPATE !!!!\n\n");
    system("pause");
    menu();
     }
     cont++;
    }
    jogada++;

    system("cls");
    }

    if(pBranco>pPreto){
      imprimirTabuleiro(tabuleiro);
      contarPecas(tabuleiro, nome1, nome2);
    printf("\n\n %s é o vencedor\n\n",player1);
    system("pause");
    system("cls");
    menu();
    }else{
    imprimirTabuleiro(tabuleiro);
      contarPecas(tabuleiro, nome1, nome2);
    printf("\n\n %s é o vencedor\n\n",player2);
    system("pause");
    system("cls");
    menu();
    }

}

void sobre(){

    int s;
    system("cls");

char p[2500];

FILE *pfile;
pfile = fopen("sobre.dama","r");
if(pfile == NULL){
    printf("Houve um erro ao abrir o arquivo!");
}else{
    fscanf(pfile, "%s", &p);
    printf("\n");
    printf("%s", *pfile);
    fflush(stderr);
}
fclose(pfile);



    printf("\n\n1 - Voltar ao menu");
    printf("\nAlternativa desejada: ");
    scanf("%d",&s);
    if(s==1){
        system("cls");
        menu();
    }
    }

void regras(){

system("cls");
int s; char p[2500];

FILE *pfile;
pfile = fopen("regras.dama","r");
if(pfile == NULL){
    printf("Houve um erro ao abrir o arquivo!");
}else{
    fscanf(pfile, "%s", &p);
    printf("\n");
    printf("%s", *pfile);
    fflush(stderr);
}
fclose(pfile);

printf("\n\n1 - Voltar ao menu");
printf("\nAlternativa desejada: ");
    scanf("%d",&s);
    if(s==1){
        system("cls");
        menu();
    }
}
//só chama as funções do menu
void menu(){

fflush(stdin);
int i=0;
printf("\n");
printf("\nEscolha alternativa desejada: \n\n");
printf("1 - JOGAR\n");
printf("2 - SOBRE\n");
printf("3 - REGRAS\n");
printf("4 - SAIR\n");
printf("Sua escolha: ");
scanf("%d",&i);

if(isalpha(i)){
    printf("Opção inválida\n");
    system("pause");
    fflush(stdin);
    system("cls");
    i=0;
    menu();

} else {
switch(i){
 case 1:
    jogar();
    i=0;
    break;
 case 2:
    sobre();
    i=0;
    break;
 case 3:
    regras();
    i=0;
    break;
 case 4:
    sair();
    i=0;
    break;

    default:
    printf("Opção inválida\n");
    system("pause");
    fflush(stdin);
    system("cls");
    i=0;
    menu();
}
}
}


void contarPecas(int *pointerTabuleiro, char *nome1, char *nome2){
    int contPecasB=0, contPecasP=0, i, j, damaBranca=0,damaPreta=0;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(*(pointerTabuleiro + j + i*TAM)=='B'){
                contPecasB++;
            }
            else if(*(pointerTabuleiro + j + i*TAM)=='P'){
                contPecasP++;
            }else if(*(pointerTabuleiro + j + i*TAM)=='*'){
                damaBranca++;
            }else if(*(pointerTabuleiro + j + i*TAM)=='#'){
                damaPreta++;
            }
        }
    }
    printf("\n\nBranco - %s - Total de pecas = %d - Damas: %d\n",nome1,contPecasB+damaBranca, damaBranca);
    printf("Preto - %s - Total de pecas = %d - Damas: %d\n\n",nome2,contPecasP+damaPreta, damaPreta);

    if(histIndex>0){
    printf("############### \tHISTÓRICO\t###################\n\n");

    for(int x=0; x<histIndex; x++){
        printf("\t   %s, moveu de [%d,%d] para [%d,%d]\n",hist[x].nome1, hist[x].linhaOrigem, hist[x].colunaOrigem, hist[x].linhaDestino, hist[x].colunaDestino);
    }
    printf("\n###########################################################\n\n\n");
    }
}

void coordenadas(int *pointerTabuleiro, int jogador,char *nome1,char *nome2){
  int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
   char nome[100];
    if(jogador==1){
     strcpy(nome,nome1);
    }else{
    strcpy(nome,nome2);
    }


    // Pede a coordenada de origem
    printf("Vez de %s\n", nome);
    printf("DIGITE  A POSIÇÃO ATUAL DA PEÇA\n");
    printf("Linha: "); scanf("%d", &linhaOrigem);
    printf("Coluna: "); scanf("%d", &colunaOrigem);

    // Pede a coordenada de destino
    printf("\nDIGITE O DESTINO DA PEÇA\n");
    printf("Linha: "); scanf("%d", &linhaDestino);
    printf("Coluna: "); scanf("%d", &colunaDestino);

    verificarJogada(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogador, pointerTabuleiro,nome1,nome2);
}


void historico(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, char *nome){

    int index, j;
    Historico aux;
    Historico h;
    strcpy(h.nome1, nome);
    h.colunaDestino = colunaDestino;
    h.colunaOrigem = colunaOrigem;
    h.linhaDestino = linhaDestino;
    h.linhaOrigem = linhaOrigem;

     if(histIndex<5){
    hist[histIndex] = h;
    histIndex++;
    }else{

        for(int i=0;i<5;i++){
            if(i<4){
                hist[i]=hist[i+1];
            }else{
                hist[i]=h;
            }
        }
    }

}

void dama(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador, int *pointerTabuleiro, char *nome1,char *nome2){
char carac, adversario, damaAdversaio;

if(jogador==1){
    carac = '*';
    adversario= 'P';
    damaAdversaio = '#';
} else {
carac = '#';
adversario = 'B';
damaAdversaio = '*';
}

int valido = 1;

if((linhaOrigem + 1 == linhaDestino && (colunaOrigem - 1 == colunaDestino || colunaOrigem + 1 == colunaDestino))||(linhaOrigem - 1 == linhaDestino && (colunaOrigem - 1 == colunaDestino || colunaOrigem + 1 == colunaDestino))){
                   *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                   *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;

       }else if(((linhaOrigem + 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino-1)*TAM)) == adversario)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       }else if (((linhaOrigem - 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino+1)*TAM)) == adversario)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       }else if((linhaOrigem + 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino-1)*TAM)) == adversario)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;

        } else if((linhaOrigem - 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino+1)*TAM)) == adversario)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
            }else if(((linhaOrigem + 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino-1)*TAM)) == damaAdversaio)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       }else if (((linhaOrigem - 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino+1)*TAM)) == damaAdversaio)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       }else if((linhaOrigem + 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino-1)*TAM)) == damaAdversaio)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;

        } else if((linhaOrigem - 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino+1)*TAM)) == damaAdversaio)){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = carac;
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
            } else {
            printf("Jogada inválida... Jogue novamente\n");
      system("pause");
      system("cls");
      imprimirTabuleiro(pointerTabuleiro);
      contarPecas(pointerTabuleiro,nome1,nome2);
      coordenadas(pointerTabuleiro, jogador,nome1,nome2);
            valido = 0;
            }


}

void verificarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int jogador, int *pointerTabuleiro,char *nome1,char *nome2){
int peca=0, i;
int movimentoValido = 1;


if((linhaDestino+colunaDestino)%2==0){
    if(jogador==1 && *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == '*'){
    if(*(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == '*' && *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) == casaBranca){
            dama(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogador, pointerTabuleiro, nome1, nome2);

        } else {
            movimentoValido=0;
        }

        if(movimentoValido){
            historico(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, nome1);
        }

    } else if(jogador==1&&linhaOrigem<linhaDestino){
        if(*(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == 'B' && *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) == casaBranca){
       if(linhaOrigem + 1 == linhaDestino && (colunaOrigem - 1 == colunaDestino || colunaOrigem + 1 == colunaDestino)){
                   *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'B';
                   *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;

       }else if((linhaOrigem + 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino-1)*TAM)) == 'P'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'B';
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       } else if(linhaOrigem + 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino-1)*TAM)) == 'P'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'B';
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;

      }else if((linhaOrigem + 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino-1)*TAM)) == '#'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'B';
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;
       } else if(linhaOrigem + 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino-1)*TAM)) == '#'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'B';
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem+1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pPreto--;

      } else{
      movimentoValido = 0;
      }
      } else {
      movimentoValido = 0;
      }

        for(i=0;i<8;i++){
            if(*(pointerTabuleiro + i + 7*TAM) == 'B'){
                *(pointerTabuleiro + i + 7*TAM)='*';
                }
            }

        if(movimentoValido){
            historico(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, nome1);
        }

    } else if(jogador==2 && *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == '#'){
        if(*(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == '#' && *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) == casaBranca){
                dama(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, jogador, pointerTabuleiro, nome1, nome2);
        } else {
        movimentoValido=0;
        }

        if(movimentoValido){
            historico(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, nome2);
        }

    }else if(jogador==2&&linhaOrigem>linhaDestino){
        if(*(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) == 'P' && *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) == casaBranca){
       if(linhaOrigem - 1 == linhaDestino && (colunaOrigem - 1 == colunaDestino || colunaOrigem + 1 == colunaDestino)){
                   *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'P';
                   *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;

       }else if((linhaOrigem - 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino+1)*TAM)) == 'B'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'P';
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pBranco--;
       } else if(linhaOrigem - 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino+1)*TAM)) == 'B'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'P';
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pBranco--;

      }else if((linhaOrigem - 2 == linhaDestino) && (colunaOrigem - 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino+1) + (linhaDestino+1)*TAM)) == '*'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'P';
                *(pointerTabuleiro + (colunaOrigem-1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pBranco--;
       } else if(linhaOrigem - 2 == linhaDestino && (colunaOrigem + 2 == colunaDestino) && (*(pointerTabuleiro + (colunaDestino-1) + (linhaDestino+1)*TAM)) == '*'){
                *(pointerTabuleiro + colunaDestino + linhaDestino*TAM) = 'P';
                *(pointerTabuleiro + (colunaOrigem+1) + (linhaOrigem-1)*TAM) = casaBranca;
                *(pointerTabuleiro + colunaOrigem + linhaOrigem*TAM) = casaBranca;
                pBranco--;

      }
       else{
      movimentoValido = 0;
      }
      } else {
      movimentoValido = 0;
      }
             for(i=0;i<8;i++){
            if(*(pointerTabuleiro + i + 0*TAM) == 'P'){
                *(pointerTabuleiro + i + 0*TAM)='#';
                }
            }

        if(movimentoValido){
            historico(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, nome2);
        }

    } else {
        movimentoValido=0;
    }

    if(!movimentoValido){
      printf("Jogada inválida... Jogue novamente\n");
      system("pause");
      system("cls");
      imprimirTabuleiro(pointerTabuleiro);
      contarPecas(pointerTabuleiro,nome1,nome2);
      coordenadas(pointerTabuleiro, jogador,nome1,nome2);
    }

    } else {
        printf("Jogada inválida... Jogue novamente\n");
      system("pause");
      system("cls");
      imprimirTabuleiro(pointerTabuleiro);
      contarPecas(pointerTabuleiro,nome1,nome2);
      coordenadas(pointerTabuleiro, jogador,nome1,nome2);
    }
}

int main(){
system("mode con:cols=75");
inicial();
menu();

return 0;
}
