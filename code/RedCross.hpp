
#ifndef REDCROSS_HPP
#define REDCROSS_HPP
#include "Turret.hpp"

class Redcross: public Turret {
public:
	static const int Price;
    Redcross(float x, float y);
    void CreateBullet() ;
	//void OnExplode() override;
};
#endif // WBCELLTURRET_HPP

