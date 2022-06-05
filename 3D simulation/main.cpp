#include <iostream>
#include <ostream>
#include <math.h>
#include <cstdlib>
#include "raylib.h"

int main(void)
{

    const int screenWidth = 1600;
    const int screenHeight = 800;


    InitWindow(screenWidth, screenHeight, "Raylib [core]");

    float X = 0.0;
    float Y = 8.0;
    float Z = 0.0;

    float CX = 20.0;
    float CY = 20.0;
    float CZ = 20.0;

    float A = 7.5;
    float B = 0.0f;
    float C = 0.0f;

    float RX = 10.0;
    float RY = 0.0;
    float RZ = 10.0;

    SetTargetFPS(190);

    while (!WindowShouldClose())
    {
        //for camera position movement//
        if(IsKeyDown(KEY_A)){
            CZ += 0.2;
        }
        if(IsKeyDown(KEY_D)){
            CZ -= 0.2;
        }
        if(IsKeyDown(KEY_W)){
            CX -= 0.2;
        }
        if(IsKeyDown(KEY_S)){
            CX += 0.2;
        }
        //----------------------------//
        Camera camera = { 0 };
        camera.position = (Vector3){ CX , CY , CZ };
        camera.target = (Vector3){ CX - RX , CY , CZ - RZ };
        camera.up = (Vector3){ 0.0f , 1.0f , 0.0f };
        camera.fovy = 80.0f;
        camera.projection = CAMERA_PERSPECTIVE;

        SetCameraMode(camera, CAMERA_FREE);

        Ray ray = { 0 };


        UpdateCamera(&camera);

        BeginDrawing();

            BeginMode3D(camera);

                ClearBackground(RAYWHITE);
                DrawGrid(20,10.0f);
                DrawCube(Vector3{ B , A , C }, 15.0f , 15.0f , 15.0f , DARKBLUE);
                DrawCube(Vector3{-6.0f , 7.5f , 25.0f }, 5.0f , 6.0f , 5.0f , DARKPURPLE);
                DrawCube(Vector3{-19.0f , 9.5f , 29.0f }, 13.0f , 9.0f , 6.0f , GREEN);

            EndMode3D();
            DrawText("3D Game Engine", 10 , 50 , 30 , BLACK);
            DrawText("Press W,A,S,D Keys to move around", 10 , 100 , 30 , BLACK);
            DrawFPS(10,200);

        EndDrawing();

    }
    CloseWindow();
    return 0;
}
