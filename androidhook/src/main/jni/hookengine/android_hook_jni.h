#ifndef ANDROIDHOOK_ANDROID_HOOK_JNI_H
#define ANDROIDHOOK_ANDROID_HOOK_JNI_H

#include <jni.h>
#include <android/log.h>
#define TAG "ANDROID_HOOK"


#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,  TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,  TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,  TAG, __VA_ARGS__)
#define A64_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#endif //ANDROIDHOOK_ANDROID_HOOK_JNI_H
