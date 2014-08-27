//
//  GameController.h
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#ifndef __NoOneDies__GameController__
#define __NoOneDies__GameController__

#include <iostream>
#include "Edge.h"
#include "Hero.h"
#include "Block.h"

#include <cocos2d.h>

USING_NS_CC;

class GameController:public Ref {
private:
    Layer * _layer;
    float _positionY;
    Size visibleSize;
    int currentFrameIndex;
    int nextFrameCount;
    Edge * edge;
    Hero * hero;
    
private:
    void resetFrames();
    void addBlock();
    
public:
    virtual bool init(Layer * layer,float positionY);
    void onUpdate(float dt);
    bool hitTestPoint(Vec2 point);
    void onUserTouch();
    static GameController* create(Layer * layer,float positionY);
};

#endif /* defined(__NoOneDies__GameController__) */
