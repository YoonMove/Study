#include <iostream>
using namespace std;

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Skeleton = 2,
	MT_Mushroom = 3,
};

PlayerType playerType;
MonsterType monsterType;

struct StatInfo {
	int Hp;
	int Defence;
	int Attack;
};

struct MonsterStatInfo {
	int MonsterHp;
	int MonsterDefence;
	int MonsterAttack;
};

StatInfo PlayerStat;
MonsterStatInfo MonsterStat;

void WaitForNextKey();
void CreateMonster();
void EnterLobby();
void SelectPlayer();
void EnterField();
void Battle();


int main()
{

	EnterLobby();


}
void EnterLobby() {
	while (true) {

		cout << "--------------------" << endl;
		cout << "로비에 들어왔습니다." << endl;
		cout << "--------------------" << endl;

		SelectPlayer();

		cout << "(1) 필드 참여 (2) 나가기" << endl;

		int number;
		cin >> number;

		if (number == 1) {
			EnterField();
		}
		else {
			return;
		}

	}

}
void SelectPlayer() {
	while (true) {

		cout << "--------------------" << endl;
		cout << "직업을 선택해주세요." << endl;
		cout << "--------------------" << endl;


		cout << "--------------------" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 마법사" << endl;
		cout << "--------------------" << endl;


		int number;
		cin >> number;

		if (number == PT_Knight) {
			PlayerStat.Hp = 150;
			PlayerStat.Attack = 3;
			PlayerStat.Defence = 0;
			playerType = PT_Knight;
			break;
		}
		else if (number == PT_Archer) {
			PlayerStat.Hp = 100;
			PlayerStat.Attack = 5;
			PlayerStat.Defence = 0;
			playerType = PT_Archer;
			break;
		}
		else if (number == PT_Mage) {
			PlayerStat.Hp = 100;
			PlayerStat.Attack = 5;
			PlayerStat.Defence = 0;
			playerType = PT_Mage;
			break;
		}

		return;

	}


}
void EnterField() {

	cout << "--------------------" << endl;
	cout << "현재 플레이어 상태" << endl;
	cout << "--------------------" << endl;

	cout << "[HP]" << PlayerStat.Hp << "[Attack]" << PlayerStat.Attack << "[Defence]" << PlayerStat.Defence << endl;

	cout << "--------------------" << endl;
	cout << "몬스터가 등장했습니다." << endl;
	cout << "--------------------" << endl;


	cout << "--------------------" << endl;
	cout << "(1) 전투 참여 (2) 도주" << endl;
	cout << "--------------------" << endl;

	int number;
	cin >> number;

	if (number == 1) {
		Battle();

	}
	else {
		return;
	}
	CreateMonster();
}
void CreateMonster() {
	int randomChoice = 1 + (rand() % 3);

	if (randomChoice == MT_Slime) {
		monsterType = MT_Slime;
		MonsterStat.MonsterHp = 500;
		MonsterStat.MonsterDefence = 0;
		MonsterStat.MonsterAttack = 3;
	}
	else if (randomChoice == MT_Skeleton) {
		monsterType = MT_Slime;
		MonsterStat.MonsterHp = 330;
		MonsterStat.MonsterDefence = 0;
		MonsterStat.MonsterAttack = 3;
	}
	else if (randomChoice == MT_Mushroom) {
		monsterType = MT_Mushroom;
		MonsterStat.MonsterHp = 330;
		MonsterStat.MonsterDefence = 0;
		MonsterStat.MonsterAttack = 3;
	}

}
void Battle()
{
	while (true)
	{
		int damage = PlayerStat.Attack - MonsterStat.MonsterDefence;
		if (damage < 0)
			damage = 0;

		// 선빵
		MonsterStat.MonsterHp -= damage;
		if (MonsterStat.MonsterHp < 0)
			MonsterStat.MonsterHp = 0;

		cout << "몬스터 남은 체력 : " << MonsterStat.MonsterHp << endl;

		if (MonsterStat.MonsterHp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			WaitForNextKey();
			return;
		}

		// 반격
		damage = MonsterStat.MonsterAttack - PlayerStat.Defence;
		if (damage < 0)
			damage = 0;

		PlayerStat.Hp -= damage;
		if (PlayerStat.Hp < 0)
			PlayerStat.Hp = 0;

		cout << "플레이어 남은 체력 : " << PlayerStat.Hp << endl;

		if (PlayerStat.Hp == 0)
		{
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			WaitForNextKey();
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << "> ";

	int input;
	cin >> input;

	system("cls");
}