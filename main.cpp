#include <cmath> 
#include <iostream> 
#include "raylib.h"
#include "VectorMath.h"

//gravity
float gravityAcceleration = 9.81;
Vector2D gravity {0,9.81};

//struct for cirles
struct Circles
{
    Vector2D position;
    float mass;
    Vector2D velocity;
    float radius;
    float resitution;
};

//convert my vector struct into a raylib vector
Vector2 convertVectors(Vector2D a)
{
    Vector2 raylibVector;
    raylibVector.x = a.x;
    raylibVector.y = a.y;
    return raylibVector;
}

Vector2D applyGravity(Vector2D velocity, Vector2D gravity, float dt)
{
    velocity = addVector(velocity, scalarMultiply(gravity, dt));
    return velocity;
}

Vector2D updateVelocity(Vector2D velocity, Vector2D gravity, float dt)
    {
        return applyGravity(velocity, gravity, dt);
    }
Vector2D updatePosition(Vector2D position, Vector2D velocity, float dt)
    {
        position = addVector(position, scalarMultiply(velocity, dt));
        return position;
    }

int main()
{
    InitWindow(1000, 600, "PhysicsEngine2D");
    SetTargetFPS(60);

    //make the first cirlce
        Circles obj1;
        obj1.position = {50, 50};
        obj1.velocity = {0,0};
        obj1.mass = 75;
        obj1.radius = 25;
        obj1.resitution = 0.2;

    while (!WindowShouldClose())
    {
        
        //get delta timne
        float dt = GetFrameTime();
    
        //apply gravity
        obj1.velocity = updateVelocity(obj1.velocity, gravity, dt);
        obj1.position = updatePosition(obj1.position, obj1.velocity, dt);
        
        //convert vector2D to vector2
        convertVectors(obj1.velocity);
        convertVectors(obj1.position);

        //ground collision
        if (obj1.position.y > 575)
        {
            obj1.position.y = 575;
            obj1.velocity.y = -obj1.resitution * obj1.velocity.y;
        }

        BeginDrawing();
        //draw the first circle
        DrawCircleV(convertVectors(obj1.position), obj1.radius , RED);
        
        //gravity physics on the ball so it falls
        //f = mak
        //obj1.velocity.y ; 

        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}