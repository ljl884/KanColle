#include "AppDelegate.h"
#include "GameScene.h"
#include "PortScene.h"
#include "GameStartScene.h"
#include "BattleModel.h"
#include "GameModel.h"
USING_NS_CC;

#define DEBUG_MODE false

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("Kancolle", Rect(0, 0, 800, 480));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(800, 480, ResolutionPolicy::EXACT_FIT);
	glview->setFrameSize(800, 480);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
	

	GameModel::getInstance()->setupInitData();

	if (DEBUG_MODE){
		auto s = PortScene::createScene();
		s->setCurrentLayer(organize);
		director->runWithScene(s);

	}
	else{
		// setRandomSeed();
		//auto model = new BattleModel();
		//auto scene = new GameScene(model);
		//auto pscene = PortScene::createScene();
		auto sscene = new GameStartScene();
		director->runWithScene(sscene);
	}

    // run
   

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::setRandomSeed()
{
	time_t tt;
	time(&tt);
	struct tm * now;
	//获得本地时间//
	now = localtime(&tt);
	timeval tv;
	//CCTime gettimeofdayCocos2d(&tv,NULL);
	gettimeofday(&tv, NULL);
	//都转化为毫秒//
	unsigned long reed = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	//srand()中传入一个随机数种子//
	srand(reed);
}