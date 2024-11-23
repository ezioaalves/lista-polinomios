#pragma once
#include "node.h"

class List
{
public:
    int size;   // Conta o tamanho da lista
    Node *head; // Primeiro valor
    Node *tail; // Último valor

    List(); //Inicia a lista

    void inserir(float coef, int deg); // Insere um valor e o organiza na lista

    Node *obterProximo(Node *node); //Obtem o próximo nó da lista

    void obterValor(Node *node, int *coef, int *deg); //Obtem o valor de um nó a partir de seus valores

    void alterarNo(Node *node, float coef, int deg); //Altera um nó para novos valores

    int tamanho() const; //Retorna o tamanho da lista

    bool existe(Node *node); //Confere se um nó existe na lista

    void mostrarALL() const; //Exibe todos os nós da lista;

    Node *buscar(float coef, int deg); //Busca um nó com base nos valores passados

    void excluir(Node *node); //Exclui o nó da lista

    ~List(); //Destrói a lista
};