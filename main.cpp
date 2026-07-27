#include <cmath> 
#include <iostream> 
    struct Vector2
    {
        float x;
        float y;
    };

    Vector2 addVector(Vector2 a, Vector2 b)
    {
        Vector2 result;
        result.x = a.x + b.x;
        result.y = a.y + b.y;
        return result;

    }

    Vector2 subtractVector(Vector2 a, Vector2 b)
    {
        Vector2 result;
        result.x = a.x - b.x;
        result.y = a.y - b.y;
        return result;

    }

    float magnitude(Vector2 a)
    {
        float result;
        result = sqrt(a.x * a.x + a.y * a.y);
        return result;
    }

    Vector2 scalarMultiply(Vector2 a, float b)
    {
        Vector2 product;
        product.x = a.x * b;
        product.y = a.y * b;
        return product;
    }
        
    Vector2 scalarDivide(Vector2 a, float b)
    {
        Vector2 product;
        product.x = a.x / b;
        product.y = a.y / b;
        return product;
    }
    
    float dotProduct(Vector2 a, Vector2 b)
    {
        float product;
        product = (a.x * b.x + a.y * b.y);
        return product;
    }

    Vector2 normalise(Vector2 a)
    {
        Vector2 result;
        result = scalarDivide(a, magnitude(a));
        return result;
    }

int main()
{
    //get two vectors and split them into their x and y
    float ax, ay;
    float bx, by;

    std::cout << "Enter Vector1 x: ";
    std::cin >> ax;
    std::cout << "Enter Vector1 y: ";
    std::cin >> ay;
    std::cout << "Enter Vector2 x: ";
    std::cin >> bx;
    std::cout << "Enter Vector2 y: ";
    std::cin >> by;

    //make vectors out of the inputs
    Vector2 a = {ax, ay};
    Vector2 b = {bx, by};

    //test the adding
    Vector2 vectorSum = addVector(a, b);
    
    float sumMagnitude = magnitude(vectorSum);

    std::cout << "The x component of the addition is " << vectorSum.x << " and the y result is " << vectorSum.y << " the magnitude of the addition is: " << sumMagnitude;

}