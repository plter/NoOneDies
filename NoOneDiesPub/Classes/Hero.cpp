//
//  Hero.cpp
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#include "Hero.h"
#include "FlashTool.h"

class FlashTool;


bool Hero::init(){
    
    Sprite::init();
    
    Size s = Size(44, 52);
    
    setContentSize(s*0.5);
    setPhysicsBody(PhysicsBody::createBox(s*0.5));
    setScale(0.5);
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("hero.json", 0.2f)));
    
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
    
}