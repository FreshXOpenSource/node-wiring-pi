#include "piFace.h"
#include <piFace.h>

namespace nodewpi {

NAN_METHOD(piFaceSetup) {
  SET_ARGUMENT_NAME(0, pinBase);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::piFaceSetup(pinBase);
  
  info.GetReturnValue().Set(res);
}

NAN_MODULE_INIT(init_piFace) {
  NAN_EXPORT(target, piFaceSetup);
}

}
