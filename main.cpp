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

class Box{
    public:
        int x, y;
        int width, height;
        int speed_x;


    void Draw(){
        DrawRectangle(x,y,width,height,WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_LEFT)){
            x-=speed_x;
        }
        if(IsKeyDown(KEY_RIGHT)){
            x+=speed_x;
        }
        if(x+width>=GetScreenWidth()){
            x=GetScreenWidth()-width;
        }
        if(x<=0){
            x=0;
        }
    }

};

Ball ball;
Box box;

int main()
{

    const int scrren_width = 800;
    const int scrren_height = 600;
    

    // Game window
    InitWindow(scrren_width,scrren_height,"Catch the Falling Starts");
    SetTargetFPS(60); // Frame rate

    // Ball Properties
    ball.x=scrren_width/2-25;
    ball.y=25;
    ball.radius =25;
    ball.speed_y= 7;

    // Box Properties
   box.x=scrren_width/2-60;
   box.y=scrren_height-60;
   box.width = 120;
   box.height = 60;
   box.speed_x = 7; 




    // Game Loop
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            ball.Update();
            box.Update();

            box.Draw();
            ball.Draw();

        EndDrawing();
    }

    CloseWindow();


    return 0;
}