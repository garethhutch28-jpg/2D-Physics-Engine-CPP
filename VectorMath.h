#ifndef VECTORMATH_H
#define VECTORMATH_H

//Remeber: Vector2D is my vector that I made (for all the math functions)
//Vector2 Is raylibs built in vector (also just a struct)

struct Vector2D
{
    float x;
    float y;
};

Vector2D addVector(Vector2D a, Vector2D b);
Vector2D subtractVector(Vector2D a, Vector2D b);
float magnitude(Vector2D a);
Vector2D scalarMultiply(Vector2D a, float b);
Vector2D scalarDivide(Vector2D a, float b);
float dotProduct(Vector2D a, Vector2D b);
Vector2D normalise(Vector2D a);


#endif