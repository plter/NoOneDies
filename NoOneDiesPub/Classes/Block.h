//
//  Block.h
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#ifndef __NoOneDies__Block__
#define __NoOneDies__Block__


#include <cocos2d.h>

USING_NS_CC;

namespace game {
    
    class Block:public Sprite {
        
    public:
        virtual bool init();
        virtual void update(float dt);
        CREATE_FUNC(Block);
    };
}

#endif /* defined(__NoOneDies__Block__) */
