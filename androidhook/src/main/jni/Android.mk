LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
LOCAL_MODULE := androidhook_64
else
LOCAL_MODULE := androidhook
endif



LOCAL_CFLAGS := -Wno-error=format-security -fpermissive -O2
LOCAL_CFLAGS += -fno-rtti -fno-exceptions
LOCAL_CPPFLAGS += -std=c++11

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)
LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)/hookengine
LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)/Substrate

LOCAL_SRC_FILES :=  $(MAIN_LOCAL_PATH)/hookengine/android_hook_jni.c \
LOCAL_SRC_FILES :=  $(MAIN_LOCAL_PATH)/hookengine/fake_dlfcn.cpp \
                    $(MAIN_LOCAL_PATH)/hookengine/access_hidden_api.c \
                    $(MAIN_LOCAL_PATH)/Substrate/hde64.c \
                    $(MAIN_LOCAL_PATH)/Substrate/And64InlineHook.cpp \
                    $(MAIN_LOCAL_PATH)/Substrate/SubstrateDebug.cpp \
                    $(MAIN_LOCAL_PATH)/Substrate/SubstrateHook.cpp \
                    $(MAIN_LOCAL_PATH)/Substrate/SubstratePosixMemory.cpp \


LOCAL_LDLIBS := -llog -latomic

include $(BUILD_SHARED_LIBRARY)