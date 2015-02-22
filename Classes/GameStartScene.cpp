#include "GameStartScene.h"
#include "PortScene.h"

GameStartScene::GameStartScene()
{
	auto bgImg = Sprite::create("TitleMain/image 1.jpg");
	bgImg->setPosition(400, 240);
	this->addChild(bgImg);

	auto logo = Sprite::create("TitleMain/image 9.png");
	logo->setPosition(620, 300);
	this->addChild(logo);

	auto startButton = MenuItemImage::create("TitleMain/image 23.png", "TitleMain/image 23.png", CC_CALLBACK_1(GameStartScene::startGame, this));
	startButton->setPosition(600, -50);
	startButton->runAction(Sequence::create(MoveTo::create(1.5,ccp(600,80)),ScaleTo::create(0.15,1.1),ScaleTo::create(0.15,1),NULL));
	auto menu = Menu::create(startButton, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);


}
void GameStartScene::startGame(Ref* pSender)
{
	auto pscene = PortScene::createScene();
	// run
	Director::getInstance()->replaceScene(pscene);
}