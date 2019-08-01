#pragma once
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define WIN_HEIGHT 800
#define WIN_WIDTH 1000
#define IMG_RATIO 60
#define LINE 9
#define COLUMN 12
#define UP	'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

//元素
typedef enum Element {
	wall,
	floor,
	box_dest,
	man,
	box,
	hit,
	all
	
}element;

//坐标结构
typedef struct Position {
	int x;
	int y;
}pos;

pos start_pos = { 140,120 };
pos man_pos;

IMAGE img[all];
IMAGE backgroud;

//地图
int map[LINE][COLUMN] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
{ 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
{ 0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0 },
{ 0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0 },
{ 0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0 },
{ 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int hit_num = 0;

void game_begin(void);
void game_play(void);
void game_over(void);
