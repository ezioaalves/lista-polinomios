#include "../include/list.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0; 
}

void List::inserir(float coef, int deg)
{
    Node *newNode = new Node(coef, deg); 

    if (head == nullptr)
    {
        head = tail = newNode; 
    }
    else if (deg >= head->degree)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;

        while (current->next != nullptr && current->next->degree > deg)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (current->next == nullptr)
        {
            tail = newNode;
        }
    }
    size++;
}

Node *List::obterProximo(Node *node)
{
    return node->next;
}

void List::obterValor(Node *node, int *coef, int *deg)
{
    if (node)
    {
        *coef = node->coefficient; 
        *deg = node->degree;
    }
}

void List::alterarNo(Node *node, float coef, int deg)
{
    if (node)
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != node)
        {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr)
        {
            head = node->next;
        }
        else
        {
            previous->next = node->next;
        }
        if (node->next == nullptr)
        {
            tail = previous;
        }
        this->excluir(node);
        this->size--;
        this->inserir(coef, deg);
    }
}

int List::tamanho() const
{
    return size;
}

bool List::existe(Node *node)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current == node)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void List::mostrarALL() const
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << "(" << current->coefficient << ", " << current->degree << ") -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

Node *List::buscar(float coef, int deg)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->coefficient == coef && current->degree == deg)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::excluir(Node *node)
{
    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current == node)
        {
            if (current == head)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            if (current == tail)
            {
                tail = previous;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

List::~List()
{
    Node *current = head; 
    while (current != nullptr)
    {
        Node *nextnode = current->next;
        delete current;
        current = nextnode;
    }
    head = tail = nullptr;
    size = 0;
}