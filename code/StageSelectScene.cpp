#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
using namespace std;


#include "LoseScene.hpp"
#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Slider.hpp"
#include "StageSelectScene.hpp"
#include "setting.hpp"

void StageSelectScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    // fIRST BUTTON
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Stage 1", "pirulen.ttf", 48, halfW, halfH / 2, 0, 0, 0, 255, 0.5, 0.5));

    // Second button
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Stage 2", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));

    // setting button
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", w-260, h-130, 200, 70);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 3));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Setting", "pirulen.ttf", 30,w-160, h-95, 0, 0, 0, 255, 0.5, 0.5));




    //btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", w - 300, h-150, 275, 100);
   // btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 2));
    //AddNewControlObject(btn);

    //Engine::ImageButton* btn;
	//btn = new Engine::ImageButton("start_scene/out.png", "start_scene/in.png", halfW - 200, halfH , 400, 100);
	//btn->SetOnClickCallback(std::bind(&SettingScene::BackOnClick, this, 2));
	//AddNewControlObject(btn);


    // TODO 1 (3/3): Move the sliderBGM, sliderSFX to the setting Scene and make sure the background music will be played

    /*Slider *sliderBGM, *sliderSFX;
    sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(std::bind(&StageSelectScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
    sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(std::bind(&StageSelectScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);

    AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));*/
    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
	bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
    //sliderBGM->SetValue(AudioHelper::BGMVolume);
    //sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void StageSelectScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void StageSelectScene::PlayOnClick(int stage) {

    if(stage==1 || stage==2){
        PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
        scene->MapId = stage;
        Engine::GameEngine::GetInstance().ChangeScene("play");
    }
    else if(stage==3){

        SettingScene* scene = dynamic_cast<SettingScene*>(Engine::GameEngine::GetInstance().GetScene("setting"));
        //scene->MapId = stage;
        Engine::GameEngine::GetInstance().ChangeScene("setting");


        //LoseScene* scene = dynamic_cast<LoseScene*>(Engine::GameEngine::GetInstance().GetScene("lose"));
        //Engine::GameEngine::GetInstance().ChangeScene("lose");

    }
}
void StageSelectScene::BGMSlideOnValueChanged(float value) {
    AudioHelper::ChangeSampleVolume(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}
void StageSelectScene::SFXSlideOnValueChanged(float value) {
    AudioHelper::SFXVolume = value;
}
