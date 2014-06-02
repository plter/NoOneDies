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

class GameOverLayer:public LayerColor {
    
public:
    virtual bool init();
    
    static Scene* createScene();
    
    CREATE_FUNC(GameOverLayer);
};


#endif /* defined(__NoOneDiesPub__GameOverScene__) */
