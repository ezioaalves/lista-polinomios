#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include "../include/polynomial.h"

int Polynomial::grau(){
        return head->degree;
    }

void Polynomial::inserir(float coef, int deg) 
{
    if (coef != 0 && deg > -1)
    {
        Node *newNode = new Node(coef, deg); 
        size++;
        simplificacao(newNode);
    }
}

void Polynomial::simplificacao(Node *node) 
{
    if (head == nullptr)
    {
        head = tail = node;
    }
    else if (head->degree == node->degree)
    {
        head->coefficient += node->coefficient;
        delete node;
        size--;
        if (head->coefficient == 0)
        {
            excluir(head);
        }
    }
    else if (head->degree == node->degree)
    {
        head->coefficient += node->coefficient;
        delete node;
        size--;
        if (head->coefficient == 0)
        {
            excluir(head);
            size--;
        }
    }
    else if (node->degree > head->degree)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node *current = head;

        while (current->next != nullptr && current->next->degree >= node->degree)
        {
            current = current->next;
        }
        if (current->degree != node->degree)
        {
            node->next = current->next;
            current->next = node;
            if (current->next == nullptr)
            {                
                tail = node;
            }
        }
        else
        {
            current->coefficient += node->coefficient;
            delete node;
            size--;
            if (current->coefficient == 0)
            {
                excluir(current);
            }
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const Polynomial &poly) 
{
    stream << poly.exibicao();
    return stream;
}

Polynomial Polynomial::operator+(Polynomial &other) 
{
    Polynomial *resultado = new Polynomial();

    Node *poly1 = this->head;
    Node *poly2 = other.head;

    while (poly1 != nullptr && poly2 != nullptr)
    {
        if (poly1->degree > poly2->degree)
        {
            resultado->inserir(poly1->coefficient, poly1->degree);
            poly1 = poly1->next;
        }
        else if (poly1->degree == poly2->degree)
        {
            resultado->inserir(poly1->coefficient + poly2->coefficient, poly1->degree);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else
        {
            resultado->inserir(poly2->coefficient, poly2->degree);
            poly2 = poly2->next;
        }
    }

    while (poly1 != nullptr)
    {
        resultado->inserir(poly1->coefficient, poly1->degree);
        poly1 = poly1->next;
    }
    while (poly2 != nullptr)
    {
        resultado->inserir(poly2->coefficient, poly2->degree);
        poly2 = poly2->next;
    }
    return *resultado;
}

Polynomial Polynomial::operator-(Polynomial &other) 
{
    Polynomial *resultado = new Polynomial();

    Node *poly1 = this->head;
    Node *poly2 = other.head;

    while (poly1 != nullptr)
    {
        resultado->inserir(poly1->coefficient, poly1->degree);
        poly1 = poly1->next;
    }
    while (poly2 != nullptr)
    {
        resultado->inserir(-poly2->coefficient, poly2->degree);
        poly2 = poly2->next;
    }
    return *resultado;
}

Polynomial Polynomial::operator*(Polynomial &other) 
{
    Polynomial *resultado = new Polynomial();

    Node *poly1 = this->head;

    while (poly1 != nullptr)
    {
        Node *poly2 = other.head;
        while (poly2 != nullptr)
        {
            resultado->inserir(poly1->coefficient * poly2->coefficient, poly1->degree + poly2->degree);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }

    return *resultado;
}

float Polynomial::avaliacao(float x) 
{
    float resultado;
    Node *current = head;
    while (current != nullptr)
    {
        resultado += pow(x, current->degree) * current->coefficient;
        current = current->next;
    }
    return resultado;
}

string Polynomial::exibicao() const 
{
    string result;
    Node *current = head;
    while (current != nullptr)
    {
        result += correcao(current->coefficient) + "X" + sobreescrito(current->degree);
        current = current->next;
        if (current != nullptr && current->coefficient > 0)
        {
            result += "+";
        }
    }
    return result;
}

string Polynomial::correcao(float valor) const 
{
    stringstream stream;
    if (floor(valor) == valor)
    {
        return to_string((int)valor);
    }
    else
    {
        stream << fixed << setprecision(2) << valor;
        string s = stream.str();
        return s;
    }
    return to_string(valor);
}

string Polynomial::sobreescrito(int valor) const 
{
    std::map<char, std::string> sobreescritos = {
        {'0', "⁰"},
        {'1', "¹"},
        {'2', "²"},
        {'3', "³"},
        {'4', "⁴"},
        {'5', "⁵"},
        {'6', "⁶"},
        {'7', "⁷"},
        {'8', "⁸"},
        {'9', "⁹"},
    };

    std::string valorStr = std::to_string(valor);

    std::string result = "";
    for (char digito : valorStr)
    {
        result += sobreescritos[digito];
    }

    return result;
}