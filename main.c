#include <stdio.h>
#include <string.h>
#include "main.h"
#include "raylib.h"


static const int screenWidth = 800;
static const int screenHeight = 460;
static const int tailleCarreau = 10;


int main(void)
{
    // INIT 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);

    modeDeJeu modeJeu;

    // MAIN LOUPE 
    //while (!WindowShouldClose()){

        modeJeu = initMenu();
        

    //}


    // THIS IS THE END
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void GameDrawUpdate(modeDeJeu mode){

    int nbreCarreauX = screenWidth()/tailleCarreau;
    int nbreCarreauY = screenHeight()/tailleCarreau;
    etatsPossibles etat[nbreCarreauX][nbreCarreauY];
    bool pause = 0;
    if (mode = GAMEOFLIFEmode){
        int nbreColonie = 1;
    }
    if (mode = QUADLIFEmode){
        int nbreColonie = 4;
    }

    premiereGen(etat, mode);

    if(IsKeyPressed('P')){
        pause = !pause;
    }


}

void premiereGen(int etat[nbreCarreauX][nbreCarreauY], int nbreColonie){
    for(int i = 0 ; i < nbreCarreau ; i ++ ){
    for(int j = 0 ; j < nbreCarreau ; j ++ ){
      etat[i][j] = GetRandomValue(0,mode);
    }
  }
}

int nbrevoisin(int x,int y, int etat[nbreCarreauX][nbreCarreauY]){
  int result = etat[x+1][y+1]
              +etat[x-1][y-1]
              +etat[x-1][y+1]
              +etat[x+1][y-1]
              +etat[x+1][y]
              +etat[x-1][y]
              +etat[x][y+1]
              +etat[x][y-1];
  return result;
}















modeDeJeu initMenu(){

    modeDeJeu mode = GAMEOFLIFEmode;
    cursorPossible cursor = PLAY;
    bool startGame = false;

    while(!startGame){
        
        
        UpdateMenu(&cursor, &mode, &startGame);
        DrawingMenu(cursor, mode);

    }
    return mode;

}

void UpdateMenu(int *pCursorSelection, int *pMode, int *startGame){

    if (IsKeyPressed(KEY_UP)){
        //printf("hautavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection > 0){
            (*pCursorSelection)--;
            //printf("hautapres = %d.\n", *pCursorSelection);
        }
    }

    if (IsKeyPressed(KEY_DOWN)){
        //printf("basavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection < 4){
            (*pCursorSelection)++;
            //printf("basapres = %d.\n", *pCursorSelection);
        }
    }


    if(IsKeyPressed(KEY_ENTER)){
        if(*pCursorSelection == PLAY){
            *startGame = true;
            return;
        }
 
        if(*pCursorSelection < PLAY){
            printf("avant%d \n", *pMode);
            *pMode = *pCursorSelection;
            printf("apres%d \n", *pMode);
        }
    }

}

void DrawingMenu(int cursorSelection, int mode){
    BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0 ; i < PLAY ; i++){
            Color rectColor = DARKGRAY;
            if ( (mode == i ) && (mode <= DOOMmode)){
                rectColor = GRAY;
            }
            DrawRectangle(10, 10+(i*60), 200, 30, rectColor);
            if ( (cursorSelection == i) && (cursorSelection <= DOOMmode) ){
                DrawRectangle(15, 15+(i*60), 20, 20, RED);
            }

            if (cursorSelection == PLAY){
                DrawRectangle(GetScreenWidth()/2 - MeasureText("JOUER", 50)/2,300, MeasureText("JOUER", 50),5, RED);
            }
        }

        DrawText("Jeu De la vie", 45, 15, 20, RAYWHITE);
        DrawText("QuadLife", 45, 75, 20, RAYWHITE);
        DrawText("Doom", 45, 135, 20, RAYWHITE);



        DrawText("JOUER", GetScreenWidth()/2 - MeasureText("JOUER", 50)/2,250, 50, RED);

    EndDrawing();
}