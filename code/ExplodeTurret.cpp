#include <allegro5/base.h>
#include <cmath>
#include <string>
#include"PlayScene.hpp"
#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "WBCellTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "ExplodeTurret.hpp"
#include "ExplosionEffect.hpp"

#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <utility>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>

#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"
#include "AudioHelper.hpp"
#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"
#include"Collider.hpp"
const int ExplodeTurret::Price = 40;
ExplodeTurret::ExplodeTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-3.png", x, y, Price, 0.5,1) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
	id = 4;
	//CollisionRadius=200;
	r=200;
}
void ExplodeTurret::CreateBullet() {
    return;
}

void ExplodeTurret::OnExplode(){
    PlayScene* scene = getPlayScene();
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
         //printf("DIRT %d\n",i);
	}
	for (auto& it : scene->EnemyGroup->GetObjects()) {
            Enemy* turret = dynamic_cast<Enemy*>(it);
            //if (!enemy->Visible)
                //continue;
            if (Engine::Collider::IsCircleOverlap(Position, r, turret->Position, turret->CollisionRadius)) {
                //OnExplode(turret);
                turret->Hit(100000);
                //getPlayScene()->dGroup->RemoveObject(objectIterator);
                //return;
            }
        }

}


