#include <string>

#include "NormalEnemy.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>
#include "Sprite.hpp"
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
#include "PlayScene.hpp"
#include "Resources.hpp"
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <random>
NormalEnemy::NormalEnemy(int x, int y) : Enemy("play/enemy-1.png", x, y, 10, 50, 5, 5,0) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
    //EnenyIndex = 0;
    //Velocity.y = 0.5*PlayScene::BlockSize*50*sin(5*Position.x);
    //CollisionRadius = 0.5*PlayScene::BlockSize-8;
    /*
    int a = rand();
    int b;
    a %= 2;
    if(a==0)    b = 1;
    else if(a==1)   b = -1;
    Velocity = Engine::Point(speed, 10*b);*/

}

void NormalEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new enemybullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
