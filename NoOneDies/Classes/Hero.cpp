//
//  Hero.cpp
//  NoOneDies
//
//  Created by plter on 14-6-2.
//
//

#include "Hero.h"
#include "FlashTool.h"


bool Hero::init(){
    Sprite::init();
    
    Size s = Size(44, 52);
    
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));
    
    setPhysicsBody(PhysicsBody::createBox(s));
    setContentSize(s);
    
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}