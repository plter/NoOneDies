//
//  Block.cpp
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#include "Block.h"


bool Block::init(){
    Sprite::init();
    Size s = Size(5+rand()%25, rand()%30+10);
    
    setPositionX(Director::getInstance()->getVisibleSize().width);
    
    setContentSize(s);
    setTextureRect(Rect(0, 0, s.width, s.height));
    setColor(Color3B(0, 0, 0));
    
    scheduleUpdate();
    
    setPhysicsBody(PhysicsBody::createBox(s));
    getPhysicsBody()->setDynamic(false);
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
}


void Block::update(float dt){
    
    setPositionX(getPositionX()-3.5);
    
    if (getPositionX()<0) {
        unscheduleUpdate();
        removeFromParent();
    }
}