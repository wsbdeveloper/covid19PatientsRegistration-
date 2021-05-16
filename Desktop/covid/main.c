#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

// Assinaturas das fun��es;
void Menu();
void cadastro_pacientes();
void cadastro_dados_paciente();
void adicionando_pacientes();
void cadastro_grupo_risco();
int validando_data();
validando_data_covid();

int main(){
    int opcao_menu;


    do{
        Menu();
        scanf("%d", &opcao_menu);

        switch(opcao_menu){
            case 1:
                cadastro_dados_paciente();
                break;
            case 2:
                return -1;
        }

    }while(opcao_menu != 1 && opcao_menu != 2 );

    return 0;
}

// Menu
void Menu(){
    printf("===========================================================\n");
    printf("================ CADASTRO DE PACIENTES ====================\n");
    printf("* Importante, nao utilize caracteres especiais para o cadastro. *\n");

    printf("\n\n");

    printf("   1.    - Digite 1 para cadastro de paciente   \n");
    printf("   2.    - Sair   \n");

}

// Validando casos no territorio brasileiro a partir do dia 25/02/2020
int validando_data_covid(int dia,int mes,int ano){
    if(ano < 2020 || ano <=0 ){
        return -1;
    }

    if(mes < 2 && ano == 2020 && dia < 25){
        return -1;
    }

    return 1;
}

int validando_data(int dia,int mes,int ano){
   if (mes <= 0 && mes > 12 ){
     printf("\n  Erro: Mes nao pode ser invalido, por favor digite corretamente!");

     return -1;
   }

   if(ano < 1910 && ano > 2020){
     printf("\n  Erro: Ano nao pode ser invalido, por favor digite corretamente!");

     return -1;
   }

   if(mes == 1 || mes == 3|| mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
      if(dia <= 0 && dia > 31){
         printf("\n  Erro: Dia nao pode ser invalido, por favor digite corretamente!");

         return -1;
       }
   }

   if(mes == 4 || mes == 6|| mes == 9 || mes == 11){
      if(dia <= 0 && dia > 30){
         printf("\n  Erro: Dia nao pode ser invalido, por favor digite corretamente!");

         return -1;
       }
   }

   // calculo de ano bissexto

    if(ano % 4 == 0){
        if(ano % 100 != 0 || ano % 400 == 0){
            if(dia <= 0 && dia > 29){
                return -1;
            }
        }
    }else {
        if(dia <= 0 && dia > 28){
            return -1;
        }
    }

    return 1;
}

// Cadastro de pacientes
void adicionando_pacientes(char *str, char *data_paciente){
    FILE *arquivo;
    char paciente[254];

    arquivo = fopen("C:\\pacientes.txt","a+");

    if(arquivo == NULL){
        printf("Erro ao ler o arquivo especificado");
    }

    fprintf(arquivo,"%s %s\n", str , data_paciente);

    fclose(arquivo);
}

void cadastro_grupo_risco(char *cep, int idade){
    FILE *arquivo;

    arquivo = fopen("c:\\grupo_risco.txt","a+");

    if(arquivo == NULL){
        printf("Erro ao ler o arquivo especificado, grupo de risco");
    }
    fprintf(arquivo, "\n=================================================================\n");
    fprintf(arquivo,"CEP : %s - IDADE: %d\n", cep , idade);
    fprintf(arquivo, "\n=================================================================\n");
    fclose(arquivo);
}

