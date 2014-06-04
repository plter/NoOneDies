//
//  GameOverScene.cpp
//  NoOneDiesPub
//
//  Created by plter on 14-6-1.
//
//

#include "GameOverScene.h"

Scene * GameOver::createScene(int currentHeroCount,double score){
    
    auto s = Scene::create();
    auto l = GameOver::create(currentHeroCount,score);
    s->addChild(l);
    return s;
}

GameOver * GameOver::create(int currentHeroCount, double score){
    auto _ins = new GameOver();
    _ins->initWithCurrentHeroCountAndScore(currentHeroCount, score);
    _ins->autorelease();
    return _ins;
}


bool GameOver::initWithCurrentHeroCountAndScore(int currentHeroCount, double score){
    LayerColor::initWithColor(Color4B(255, 255, 255, 255));
    
    _currentHeroCount = currentHeroCount;
    _score = score;
    
    auto label = Label::create();
    label->setString("Game Over");
    label->setColor(Color3B(0, 0, 0));
    label->setSystemFontSize(50);
    addChild(label);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    label->setPosition(visibleSize.width/2, visibleSize.height/2);
    
    return true;
}