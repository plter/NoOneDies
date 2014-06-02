//
//  Edge.h
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#ifndef __NoOneDies__Edge__
#define __NoOneDies__Edge__

#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

class Edge:public Node {
    
public:
    virtual bool init();
    CREATE_FUNC(Edge);
};

#endif /* defined(__NoOneDies__Edge__) */
