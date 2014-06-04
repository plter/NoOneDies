//
//  Block.h
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#ifndef __NoOneDies__Block__
#define __NoOneDies__Block__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Block:public Sprite {
    
public:
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(Block);
};

#endif /* defined(__NoOneDies__Block__) */
