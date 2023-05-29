#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
Endereco *construir_endereco();

Aluno *construir_aluno();

/*
    Busca um aluno
*/
Aluno *buscar_aluno(Aluno **alunos, int *posicao);

void imprimir_aluno(Aluno *aluno);

void imprimir_endereco(Endereco *endereco);


// TODO: add tratadores professor
void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);
Professor *construir_professor();
Professor *buscar_professor(Professor **professores, int *posicao);
void imprimir_professor(Professor *professor);

// TODO: add tratadores turma
void tratador_menu_turma(Turma **turmas, int *qtd_atual_turma, Professor **professores, int *qtd_atual_professores);
Turma *construir_turma(Professor **professores);
Turma *buscar_turma(Turma **turmas, int *posicao);
void imprimir_turma(Turma *turma);

// void imprimir_endereco(Endereco *endereco);

// TODO: update aluno
void atualizacao_aluno(Aluno *aluno, Endereco *end);
void atualizacao_endereco(Aluno *aluno, Endereco *end);

void tratador_menu_estatistica(Professor **professores, int *qtd_atual_professores);

#endif