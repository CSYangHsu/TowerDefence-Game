
#ifndef ENEMYBULLET_HPP
#define ENEMYBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class enemybullet : public Bullet {
public:
	explicit enemybullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* enemy);
};
#endif // ICECREAMBULLET_HPP
