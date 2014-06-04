//
//  FlashTool.h
//  NoOneDies
//
//  Created by plter on 14-5-29.
//
//

#ifndef __NoOneDies__FlashTool__
#define __NoOneDies__FlashTool__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class FlashTool {
    
public:
    static Animate * readJsonSpriteSheet(std::string jsonFile,float delayPerUnit);
};


#endif /* defined(__NoOneDies__FlashTool__) */
