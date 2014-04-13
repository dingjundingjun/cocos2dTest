#include "testmenuscene.h"
#include "../AppMacros.h"
#include "../testResource.h"
USING_NS_CC;

CCScene* TestMenuScene::scene()
{
	//����һ������
	CCScene *scene = CCScene::create();
	//����һ����
	TestMenuScene *layer = TestMenuScene::create();
	layer->initLayer();
	//�������Ĳ���ӵ�������
	scene->addChild(layer);
	return scene;
}

void TestMenuScene::initLayer()
{
	//����˳���ť
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