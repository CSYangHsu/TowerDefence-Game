#ifndef NORMALENEMY_HPP
#define NORMALENEMY_HPP
#include "Enemy.hpp"

class NormalEnemy : public Enemy {
public:
	NormalEnemy(int x, int y);
	void CreateBullet() override;
//	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
};
#endif // NORMALENEMY_HPP
