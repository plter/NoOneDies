#include "StartUpScene.h"
#include "GameOverScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* StartUp::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartUp::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartUp::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    
    addBtns();
    addBtnListeners();
    
    //add logo
    auto logo = Sprite::create("logo.png");
    addChild(logo);
    logo->setPosition(visibleSize.width/2,20);
    logo->setAnchorPoint(Vec2(0.5, 0));
    
    //add title
    auto titleLabel = Label::create();
    titleLabel->setSystemFontSize(40);
    titleLabel->setString("一个都不能死");
    titleLabel->setColor(Color3B::BLACK);
    titleLabel->setPosition(visibleSize.width/2, visibleSize.height - titleLabel->getContentSize().height/2 -20);
    addChild(titleLabel);
    
    //add open source url
    auto osu = Label::create();
    osu->setSystemFontSize(12);
    osu->setString("开源地址：https://github.com/plter/NoOneDies\n极客学院：http://jikexueyuan.com");
    osu->setColor(Color3B::BLACK);
    osu->setPosition(visibleSize.width/2, titleLabel->getPositionY()-titleLabel->getContentSize().height/2-20);
    addChild(osu);
    
    return true;
}


void StartUp::addBtnListeners(){
    touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch* t,Event * e){
        
        if (this->btnTwo->getBoundingBox().containsPoint(t->getLocation())) {
            Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
            Director::getInstance()->replaceScene(Game::createScene(1));
        }else if (this->btnThree->getBoundingBox().containsPoint(t->getLocation())){
            Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
            Director::getInstance()->replaceScene(Game::createScene(2));
        }else if (this->btnFour->getBoundingBox().containsPoint(t->getLocation())){
            Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
            Director::getInstance()->replaceScene(Game::createScene(3));
        }else if (this->btnFive->getBoundingBox().containsPoint(t->getLocation())){
            Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
            Director::getInstance()->replaceScene(Game::createScene(4));
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}


void StartUp::addBtns(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    btnTwo = Label::create();
    btnTwo->setSystemFontSize(32);
    btnTwo->setColor(Color3B::BLACK);
    btnTwo->setString("一个");
    btnTwo->setPosition(visibleSize.width/2, visibleSize.height/2+75);
    addChild(btnTwo);
    
    btnThree = Label::create();
    btnThree->setSystemFontSize(32);
    btnThree->setColor(Color3B::BLACK);
    btnThree->setString("两个");
    btnThree->setPosition(visibleSize.width/2, visibleSize.height/2+25);
    addChild(btnThree);
    
    btnFour = Label::create();
    btnFour->setSystemFontSize(32);
    btnFour->setColor(Color3B::BLACK);
    btnFour->setString("三个");
    btnFour->setPosition(visibleSize.width/2, visibleSize.height/2-25);
    addChild(btnFour);
    
    btnFive = Label::create();
    btnFive->setSystemFontSize(32);
    btnFive->setColor(Color3B::BLACK);
    btnFive->setString("四个");
    btnFive->setPosition(visibleSize.width/2, visibleSize.height/2-75);
    addChild(btnFive);
}

void StartUp::menuCloseCallback(Ref* pSender)
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
