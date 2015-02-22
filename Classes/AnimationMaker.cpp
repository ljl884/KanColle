#include "AnimationMaker.h"

void DamageAnimation(Sprite* sprite,float delay);
bool AnimationMaker::damageNumberInitialized = false;
void AnimationMaker::playPlaneAnimation(Node* parent,float delay)
{
	Sprite *plane1 = Sprite::create("item_up/055.png");
	Sprite *plane2 = Sprite::create("item_up/113.png");
	Sprite *plane3 = Sprite::create("item_up/024.png");
	plane1->setScale(0.5);
	plane2->setScale(0.7);
	plane3->setScale(0.6);


	plane1->setPosition(-50, 420);
	plane2->setPosition(-100, 100);
	plane3->setPosition(-100, 0);
	plane1->setZOrder(3);
	plane2->setZOrder(3);
	plane3->setZOrder(3);
	parent->addChild(plane1);
	parent->addChild(plane2);
	parent->addChild(plane3);

	FiniteTimeAction *p1move1 = MoveTo::create(0.3, Point(380, 380));
	FiniteTimeAction *p1move2 = MoveTo::create(0.3, Point(380, 370));
	FiniteTimeAction *p1move4 = MoveTo::create(0.6, Point(1000, 350));
	Sequence *s1 = Sequence::create(DelayTime::create(delay), p1move1, p1move2, p1move1, p1move4, NULL);
	plane1->runAction(s1);

	FiniteTimeAction *p2move1 = MoveTo::create(0.3, Point(200, 150));
	FiniteTimeAction *p2move2 = MoveTo::create(0.3, Point(200, 130));
	FiniteTimeAction *p2move4 = MoveTo::create(0.6, Point(1000, 200));
	Sequence *s2 = Sequence::create(DelayTime::create(delay), p2move1, p2move2, p2move1, p2move4, NULL);
	plane2->runAction(s2);

	FiniteTimeAction *p3move1 = MoveTo::create(0.3, Point(80, 60));
	FiniteTimeAction *p3move2 = MoveTo::create(0.3, Point(80, 40));
	FiniteTimeAction *p3move4 = MoveTo::create(0.6, Point(1000, 150));
	Sequence *s3 = Sequence::create(DelayTime::create(delay), p3move1, p3move2, p3move1, p3move4, NULL);
	plane3->runAction(s3);
}
float AnimationMaker::FlyToPositionAndFadeOut(Node* target, float delay, Point position,float stayingTime)
{
	FiniteTimeAction *fadeIn = FadeIn::create(0.1);
	FiniteTimeAction *moveToCenter = MoveTo::create(0.2,position);
	FiniteTimeAction *fadeOut = FadeOut::create(0.1);
	Sequence *seq = Sequence::create(DelayTime::create(delay), fadeIn, moveToCenter, DelayTime::create(stayingTime), fadeOut, NULL);
	target->runAction(seq);
	return delay + 0.4;
}
float AnimationMaker::FlyToCenterLeftAndFadeOut(Node* target,float delay)
{
	return FlyToPositionAndFadeOut(target, delay, Point(220, 240),1);
}
void AnimationMaker::playAirBattleAnimation(Node* parent, float delay)
{
	int planeNumber = 3;
	int x = 30;
	for (int i = 0; i < planeNumber; i++)
	{
		
		Sprite *plane1 = Sprite::create("BattleMain/image 469.png");
		
		
		plane1->setPosition(-50+x*(i+5), 30-i*5);
		plane1->setScale(0.7);
		x = x*(-1);

		plane1->setOpacity(0);
	

		FiniteTimeAction *fadeIn1 = FadeIn::create(0.2);
	
		plane1->runAction(Sequence::create(DelayTime::create(delay-0.3), fadeIn1, NULL));
	
		
		FiniteTimeAction *move = MoveBy::create(0.6 - i*0.05, ccp(200, -40));
		FiniteTimeAction *move2 = MoveBy::create(0.9 - i*0.02, Point(200, 15));
		FiniteTimeAction *move3 = MoveBy::create(0.8, Point(100+i*10, 15 ));
		FiniteTimeAction *move4 = MoveBy::create(0.2, Point(200, 40 ));
		FiniteTimeAction *move5 = MoveBy::create(0.6-i*0.02, Point(500, 80 ));
		plane1->runAction(Sequence::create(DelayTime::create(delay + 0.05*i), move, move2, move3, move4, move5,NULL));
		plane1->setPosition(100 - 30 * i, 300 - 35 * i);
		parent->addChild(plane1);
	}
}
void AnimationMaker::makeExplodeAnimation()
{
	Vector<SpriteFrame*> animFrames;
	CCAnimation *animation;
	for (int i = 386; i <= 414; i += 2)
	{
		Image* image = new Image();
		std::string numStr = int2str(i);
		image->initWithImageFile("BattleMain/image "+numStr+".png");
		CCTexture2D *texture = new Texture2D();
		int x = image->getWidth();
		int y = image->getHeight();
		texture->initWithImage(image);
		CCSpriteFrame * frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(0, 0, x, y));
		animFrames.pushBack(frame);
		animation = CCAnimation::createWithSpriteFrames(animFrames, 0.03f);
	}
	AnimationCache::sharedAnimationCache()->addAnimation(animation, "explode");
	
	
	
}

