#include "wiringPiISR.h"
#include <wiringPi.h>
#include <uv.h>

using namespace v8;



typedef struct interrupt_t {
  int pin;
  unsigned int delta;
  unsigned long int previous_timestamp;
} interrupt_t;


typedef void (*NATIVE_INTERRUPT_HANDLER_T)(void);

static uv_async_t async_handlers[64];
static interrupt_t interrupt_data[64];




void processNativeInterrupt(int pin) {
    unsigned int now = ::micros();
    uv_async_t* handle = &async_handlers[pin];
    interrupt_t* data = &interrupt_data[pin];
    data->pin = pin;
    data->delta = now - data->previous_timestamp;
    handle->data = (void*)data;
    uv_async_send(handle);
    data->previous_timestamp = now;
}


#define DEFINE_NATIVE_INTERRUPT_HANDLER(pin) \
      static void nativeInterruptHandler##pin(void) { \
          processNativeInterrupt(pin); \
      }


// define interrupt handlers calling the processNativeIntrupts with a static Pin number.
DEFINE_NATIVE_INTERRUPT_HANDLER(0);
DEFINE_NATIVE_INTERRUPT_HANDLER(1);
DEFINE_NATIVE_INTERRUPT_HANDLER(2);
DEFINE_NATIVE_INTERRUPT_HANDLER(3);
DEFINE_NATIVE_INTERRUPT_HANDLER(4);
DEFINE_NATIVE_INTERRUPT_HANDLER(5);
DEFINE_NATIVE_INTERRUPT_HANDLER(6);
DEFINE_NATIVE_INTERRUPT_HANDLER(7);
DEFINE_NATIVE_INTERRUPT_HANDLER(8);
DEFINE_NATIVE_INTERRUPT_HANDLER(9);
DEFINE_NATIVE_INTERRUPT_HANDLER(10);
DEFINE_NATIVE_INTERRUPT_HANDLER(11);
DEFINE_NATIVE_INTERRUPT_HANDLER(12);
DEFINE_NATIVE_INTERRUPT_HANDLER(13);
DEFINE_NATIVE_INTERRUPT_HANDLER(14);
DEFINE_NATIVE_INTERRUPT_HANDLER(15);
DEFINE_NATIVE_INTERRUPT_HANDLER(16);
DEFINE_NATIVE_INTERRUPT_HANDLER(17);
DEFINE_NATIVE_INTERRUPT_HANDLER(18);
DEFINE_NATIVE_INTERRUPT_HANDLER(19);
DEFINE_NATIVE_INTERRUPT_HANDLER(20);
DEFINE_NATIVE_INTERRUPT_HANDLER(21);
DEFINE_NATIVE_INTERRUPT_HANDLER(22);
DEFINE_NATIVE_INTERRUPT_HANDLER(23);
DEFINE_NATIVE_INTERRUPT_HANDLER(24);
DEFINE_NATIVE_INTERRUPT_HANDLER(25);
DEFINE_NATIVE_INTERRUPT_HANDLER(26);
DEFINE_NATIVE_INTERRUPT_HANDLER(27);
DEFINE_NATIVE_INTERRUPT_HANDLER(28);
DEFINE_NATIVE_INTERRUPT_HANDLER(29);
DEFINE_NATIVE_INTERRUPT_HANDLER(30);
DEFINE_NATIVE_INTERRUPT_HANDLER(31);
DEFINE_NATIVE_INTERRUPT_HANDLER(32);
DEFINE_NATIVE_INTERRUPT_HANDLER(33);
DEFINE_NATIVE_INTERRUPT_HANDLER(34);
DEFINE_NATIVE_INTERRUPT_HANDLER(35);
DEFINE_NATIVE_INTERRUPT_HANDLER(36);
DEFINE_NATIVE_INTERRUPT_HANDLER(37);
DEFINE_NATIVE_INTERRUPT_HANDLER(38);
DEFINE_NATIVE_INTERRUPT_HANDLER(39);
DEFINE_NATIVE_INTERRUPT_HANDLER(40);
DEFINE_NATIVE_INTERRUPT_HANDLER(41);
DEFINE_NATIVE_INTERRUPT_HANDLER(42);
DEFINE_NATIVE_INTERRUPT_HANDLER(43);
DEFINE_NATIVE_INTERRUPT_HANDLER(44);
DEFINE_NATIVE_INTERRUPT_HANDLER(45);
DEFINE_NATIVE_INTERRUPT_HANDLER(46);
DEFINE_NATIVE_INTERRUPT_HANDLER(47);
DEFINE_NATIVE_INTERRUPT_HANDLER(48);
DEFINE_NATIVE_INTERRUPT_HANDLER(49);
DEFINE_NATIVE_INTERRUPT_HANDLER(50);
DEFINE_NATIVE_INTERRUPT_HANDLER(51);
DEFINE_NATIVE_INTERRUPT_HANDLER(52);
DEFINE_NATIVE_INTERRUPT_HANDLER(53);
DEFINE_NATIVE_INTERRUPT_HANDLER(54);
DEFINE_NATIVE_INTERRUPT_HANDLER(55);
DEFINE_NATIVE_INTERRUPT_HANDLER(56);
DEFINE_NATIVE_INTERRUPT_HANDLER(57);
DEFINE_NATIVE_INTERRUPT_HANDLER(58);
DEFINE_NATIVE_INTERRUPT_HANDLER(59);
DEFINE_NATIVE_INTERRUPT_HANDLER(60);
DEFINE_NATIVE_INTERRUPT_HANDLER(61);
DEFINE_NATIVE_INTERRUPT_HANDLER(62);
DEFINE_NATIVE_INTERRUPT_HANDLER(63);


