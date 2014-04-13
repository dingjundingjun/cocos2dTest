#include "Appdelegate.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include <vector>
#include "AppMacros.h"
#include "menuScene/testmenuscene.h"
USING_NS_CC;
using namespace CocosDenshion;

Appdelegate::Appdelegate(void)
{
}


Appdelegate::~Appdelegate(void)
{
}

//��ʼ������
bool Appdelegate::applicationDidFinishLaunching()
{
	//��ʼ�����ݺͳ���
	CCDirector *pDirector = CCDirector::sharedDirector();
	CCEGLView *pEGLView = CCEGLView::sharedOpenGLView();
	pDirector->setOpenGLView(pEGLView);

	std::vector<std::string> searchPaths;

	//������Դ
	CCSize frameSize = pEGLView->getFrameSize();
	CCLOG("resolution width=%f,height=%f frameSize.heigt=%f,frameSize.width=%f",designResolutionSize.width,designResolutionSize.height,frameSize.height,frameSize.width);
	CCLOG("mediumResource width=%f",mediumResource.size.height);
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
	if (frameSize.height > mediumResource.size.height)
	{
		searchPaths.push_back(largeResource.directory);
		CCLOG("mediumResource 11111111111111111111");
		pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is larger than the height of small resource size, select medium resource.
	else if (frameSize.height > smallResource.size.height)
	{
		searchPaths.push_back(mediumResource.directory);

		pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is smaller than the height of medium resource size, select small resource.
	else
	{
		searchPaths.push_back(smallResource.directory);

		pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
	}

	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

	//����fps
	pDirector->setDisplayStats(true);
	pDirector->setAnimationInterval(1.0 / 60);

	//����һ������
	CCScene * pScene =TestMenuScene::scene();

	//�������ܴ����ĳ���
	pDirector->runWithScene(pScene);

	return true;
}

//���ڴ�ǰ̨ת����̨
void Appdelegate::applicationDidEnterBackground()
{
	
}

//���ڴӺ�̨����ǰ̨
void Appdelegate::applicationWillEnterForeground()
{
	CCDirector::sharedDirector()->startAnimation();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
