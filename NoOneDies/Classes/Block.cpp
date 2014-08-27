//
//  Block.cpp
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#include "Block.h"


bool Block::init(){
    Sprite::init();
    
    Size size = Size((rand()%20)+5, (rand()%30)+10);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    setPhysicsBody(PhysicsBody::createBox(size));
    setTextureRect(Rect(0, 0, size.width, size.height));
    setColor(Color3B(0, 0, 0));
    setContentSize(size);
    
    setPositionX(visibleSize.width);
    scheduleUpdate();
    
    getPhysicsBody()->setDynamic(false);
    
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
}


void Block::update(float dt){
    
    this->setPositionX(getPositionX()-4);
    
    if (getPositionX()<0) {
        unscheduleUpdate();
        removeFromParent();
    }
    
}

