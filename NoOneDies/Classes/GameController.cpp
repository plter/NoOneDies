//
//  GameController.cpp
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#include "GameController.h"


GameController* GameController::create(cocos2d::Layer *layer, float positionY){
    
    auto _ins = new GameController();
    _ins->init(layer, positionY);
    _ins->autorelease();
    return _ins;
}


bool GameController::init(cocos2d::Layer *layer, float positionY){
    
    _layer = layer;
    _positionY = positionY;
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //add edge
    edge = Edge::create();
    edge->setPosition(visibleSize.width/2, visibleSize.height/2+positionY);
    edge->setContentSize(visibleSize);
    layer->addChild(edge);
    
    //add ground
    auto ground = Sprite::create();
    ground->setColor(Color3B(0, 0, 0));
    ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
    ground->setPosition(visibleSize.width/2,1.5+positionY);
    layer->addChild(ground);
    
    //add hero
    hero = Hero::create();
    hero->setPosition(50, hero->getContentSize().height/2+positionY);
    layer->addChild(hero);
    
    
    resetFrames();
    return true;
}

void GameController::resetFrames(){
    currentFrameIndex = 0;
    nextFrameCount = (rand()%120) + 100;
}


void GameController::addBlock(){
    auto b = Block::create();
    _layer->addChild(b);
    b->setPositionY(b->getContentSize().height/2+_positionY);
}


void GameController::onUpdate(float dt){
    currentFrameIndex++;
    
    if (currentFrameIndex>=nextFrameCount) {
        resetFrames();
        
        addBlock();
    }
}

bool GameController::hitTestPoint(cocos2d::Vec2 point){
    return edge->getBoundingBox().containsPoint(point);
}

void GameController::onUserTouch(){
    hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}
