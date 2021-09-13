# QRcodeEink

Subclass that you can use jointly with https://github.com/yoprogramo/QRcodeDisplay to generate QRcodes in EINK displays like Lilygo TTGO T5

To use it:

* In platform.io: add as dependencies:

 ** yoprogramo/QRcodeDisplay
 ** yoprogramo/QRcodeEink
 ** adafruit/Adafruit GFX Library@1.7.5
 ** https://github.com/lewisxhe/GxEPD

 * In arduino ide open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

 ** QRcodeDisplay
 ** QRcodeOled
 ** Adafruit GFX Library@1.7.5
 ** https://github.com/lewisxhe/GxEPD

 Creating a QRcode is just as simple as:

 ```
#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <qrcodeeink.h>

GxIO_Class io(SPI, ELINK_SS, ELINK_DC, ELINK_RESET);
GxEPD_Class display(io, ELINK_RESET, ELINK_BUSY);

QRcodeEink qrcode (&display);

void setup() {

    qrcode.init();
    qrcode.create("Hello world.");

}

 ```

 For other displays, please refer the main repository: https://github.com/yoprogramo/QRcodeDisplay
