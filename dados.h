#ifndef _DADOS_H_
#define _DADOS_H_

typedef struct
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco; //Criando protótipo de estrutura de dados "Endereço"

typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Aluno; //Criando protótipo de estrutura de dados "Aluno"

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero); //Protótipo de função

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end); //Protótipo de função

void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *);

#endif