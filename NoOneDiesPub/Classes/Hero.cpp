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
    
    setContentSize(Size(44, 52));
    setPhysicsBody(PhysicsBody::createBox(Size(44, 52)));
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("hero.json", 0.2f)));
    
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
    
}