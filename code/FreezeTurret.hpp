#ifndef FREEZETURRET_HPP
#define FREEZETURRET_HPP
#include "Turret.hpp"

class FreezeTurret: public Turret {
public:
	static const int Price;
    FreezeTurret(float x, float y);
	void CreateBullet() override;
};
#endif // WBCELLTURRET_HPP
