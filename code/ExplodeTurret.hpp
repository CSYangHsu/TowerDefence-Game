#ifndef EXPLODETURRET_HPP
#define EXPLODETURRET_HPP
#include "Turret.hpp"

class ExplodeTurret: public Turret {
public:
	static const int Price;
    ExplodeTurret(float x, float y);
	void CreateBullet() override;
	void OnExplode() override;
    int r;
	//void Draw() override;
};
#endif // WBCELLTURRET_HPP
