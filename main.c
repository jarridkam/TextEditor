#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor_inputs.h"


static int screenWidth;
static int screenHeight;

void SetScreen(const bool fullscreen)
{
    if (fullscreen)
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        return;
    }
    screenWidth = 800;
    screenHeight = 450;
}


int main(void)
{

    SetScreen(false);
    InitWindow(screenWidth, screenHeight, "Text Editor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        CheckInputs();
        ClearBackground(BLACK);
        DrawText(text_buffer, 0, 30, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}