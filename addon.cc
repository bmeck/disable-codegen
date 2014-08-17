/**********************************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2014 NAN contributors
 *
 * MIT +no-false-attribs License <https://github.com/rvagg/nan/blob/master/LICENSE>
 **********************************************************************************/

#include <node.h>
#include <nan.h>

using v8::Local;
using v8::Context;
using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::Boolean;
using v8::String;

NAN_METHOD(AllowCodeGenerationFromStrings) {
  NanScope();

  Local<Context> ctx = NanGetCurrentContext();
  ctx->AllowCodeGenerationFromStrings(args[0]->IsTrue());

  NanReturnUndefined();
}

NAN_METHOD(IsCodeGenerationFromStringsAllowed) {
  NanScope();

  Local<Context> ctx = NanGetCurrentContext();

  NanReturnValue(NanNew(ctx->IsCodeGenerationFromStringsAllowed()));
}

NAN_METHOD(SetErrorMessageForCodeGenerationFromStrings) {
  NanScope();

  Local<Context> ctx = NanGetCurrentContext();
  ctx->SetErrorMessageForCodeGenerationFromStrings(args[0]->ToString());

  NanReturnUndefined();
}

// Expose synchronous and asynchronous access to our
// Estimate() function
void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("allowCodeGenerationFromStrings"),
    NanNew<FunctionTemplate>(AllowCodeGenerationFromStrings)->GetFunction());

  exports->Set(NanNew<String>("isCodeGenerationFromStringsAllowed"),
    NanNew<FunctionTemplate>(IsCodeGenerationFromStringsAllowed)->GetFunction());

  exports->Set(NanNew<String>("setErrorMessageForCodeGenerationFromStrings"),
    NanNew<FunctionTemplate>(SetErrorMessageForCodeGenerationFromStrings)->GetFunction());
}

NODE_MODULE(addon, InitAll)
