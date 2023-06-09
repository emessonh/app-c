#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i <= *qtd_atual_aluno; i++)
            {
                if (alunos[i] == NULL)
                {
                    break;
                }
            }
            Aluno *aluno = construir_aluno();
            alunos[i] = aluno;
            *qtd_atual_aluno++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            imprimir_aluno(aluno);
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        // printf("Implementar a atualização de aluno\n");
        int posicao = 0;
        int continuar = 1;
        aluno = buscar_aluno(alunos, &posicao);
        // if aluno for encontrado atualiza o endereço
        if (aluno){
            atualizacao_endereco(aluno, aluno->endereco);
            printf("Atualizado com sucesso!\n");
            continuar = 0;
        }
        // caso não seja encontrado imprime a informação para o usuário
        else{
            printf("Aluno não encontrado!\n");
        }
    }

    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

// TODO: add tratador_menu_professor

void tratador_menu_professor(Professor **professores, int *qtd_atual_professor)
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
   
        if (*qtd_atual_professor >= MAX_PROFESSOR)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i <= *qtd_atual_professor; i++)
            {
                if (professores[i]== NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            // TODO: check this error
            professor = construir_professor();
            professores[i] = professor;
            (*qtd_atual_professor)++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }
    break;
    case 3:
    // TODO: implementar update of "professor"
    {
        printf("Implementar a atualização de Professor\n");
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("professor destruido\n");
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Número\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;
    printf("Matrícula\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 11, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matrícula > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_aluno(Aluno *aluno)
{
    printf("Matrícula: %s", aluno->matricula);
    printf("Nome: %s", aluno->nome);
    printf("CPF: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Número: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

// TODO: add tratadores professor
Professor *construir_professor()
{
    Professor professor;
    printf("Matrícula\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 11, stdin);

    professor.endereco = construir_endereco();
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matrícula > ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_professor(Professor *professor)
{
    printf("Matrícula: %s", professor->matricula);
    printf("Nome: %s", professor->nome);
    printf("CPF: %s", professor->cpf);
    imprimir_endereco(professor->endereco);
}

// TODO: add tratadores turma
Turma *construir_turma()
{
    Turma turma;
    // printf("Matrícula\t> ");
    // fgets(turma.matricula, 9, stdin);
    // printf("Nome\t> ");
    // fgets(professor.nome, 49, stdin);
    // printf("CPF\t> ");
    // fgets(professor.cpf, 11, stdin);

    // professor.endereco = construir_endereco();
    // return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Turma *buscar_turma(Turma **turmas, int *posicao)
{
    // char matricula[50];
    // printf("Matrícula > ");
    // fgets(matricula, 49, stdin);
    // Professor *resultado = NULL;
    // int pos_resultado = -1;
    // for (int i = 0; i < MAX_ALUNO; i++)
    // {
    //     // Vamos testar se o aluno existe e se a matricula e a buscada
    //     // strcmp compara strings. Se for 0 indica que são iguais
    //     if (professores[i] && !strcmp(matricula, professores[i]->matricula))
    //     {
    //         resultado = professores[i];
    //         break;
    //     }
    // }
    // *posicao = pos_resultado;
    // return resultado;
}

void imprimir_turma(Turma *turma)
{
    // printf("Matrícula: %s", professor->matricula);
    // printf("Nome: %s", professor->nome);
    // printf("CPF: %s", professor->cpf);
    // imprimir_endereco(professor->endereco);
}

// função que atualiza o objeto endereço, recebe os ponteiros de aluno e endereço
void atualizacao_endereco(Aluno *aluno, Endereco *end){
    // pede ao usuário as atulizações, acessa cada atributo do endereço e o modifica
    printf("Logradouro\t> ");
    fgets(end->logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(end->bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(end->cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(end->estado, 9, stdin);
    printf("Número\t> ");
    fgets(end->numero, 9, stdin);
}

// TODO: imprimir os professores, as matriculas dos professores que estão sem turma e a média de todas as turmas
void tratador_menu_estatistica(Professor **professores, int *qtd_atual_professores){
    int opcao = menu_estatistica();
    switch (opcao)
    {
    // caso a opção seja 1 ele vai imprimir os nomes de todos os professores
    case 1:
        for (int i = 0; i < *qtd_atual_professores; i++){
            printf("Professor(a): %s", professores[i] -> cpf);
        }
        break;
    case 2:
    
        break;
    case 3:
    
        break;
    }
}