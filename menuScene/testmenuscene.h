#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
#include "cocos2d.h"
class TestMenuScene : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();
	 CREATE_FUNC(TestMenuScene);
private:
	void initLayer();
	void closeCallback(CCObject * pSender);
};

#endif