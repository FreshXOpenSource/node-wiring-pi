#include "devlib.h"

/* 
#include "ds1302.h"
#include "gertboard.h"
#include "lcd.h"
#include "lcd128x64.h"
#include "maxdetect.h"
#include "piGlow.h"
#include "piNes.h"
*/

#include "piFace.h"

namespace nodewpi {

NAN_MODULE_INIT(init_devlib) {
  /* 
  INIT(ds1302);
  INIT(gertboard);
  INIT(lcd);
  INIT(lcd128x64);
  INIT(maxdetect);
  INIT(piGlow);
  INIT(piNes);
  */
  nodewpi::init_piFace(target);
}

}
