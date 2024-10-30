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
    ball.x = 25 + rand() % ((screen_width - 25) - 10 + 1);
    // 10+rand()%(780-10+1);
    ball.y = 25;
    ball.radius = 20;
    ball.speed_y = 7;

    // Box Propertie
    box.x = screen_width / 2 - 60;
    box.y = screen_height - 60;
    box.width = 120;
    box.height = 60;
    box.speed_x = 10;

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

            Vector2 mousePoint = GetMousePosition();
            if(CheckCollisionPointRec(mousePoint, Rectangle{buttonX,buttonY,buttonWidth,buttonHeight})){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    gameState = PLAYING;
                }
            }
        }
        if (gameState == PLAYING)
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
            }
            if(ball.y+ball.radius>=GetScreenHeight()+10){
                gameState = GAME_OVER;
            }



            box.Draw();
            ball.Draw();
        }
        if (gameState == GAME_OVER)
        {
            string yourScore = "Your Score : "+ to_string(score);
            DrawText("GAME OVER",screen_width/2-200,50,70,WHITE);
            DrawText(yourScore.c_str(),screen_width/2-150,150,40,WHITE);


            float buttonX = screen_width/2 - 160;
            float buttonY = 400;
            float buttonWidth = 320;
            float buttonHeight = 100;

            DrawRectangle(buttonX,buttonY,buttonWidth,buttonHeight,BLUE);
            DrawText("Play Again",screen_width/2-135,420,50,WHITE);

            Vector2 mousePoint = GetMousePosition();
            if(CheckCollisionPointRec(mousePoint, Rectangle{buttonX,buttonY,buttonWidth,buttonHeight})){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    gameState = PLAYING;
                    score = 0;
                    ball.x = 25 + rand() % ((screen_width - 25) - 10 + 1);
                    ball.y =25;
                }
            }


        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}