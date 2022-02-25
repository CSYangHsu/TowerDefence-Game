#ifndef KILLER_HPP
#define KILLER_HPP
#include "Sprite.hpp"

class PlayScene;

class Killer: public Engine::Sprite {
protected:
	PlayScene* getPlayScene();
public:
    Killer(float x, float y, int i);
	void Update(float deltaTime) override;
	int index;
	bool sosuper;
};
#endif // KILLER_HPP
