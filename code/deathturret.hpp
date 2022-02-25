
#ifndef DEATHTURRET_HPP
#define DEATHTURRET_HPP
#include "Turret.hpp"

class deathturret: public Turret {
public:
	static const int Price;
    deathturret(float x, float y);
    void CreateBullet() ;
	//void OnExplode() override;
};
#endif // WBCELLTURRET_HPP


