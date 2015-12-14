//
//  GameScene.cpp
//  NoOneDiesPub
//
//  Created by plter on 14-6-4.
//
//

#include "GameScene.h"
#include "GameOverScene.h"

Scene * Game::createScene(int heroCount){
    auto s = Scene::createWithPhysics();
    s->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    s->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    auto l = Game::create(heroCount);
    s->addChild(l);
    return s;
}

Game* Game::create(int heroCount){
    auto _ins = new Game();
    _ins->initWithHeroCount(heroCount);
    _ins->autorelease();
    return _ins;
}


bool Game::initWithHeroCount(int heroCount){
    LayerColor::initWithColor(Color4B(255, 255, 255, 255));
    
    _heroCount = heroCount;
    
    addContactListener();
    addUserTouchListener();
    addGcs(heroCount);
    
    scheduleUpdate();
    return true;
}

void Game::addGcs(int heroCount){
    Size size = Director::getInstance()->getVisibleSize();
    float startPosition = 30;
    float gap = (size.height-startPosition)/heroCount;
    for (int i=0; i<heroCount; i++) {
        gcs.insert(0, GameController::create(this, startPosition+gap*i));
    }
}

void Game::addContactListener(){
    contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [this](PhysicsContact & contact){
        
        this->unscheduleUpdate();
        
        auto dir = Director::getInstance();
        dir->getEventDispatcher()->removeEventListener(contactListener);
        dir->getEventDispatcher()->removeEventListener(touchListener);
        dir->replaceScene(GameOver::createScene(_heroCount,20));
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}


void Game::addUserTouchListener(){
    touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch * t,Event * e){
        
        for (auto it = this->gcs.begin(); it!=this->gcs.end(); it++) {
            auto gc = *it;
            
            if (gc->getEdge()->getBoundingBox().containsPoint(t->getLocation())) {
                gc->onTouch();
                break;
            }
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void Game::update(float dt){
    for (auto it = gcs.begin(); it!=gcs.end(); it++) {
        (*it)->onUpdate();
    }
}
