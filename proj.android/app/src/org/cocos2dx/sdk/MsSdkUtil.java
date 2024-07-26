package org.cocos2dx.sdk;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.aly.sdk.ALYAnalysis;
import com.ms.sdk.MsInterstitialAd;
import com.ms.sdk.MsRewardVideoAd;
import com.ms.sdk.MsSDK;
import com.ms.sdk.listener.MsSdkInitializationListener;
import com.ms.sdk.wrapper.interstitial.MsInterstitialAdListener;
import com.ms.sdk.wrapper.interstitial.MsInterstitialLoadCallback;
import com.ms.sdk.wrapper.video.MsRewardVideoAdListener;
import com.ms.sdk.wrapper.video.MsRewardVideoLoadCallback;

import org.cocos2dx.cpp.AppActivity;
import org.cocos2dx.cpp.JavaHelper;

public class MsSdkUtil {
    public static final String TAG = "=====MsSdk_cocos2dx_demo";
    private static MsRewardVideoAd mVideoAd;
    private static MsInterstitialAd mInterstitialAd;
    private static Context context = AppActivity.getContext();



    public static void initMsSdk(){
        ALYAnalysis.enalbeDebugMode(true);
        ALYAnalysis.init(context, "999999", "32408", new ALYAnalysis.TasdkinitializdListener() {
            @Override
            public void onSuccess(String s) {
                MsSDK.init(context, new MsSdkInitializationListener() {
                    @SuppressLint("LongLogTag")
                    @Override
                    public void onInitializationSuccess() {
                        Log.i(TAG, "mssdk初始化成功: ");
                        JavaHelper.MsSdkInitSuccess();
//                        initInter();
//                        initRW();
                    }

                    @SuppressLint("LongLogTag")
                    @Override
                    public void onInitializationFail(String s) {
                        Log.i(TAG, "mssdk初始化失败: " + s);
                        JavaHelper.MsSdkInitFail(s);
                    }
                });
            }

            @SuppressLint("LongLogTag")
            @Override
            public void onFail(String s) {
                Log.i(TAG, "tasdk 初始化失败 " + s);
            }
        });
    }

    public static void initInter(String placement) {
//        mInterstitialAd = new MsInterstitialAd((Activity) context, "Shop_inter");
        mInterstitialAd = new MsInterstitialAd((Activity) context, placement);

    }

    public static void initRW() {
        mVideoAd = MsRewardVideoAd.getInstance((Activity) context);
    }


    public static void setInterLoadCallback() {
        if (mInterstitialAd == null) {
            Toast.makeText(context, "mssdk没有初始化完成", Toast.LENGTH_SHORT).show();
            return;
        }
        mInterstitialAd.setLoadCallBack(new MsInterstitialLoadCallback() {
            @SuppressLint("LongLogTag")
            @Override
            public void onLoadFailed(String placement) {
                Log.i(TAG, "onLoadFailed: " + placement);
                JavaHelper.OnInterLoadFail(placement);
            }

            @SuppressLint("LongLogTag")
            @Override
            public void onLoadSuccessed(String placement) {
                Log.i(TAG, "onLoadSuccessed: " + placement);
                JavaHelper.OnInterLoadSuccess(placement);

            }
        });
    }

    @SuppressLint("LongLogTag")
    public static void showInterAds() {
        if (mInterstitialAd == null) {
            Toast.makeText(context, "mssdk没有初始化完成", Toast.LENGTH_SHORT).show();
            return;
        }
        if (mInterstitialAd.isReady()) {
            mInterstitialAd.setInterstitialAdListener(new MyInterAdsShowListener());
            mInterstitialAd.show();
        }else{
            Log.i(TAG, "showInterAds: not ready");
        }
    }

    private static class MyInterAdsShowListener implements MsInterstitialAdListener {

        @SuppressLint("LongLogTag")
        @Override
        public void onClicked() {
            Log.i(TAG, "onClicked: ");
            JavaHelper.OnInterClicked();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onClosed() {
            Log.i(TAG, "onClosed: ");
            JavaHelper.OnInterClosed();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onDisplayed() {
            Log.i(TAG, "onDisplayed: ");
            JavaHelper.OnInterDisplay();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onShowFailed(String reason) {
            Log.i(TAG, "onShowFailed: " + reason);
            JavaHelper.OnInterShowFailed(reason);
        }
    }


    public static void setRwdLoadCallback() {
        if (mVideoAd == null) {
            Toast.makeText(context, "mssdk没有初始化完成", Toast.LENGTH_SHORT).show();
            return;
        }
        mVideoAd.setLoadCallback(new MsRewardVideoLoadCallback() {
            @SuppressLint("LongLogTag")
            @Override
            public void onLoadFailed() {
                Log.i(TAG, "onLoadFailed: ");
                JavaHelper.OnRwdLoadFail();
            }

            @SuppressLint("LongLogTag")
            @Override
            public void onLoadSuccessed() {
                Log.i(TAG, "onLoadSuccessed: ");
                JavaHelper.OnRwdLoadSuccess();
            }
        });
    }


    @SuppressLint("LongLogTag")
    public static void showRwd(String placement) {
        if (mVideoAd == null) {
            Toast.makeText(context, "mssdk没有初始化完成", Toast.LENGTH_SHORT).show();
            return;
        }
        if (mVideoAd.isReady()) {
            mVideoAd.setVideoAdListener(new MyVideoShowListener());
//            mVideoAd.show("hall_rwd");
            mVideoAd.show(placement);
        } else {
            Log.i(TAG, "showRwd: not ready");
        }
    }
    private static class MyVideoShowListener implements MsRewardVideoAdListener {
        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdClicked() {
            Log.i(TAG, "onVideoAdClicked: ");
            JavaHelper.OnRwdClicked();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdClosed() {
            Log.i(TAG, "onVideoAdClosed: ");
            JavaHelper.OnRwdClosed();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdDisplayed() {
            Log.i(TAG, "onVideoAdDisplayed: ");
            JavaHelper.OnRwdDisplay();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdReward() {
            Log.i(TAG, "onVideoAdReward: ");
            JavaHelper.OnRwdAdReward();
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdDontReward(String reason) {
            Log.w(TAG, "onVideoAdDontReward: " + reason);
            JavaHelper.OnRwdDontReward(reason);
        }

        @SuppressLint("LongLogTag")
        @Override
        public void onVideoAdShowFailed(String s) {
            Log.w(TAG, "onVideoAdShowFailed: " + s);
            JavaHelper.OnRwdShowFailed(s);
        }
    }




}
