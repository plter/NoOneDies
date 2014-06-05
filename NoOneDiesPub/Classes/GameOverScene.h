//
//  GameOverScene.h
//  NoOneDiesPub
//
//  Created by plter on 14-6-1.
//
//

#ifndef __NoOneDiesPub__GameOverScene__
#define __NoOneDiesPub__GameOverScene__

#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

class GameOver:public LayerColor {
    
private:
    int _currentHeroCount;
    double _score;
    Label *btnReplay,*btnGoHome;
    EventListenerTouchOneByOne * touchListener;
    
private:
    Label * createButton(std::string text,float fontSize);
    
public:
    virtual bool initWithCurrentHeroCountAndScore(int currentHeroCount,double score);
    
    static Scene* createScene(int currentHeroCount,double score);
    
    static GameOver* create(int currentHeroCount,double score);
};


#endif /* defined(__NoOneDiesPub__GameOverScene__) */