void cadastro_dados_paciente(){
    char *paciente;

    char nome[100];
    char cpf[20];

    char telefone[30];
    char rua[40];
    char bairro[40];
    char cidade[40];
    char estado[40];
    char cep[12];
    char email[40];
    char comorbidade[100];

    char data_diagnostico[12];

    int dia_diagnostico;
    int mes_diagnostico;
    int ano_diagnostico;

    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento;
    int idade;

    printf("\n\n========== VAMOS INICAR O CADASTRO DO PACIENTE ==========");
    printf("\n\n");

    do{
        printf("Digite o Nome: ");
        fflush(stdin);
        fgets(nome, 100, stdin);

        if(strlen(nome) >= 101){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(nome) >= 101);

    do{
        printf("Digite o CPF: ");
        fflush (stdin);
        fgets(cpf, 20,stdin);
        if(strlen(cpf) >= 21){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(cpf) >= 21);

    do{
        printf("Digite o Telefone: ");
        fflush (stdin);
        fgets(telefone, 30, stdin);
        if(strlen(telefone) >= 31){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(telefone) >= 31);

    do{
        printf("Digite nome da rua: ");
        fflush (stdin);
        fgets(rua, 40, stdin);
        if(strlen(bairro) >= 41){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(bairro) >= 41);

    do{
        printf("Digite o Bairro: ");
        fflush (stdin);
        fgets(bairro, 40, stdin);

        if(strlen(bairro) >= 41){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(bairro) >= 41);

    do{
        printf("Digite a Cidade: ");
        fflush (stdin);
        fgets(cidade, 40, stdin);

        if(strlen(cidade) >= 41){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(cidade) >= 41);

    do{
        printf("Digite o Estado: ");
        fflush (stdin);
        fgets(estado, 40, stdin);

        if(strlen(estado) >= 41){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(estado) >= 41);

    do{
        printf("Digite o CEP:  ");
        fflush (stdin);
        fgets(cep, 12, stdin);

        if(strlen(cep) >= 13){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(cep) >= 13);

    do{
        printf("Digite o E-mail:  ");
        fflush (stdin);
        fgets(email, 40, stdin);

        if(strlen(email) >= 41){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(email) >= 41);

    do{
        printf("Descreva a comorbidade: ");
        printf("Caso nao tenha digite (N)\n");
        fflush (stdin);
        fgets(comorbidade, 100, stdin);


        if(strlen(comorbidade) >= 101){
            printf("\n === Erro tamanho muito grande ==== \n\n");
        }
    }while(strlen(comorbidade) >= 101);

    // Variavel de controle de valida��o.
    int valida_diag = 0;

    do{
        printf("\n == Preencha a data de diagnostico == \n\n");
        printf("Informe o dia do diagnostico : ");
        fflush (stdin);
        scanf("%d", &dia_diagnostico);

        printf("Informe o mes do diagnostico : ");
        fflush (stdin);
        scanf("%d", &dia_diagnostico);

        printf("Informe o ano do diagnostico : ");
        fflush (stdin);
        scanf("%d", &dia_diagnostico);

        valida_diag = validando_data(dia_diagnostico,mes_diagnostico,ano_diagnostico);

        if(valida_diag == -1){
            printf("\n\n === ATENCAO === \n\n");

            printf("Dado fornecido esta invalido");

            printf("\n");
        }
    }while(valida_diag == -1);

    // Variavel de controle de valida��o.
    int valida_nasci = 0;

    do{
        printf("\n == Preencha a data de nascimento do paciente == \n\n");
        printf("Digite o dia do nascimento: ");
        fflush (stdin);
        scanf("%d", &dia_nascimento);

        printf("Digite o mes do nascimento: ");
        fflush (stdin);
        scanf("%d", &mes_nascimento);

        printf("Digite o ano do nascimento: ");
        fflush (stdin);
        scanf("%d", &ano_nascimento);

        valida_nasci = validando_data(dia_diagnostico,mes_diagnostico,ano_diagnostico);

        if(valida_nasci == -1){
            printf("\n\n === ATENCAO === \n\n");

            printf("Dado fornecido esta invalido");

            printf("\n");
        }
    }while(valida_nasci == -1);
    // C�lculo de idade
    idade = (ano_nascimento - 2020) * -1;

    printf("Nome        : %s", nome);
    printf("CPF         : %s", cpf);
    printf("Telefone    : %s", telefone);
    printf("Rua         : %s", rua);
    printf("Bairro      : %s", bairro);
    printf("Cidade      : %s", cidade);
    printf("Estado      : %s", estado);
    printf("CEP         : %s", cep);
    printf("E-mail      : %s", email);
    printf("Comorbidade : %s", comorbidade);
    printf("Dia Nasc.   : %d \n", dia_nascimento);
    printf("Mes Nasc.   : %d \n", mes_nascimento);
    printf("Ano Nasc.   : %d \n", ano_nascimento);
    printf("Idade       : %d \n", idade);

    if(idade >= 65 || comorbidade != "N" || comorbidade != "n"){
        printf("\n\n ++++++++ Paciente esta dentro do grupo de risco. +++++++++++");

        cadastro_grupo_risco(cep,idade);
    }

    // Verifica��es de strings vazias.
    if(strlen(nome) == 1 || strlen(cpf) == 1 || strlen(telefone) == 1 ||
       strlen(rua) == 1 || strlen(bairro) == 1 || strlen(cidade) == 1 ||
       strlen(estado) == 1 || strlen(cep) == 1 || strlen(email) == 1 ||
       strlen(data_diagnostico) == 1 || strlen(comorbidade) == 1){
        printf("\n==================================================\n");
        printf("\nOs campos devem ser preenchido corretamente!!\n\n");
        printf("\n==================================================\n");
        cadastro_dados_paciente();
    }

    // Valida��o de ano de nascimento.
    if(ano_nascimento <= 1900 && ano_nascimento <= 2020){
        printf("\n==================================================\n");
        printf("\n Ano cadastrado invalido");
        printf("\n==================================================\n");
        cadastro_dados_paciente();
    }

    // Valida��o de dias do m�s.
    if(dia_nascimento <= 0 && dia_nascimento > 31){
        printf("\n==================================================\n");
        printf("\n Dia cadastrado invalido");
        printf("\n==================================================\n");
        cadastro_dados_paciente();
    }

    // Valida��o do range de m�s validos.
    if(mes_nascimento <= 0 && dia_nascimento <= 12){
        printf("\n==================================================\n");
        printf("\n M�s cadastrado invalido");
        printf("\n==================================================\n");
        cadastro_dados_paciente();
    }

    printf("\n\n");

    printf("\n\n ==================================================================== \n");
    printf("    1. Deseja salvar as informacoes           ");
    printf("    2. Redigir informacoes do paciente        ");
    printf("\n\n");

    // salvando os arquivos.
    int op_dados;
    int back_opcoes = 0;
    int novo_paciente = 0;
    char label[100] = "\n========================================================";

    scanf("%d", &op_dados);

    do{
        switch(op_dados){
            case 1 :
                adicionando_pacientes("\n",label);
                adicionando_pacientes("Nome        : ", nome);
                adicionando_pacientes("CPF         : ", cpf);
                adicionando_pacientes("Telefone    : ", telefone);
                adicionando_pacientes("Rua         : ", rua);
                adicionando_pacientes("Bairro      : ", bairro);
                adicionando_pacientes("Cidade      : ", cidade);
                adicionando_pacientes("Estado      : ", estado);
                adicionando_pacientes("CEP         : ", cep);
                adicionando_pacientes("E-mail      : ", email);
                adicionando_pacientes("Comorbidade : ", comorbidade);
                adicionando_pacientes("Dia do Nascimento     : ", dia_nascimento);
                adicionando_pacientes("Mes de Nascimento     : ", mes_nascimento);
                adicionando_pacientes("Ano de Nascimento.    : ", ano_nascimento);
                adicionando_pacientes("Idade                 : ", idade);
                adicionando_pacientes("\n",label);

                if(idade >= 65){
                    adicionando_pacientes("Grupo de Risco    : ", "SIM");
                }

                printf("\n\n+++++++ Dados cadastrado com sucesso! +++++");


                printf("\n\n 1. Para cadastrar um novo paciente.\n");

                scanf("%d", &novo_paciente);

                if(novo_paciente == 1){
                    cadastro_dados_paciente();
                }

                break;
            case 2 :
                cadastro_dados_paciente();

                break;
            default :
                printf("\n Erro opcao invalida !\n\n");
                back_opcoes = 1;
                break;

        }
    }while(back_opcoes == 1);
}
