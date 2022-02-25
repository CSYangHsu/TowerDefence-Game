#include <string>

#include "SpeedEnemy.hpp"
#include <string>

#include "NormalEnemy.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "WBCellTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "FreezeTurret.hpp"
#include "FireBullet.hpp"
#include "enemybullet.hpp"

SpeedEnemy::SpeedEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 10, 50,7, 5,4) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
    //EnenyIndex = 4;

}

void SpeedEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new enemybullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
