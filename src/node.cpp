#include "../include/node.h"

Node::Node(float coeff, int deg)
{
    coefficient = coeff;
    degree = deg;
    next = nullptr;
}