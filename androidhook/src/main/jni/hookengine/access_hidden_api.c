#include "access_hidden_api.h"
#include "CydiaSubstrate.h"
#include "fake_dlfcn.h"
#include <stdbool.h>
#include <stdio.h>
#include <android/log.h>

#if defined(__LP64__)
#define LIB_ART_PATH "/system/lib64/libart.so"
#else
#define LIB_ART_PATH "/system/lib/libart.so"
#endif

enum Action {
    kAllow,
    kAllowButWarn,
    kAllowButWarnAndToast,
    kDeny
};

bool bypassGetFieldAction() {
    return kAllow;
}

bool bypassGetMethodAction() {
    return kAllow;
}

bool bypassShouldBlockAccessToField() {
    return false;
}

bool bypassShouldBlockAccessToMethod() {
    return false;
}

void access_hidden_api() {
    void *handle = fake_dlopen(LIB_ART_PATH, 0);

    if (handle == NULL) {
        __android_log_write(ANDROID_LOG_ERROR, "hooklib", "failed to get handle to runtime libs");
        return;
    }

    void *symbol = fake_dlsym(handle,
                              "_ZN3art9hiddenapi25ShouldBlockAccessToMemberINS_8ArtFieldEEEbPT_PNS_6ThreadENSt3__18functionIFbS6_EEENS0_12AccessMethodE");
    if (symbol) {
        MSHookFunction(symbol, (void *) &bypassShouldBlockAccessToField, (void **) NULL);
    }
    symbol = fake_dlsym(handle,
                        "_ZN3art9hiddenapi25ShouldBlockAccessToMemberINS_9ArtMethodEEEbPT_PNS_6ThreadENSt3__18functionIFbS6_EEENS0_12AccessMethodE");
    if (symbol) {
        MSHookFunction(symbol, (void *) &bypassShouldBlockAccessToMethod, (void **) NULL);
    }

    symbol = fake_dlsym(handle,
                        "_ZN3art9hiddenapi6detail19GetMemberActionImplINS_8ArtFieldEEENS0_6ActionEPT_NS_20HiddenApiAccessFlags7ApiListES4_NS0_12AccessMethodE");
    if (symbol) {
        MSHookFunction(symbol, (void *) &bypassGetFieldAction, (void **) NULL);
    }
    symbol = fake_dlsym(handle,
                        "_ZN3art9hiddenapi6detail19GetMemberActionImplINS_9ArtMethodEEENS0_6ActionEPT_NS_20HiddenApiAccessFlags7ApiListES4_NS0_12AccessMethodE");
    if (symbol) {
        MSHookFunction(symbol, (void *) &bypassGetMethodAction, (void **) NULL);
    }
    fake_dlclose(handle);
}