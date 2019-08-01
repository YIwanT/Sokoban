#include "pushbox.h"


int main(void) {

	game_begin();
	game_play();
	game_over();
	return 0;
}


void game_begin() {
	//初始化图形输出区域
	//加载背景图片、元素图片
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	loadimage(&backgroud, L"blackground.bmp", WIN_WIDTH, WIN_HEIGHT,true);
	putimage(0, 0, &backgroud);
	loadimage(&img[wall], L"wall.bmp", IMG_RATIO, IMG_RATIO, true);
	loadimage(&img[floor], L"floor.bmp", IMG_RATIO, IMG_RATIO, true);
	loadimage(&img[box_dest], L"box_dest.bmp", IMG_RATIO, IMG_RATIO, true);
	loadimage(&img[man], L"man.bmp", IMG_RATIO, IMG_RATIO, true);
	loadimage(&img[box], L"box.bmp", IMG_RATIO, IMG_RATIO, true);
	loadimage(&img[hit], L"box.bmp", IMG_RATIO, IMG_RATIO, true);
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			putimage(start_pos.x + j * IMG_RATIO, start_pos.y + i * IMG_RATIO, &img[map[i][j]]);
			if (map[i][j] == man) {
				man_pos.x = i;
				man_pos.y = j;
			}
		}
	}

	
}

void game_play() {
	//
	char ch;
	bool isOver = false;
	pos next_pos;
	pos nest_nest_pos;
	while (!isOver) {
		hit_num = 0;
		ch = _getch();
		next_pos = man_pos;
		nest_nest_pos = man_pos;
		switch (ch) {
		case UP:	next_pos.x -= 1; nest_nest_pos.x -= 2; break;
		case DOWN:	next_pos.x += 1; nest_nest_pos.x += 2; break;
		case LEFT:	next_pos.y -= 1; nest_nest_pos.y -= 2; break;
		case RIGHT:	next_pos.y += 1; nest_nest_pos.y += 2; break;
		default:
			break;
		}
		// 判断位置 修改地图目标，更换元素
		if (map[next_pos.x][next_pos.y] != wall && (next_pos.x != man_pos.x || next_pos.y != man_pos.y)) {
			if (map[next_pos.x][next_pos.y] != box && map[next_pos.x][next_pos.y] != hit) {
				putimage(start_pos.x + next_pos.y * IMG_RATIO, start_pos.y + next_pos.x * IMG_RATIO, &img[man]);
				if (map[next_pos.x][next_pos.y] == box_dest) {
					map[man_pos.x][man_pos.y] = floor;
					putimage(start_pos.x + man_pos.y * IMG_RATIO, start_pos.y + man_pos.x * IMG_RATIO, &img[floor]);
				}
				else if (map[man_pos.x][man_pos.y] == box_dest) {
					map[next_pos.x][next_pos.y] = man;
					putimage(start_pos.x + man_pos.y * IMG_RATIO, start_pos.y + man_pos.x * IMG_RATIO, &img[box_dest]);
				}
				else {
					putimage(start_pos.x + man_pos.y * IMG_RATIO, start_pos.y + man_pos.x * IMG_RATIO, &img[floor]);
					map[next_pos.x][next_pos.y] = man;
					map[man_pos.x][man_pos.y] = floor;
				}
				man_pos = next_pos;
			}

			else if (map[next_pos.x][next_pos.y] == box && map[next_pos.x][next_pos.y] != hit && map[nest_nest_pos.x][nest_nest_pos.y] != wall) {
				if (map[nest_nest_pos.x][nest_nest_pos.y] == box_dest) {
					map[nest_nest_pos.x][nest_nest_pos.y] = hit;

				}
				else {
					map[nest_nest_pos.x][nest_nest_pos.y] = box;
				}
				putimage(start_pos.x + next_pos.y * IMG_RATIO, start_pos.y + next_pos.x * IMG_RATIO, &img[man]);
				putimage(start_pos.x + man_pos.y * IMG_RATIO, start_pos.y + man_pos.x * IMG_RATIO, &img[floor]);
				putimage(start_pos.x + nest_nest_pos.y * IMG_RATIO, start_pos.y + nest_nest_pos.x * IMG_RATIO, &img[box]);
				map[next_pos.x][next_pos.y] = man;
				map[man_pos.x][man_pos.y] = floor;
				man_pos = next_pos;
			}

		}
		
		for (int i = 0; i < LINE; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (map[i][j] == hit) {
					hit_num++;
				}
			}
		}
		if (hit_num == 4) {
			isOver = true;
		}
		Sleep(100);
	}

}



void game_over() {
	cleardevice();
	settextcolor(RGB(200, 0, 0));
	settextstyle(60, 0, _T("宋体"));
	outtextxy(250, 300, L"恭喜你，过关啦！");
	_getch();
	closegraph();
}