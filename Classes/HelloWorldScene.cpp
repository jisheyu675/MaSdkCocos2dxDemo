/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("msSdk cocos demo", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//    if (sprite == nullptr)
//    {
//        problemLoading("'HelloWorld.png'");
//    }
//    else
//    {
//        // position the sprite on the center of the screen
//        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//        // add the sprite as a child to this layer
//        this->addChild(sprite, 0);
//    }


    auto msSdkInit = MenuItemImage::create(
            "init.png",
            "init.png",
            CC_CALLBACK_1(HelloWorld::msSdkInit, this));

    msSdkInit->setPosition(Point(100, 200));
    auto msSdkInitMenu = Menu::create(msSdkInit, NULL);
    msSdkInitMenu->setPosition(Point::ZERO);
    this->addChild(msSdkInitMenu, 1);


    auto setInterCallback = MenuItemImage::create(
            "interLoad.png",
            "interLoad.png",
            CC_CALLBACK_1(HelloWorld::setInterLoadCallback, this));

    setInterCallback->setPosition(Point(100, 150));
    auto setInterCallbackMenu = Menu::create(setInterCallback, NULL);
    setInterCallbackMenu->setPosition(Point::ZERO);
    this->addChild(setInterCallbackMenu, 1);

    auto showInter = MenuItemImage::create(
            "showInter.png",
            "showInter.png",
            CC_CALLBACK_1(HelloWorld::showInterstitialAds, this));

    showInter->setPosition(Point(200, 150));
    auto showInterMenu = Menu::create(showInter, NULL);
    showInterMenu->setPosition(Point::ZERO);
    this->addChild(showInterMenu, 1);


    auto setRWDCallback = MenuItemImage::create(
            "RwdLoad.png",
            "RwdLoad.png",
            CC_CALLBACK_1(HelloWorld::setRwdLoadCallback, this));

    setRWDCallback->setPosition(Point(100, 100));
    auto setRWDCallbackMenu = Menu::create(setRWDCallback, NULL);
    setRWDCallbackMenu->setPosition(Point::ZERO);
    this->addChild(setRWDCallbackMenu, 1);


    auto showRwd = MenuItemImage::create(
            "showRwd.png",
            "showRwd.png",
            CC_CALLBACK_1(HelloWorld::showRwd, this));

    showRwd->setPosition(Point(200, 100));
    auto showRwdMenu = Menu::create(showRwd, NULL);
    showRwdMenu->setPosition(Point::ZERO);
    this->addChild(showRwdMenu, 1);

//    auto setInterCallback = MenuItemImage::create(
//            "HelloWorld.png",
//            "HelloWorld.png",
//            CC_CALLBACK_1(HelloWorld::setInterLoadCallback, this));
//
//    setInterCallback->setPosition(Point(60, 200));
//    auto setInterCallbackMenu = Menu::create(setInterCallback, NULL);
//    setInterCallbackMenu->setPosition(Point::ZERO);
//    this->addChild(setInterCallbackMenu, 1);


//    auto adjustButton = MenuItemImage::create(
//            "HelloWorld.png",
//            "HelloWorld.png", CC_CALLBACK_1(HelloWorld::showInterstitialAds, this));
//    adjustButton->setPosition(Point(200, 220));
//    auto adjustMenu = Menu::create(adjustButton, NULL);
//    adjustMenu->setPosition(Point::ZERO);
//    this->addChild(adjustMenu, 1);


    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::msSdkInit(Ref* pSender) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniMethodInfo method;

    bool b = JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "initMsSdk", "()V");
    if (b)
    {
        method.env->CallStaticVoidMethod(method.classID, method.methodID);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}


void HelloWorld::initInterstitial(std::string placement) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo method;
    if (JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "initInter", "(Ljava/lang/String;)V"))
    {
        jstring arg = method.env->NewStringUTF(placement.c_str());
        /*std::string jstr = Object::env->NewStringUTF(adjustId);*/
        method.env->CallStaticVoidMethod(method.classID, method.methodID, arg);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}

void HelloWorld::setInterLoadCallback(Ref* pSender) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniMethodInfo method;

    bool b = JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "setInterLoadCallback", "()V");
    if (b)
    {
        method.env->CallStaticVoidMethod(method.classID, method.methodID);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}

void HelloWorld::showInterstitialAds(Ref* pSender) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniMethodInfo method;

    bool b = JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "showInterAds", "()V");
    if (b)
    {
        method.env->CallStaticVoidMethod(method.classID, method.methodID);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}


void HelloWorld::initRW() {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniMethodInfo method;

    bool b = JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "initRW", "()V");
    if (b)
    {
        method.env->CallStaticVoidMethod(method.classID, method.methodID);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}


void HelloWorld::setRwdLoadCallback(Ref* pSender) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    JniMethodInfo method;

    bool b = JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "setRwdLoadCallback", "()V");
    if (b)
    {
        method.env->CallStaticVoidMethod(method.classID, method.methodID);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}


void HelloWorld::showRwd(Ref* pSender) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo method;
    if (JniHelper::getStaticMethodInfo(method, "org.cocos2dx.sdk.MsSdkUtil", "showRwd", "(Ljava/lang/String;)V"))
    {
        jstring arg = method.env->NewStringUTF("hall_rwd");
        /*std::string jstr = Object::env->NewStringUTF(adjustId);*/
        method.env->CallStaticVoidMethod(method.classID, method.methodID, arg);
    }
    else {
        CCLOG("====> %s %d: error to get methodInfo", __FILE__, __LINE__);
    }
#endif
}
