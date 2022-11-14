#pragma once

#include <stdio.h>
#include <string.h>


static const int screenWidth = 800;
static const int screenHeight = 460;
static const int tailleCarreau = 20;
static int nbreCarreauX = screenWidth/tailleCarreau;
static int nbreCarreauY = screenHeight/tailleCarreau;


typedef enum etatsPossibles
{
    MORT,
    VIVANT1,
    VIVANT2,
    VIVANT3=4,
    VIVANT4=8
} etatsPossibles;

typedef enum modeDeJeu
{
    GAMEOFLIFEmode,
    QUADLIFEmode,
    DOOMmode
} modeDeJeu;

typedef enum cursorPossible
{
    GAMEOFLIFE,
    QUADLIFE,
    DOOM,
    PLAY,
    SETTING

} cursorPossible;

typedef enum GameScreen { MENU, GAME} GameScreen;

static cursorPossible cursor = PLAY;
static modeDeJeu mode = GAMEOFLIFEmode ;

//dsl pour les variables globales mais je ne comprend pas l'affichage de raylib
//j'ai eu de gros probleme avec le fct de begin et end drawing
// ca fait 2h que j'essaye de comprendre et je n'ai pas de retour d'erreur permettant de comprendre
//par conséquent ça sera moche avec quelques variables globales


modeDeJeu initMenu();

void DrawingMenu(int cursorSelection, int mode);

void UpdateMenu(int *pCursorSelection, int *pMode, int *startGame);

void GameDrawUpdate(modeDeJeu mode);

int nbrevoisin(int x,int y, int etat[nbreCarreauX][nbreCarreauY]);

void premiereGen(int etat[nbreCarreauX][nbreCarreauY], modeDeJeu mode);

void UpdateGame(modeDeJeu mode,int etat[nbreCarreauX][nbreCarreauY]);

void DrawingGame(modeDeJeu mode,int etat[nbreCarreauX][nbreCarreauY]);

void ALL_DRAWING(GameScreen screen, int mode ,int cursorSelection, int etat[nbreCarreauX][nbreCarreauY] );