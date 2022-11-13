#include <stdio.h>
#include "main.h"
#include "raylib.h"


static const int screenWidth = 800;
static const int screenHeight = 450;


int main(void)
{
    // INIT 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);

    // MAIN LOUPE 
    while (!WindowShouldClose()){

        initMenu();

    }


    // THIS IS THE END
    UnloadGame();       

    CloseWindow();


    return 0;
}


void initMenu(){

    modeDeJeu mode = GAMEOFLIFEmode;
    cursorPossible cursor = PLAY;
    bool startGame = false;

    while(true){

        if (IsKeyDown(KEY_UP)){
            int cursor_temp = cursor;
            cursor = (cursor_temp < 0 ) ? 0 : cursor_temp;
            printf("cursor = %d.\n", cursor);
        }


        //printf("cursor = %d.\n", cursor);

        //if (IsKeyDown(KEY_DOWN));

    }
}

void DrawingMenu(int cursorSelection, int mode){

    int test = 1;
}