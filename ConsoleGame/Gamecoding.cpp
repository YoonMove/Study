#include <iostream>
#include <windows.h>
using namespace std;
#include "Map.h"
#include "Helper.h"
#include "Player.h"

MoveDir GMoveDir;

bool canMove = true;

void HandleMove() {
	// 키보드 떼고 있으면, 다음 번엔 움직일 수 있다
	if (GMoveDir == MD_NONE) 
	{
		canMove = true;
		return;
	}
	if (canMove == false)
		return;
	
	canMove = false;

	switch (GMoveDir)
	{
		case MD_LEFT:
			MovePlayer(GPlayerX - 1, GPlayerY);
			break;
		case MD_RIGHT:
			MovePlayer(GPlayerX + 1, GPlayerY);
			break;
		case MD_UP:
			MovePlayer(GPlayerX, GPlayerY - 1);
			break;
		case MD_DOWN:
			MovePlayer(GPlayerX, GPlayerY + 1);
			break;
	}
}



int main()
{
	SetCursorOnOff(false);

	//MovePlayer(3, 2);

	while (true) {
		HandleKeyInput();
		HandleMove();
		PrintMap1D();
	}
}