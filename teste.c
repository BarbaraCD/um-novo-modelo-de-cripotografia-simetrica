/****************************************************************************
* Instituto Federal Goiano - Campus Rio Verde                               *
* Autores: Ana Kelly, Barbara Diniz, Manoel Victor e Raquel Veloso;         *
* 06/06/2017                                                                *
*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 10000

char* bin_rest(int , char *);
char* bin_quo(int , char *);
int num_novo(int , int );
char* vetor_tres (char *, char *);
char* vetor_cinco (char * , char *);
char* converte_bin_novo (int , char *);
int multiplica (int , int );
char* bin_novo(char [], char [], char *);
int quociente (int , int );
int resto (int , int );
int trans_dec(char *);
char* bin_char(int , char *);
int binary_conversion(int );

int main() {

    int aux = 0, aux2 = 0;
    int chave = 8, x;
    char numero[TAM], novo[TAM];
    char bin_string[9], str_quo[5], str_rest[3];

    printf("Digite o numero que deseja inverter:");
    scanf("%[^\n]", numero);

/****************************** CIFRAGEM ******************************/
    for (x = 0; numero[x] != '\0'; x++){

        //Converte o número pra binario;
        binary_conversion(numero[x]);

        //Armazena em um vetor char e inverte o binário;
        bin_char(numero[x],bin_string);

        //Transforma o binario invertido em um inteiro;
        trans_dec(bin_char(numero[x], bin_string));

        //Faz a operação de resto com a chave;
        aux2 = resto(chave, trans_dec(bin_char(numero[x], bin_string)));

        //Divide o numero pela chave;
        aux = quociente(chave, trans_dec(bin_char(numero[x], bin_string)));

        //Converte o resto para binário;
        binary_conversion(aux2);
        binary_conversion(aux);

        //Armazena o resto e o quociente em um binario;
        bin_quo(aux, str_quo);
        bin_rest(aux2, str_rest);

        //gera novo caracter;
        bin_novo(str_rest, str_quo, bin_string);

        trans_dec(bin_string);


        novo[x] = trans_dec(bin_string);

    }

    novo[x] = '\0';

/************************* FIM DA CIFRAGEM ***********************/

    printf("Mensagem original: %s\n", numero);
    printf("Mensagem cifrada: %s\n", novo);


/************************** DECIFRAGEM **************************/
    char novo_bin_string[9], mens_original[TAM];
    char tres[9], cinco[9];
    int trans_deci, multi, novo_tres, original;

    for (x = 0; novo[x] != '\0'; x++){

        binary_conversion(novo[x]);

        converte_bin_novo(novo[x], novo_bin_string);

        vetor_cinco(novo_bin_string, cinco);

        vetor_tres(novo_bin_string, tres);

        trans_dec(cinco);
        trans_deci = trans_dec(cinco);

        multiplica(chave, trans_deci);
        multi = multiplica(chave, trans_deci);

        trans_dec(tres);
        novo_tres = trans_dec(tres);

        original = num_novo(novo_tres, multi);

        bin_char(original, novo_bin_string);

        mens_original[x] = trans_dec(novo_bin_string);
    }

    mens_original[x] = '\0';

/************************* FIM DA DECIFRAGEM ***********************/

    printf("Decifragem: %s \n", mens_original);

return 0;
}


/********** CONVERSÃO PARA BINÁRIO **********/
int binary_conversion(int num){
    if (num == 0){
        return 0;
    }
    else{
        return (num % 2) + (10 * binary_conversion(num/2));
    }
}
/********** FIM DA FUNÇÃO **********/

/********** ARMAZENA O BINÁRIO EM UM VETO E INVERTE AS POSIÇÕES **********/
char* bin_char(int num, char *p){
int c,k,i=0;

/***** Armazena o binário em um vetor char; *****/
  for (c = 7; c >= 0; c--){
    k = num >> c;

    if (k & 1){
      p[i]='1';
      i++;
    } else{
      p[i]='0';
      i++;
    }
  }
  p[8]='\0';

/***** Troca as posições do vetor, invertendo o binário; *****/
char aux;
  k=7;
  for(c=0;c<4;c++){
      aux=p[c];
      p[c]=p[k];
      p[k]=aux;
      k--;
  }
    return p;
}
/********** FIM DA FUNÇÃO **********/

