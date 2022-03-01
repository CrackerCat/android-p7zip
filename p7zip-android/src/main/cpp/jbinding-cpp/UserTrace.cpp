/*
 * UserTrace.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: Boris Brodski
 */

#include "SevenZipJBinding.h"
#include "JNITools.h"

#include "JavaStatInfos/JavaPackageSevenZip.h"
#include "UnicodeHelper.h"
#include "UserTrace.h"

bool isUserTraceEnabled(JNIEnvInstance & jniEnvInstance, jobject thiz) {
//    jboolean result = jni::OutArchiveImpl::trace_Get(jniEnvInstance, thiz);
//    if (jniEnvInstance.exceptionCheck()) {
//        return false;
//    }
//    return result;
    return false;
}

void userTrace(JNIEnvInstance & jniEnvInstance, jobject thiz, UString msg) {
    jstring jmsg = jniEnvInstance->NewString(UnicodeHelper(msg.GetBuf(0)), msg.Len());
    jni::OutArchiveImpl::traceMessage(jniEnvInstance, thiz, jmsg);
    jniEnvInstance.exceptionCheck(); // Ignore result
    jniEnvInstance->DeleteLocalRef(jmsg);
}

