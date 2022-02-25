#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "PlayScene.hpp"
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
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <random>
#include "Collider.hpp"

PlayScene* Enemy::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void Enemy::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
}

Enemy::Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money, int a) :
    Engine::Sprite(img, x, y), speed(speed), hp(hp), money(money) {
    EnemyIndex = a;
	CollisionRadius = radius+7;
	supercount = 0;
	super = 0;
	reachEndTime = 0;
	Freezed = false;
	Velocity = Engine::Point(speed , 0);

	target = Engine::Point(PlayScene::EndGridPointx , static_cast<int>(floor(Position.y / PlayScene::BlockSize))) * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
    upy = Position.y;
    sin_x = 0;
    //int a = rand();
    //int b;
    //a %= 2;
    //if(a==0)    b = 1;
    //else if(a==1)   b = -1;
    //Velocity = Engine::Point(speed, 15);

    //deathmode = false;

   // modecount = 0;


}
void Enemy::Hit(float damage) {

	//std::cout<<"HEY---"<<EnemyIndex<<std::endl;

	if(EnemyIndex==4){

        //if(super==5)    super=0;
        if(super<=2){
            hp -= damage;
        }
        super++;
	}
	else{
        hp -= damage;
	}





	/*if(EnemyIndex==4&&super>=2){
        hp = hp;
        super++;

	}
	else{
        hp -= damage;
        if(EnemyIndex==4)   super++;    //蝑鋡急??拐?敺??uper

	}
	if(EnemyIndex==4 && super==4)    super=0;*/

	if (hp <= 0) {
		OnExplode();
		// Remove all turret's reference to target.
		for (auto& it: lockedTurrets)
			it->Target = nullptr;
		for (auto& it: lockedBullets)
			it->Target = nullptr;
		getPlayScene()->EarnMoney(money);
		getPlayScene()->EnemyGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
	}
}
void Enemy::Update(float deltaTime) {
    //printf("supercount  %d\n",supercount);
    int c=1;
    int a = Velocity.x , b = Velocity.y;
    //if(deathmode==true){
        //a=5*Velocity.x;
        //modecount++;
    //}
    //if(modecount==60){
        //deathmode = false;
        //modecount=0;
    //}

    if(supercount>=60){
        super = 0;
        supercount=0;
    }
	PlayScene* scene = getPlayScene();
	float remainSpeed = speed * deltaTime;
	if (!Enabled)   return;
	if (Target) {
		if (Target->Position.x > Position.x&& Target->Position.y >= Position.y  && Target->Position.y < Position.y+scene->BlockSize/2) {
			Target->lockedenemys.erase(lockedenemyIterator);
			Target = nullptr;
			lockedenemyIterator = std::list<Enemy*>::iterator();
		}
		else if (Target->Position.x+80 >= Position.x)
        {
            Position.x=Target->Position.x+80;
            c = 0;
        }
		// Shoot reload.
		reload -= deltaTime;
		if (reload <= 0) {
			// shoot.
			reload = coolDown;
			CreateBullet();
		}
	}
	if (!Target) {
		// Lock first seen target.
		// Can be improved by Spatial Hash, Quad Tree, ...
		// However simply loop through all enemies is enough for this program.
		//b = Velocity.y;
		for (auto& turret : scene->TowerGroup->GetObjects()) {
            //it->Position.x < Position.x&&it->Position.x+100 >= Position.x && it->Position.y >= Position.y  && it->Position.y < Position.y+scene->BlockSize
            //Engine::Collider::IsCircleOverlap(Position, 20, Target->Position, 20
            //IsRectOverlap(Point r1Min, Point r1Max, Point r2Min, Point r2Max)
            if (turret->Position.x < Position.x&&turret->Position.x+100 >= Position.x &&Engine::Collider::IsPointInRect(turret->Position, Engine::Point(Position.x - PlayScene::BlockSize, Position.y - PlayScene::BlockSize/2), Engine::Point(PlayScene::BlockSize, PlayScene::BlockSize))) {
				Target = dynamic_cast<Turret*>(turret);
				Target->lockedenemys.push_back(this);
				lockedenemyIterator = std::prev(Target->lockedenemys.end());
				break;
			}
		}
	}

    //a = Velocity.x , b = Velocity.y;
    if(EnemyIndex!=4){
            if(EnemyIndex==2){

                sin_x = sin_x + 50;
                if(Freezed){
                    Position.x -= a*3/10 * deltaTime;
                    Position.y =upy+ 1500*c* deltaTime*sin(sin_x);
                }
                else{
                     Position.x -= a * deltaTime;
                     Position.y =upy+ c*2900* deltaTime*sin(sin_x);
                }

            }
            else{
                if(Freezed){
                    Position.x -= a*3/10 * deltaTime;
                    Position.y += b *3/10* deltaTime;
                }
                else{
                    Position.x -= a*3 * deltaTime;
                    Position.y += b *3* deltaTime;
                    //printf("IOHIOHIOHOIH\n");
                }
            }
    }
	else if(EnemyIndex==4){
        if(super>=2){
            Position.x -= a*3 * deltaTime;
            Position.y += b *3* deltaTime;
            supercount++;
        }
        else{
            Position.x -= a * deltaTime;
            Position.y += b * deltaTime;
        }

	}
    if(Position.y<-5){
        Velocity.y*=-1;
    }
    if(Position.y>PlayScene::MapHeight){
        Velocity.y*=-1;
    }



    //Position.x -= Velocity.x * deltaTime;
	//Position.y += Velocity.y * deltaTime;
	if(Position.x <= PlayScene::EndGridPointx * PlayScene::BlockSize + PlayScene::BlockSize / 2){
		Hit(hp);
		getPlayScene()->Hit();
		reachEndTime = 0;
		return;
	}








	Engine::Point vec = target - Position;
	reachEndTime = (vec.Magnitude() - remainSpeed) / speed;

	/*bool flag = false;
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	for (auto& it : scene->TowerGroup->GetObjects()) {
            Turret* turret = dynamic_cast<Turret*>(it);
            if(Position.y + Engine::GameEngine::GetInstance().GetScreenSize().y / 14 > turret->Position.y&&Position.y-Engine::GameEngine::GetInstance.GetScreenSize().y/14<turret->Position.y)
            {
                if(turret->Position.x<=Position.x&&Position.x<=turret->Position + 100){
                    Position.x = turret->Position.x+100;
                    flag = true
                }
                if(reload<=0&&(flag)){
                    reload = coolDown;
                    CreateBullet();
                }
                reload -= deltaTime;

            }
		}*/




}
void Enemy::Draw() const {
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw collision radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(255, 0, 0), 2);

	}

}
