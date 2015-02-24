#include "CharacterCard.h"

CharacterCard::CharacterCard()
{
	initCard();

}
CharacterCard::CharacterCard(bool isEnemy, std::string resourcefolder)
{
	initCard();
	this->isEnemy = isEnemy;
	updateCharacter(resourcefolder, BrokenType::normal);
}
CharacterCard::CharacterCard(CharacterInfo* info)
{
	initCard();
	updateCharacter(info->resourceFolder, info->brokenType);
}
CharacterCard::CharacterCard(std::string resourcefolder)
{
	initCard();
	updateCharacter(resourcefolder, BrokenType::normal);
}

void CharacterCard::initCard()
{
	this->isEnemy = false;
	mainImage = Sprite::create();
	shader = Sprite::create();
	brokenMark = Sprite::create();
	this->addChild(mainImage);
	this->addChild(brokenMark);
	this->addChild(shader);
}
void CharacterCard::updateCharacter(std::string resourceFolder, BrokenType type)
{
	
	if (isEnemy)
	{
		mainImage->setTexture("Enemy/" + resourceFolder + "/image 1.png");
		if (Sprite::create("Enemy/" + resourceFolder + "/image 1.png") == nullptr)
			mainImage->setTexture("Enemy/" + resourceFolder + "/image 1.jpg");
	}
		
	else if (type == BrokenType::normal || type == BrokenType::tiny)
	{
		mainImage->setTexture("Character/" + resourceFolder + "/image 1.png");
		if (Sprite::create("Character/" + resourceFolder + "/image 1.png") == nullptr)
			mainImage->setTexture("Character/" + resourceFolder + "/image 1.jpg");
	}

	else
	{
		mainImage->setTexture("Character/" + resourceFolder + "/image 3.png");
		if (Sprite::create("Character/" + resourceFolder + "/image 3.png") == nullptr)
			mainImage->setTexture("Character/" + resourceFolder + "/image 3.jpg");
	}
	setBrokenMark(type);
}
void CharacterCard::setBrokenMark(BrokenType brokenType)
{
	switch (brokenType)
	{
	case BrokenType::tiny:
		brokenMark->setTexture("commonAssets/image 344.png");
		shader->setTexture("commonAssets/image 367.png");
		break;
	case BrokenType::mid:
		brokenMark->setTexture("commonAssets/image 346.png");
		shader->setTexture("commonAssets/image 369.png");
		break;
	case BrokenType::large:
		brokenMark->setTexture("commonAssets/image 348.png");
		shader->setTexture("commonAssets/image 371.png");
		break;
	case BrokenType::drown:
		brokenMark->setTexture("commonAssets/image 350.png");
		mainImage->setColor(Color3B(90, 90, 96));//GRAY
		shader->setTexture("commonAssets/image 371.png");
		break;
	default:
		break;
	}
}
