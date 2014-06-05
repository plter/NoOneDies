//
//  GameScene.h
//  NoOneDiesPub
//
//  Created by plter on 14-6-4.
//
//

#include <cocos2d.h>
#include "GameController.h"

USING_NS_CC;

class Game:public LayerColor {
    
private:
    Vector<GameController*> gcs;
    int _heroCount;
    EventListenerPhysicsContact * contactListener;
    EventListenerTouchOneByOne * touchListener;
    
private:
    void addContactListener();
    void addUserTouchListener();
    void addGcs(int heroCount);
    
public:
    virtual bool initWithHeroCount(int heroCount);
    virtual void update(float dt);
    static Game * create(int heroCount);
    static Scene* createScene(int heroCount);
};