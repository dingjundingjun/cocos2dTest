#include "testmenuscene.h"
#include "../AppMacros.h"
#include "../testResource.h"
USING_NS_CC;

CCScene* TestMenuScene::scene()
{
	//创建一个场景
	CCScene *scene = CCScene::create();
	//创建一个层
	TestMenuScene *layer = TestMenuScene::create();
	layer->initLayer();
	//将创建的层添加到场景中
	scene->addChild(layer);
	return scene;
}

void TestMenuScene::initLayer()
{
	//添加退出按钮
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(s_pPathClose,s_pPathClose,this,menu_selector(TestMenuScene::closeCallback));
	CCMenu* pMenu =CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	pCloseItem->setPosition(ccp( VisibleRect::right().x - 30, VisibleRect::top().y - 30));
	addChild(pMenu);
}

void TestMenuScene::closeCallback(CCObject * pSender)
{
	CCLOG("close windows===");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");

#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}