#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <list>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Sprite.hpp"

class Bullet;
class PlayScene;
class Turret;

class Enemy : public Engine::Sprite {

protected:
	Engine::Point target;
	float speed;
	float hp;
	int money;
	float coolDown = 1;
	int EnemyIndex;
	int super;
	float reload = 0;
	PlayScene* getPlayScene();
	virtual void OnExplode();
	virtual void CreateBullet() = 0;
	std::list<Enemy*>::iterator lockedenemyIterator;
	//bool Freezed;
public:
	bool Enabled = true;
	float reachEndTime;
	std::list<Turret*> lockedTurrets;
	std::list<Bullet*> lockedBullets;
	Turret* Target = nullptr;
	Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money,int EnemyIndex );
 	void Hit(float damage);
	void Update(float deltaTime) override;
	void Draw() const override;
	bool Freezed ;
	//int super;
	//int EnenyIndex;
	int supercount;
	int upy ;
	int sin_x;
	//bool deathmode;
	//int modecount;

};
#endif // ENEMY_HPP
