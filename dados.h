#ifndef _DADOS_H_
#define _DADOS_H_

typedef struct
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Aluno;

// TODO: add professor model

typedef struct {
    char matricula[10];
    char nome[50];
    char cpf[12];
    Endereco *endereco;
} Professor;


// TODO: add turma model
typedef struct {
    char codigo[10];
    char nome_disciplina[50];
    Professor *professor;
    Aluno **lista_alunos;
    float *media_turma;
} Turma;

// TODO: add interface create turma 
Turma *criarTurma (char *codigo,
                   char *nome_disciplina,
                   Professor *professor,
                   Aluno **lista_alunos,
                   float *media_turma);


// TODO: add interface create professor 

Professor *criarProfessor(char *matricula,
                        char *nome,
                        char *cpf,
                        Endereco *end);


Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);

void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *endereco);
void destruirProfessor(Professor *professor);
void destruirTurma(Turma *turma);

#endif