//
//  Edge.cpp
//  NoOneDies
//
//  Created by plter on 14-5-30.
//
//

#include "Edge.h"


bool Edge::init(){
    Node::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setContentSize(visibleSize);
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
    
    return true;
}