#include <allegro5/base.h>
#include <cmath>
#include <string>
#include "StopTurret.hpp"
#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "WBCellTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "FreezeTurret.hpp"
const int StopTurret::Price = 20;
StopTurret::StopTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-4.png", x, y, Price, 0.5,6) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
	id=5;
}
void StopTurret::CreateBullet() {

}

