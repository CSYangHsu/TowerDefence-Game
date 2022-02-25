#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <utility>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "WBCellTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "bomb.hpp"
#include "ExplosionEffect.hpp"
#include "Turret.hpp"
#include "DirtyEffect.hpp"
#include "deathturret.hpp"
const int deathturret::Price = 0;
deathturret::deathturret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/redcross.png", x, y, Price, 0.5,0) {
	// Move center downward, since we the turret head is slightly biased upward.

	Anchor.y += 8.0f / GetBitmapHeight();
	id = 14;
}
void Redcross::CreateBullet() {
    return;
}




