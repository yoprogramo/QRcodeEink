#include <Arduino.h>
#include "qrencode.h"
#include "qrcodeeink.h"


QRcodeEink::QRcodeEink(GxGDE0213B72B *display) {
    this->display = display;
}

void QRcodeEink::init() {
    display->init();
    this->screenwidth = display->width();
    this->screenheight = display->height();
    display->setRotation(1);
    display->eraseDisplay();
    int min = screenwidth;
    if (screenheight<screenwidth)
        min = screenheight;
    multiply = min/WD;
    offsetsX = (screenwidth-(WD*multiply))/2;
    offsetsY = (screenheight-(WD*multiply))/2;
}

void QRcodeEink::screenwhite() {
    display->fillScreen(GxEPD_WHITE);
}

void QRcodeEink::screenupdate() {
    display->update();
}

void QRcodeEink::drawPixel(int x, int y, int color) {
    if(color==1) {
        color = GxEPD_BLACK;
    } else {
        color = GxEPD_WHITE;
    }
    display->drawPixel(x,y,color);
    if (this->multiply>1) {
        display->drawPixel(x+1,y,color);
        display->drawPixel(x+1,y+1,color);
        display->drawPixel(x,y+1,color);
    }
}