/********** PASSA O VETOR CHAR PARA UM INTEIRO **********/
int trans_dec(char *bin){
    int num = 0;
    int i;
    int t = strlen(bin) - 1;
    for (i = 0; bin[i] != '\0'; i++){
        if(bin[i] == '1'){
            num = num + (pow(2, t-i));
        } else if ( bin[i] == '0'){
            num = num + 0;
        }
    }
    return num;

}
/********** FIM DA FUNÇÃO **********/

/********** FAZ A OPERAÇÃO DO RESTO DA DIVISÃO PELA CHAVE **********/
int resto (int c, int n){
    int modulo;
    modulo = (n%c);

    return modulo;
}
/********** FIM DA FUNÇÃO **********/

/********** FAZ A DIVISÃO DO CARACTER PELA CHAVE **********/
int quociente (int c, int n){
    int div;
    div = (n/c);

    return div;
}
/********** FIM DA FUNÇÃO **********/

/********** Armazena o resto em um vetor de binário **********/
char* bin_rest(int num, char *p){
int c,k,i=0;

  for (c = 2; c >= 0; c--){
    k = num >> c;

    if (k & 1){
      p[i]='1';
      i++;
    } else{
      p[i]='0';
      i++;
    }
  }
  p[3]='\0';

  return p;
  }
/********** FIM DA FUNÇÃO **********/

/********** Armazena o quociente em um vetor de binário **********/
char* bin_quo(int num, char *p){
int c,k,i=0;

  for (c = 4; c >= 0; c--){
    k = num >> c;

    if (k & 1){
      p[i]='1';
      i++;
    } else{
      p[i]='0';
      i++;
    }
  }
  p[5]='\0';

  return p;
  }
/********** FIM DA FUNÇÃO **********/

/********** FUNÇÃO PARA GERAR NOVO CARACTER **********/
char* bin_novo(char n1[3], char n2[5], char *p){
    strcpy(p, n1);
    strcat(p, n2);
    //p[8] = '\0';

return p;
}

/********** FIM DA FUNÇÃO **********/

/********** FUNÇÃO PARA ARMAZENAR UM BINARIO EM UM VETOR **********/
char* converte_bin_novo (int num, char *p){
int c,k,i=0;

  for (c = 7; c >= 0; c--){
    k = num >> c;

    if (k & 1){
      p[i]='1';
      i++;
    } else{
      p[i]='0';
      i++;
    }
  }
  p[8]='\0';

return p;

  }
/********** FIM DA FUNÇÃO **********/

/***** ARMAZENA AS CINCO ULTIMAS POSIÇÕES DO VETOR EM UM OUTRO VETOR *****/
char* vetor_cinco (char *p, char *novo){
    int i, j = 0;
    for(i = 3; i <= 7; i++){
        novo[j] = p[i];
        j++;
    }
    novo[j] = '\0';
    return novo;
}
/********** FIM DA FUNÇÃO **********/

/*********** ARMAZENA AS TRES PRIMEIRAS POSIÇÕES DO VETOR EM UM OUTRO VETOR **********/
char* vetor_tres (char *p, char *novo){
    int i, j = 0;
    for(i = 0; i <= 2; i++){
        novo[j] = p[i];
        j++;
    }
    novo[j] = '\0';
    return novo;
}
/********** FIM DA FUNÇÃO **********/

/************ FUNÇÃO PARA MULTIPLICAÇÃO ************/
int multiplica (int c, int n){
    int mult, result;
    mult = (n * c) % 256;
    return mult;
}
/********** FIM DA FUNÇÃO **********/

/*********** FUNÇÃO DE SOMA **********/
int num_novo(int x, int y){
    return (x + y) % 256;
}
/********** FIM DA FUNÇÃO **********/

