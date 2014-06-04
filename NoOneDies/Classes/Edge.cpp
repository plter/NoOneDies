//
//  Edge.cpp
//  NoOneDies
//
//  Created by plter on 14-6-2.
//
//

#include "Edge.h"


bool Edge::init(){
    
    Node::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
    setContentSize(visibleSize);
    
    return true;
}