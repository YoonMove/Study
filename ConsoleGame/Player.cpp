#include "Player.h"
#include "Map.h"


int GPlayerX = 2;
int GPlayerY = 2;

void MovePlayer(int x, int y) {
	// 범위 체크
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;
	// 벽 체크
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1)
		return;
	// 기존 위치 정리
	{
		int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[prevIndex] = 0;
	}


	// 새 위치 이동 
	GPlayerX = x;
	GPlayerY = y;

	{
		int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[prevIndex] = 2;
	}


}