
#ifndef SPEEDENEMY_HPP
#define SPEEDENEMY_HPP
#include "Enemy.hpp"

class SpeedEnemy : public Enemy {
public:
	SpeedEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // NORMALENEMY_HPP
