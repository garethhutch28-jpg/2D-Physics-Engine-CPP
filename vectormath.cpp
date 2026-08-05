#include <cmath> 
#include "VectorMath.h"


Vector2D addVector(Vector2D a, Vector2D b)
{
    Vector2D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2D subtractVector(Vector2D a, Vector2D b)
{
    Vector2D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

float magnitude(Vector2D a)
{
    float result;
    result = sqrt(a.x * a.x + a.y * a.y);
    return result;
}

Vector2D scalarMultiply(Vector2D a, float b)
{
    Vector2D product;
    product.x = a.x * b;
    product.y = a.y * b;
    return product;
}
    
Vector2D scalarDivide(Vector2D a, float b)
{
    Vector2D product;
    product.x = a.x / b;
    product.y = a.y / b;
    return product;
}

float dotProduct(Vector2D a, Vector2D b)
{
    float product;
    product = (a.x * b.x + a.y * b.y);
    return product;
}

Vector2D normalise(Vector2D a)
{
    Vector2D result;
    result = scalarDivide(a, magnitude(a));
    return result;
}