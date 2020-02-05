#include "android_hook_jni.h"
#include "access_hidden_api.h"

static const char *NATIVE_ENGINE_CLASS = "com/seven/lib/androidhook/AndroidHook";

static const JNINativeMethod _METHODS[] = {
        {"accessPieHiddenAPI", "()V", (void *) access_hidden_api}
};
static const int _METHODS_LEN = sizeof(_METHODS) / sizeof(JNINativeMethod);


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGD("JNI_OnLoad start...");
JNIEnv *env;

if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
LOGE("Failed to get the environment using GetEnv()");
return -1;
}

jclass cls = (*env)->FindClass(env, NATIVE_ENGINE_CLASS);
if (cls == NULL) {
LOGE("Failed to FindClass %s", NATIVE_ENGINE_CLASS);
return JNI_FALSE;
}

if ((*env)->RegisterNatives(env, cls, _METHODS, _METHODS_LEN) < 0) {
LOGE("Failed to RegisterNatives for %s",
NATIVE_ENGINE_CLASS);
return JNI_FALSE;
}
    LOGD("JNI_OnLoad finish...");
return JNI_VERSION_1_6;
}