#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor_inputs.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    char *text_buffer = calloc(8192, 1);

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