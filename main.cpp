#include <iostream>
#include <raylib.h>
using namespace std;


class Ball{
    public:
        float radius;
        int x, y;
        float speed_y;
    
    void Draw(){
        DrawCircle(x,y,radius,WHITE);
    }

    void Update(){
        y+=speed_y;
    }
};

Ball ball;

int main()
{

    const int scrren_width = 800;
    const int scrren_height = 600;
    

    // Game window
    InitWindow(scrren_width,scrren_height,"Catch the Falling Starts");
    SetTargetFPS(60); // Frame rate

    ball.x=scrren_width/2-25;
    ball.y=25;
    ball.radius =25;
    ball.speed_y= 7;

    // Ball Properties



    // Game Loop
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            ball.Update();


            ball.Draw();
            DrawRectangle(scrren_width/2 - 60,scrren_height-60,120,60,WHITE);

        EndDrawing();
    }

    CloseWindow();


    return 0;
}