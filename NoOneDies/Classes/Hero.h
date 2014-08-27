//
//  Hero.h
//  NoOneDies
//
//  Created by plter on 14-6-2.
//
//

#ifndef __NoOneDies__Hero__
#define __NoOneDies__Hero__

#include <iostream>

#include <cocos2d.h>

USING_NS_CC;

class Hero:public Sprite {
    
public:
    virtual bool init();
    CREATE_FUNC(Hero);
};

#endif /* defined(__NoOneDies__Hero__) */
