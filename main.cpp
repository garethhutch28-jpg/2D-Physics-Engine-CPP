#include <cmath> 
#include <iostream> 
#include "raylib.h"
#include "VectorMath.h"
#include <vector>

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

    //make vector for circles
    std::vector<Circles> circles;
    

    while (!WindowShouldClose())
    {
        

        //get delta timne
        float dt = GetFrameTime();
    
        //bouncy ball spawner (right arrow)
        if (IsKeyPressed(KEY_RIGHT))
        {
            Circles bouncyBall;
            bouncyBall.position = {50, 50};
            bouncyBall.velocity = {0,1};
            bouncyBall.mass = 0.12;
            bouncyBall.radius = 10;
            bouncyBall.resitution = 0.9;
            circles.push_back(bouncyBall);
        }

        //tennis ball spawner (left arrow)
        if (IsKeyPressed(KEY_LEFT))
        {
            Circles tennisBall;
            tennisBall.position = {100, 50};
            tennisBall.velocity = {0, 1};
            tennisBall.mass = 0.56;
            tennisBall.radius = 15;
            tennisBall.resitution = 0.7;
            circles.push_back(tennisBall);
        }

        //bowling ball spawner
        if (IsKeyPressed(KEY_UP))
        {
            Circles bowlingBall;
            bowlingBall.position = {150, 50};
            bowlingBall.velocity = {0, 1};
            bowlingBall.mass = 6;
            bowlingBall.radius = 25;
            bowlingBall.resitution = 0.2;
            circles.push_back(bowlingBall);

        }


            
        ///all balls physics updates
        for (Circles&c : circles)
        {
            c.velocity = updateVelocity(c.velocity, gravity, dt);
            c.position = updatePosition(c.position, c.velocity, dt);

            //convert vector2D to vector2
            convertVectors(c.velocity);
            convertVectors(c.position);

            //ground collision
            if (c.position.y > 575)
            {
                c.position.y = 575;
                c.velocity.y = -c.resitution * c.velocity.y;
            }
        }
        
        BeginDrawing();
        //draw all circles
        for (Circles&c:circles)
        {
            DrawCircleV(convertVectors(c.position), c.radius , RED);
        }
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}