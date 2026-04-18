#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor_inputs.h"


static int screenWidth;
static int screenHeight;
static bool fullscreen = false;

void SetScreen(bool _fullscreen)
{
    if (_fullscreen)
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        return;
    }
    screenWidth = 800;
    screenHeight = 450;

}
static char text_buffer[8192];

int main(void)
{


    SetScreen(true);
    InitWindow(screenWidth, screenHeight, "Text Editor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        CheckInputs(text_buffer, GetFrameTime());
        ClearBackground(BLACK);
        DrawText(text_buffer, 0, 30, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    free(text_buffer);
    return 0;
}