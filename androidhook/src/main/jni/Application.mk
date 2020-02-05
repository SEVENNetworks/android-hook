APP_ABI := armeabi-v7a arm64-v8a
APP_STL := c++_static
APP_PLATFORM := android-21
HOOK_ROOT          := $(call my-dir)
NDK_MODULE_PATH  := $(NDK_MODULE_PATH):$(HOOK_ROOT)
NDK_TOOLCHAIN_VERSION := clang
APP_CFLAGS            += -O3
APP_CPPFLAGS          += -O3