#include <node.h>
#include <v8.h>
#include <v8-debug.h>

using namespace node;
using namespace v8;


class StaticDebugger {
  public:
    static void
    Initialize(Handle<Object> target) {
      HandleScope scope;

      NODE_SET_METHOD(target, "start", Start);
    }

    static Handle<Value>
    Start(const Arguments &args) {
      int port = args[0]->Int32Value();

      if (port > 1024 && port < 65546) {
        return Boolean::New(v8::Debug::EnableAgent("node custom debugger", port));
      } else {
        return ThrowException(Exception::Error(String::New("Invalid port")));
      }
    }
};
 

extern "C" void
init (Handle<Object> target)
{
    HandleScope scope;

    StaticDebugger::Initialize(target);
}