// Initialise an array of interupt handlers.
#define STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(pin) &nativeInterruptHandler##pin
static NATIVE_INTERRUPT_HANDLER_T interrupt_handlers[64] = {
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(0),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(1),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(2),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(3),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(4),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(5),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(6),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(7),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(8),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(9),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(10),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(11),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(12),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(13),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(14),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(15),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(16),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(17),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(18),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(19),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(20),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(21),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(22),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(23),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(24),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(25),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(26),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(27),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(28),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(29),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(30),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(31),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(32),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(33),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(34),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(35),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(36),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(37),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(38),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(39),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(40),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(41),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(42),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(43),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(44),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(45),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(46),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(47),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(48),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(49),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(50),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(51),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(52),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(53),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(54),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(55),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(56),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(57),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(58),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(59),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(60),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(61),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(62),
      STATIC_REGISTER_NATIVE_INTERRUPT_HANDLER(63)
};


#if NODE_VERSION_AT_LEAST(0, 11, 0)
  typedef v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > CopyablePersistentFunction;
#else
  typedef v8::Persistent<v8::Function> CopyablePersistentFunction;
#endif

static CopyablePersistentFunction interrupt_callbacks[64];




#if NODE_VERSION_AT_LEAST(12, 0, 0)
  // Node >= 11 version of dispatchInterrupt
  static void dispatchInterrupt(uv_async_t* handle) {
    interrupt_t* data = (interrupt_t*)handle->data;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    HandleScope scope(isolate);
    v8::Local<Function> callback = v8::Local<Function>::New(isolate, interrupt_callbacks[data->pin]);
    Local<Value> argv[] = {
      UINT32(data->delta)
    };
    callback->Call(isolate->GetCurrentContext(), Null(isolate), 1, argv);
  }
#elif NODE_VERSION_AT_LEAST(0, 11, 0)
  // Node >= 11 version of dispatchInterrupt
  static void dispatchInterrupt(uv_async_t* handle) {
    interrupt_t* data = (interrupt_t*)handle->data;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    HandleScope scope(isolate);
    v8::Local<Function> callback = v8::Local<Function>::New(isolate, interrupt_callbacks[data->pin]);
    Local<Value> argv[] = {
      UINT32(data->delta)
    };
    callback->Call(isolate->GetCurrentContext()->Global(), 1, argv);
  }
