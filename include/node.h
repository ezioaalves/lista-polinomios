#include <iostream>
using namespace std;

class Node
{
public:
    float coefficient; // 2
    int degree;        // ²
    Node *next;        // Guarda a posição do próximo nó

    Node(float coeff, int deg); // Cria o nó
};