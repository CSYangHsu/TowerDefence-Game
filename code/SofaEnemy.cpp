#include <string>

#include "SofaEnemy.hpp"
#include "enemybullet.hpp"
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

SofaEnemy::SofaEnemy(int x, int y) : Enemy("play/enemy-2.png", x, y, 16, 100, 10, 10,2) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
	//EnenyIndex = 1;
    Velocity.y = 10;
}
void SofaEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new enemybullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
