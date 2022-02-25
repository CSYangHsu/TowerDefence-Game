
#ifndef STOPTURRET_HPP
#define STOPTURRET_HPP
#include "Turret.hpp"

class StopTurret: public Turret {
public:
	static const int Price;
    StopTurret(float x, float y);
	void CreateBullet() override;
};
#endif // WBCELLTURRET_HPP