std::string  AnimationMaker::int2str(int &i) {
	std::string s;
	std::stringstream ss(s);
	ss << i;

	return ss.str();
}
float AnimationMaker::playExplodeAnimation(Node* parent, float delay, Point position, int times)
{
	Point p = position;
	for (int i = 0; i < times; i++)
	{
		p = ccp(position.x + i * 15, p.y);
		playExplodeAnimation(parent, delay + i*0.15, p);
		p = ccp(position.x - i * 15, p.y);
		playExplodeAnimation(parent, delay + i*0.15, p);
	}
	return delay+(0.15 + 0.45+0.1)*times;
}
float AnimationMaker::playExplodeAnimation(Node* parent, float delay, Point position)
{
	Animation *animation = nullptr;
	animation = CCAnimationCache::sharedAnimationCache()->getAnimation("explode");
	if (animation == nullptr)
	{
		makeExplodeAnimation();
		animation = CCAnimationCache::sharedAnimationCache()->getAnimation("explode");		
	}
	Animate * animate = Animate::create(CCAnimationCache::sharedAnimationCache()->getAnimation("explode"));
	
		
	Sprite * node = Sprite::create();
	FiniteTimeAction *fadeOut = FadeOut::create(0.1);
	node->setPosition(position);
	parent->addChild(node);
	node->runAction(Sequence::create(DelayTime::create(delay), animate, fadeOut, NULL));
	return delay+0.45 + 0.1;
	
}
void AnimationMaker::playShakingAnimation(Node* target, float delay)
{
	FiniteTimeAction *move1 = MoveBy::create(0.05, ccp(15, 0));
	FiniteTimeAction *move2 = MoveBy::create(0.1, ccp(-30, 0));
	target->runAction(Sequence::create(DelayTime::create(delay), move1, move2, move1, move1, move2,move1, NULL));
}
void  AnimationMaker::playDamageNumberAnimation(Point position, Node*parent, float delay, bool miss, bool critical, int damage, CallFunc* callback)
{
	if (damageNumberInitialized == false)
	{
		InitDamageNumber();
	}
	if (miss)
	{
		Sprite *miss = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey("miss"));		
		parent->addChild(miss);
		miss->setPosition(position);
		DamageAnimation(miss, delay);		
	}
	else
	{
		Sprite*tempSprite = Sprite::create();
		parent->addChild(tempSprite);
		tempSprite->runAction(Sequence::create(DelayTime::create(delay), callback, NULL));
		std::string key;
		std::string numStr;
		if (critical)
		{
			key = "critical";
			Sprite *critical = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey(key));
			parent->addChild(critical);
			critical->setPosition(position.x,position.y-10);
			DamageAnimation(critical, delay);
			position = ccp(position.x, position.y + 10);

		}
		else
			key = "damage";
			
		int remainingdamage = damage;
		if (damage>999)
		{
			int i = (damage / 1000) % 10;
			numStr = int2str(i);
			remainingdamage = damage - 1000 * i;
			std::string tempKey = key + numStr;
			Sprite* damage = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey(tempKey));
			parent->addChild(damage);
			damage->setPosition(position.x - 26, position.y);
			DamageAnimation(damage, delay);

		}
		if (damage>99)
		{
			int i = (damage/100)%10;
			numStr = int2str(i);
			remainingdamage = remainingdamage - 100 * i;
			std::string tempKey = key + numStr;
			Sprite* damage = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey(tempKey));
			parent->addChild(damage);
			damage->setPosition(position.x-13,position.y);
			DamageAnimation(damage, delay);
			
		}
		if (damage>9)
		{
			int i = (remainingdamage / 10) % 10;
			remainingdamage = remainingdamage - i * 10;
			numStr = int2str(i);
			std::string tempKey = key + numStr;			
			Sprite* damage = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey(tempKey));
			parent->addChild(damage);
			damage->setPosition(position);
			DamageAnimation(damage, delay);
		}
		numStr = int2str(remainingdamage);
		std::string tempKey = key + numStr;
		Sprite* damage = Sprite::createWithTexture(TextureCache::sharedTextureCache()->getTextureForKey(tempKey));
		parent->addChild(damage);
		damage->setPosition(position.x+13,position.y);
		DamageAnimation(damage, delay);
		
	}
}
void AnimationMaker::InitDamageNumber()
{
	for (int i = 616,j=0; i <= 636; i += 2)
	{
		Image* image = new Image();
		std::string fileStr = int2str(i);
		image->initWithImageFile("BattleMain/image " + fileStr + ".png");		
		std::string numStr = "damage"+int2str(j);
		if (i == 636)
			numStr = "miss";
		Texture2D *texture = TextureCache::sharedTextureCache()->addImage(image,numStr);
		j++;
	}
	for (int i = 638, j = 0; i <= 658; i += 2)
	{
		Image* image = new Image();
		std::string fileStr = int2str(i);
		image->initWithImageFile("BattleMain/image " + fileStr + ".png");
		std::string numStr = "critical" + int2str(j);
		if (i == 658)
			numStr = "invaliddamage";
		Texture2D *texture = TextureCache::sharedTextureCache()->addImage(image, numStr);
		j++;
	}
	Image* image = new Image();
	image->initWithImageFile("BattleMain/image 661.png");
	Texture2D *texture = TextureCache::sharedTextureCache()->addImage(image, "critical");
	damageNumberInitialized = true;

}
void DamageAnimation(Sprite* sprite,float delay)
{
	FiniteTimeAction *fadeIn = FadeIn::create(0.05);
	FiniteTimeAction *moveUp = MoveBy::create(0.1, ccp(0, 3));
	FiniteTimeAction *moveDown = MoveBy::create(0.1, ccp(0, -3));
	FiniteTimeAction *fadeOut = FadeOut::create(0.3);
	Action *action = Sequence::create(DelayTime::create(delay), fadeIn, moveUp, moveDown, moveUp, moveDown, fadeOut, NULL);
	sprite->setOpacity(0);
	sprite->runAction(action);

}