#include <iostream>
#include <raylib.h>
using namespace std;

class Ball
{
public:
    float radius;
    float x, y;
    float speed_y;

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        y += speed_y;
    }
};

class Box
{
public:
    float x, y;
    float width, height;
    int speed_x;

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_LEFT))
        {
            x -= speed_x;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            x += speed_x;
        }
        if (x + width >= GetScreenWidth())
        {
            x = GetScreenWidth() - width;
        }
        if (x <= 0)
        {
            x = 0;
        }
    }
};

Ball ball;
Box box;

int main()
{

    // game states
    enum GameState
    {
        MENU,
        PLAYING,
        GAME_OVER
    };
    GameState gameState = MENU;

    const int screen_width = 800;
    const int screen_height = 600;

    // score
    int score = 0;
    string scoreInString = "";

    // Game window
    InitWindow(screen_width, screen_height, "Catch the Falling Starts");
    SetTargetFPS(60); // Frame rate

    // Ball Properties
    ball.x = 10 + rand() % ((screen_width - 10) - 10 + 1);
    // 10+rand()%(780-10+1);
    ball.y = 25;
    ball.radius = 20;
    ball.speed_y = 7;

    // Box Propertie
    box.x = screen_width / 2 - 60;
    box.y = screen_height - 60;
    box.width = 120;
    box.height = 60;
    box.speed_x = 7;

    // Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (gameState == MENU)
        {

            float buttonX = screen_width / 2 - 100;
            float buttonY = screen_height / 2 - 50;
            float buttonWidth = 200;
            float buttonHeight = 100;

            DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, BLUE);
            DrawText("Play", buttonX + 50, buttonY + 30, 50, WHITE);

            
        }
        else if (gameState == PLAYING)
        {

            ball.Update();
            box.Update();

            scoreInString = "Score : " + to_string(score);
            DrawText(scoreInString.c_str(), 15, 30, 20, WHITE);
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{box.x, box.y, box.width, box.height}))
            {
                ball.x = 10 + rand() % ((screen_width - 10) - 10 + 1);
                ball.y = 25;
                score++;
            }else{
                gameState = GAME_OVER;
            }

            box.Draw();
            ball.Draw();
        }
        else
        {

            DrawText("GAME OVER",screen_width+250,screen_height+50,69,WHITE);
            DrawText("Your Score :",screen_width+300,screen_height+100,50,WHITE);

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}