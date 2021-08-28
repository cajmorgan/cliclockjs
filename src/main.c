#include <node_api.h>
#include "clock.h"

napi_value startClock(napi_env env);

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 0, startClock, NULL, &fn);
  if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function");
  }

  status = napi_set_named_property(env, exports, "start_clock", fn);
  if (status != napi_ok) {
      napi_throw_error(env, NULL, "Unable to populate exports");
  }

  return exports; 
}

napi_value startClock(napi_env env) {

  clockFunc();

  return 0;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)