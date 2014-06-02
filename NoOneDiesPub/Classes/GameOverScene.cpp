//
//  GameOverScene.cpp
//  NoOneDiesPub
//
//  Created by plter on 14-6-1.
//
//

#include "GameOverScene.h"

Scene * GameOverLayer::createScene(){
    
    auto s = Scene::create();
    auto l = GameOverLayer::create();
    s->addChild(l);
    return s;
}


bool GameOverLayer::init(){
    LayerColor::initWithColor(Color4B(255, 255, 255, 255));
    
    auto label = Label::create();
    label->setString("Game Over");
    label->setColor(Color3B(0, 0, 0));
    label->setSystemFontSize(50);
    addChild(label);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    label->setPosition(visibleSize.width/2, visibleSize.height/2);
    
    return true;
}