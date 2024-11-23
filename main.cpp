#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include "include/list.h"
#include "include/polynomial.h"
using namespace std;

Polynomial processamento(string s) //Recebe a string da entrada, processa o dado para ser inserido dentro da lista.
{
    Polynomial *MyPolynomial = new Polynomial();

    float carga = 0;
    bool trigger = false;
    string agulha;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            agulha += s[i];
        }
        else
        {
            if (!trigger)
            {
                carga = stof(agulha);
                agulha = "";
                trigger = true;
            }
            else
            {
                MyPolynomial->inserir(carga, stoi(agulha));
                agulha = "";
                carga = 0;
                trigger = false;
            }
        }
    }
    if (!agulha.empty())
    {
        if (!trigger)
        {
            carga = stof(agulha);
        }
        else
        {
            MyPolynomial->inserir(carga, stoi(agulha));
        }
    }
    return *MyPolynomial;
}

int main()
{
    ifstream f("input.txt");
    string s;
    while (getline(f, s)) //Usando switch eu troco as opções e chamo as linhas necessárias para cada operação.
    {
        char option = s[0];
        option = tolower(option);
        switch (option)
        {
        case 'g':
        {
            getline(f, s);
            cout << "Grau do Polinomio: " << processamento(s).grau() << endl;
            break;
        }
        case 't':
        {
            getline(f, s);
            cout << "Tamanho do Polinomio: " << processamento(s).tamanho() << endl;
            break;
        }

        case '+':
        {
            getline(f, s);
            Polynomial poly1 = processamento(s);
            getline(f, s);
            Polynomial poly2 = processamento(s);
            Polynomial resultado = poly1 + poly2;
            cout << "Soma dos polinômios: " << resultado << endl;
            break;
        }

        case '-':
        {
            getline(f, s);
            Polynomial poly1 = processamento(s);
            getline(f, s);
            Polynomial poly2 = processamento(s);
            Polynomial resultado = poly1 - poly2;
            cout << "Subtração dos polinômios: " << resultado << endl;
            break;
        }

        case '*':
        {
            getline(f, s);
            Polynomial poly1 = processamento(s);
            getline(f, s);
            Polynomial poly2 = processamento(s);
            Polynomial resultado = poly1 * poly2;
            cout << "Multiplicação dos polinômios: " << resultado << endl;
            break;
        }

        case 'p':
        {
            getline(f, s);
            cout << "Apresentação do polinômio: " << processamento(s).exibicao() << endl;
            break;
        }

        case 'a':
        {
            getline(f, s);
            float valorx = stof(s);
            getline(f, s);
            Polynomial poly = processamento(s);
            cout << "Resultado avalição: " << poly.avaliacao(valorx) << endl;
            break;
        }

        default:
        {
            cout << "Valor incorreto! Error!" << endl;
            break;
        }
        }
    };
    return 0;
}

// Main com a classe lista
// int main()
// {
//     List myList;     // Cria uma instância de lista
//     int option = -1; // Cria uma variação que vai guardar a opção selecionada no menu

//     do
//     {
//         cout << "\n=== MENU ===" << endl;
//         cout << "1. Inserir nó" << endl;
//         cout << "2. Exibir lista" << endl;
//         cout << "3. Buscar nó" << endl;
//         cout << "4. Obter próximo nó" << endl;
//         cout << "5. Alterar valores de um nó" << endl;
//         cout << "6. Excluir nó" << endl;
//         cout << "7. Tamanho da lista" << endl;
//         cout << "8. Destruir lista" << endl;
//         cout << "0. Sair" << endl;
//         cout << "Escolha uma opção: "; // Imprime o menu
//         cin >> option;                 // Recebe a opção desejada

//         switch (option)
//         { // Alterna entre as opções
//         case 1:
//         {
//             float coef;
//             int deg; // Cria as variaveis
//             cout << "Digite o coeficiente e o grau do nó: ";
//             cin >> coef >> deg;                         // Recebe os valores
//             myList.inserir(coef, deg);                  // Ativa o metodo com os valores informados
//             cout << "Nó inserido com sucesso!" << endl; // Feedback
//             break;
//         }

