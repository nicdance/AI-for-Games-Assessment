/*******************************************************************************************

UP TO SESSION 6 1:19:48 
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
#include "MapReader.h"
#include "Graph.h"
#include "MakeNodeGrid.h"
#include "PathFollowBehaviour.h"
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

void DrawPath(const Path& path) {
    if (path.size()  < 2)
    {
        return;
    }
    for (auto j = path.begin(), i = std::next(j); i!=path.end(); ++i, ++j)
    {
        DrawLine(   (*i)->position.x, 
                    (*i)->position.y, 
                    (*j)->position.x, 
                    (*j)->position.y, 
                    Color{255,255,255,255});
    }
}

int main(int argc, char* argv[])
{


    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    int ts = 32;

    InitWindow(screenWidth, screenHeight, "AnimalSim");
    SetTargetFPS(60);

    
   //Texture bugs = LoadTexture("textures/bugs.png");

    Agent* agent = new Agent();
    agent->SetPosition({200,200});
    auto follow_path = new PathFollowBehaviour(20);
    agent->AddBehaviour(follow_path);

    Path path;
//    std::vector<std::shared_ptr<Agent>> agents;


    auto mp = ReadMapInfo("maps/level1.map");
    mp.tile_atlas = LoadTexture("textures/forest_tiles.png");
    mp.tilesize = ts;
    Rectangle rectarray[] = {
        {0,0,ts,ts},
        {13*ts,7*ts,ts,ts},
        {14*ts,7*ts,ts,ts},
        {5*ts,8*ts,ts,ts}
    };
    mp.rectanglemap = rectarray;

    float terrain_difficulty[] = { 1, 2, 4, impassable };

    auto graph = BuildNodeGraph(mp, ts,  terrain_difficulty);

    ResetGraph(&graph.front(), &graph.back());



    //int start = 0;
    //int end = 46;
    //auto path = dijkstrasSearch(&graph[start], &graph[end]);

   

    while (!WindowShouldClose()) {
        auto p = GetMousePosition();
      // // p.x = (int)(p.x/ts);
       // p.y = (int)(p.y / ts);
      //  int tileID = p.x + p.y * mp.x;
        int tileID = mp.GetPositionID(p.x, p.y);

        Vector2 mouse_int{ ((int)p.x/ts)*ts, ((int)p.y/ts)*ts };
        if (IsMouseButtonPressed(0))
        {
            auto end = tileID;

            ResetGraph(&graph[0], &graph[graph.size() - 1]);

            auto agent_Tile = mp.GetPositionID(agent->GetPosition().x, agent->GetPosition().y);
            path = dijkstrasSearch(&graph[agent_Tile], &graph[end]);
            follow_path->SetPath(path);
        }

        /*if (IsMouseButtonPressed(1))
        {
            end = tileID;
            moused = true;
        }*/

        /*if (moused)
        {
            ResetGraph(&graph[0], &graph[graph.size()-1]);
            path = dijkstrasSearch(&graph[start], &graph[end]);
            follow_path->SetPath(path);
        }*/

        // update Agents
        agent->Update(GetFrameTime());

        BeginDrawing();

        ClearBackground(RAYWHITE);
        mp.Draw();
        DrawPath(path);

        agent->Draw();


        DrawRectangleLines(mouse_int.x, mouse_int.y, ts, ts, Color{54,255,128,255});

        EndDrawing();

    }
    CloseWindow();
    
    
    
    // **********    Up To 2:06

 


    /*
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