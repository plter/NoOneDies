//
//  GameController.h
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#ifndef __NoOneDies__GameController__
#define __NoOneDies__GameController__

#include <iostream>
#include <cocos2d.h>
#include "Edge.h"
#include "Hero.h"
#include "Block.h"

class Edge;
class Hero;
class Block;

using namespace cocos2d;

class GameController :public Scheduler{
    
private:
    Layer * _layer;
    bool running;
    float _positionY;
    int nextKeyFrameIndex;
    int frameIndex;
    Node * _edge;
    Hero * _hero;
    
private:
    void resetTimer();
    
public:
    virtual bool initWithLayerAndPositionY(Layer * layer,float positionY);
    void onUpdate();
    Node * getEdge();
    void onTouch();
    static GameController* create(Layer * layer,float positionY);
};

#endif /* defined(__NoOneDies__GameController__) */
