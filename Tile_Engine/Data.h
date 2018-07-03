#pragma once
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 896;
const int SCREEN_BPP = 32;

const int TILE_SHEET_WIDTH = 192;
const int TILE_SHEET_HEIGHT = 384;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//Tile constants
const int TILE_WIDTH = 64;
const int TILE_HEIGHT = 64;
const int ROW_TILES = 16;
const int COLUMN_TILES = 14;
const int TOTAL_TILES = 224;
const int TILE_SPRITES = 18;

//The different tile sprites
const int FLOOR = 1;
const int DOOR = 2;
const int WALL_FIRE = 3;
const int WALL = 4;
const int LADDER_TOP_LEFT = 5;
const int LADDER_TOP_RIGHT = 6;
const int LADDER_BOTTOM_LEFT = 7;
const int LADDER_BOTTOM_RIGHT = 8;
const int BORDER_TOP_LEFT = 9;
const int BORDER_TOP_RIGHT = 10;
const int BORDER_BOTTOM_LEFT = 11;
const int BORDER_BOTTOM_RIGHT = 12;
const int BORDER_LEFT = 13;
const int BORDER_TOP = 14;
const int BORDER_RIGHT = 15;
const int BORDER_DOWN = 16;
const int TREASURE = 17;