//         case 2:
//         {
//             cout << "Lista: ";
//             myList.mostrarALL(); // Ativa o metodo que imprime a lista
//             break;
//         }

//         case 3:
//         {
//             float coef;
//             int deg; // Cria as variaveis
//             cout << "Digite o coeficiente e o grau do nó para buscar: ";
//             cin >> coef >> deg;                      // Recebe as variaveis
//             Node *result = myList.buscar(coef, deg); // Busca e armazena o resultado
//             if (result)
//             { // Se houver um retorno, ele imprime que existe
//                 cout << "Nó encontrado na lista!" << endl;
//             }
//             else
//             { // Caso contrario vai achar um resultado vazio que é dado como nulo
//                 cout << "Nó não encontrado." << endl;
//             }
//             break;
//         }

//         case 4:
//         {
//             float coef;
//             int deg; // Cria as variaveis
//             cout << "Digite o coeficiente e o grau do nó para buscar: ";
//             cin >> coef >> deg;                      // Recebe as variaveis
//             Node *result = myList.buscar(coef, deg); // Busca e armazena o resultado
//             if (result)
//             { // Se houver um retorno, ele imprime que existe
//                 Node *next = myList.obterProximo(result);
//                 if (next)
//                 {
//                     int coef;
//                     int deg;
//                     myList.obterValor(next, &coef, &deg);
//                     cout << "Nó encontrado na lista!" << endl;
//                     cout << "Próximo nó:" << "(" << coef << ", " << deg << ") -> " << endl; // Imprime os dois números armazenados no nó
//                 }
//                 else
//                 {
//                     cout << "Último nó da lista!" << endl;
//                 }
//             }
//             else
//             { // Se não houver um resultado, imprime que o nó não foi encontrado.
//                 cout << "Nó não encontrado." << endl;
//             }
//             break;
//         }

//         case 5:
//         { // Alterar valores de um nó
//             float coef;
//             int deg; // Cria as variaveis
//             cout << "Digite o coeficiente e o grau do nó para buscar: ";
//             cin >> coef >> deg;                      // Recebe as variaveis
//             cout << coef;
//             cout << deg;
//             Node *result;
//             result = myList.buscar(coef, deg); // Busca e armazena o resultado
//             if (result)
//             { // Se houver um retorno, ele imprime que existe
//                 cout << "Digite os novos valores (coeficiente e grau) para o nó: " << endl;
//                 float newcoef;
//                 int newdeg;
//                 cin >> newcoef;
//                 cin >> newdeg;
//                 myList.alterarNo(result, newcoef, newdeg);
//                 cout << "Valores do nó alterados com sucesso!" << endl;
//             }
//             else
//             { // Se não houver um resultado, imprime que o nó não foi encontrado.
//                 cout << "Nó não encontrado." << endl;
//             }
//             break;
//         }

//         case 6:
//         { // Excluir nó
//             float coef;
//             int deg; // Cria as variaveis
//             cout << "Digite o coeficiente e o grau do nó para buscar: ";
//             cin >> coef >> deg;                      // Recebe as variaveis
//             Node *result = myList.buscar(coef, deg); // Busca e armazena o resultado
//             if (result)
//             { // Se houver um retorno, ele imprime que existe
//                 myList.excluir(result);
//                 cout << "Nó excluído!" << endl;
//             }
//             else
//             { // Se não houver um resultado, imprime que o nó não foi encontrado.
//                 cout << "Nó não encontrado." << endl;
//             }
//             break;
//         }

//         case 7:
//         { // Tamanho da lista
//             cout << "Tamanho da lista: " << myList.tamanho() << endl;
//             break;
//         }

//         case 8:
//         { // Destruir lista
//             myList.~List();
//             cout << "Lista destruída." << endl;
//             break;
//         }

//         case 0: // Sair
//             cout << "Saindo do programa..." << endl;
//             break;

//         default:
//             cout << "Opção inválida. Tente novamente." << endl;
//         }
//     } while (option != 0);

//     return 0;
// }