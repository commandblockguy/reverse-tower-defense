#ifndef H_GLOBALS
#define H_GLOBALS

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "tower.h"
#include "path.h"

#define F_BTN_HEIGHT 16
#define TEXT_HEIGHT  8
#define CLICK_RADIUS 8
#define TOWER_RADIUS 8

#define TPS 60
#define ONE_SECOND 128
#define TPC TPS / ONE_SECOND

enum status {
    PRE_WAVE,
    PAUSED,
    WAVE,
    PATH_EDIT
};

// Data that will be included in the save
// Lines and enemies are also included but handled differently
struct gameData {
    uint8_t lives;
    uint8_t status; // Whether the game is pre-wave, paused, or wave
    int8_t score; // Number of enemies killed
    uint24_t waveNumber;
    
    uint8_t numPathPoints; // Equal to the number of points
    
    // Wave specific variables
    uint24_t numEnemies;
    uint24_t livingEnemies;
    ufix_t enemyOffset; // Distance that enemies have proceeded onto the map
    uint8_t xpAmt; // XP amount, dependant on the length of the path
};
// Global vars

extern struct gameData game;
extern pathPoint_t *path;

extern uint16_t pathBufX[255];
extern uint8_t pathBufY[255];
extern char pathBufErr[32];
extern uint8_t bufSize;

extern tower_t towers[NUM_TOWERS];

// Upper 24 bits of the timer
// 128 cycles / second
#define timer_1_Upper *(uint24_t*)(((uint8_t*)&timer_1_Counter)+1)

#endif
