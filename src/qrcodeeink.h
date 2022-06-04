#ifndef ESPQRCODEEINK_H
#define ESPQRCODEEINK_H

/* ESP_QRcode. e-ink version
 * Import this .h when using some e-ink display
 */

#define EINKDISPLAY

#include <qrcodedisplay.h>
#include <Adafruit_GFX.h>   
#include <GxEPD.h>
#include <GxGDE0213B72B/GxGDE0213B72B.h>

#ifndef EINK_MODEL
#define EINK_MODEL 128
#endif

class QRcodeEink : public QRcodeDisplay
{
	private:
		GxGDE0213B72B *display;
        void drawPixel(int x, int y, int color);
	public:
		
		QRcodeEink(GxGDE0213B72B *display);
		void init();
		void screenwhite();
		void screenupdate();
};
#endif