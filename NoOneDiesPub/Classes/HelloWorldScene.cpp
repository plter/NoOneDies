#include "HelloWorldScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [this](PhysicsContact & contact){
        Director::getInstance()->replaceScene(GameOverLayer::createScene());
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    gcs.insert(0, GameController::create(this, 30));
    gcs.insert(0, GameController::create(this, 180));
    gcs.insert(0, GameController::create(this, 330));
    gcs.insert(0, GameController::create(this, 480));
    
    scheduleUpdate();
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch * t,Event * e){
        
        for (auto it = this->gcs.begin(); it!=this->gcs.end(); it++) {
            auto gc = *it;
            
            if (gc->getEdge()->getBoundingBox().containsPoint(t->getLocation())) {
                gc->onTouch();
                break;
            }
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void HelloWorld::update(float dt){
    for (auto it = gcs.begin(); it!=gcs.end(); it++) {
        (*it)->onUpdate();
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
