package com.example.jaydeep.clientlibwrapper;


public class JsonGenerator {
    public native static int getInt(int a);

    public native static String getStr(String str);

    static {
        System.loadLibrary("clientlibwrapper");
    }
}
