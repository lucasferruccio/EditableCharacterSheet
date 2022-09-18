#include <stdio.h>
#include "raylib.h"
#include "opa.h"

#define MAX_INPUT_CHARS     10

int main(void)
{
    teste();
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RollDices");
    
    Rectangle DiceWriting = {70, 70, 250, 50};
    bool MouseOnText = false;

    int letterCount = 0;

    int framesCounter = 0;

    SetTargetFPS(10);
    
    char Dice[MAX_INPUT_CHARS];
    
    while (!WindowShouldClose()) 
    {
        if (CheckCollisionPointRec(GetMousePosition(), DiceWriting)) 
        {
            MouseOnText = true;
        }
        else
        {
            MouseOnText = false;
        }
    
        if(MouseOnText)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            
            //Pick the character typed by the user
            int Char_Input = GetCharPressed();
            
            //For dealing with the return 0 by the function
            while(Char_Input > 0)
            {
                //To pick only character that are needed for roolling the dices
                if ((Char_Input >= 32) && (Char_Input <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    Dice[letterCount] = (char) Char_Input;
                    Dice[letterCount + 1] = NULL;
                    letterCount++;
                }
                
                Char_Input = GetCharPressed();
            }
            Char_Input = GetCharPressed();
            //To erase the characters
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0)
                {
                    letterCount = 0;
                }
                Dice[letterCount] = '\0';
            }
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
        
        //Drawing the HUD
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        //The input bars, recive the dice value
        DrawRectangleLines(DiceWriting.x, DiceWriting.y, DiceWriting.width, DiceWriting.height, DARKGRAY);
        DrawText(Dice, (int) DiceWriting.x + 10, (int) DiceWriting.y + 10, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
