/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include <glm.hpp>
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "AnimalSim");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    std::vector<Agent*> agents;

    Agent* player = new Agent();
    player->AddBehaviour(new KeyboardBehaviour(8000));
    agents.push_back(player);

    for (int ii = 0; ii < 30; ii++)
    {
        Agent* seeker = new Agent(BLACK);
        seeker->AddBehaviour(new SeekBehaviour(player, 8000));

        glm::vec2 pos(100+20*ii, 100);
        seeker->SetPosition(pos);

        agents.push_back(seeker);
    }

    float deltaTime = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        deltaTime = GetFrameTime();

        for (auto a:agents) {
            a->Update(deltaTime);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);


        for (auto a : agents) {
            a->Draw();
        }

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    for (auto a : agents) {
       delete a;
    }
    return 0;
}