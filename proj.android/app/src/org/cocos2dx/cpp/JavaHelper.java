package org.cocos2dx.cpp;

/***
 * cpp回调
 */
public class JavaHelper {
    public static native void MsSdkInitSuccess();
    public static native void MsSdkInitFail(String msg);

    public static native void OnInterLoadSuccess(String msg);
    public static native void OnInterLoadFail(String msg);


    public static native void OnInterClicked();
    public static native void OnInterClosed();
    public static native void OnInterDisplay();
    public static native void OnInterShowFailed(String msg);

    public static native void OnRwdLoadSuccess();
    public static native void OnRwdLoadFail();


    public static native void OnRwdClicked();
    public static native void OnRwdClosed();
    public static native void OnRwdDisplay();
    public static native void OnRwdAdReward();
    public static native void OnRwdDontReward(String msg);
    public static native void OnRwdShowFailed(String msg);




}
