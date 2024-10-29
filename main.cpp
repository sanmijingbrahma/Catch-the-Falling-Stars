#include <iostream>
#include <raylib.h>
using namespace std;





int main()
{

    const int scrren_width = 800;
    const int scrren_height = 600;
    

    // Game window
    InitWindow(scrren_width,scrren_height,"Catch the Falling Starts");
    SetTargetFPS(60); // Frame rate


    // Game Loop
    while(!WindowShouldClose()){
        BeginDrawing();

            DrawRectangle(scrren_width/2 - 60,scrren_height-60,120,60,WHITE);

        EndDrawing();
    }

    CloseWindow();


    return 0;
}