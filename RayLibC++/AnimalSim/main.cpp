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
#include <list>
#include <glm.hpp>
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include "SteeringBehaviour.h"
#include "Graph.h"

using Path = std::list<Node*>;
Path dijkstrasSearch(Node* startNode, Node* endNode);

//class ManagedTexture {
//private:
//    Texture image;
//public:
//    ManagedTexture(const char* file) {
//        image = LoadTexture(file);
//    }
//
//    ~ManagedTexture() {
//        UnloadTexture(image);
//    }
//    operator Texture() const { 
//        return image;
//    }
//};

void ResetGraph(Node* start, Node* end){
    for (; start !=end; ++start)
    {
        start->gscore = 100000000;
    }
}

int main(int argc, char* argv[])
{
    Node map[9];

    enum {A,B,C,D,E,F,G,H,I};

    map[A] = { 'A', { {&map[B],1}, {&map[F],2}, {&map[E],3} } };
    map[B] = { 'B',{{&map[A],1}, {&map[C],1}} };
    map[C] = { 'C',{{&map[B],1}, {&map[D],1}} };
    map[D] = { 'D',{{&map[C],1}, {&map[I],2} , {&map[E],3} } };
    map[E] = { 'E',{{&map[A],3}, {&map[D],3}, {&map[F],3}, {&map[I],13}  } };
    map[F] = { 'F',{{&map[A],2}, {&map[E],3}, {&map[G],1} } };
    map[G] = { 'G',{{&map[F],1}, {&map[H],1}} };
    map[H] = { 'H',{{&map[G],1}, {&map[I],1}} };
    map[I] = { 'I',{{&map[D],2}, {&map[E],3}, {&map[H],1} } };
        
    ResetGraph(&map[0], &map[8]);
    auto path  =  dijkstrasSearch(&map[A], &map[D]);

    /*
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "AnimalSim");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    std::vector<Agent*> agents;

    Texture bugs = LoadTexture("textures/bugs.png");

    Agent* player = new Agent(bugs);
    player->AddBehaviour(new KeyboardBehaviour(8000));
    glm::vec2 posA(250,250);
    player->SetPosition(posA);
    player->max_speed = 400;

    agents.push_back(player);
    SeekForce* sf = new SeekForce(player);
    SteeringBehaviour* sb = new SteeringBehaviour(sf);

    for (int ii = 0; ii <10; ii++)
    {
        Agent* agent = new Agent(bugs);
        //agent->AddBehaviour(new SeekBehaviour(player, 8000));

        agent->AddBehaviour(sb);
        agent->initial_frame_y = ii % 7 *2+ 2;
        glm::vec2 pos(100+20*ii, 100);
        agent->SetPosition(pos);
        agent->max_speed = 100 + ii * 20;
        agents.push_back(agent);
    }



    FleeForce* ff = new FleeForce(player);
    SteeringBehaviour* fb = new SteeringBehaviour(ff);

    for (int ii = 0; ii < 10; ii++)
    {
        Agent* agent = new Agent(bugs);
        //agent->AddBehaviour(new SeekBehaviour(player, 8000));

        agent->AddBehaviour(fb);
        agent->initial_frame_y = ii % 7 * 2 + 2;
        glm::vec2 pos(100 + 20 * ii, 200);
        agent->SetPosition(pos);
        agent->max_speed = 20 + ii *10;
        agents.push_back(agent);
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

    // clean up textures
    UnloadTexture(bugs);
    

    for (auto a : agents) {
       delete a;
    }
    */

    return 0;
}