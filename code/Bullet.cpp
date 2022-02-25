#include "Bullet.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"

PlayScene* Bullet::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void Bullet::OnExplode(Enemy* enemy) {
}
void Bullet::OnExplode(Turret* enemy) {
}
Bullet::Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent),Enemyparent(nullptr) {
	Velocity = forwardDirection * speed;
	Rotation = rotation;
	CollisionRadius = 4;
	isturret = true;
}
Bullet::Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), Enemyparent(parent),parent(nullptr) {
	Velocity = -1*forwardDirection * speed;
	Rotation = rotation;
	CollisionRadius = 4;
	isturret = false;
}
void Bullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	if(isturret == true ){
        for (auto& it : scene->EnemyGroup->GetObjects()) {
            Enemy* enemy = dynamic_cast<Enemy*>(it);
            if (!enemy->Visible)
                continue;
            if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
                OnExplode(enemy);
                enemy->Hit(damage);
                getPlayScene()->BulletGroup->RemoveObject(objectIterator);
                return;
            }
        }
	}
	else{
        for (auto& it : scene->TowerGroup->GetObjects()) {
            Turret* turret = dynamic_cast<Turret*>(it);
            //if (!enemy->Visible)
                //continue;
            if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, turret->Position, turret->CollisionRadius)) {
                OnExplode(turret);
                turret->hit(damage);
                getPlayScene()->BulletGroup->RemoveObject(objectIterator);
                return;
            }
        }
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()))
		getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}
