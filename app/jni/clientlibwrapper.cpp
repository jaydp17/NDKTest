#include <jni.h>
#include <android/log.h>
#include <string>
#include <vector>

using namespace std;

namespace com_example_jaydeep_clientlibwrapper {

    static void jstringToStdString(JNIEnv *AEnv, jstring AStr, std::string &ARes) {
      if (!AStr) {
        ARes.clear();
        return;
      }

      const char *s = AEnv->GetStringUTFChars(AStr,NULL);
      ARes=s;
      AEnv->ReleaseStringUTFChars(AStr,s);
    }

    static jint incr(JNIEnv *env, jclass clazz, jint n) {
        return n+1;
    }

    static jstring addA(JNIEnv *env, jclass clazz, jstring str) {
        string str_std;
        jstringToStdString(env, str, str_std);
        str_std += "!";
        vector<int> abc{1,2,4};
        return env->NewStringUTF(str_std.c_str());
    }

    static JNINativeMethod method_table[] = {
        { "getInt", "(I)I", (void *) incr },
        { "getStr", "(Ljava/lang/String;)Ljava/lang/String;", (void *) addA}
    };
}

using namespace com_example_jaydeep_clientlibwrapper;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    } else {
        jclass clazz = env->FindClass("com/example/jaydeep/clientlibwrapper/JsonGenerator");
        if (clazz) {
            env->RegisterNatives(clazz, method_table, sizeof(method_table)/ sizeof(method_table[0]));
            env->DeleteLocalRef(clazz);
            return JNI_VERSION_1_6;
        } else {
            return -1;
        }
    }

    // Get jclass with env->FindClass.
    // Register methods with env->RegisterNatives.

    return JNI_VERSION_1_6;
}