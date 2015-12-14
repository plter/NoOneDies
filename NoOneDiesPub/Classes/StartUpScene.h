#pragma once

#include "cocos2d.h"
#include "GameController.h"

USING_NS_CC;

class GameController;

class StartUp : public cocos2d::LayerColor
{
    
private:
    Label *btnTwo,*btnThree,*btnFour,*btnFive;
    EventListenerTouchOneByOne * touchListener;
    
private:
    void addBtns();
    void addBtnListeners();
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartUp);
};

