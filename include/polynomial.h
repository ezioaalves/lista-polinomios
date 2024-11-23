#include <iostream>
#include <cmath>
#include "list.h"
using namespace std;

class Polynomial : public List
{
public:
    int grau(); //Retorna o grau do polinômio

    void inserir(float coef, int deg); // Cria um novo nó

    void simplificacao(Node *node); //Organiza e simplifica o polinomio.

    friend std::ostream &operator<<(std::ostream &stream, const Polynomial &poly); //Sobrecarrega o operador << para retornar a apresentação do polinômio

    Polynomial operator+(Polynomial &other); // Sobrecarrega o operador +, para que ele some os polinômios

    Polynomial operator-(Polynomial &other); // Sobrecarrega o operador -, para que ele subtraia os polinômios

    Polynomial operator*(Polynomial &other); // Sobrecarrega o operador *, para que ele multiplique os polinômios

    float avaliacao(float x); //Apartir do valor repassado, verifica o resultado final do polinômio

    string exibicao() const; //Exibe o polinômio em forma de string

    string correcao(float valor) const; //Corrige o valor de float para que não tenha diversos zeros após a virgula

    string sobreescrito(int valor) const; //insere o valor sobreescrito na exibição
};