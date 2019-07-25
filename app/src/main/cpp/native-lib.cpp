#include <jni.h>
#include <string>
#include <libavutil/log.h>


extern "C" JNIEXPORT jstring JNICALL
Java_cn_iwenchaos_avcoder_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_cn_iwenchaos_avcoder_utils_FFUtil_playVideo(JNIEnv *env, jclass type, jstring filePath_,
                                                 jobject surface) {
    const char *filePath = env->GetStringUTFChars(filePath_, 0);
//    ALOGI()
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "%s\n", filePath);
    av_log(NULL, AV_LOG_INFO, "%s\n", filePath);
    av_log(NULL, AV_LOG_WARNING, "%s\n", filePath);
    av_log(NULL, AV_LOG_ERROR, "%s\n", filePath);

    if (filePath == NULL) {
        return;
    }
//    AVFormatContext *
    // TODO

    env->ReleaseStringUTFChars(filePath_, filePath);
}
