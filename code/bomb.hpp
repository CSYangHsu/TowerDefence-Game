#ifndef BOMB_HPP
#define BOMB_HPP
#include "Turret.hpp"

class bomb: public Turret {
public:
	static const int Price;
    bomb(float x, float y);
    void CreateBullet() ;
	//void OnExplode() override;
};
#endif // WBCELLTURRET_HPP

