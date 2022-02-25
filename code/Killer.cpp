#include <allegro5/allegro.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Killer.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include <iostream>
#include<math.h>
// TODO bonus : Try to finish it.
PlayScene* Killer::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
Killer::Killer(float x, float y,int i) : Sprite("play/killer.png", x, y, 0, 0, 0, 0){
    Velocity = Engine::Point(450,0);
    CollisionRadius = 50;
    index = i;
}
void Killer::Update(float deltaTime){

    if(Position.x>=2000){
            return;
        //std::cout << "inin\n";
      //  delete this;
    }

    Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
    Position.x += Velocity.x * deltaTime;
    for ( auto& it : getPlayScene() -> EnemyGroup -> GetObjects() ){
        Enemy* enemy = dynamic_cast<Enemy*>(it);
        //std::cout << Position.x << "," << Position.y << " ---- " << enemy->Position.x << ", " << enemy->Position.y << "\n";
        //std::cout << "IN\n";
        /*if ( Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius) ){
            enemy->Hit(100000);
            //std::cout << "HIT"<<std::endl;
           //getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }*/

        if((*enemy).Position.x<=Position.x&& (*enemy).Position.y>=index*(PlayScene::BlockSize) && (*enemy).Position.y<=(index+1)*(PlayScene::BlockSize)) {
            //OnExplode(enemy);

           // printf("KILLER POSITION.y : %d------Enemy positon.y:%d\n",Position.y,(*enemy).Position.y);
            enemy->Hit(100000);
            //std::cout << "HIT"<<std::endl;
           //getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }

    //if(Position.x>=2000){
        //std::cout << "inin\n";
      //  delete this;
    //}

}
