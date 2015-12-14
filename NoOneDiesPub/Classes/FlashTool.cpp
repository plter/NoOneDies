//
//  FlashTool.cpp
//  NoOneDies
//
//  Created by plter on 14-5-29.
//
//

#include "FlashTool.h"
#include <json/document.h>


Animate * FlashTool::readJsonSpriteSheet(std::string jsonFile,float delayPerUnit){
    
    rapidjson::Document doc;
    std::string fileContent = FileUtils::getInstance()->getStringFromFile(jsonFile);
    fileContent.erase(0,fileContent.find_first_of('{'));
    
    doc.Parse<0>(fileContent.c_str());
    
    std::string imgFileName = doc["meta"]["image"].GetString();
    
    auto &frames = doc["frames"];
    auto sfc = SpriteFrameCache::getInstance();
    
    Vector<AnimationFrame*> animFrames;
    for (auto m=frames.MemberBegin(); m!=frames.MemberEnd(); m++) {
        auto frameName = m->name.GetString();
        auto & frameProperties = m->value["frame"];
        auto & spriteSourceSize = m->value["spriteSourceSize"];
        
        auto sf = sfc->getSpriteFrameByName(frameName);
        if (!sf) {
            sf = SpriteFrame::create(imgFileName, Rect(frameProperties["x"].GetInt(), frameProperties["y"].GetInt(), frameProperties["w"].GetInt(), frameProperties["h"].GetInt()), m->value["rotated"].GetBool(), Vec2(spriteSourceSize["x"].GetInt(), spriteSourceSize["y"].GetInt()), Size(spriteSourceSize["w"].GetInt(), spriteSourceSize["h"].GetInt()));
            sfc->addSpriteFrame(sf, frameName);
        }
        animFrames.pushBack(AnimationFrame::create(sf, delayPerUnit, ValueMapNull));
    }
    
    Animation * animation = Animation::create(animFrames,delayPerUnit);
    return Animate::create(animation);
}