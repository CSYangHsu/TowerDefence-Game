#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>
#include "Bullet.hpp"

#include "Sprite.hpp"

class Enemy;
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    int price;
    float hp;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;
    virtual void OnExplode();
    //int id;

public:
    bool Enabled = true;
    bool Preview = false;
    std::list<Enemy*> lockedenemys;
    std::list<Bullet*> lockedBullets;
    Enemy* Target = nullptr;
    Turret(/*std::string imgBase,*/std::string imgTurret, float x, float y,/* float radius,*/ int price, float coolDown,float HP);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
	void hit(float damage);
	void heal(float plus);
	void OnHeal();
	int id;
};
#endif // TURRET_HPP
