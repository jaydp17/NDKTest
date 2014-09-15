LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := clientlibwrapper.cpp
LOCAL_MODULE := clientlibwrapper
include $(BUILD_SHARED_LIBRARY)