#else
  // Node < 11 version of dispatchInterrupt
  static void dispatchInterrupt(uv_async_t* handle, int status) {
    interrupt_t* data = (interrupt_t*)handle->data;
    v8::Local<Function> callback = v8::Local<Function>::New(interrupt_callbacks[data->pin]);
    Local<Value> argv[] = {
      UINT32(data->delta)
    };
    callback->Call(Context::GetCurrent()->Global(), 1, argv);
  }
#endif



namespace nodewpi {

  NAN_METHOD(wiringPiISR) {

    SET_ARGUMENT_NAME(0, pin);
    SET_ARGUMENT_NAME(1, edgeType);
    SET_ARGUMENT_NAME(2, callback);

    CHECK_ARGUMENTS_LENGTH_EQUAL(3);

    CHECK_ARGUMENT_TYPE_INT32(0);
    CHECK_ARGUMENT_TYPE_INT32(1);
    CHECK_ARGUMENT_TYPE_FUNCTION(2);

    int pin = GET_ARGUMENT_AS_INT32(0);
    int edgeType = GET_ARGUMENT_AS_INT32(1);

    #if NODE_VERSION_AT_LEAST(0, 11, 0)
      // not very certain about this.
      v8::Isolate* isolate = v8::Isolate::GetCurrent();
      HandleScope scope(isolate);
      Persistent<Function> callback(isolate, GET_ARGUMENT_AS_LOCAL_FUNCTION(2));
    #else
      Persistent<Function> callback = GET_ARGUMENT_AS_PERSISTENT_FUNCTION(2);
    #endif


    // check the edge type is valid.  
    const std::vector<int> validInputs = { INT_EDGE_FALLING, INT_EDGE_RISING, INT_EDGE_BOTH, INT_EDGE_SETUP};

    if(! find_int(edgeType, validInputs)) {
      THROW_INVALID_ARGUMENT_EXCEPTION(1, edgeType);
    }

    interrupt_callbacks[pin] = callback;
    interrupt_data[pin].previous_timestamp = ::micros();


    uv_async_init(uv_default_loop(), &async_handlers[pin], &dispatchInterrupt);
    uv_ref((uv_handle_t*)&async_handlers[pin]);

    // everything must be initialised when the isr is installed otherwise if 
    // a pulse arrives before structures are setup there will be a segv.
    ::wiringPiISR(pin, edgeType, interrupt_handlers[pin]);

  }

/* The standard wiringPi lib doesnt allow cancelling an ISR.
  Assuming, based on other example code that the ISR cancels when 
  the process exits. Some forks of wiringPi do support cancelling an ISR,
  but this lib uses the standard, unpatched wiringPi.
  NAN_METHOD(wiringPiISRCancel) {

    SET_ARGUMENT_NAME(0, pin);

    CHECK_ARGUMENTS_LENGTH_EQUAL(1);

    CHECK_ARGUMENT_TYPE_INT32(0);

    int pin = GET_ARGUMENT_AS_INT32(0);

    ::wiringPiISRCancel(pin);
    uv_close((uv_handle_t*)&async_handlers[pin], NULL);

  }
  */

  NAN_MODULE_INIT(init_wiringPiISR) {
      NAN_EXPORT(target, wiringPiISR);
//      NAN_EXPORT(target, wiringPiISRCancel);

      NODE_DEFINE_CONSTANT(target, INT_EDGE_FALLING);
      NODE_DEFINE_CONSTANT(target, INT_EDGE_RISING);
      NODE_DEFINE_CONSTANT(target, INT_EDGE_BOTH);
      NODE_DEFINE_CONSTANT(target, INT_EDGE_SETUP);
  }
}
