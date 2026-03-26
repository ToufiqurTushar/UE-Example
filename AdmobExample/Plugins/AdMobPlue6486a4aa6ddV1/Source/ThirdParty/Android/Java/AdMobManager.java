// Copyright (c) 2025 Loko. All Rights Reserved.
package com.google.admob;

import android.app.Activity;
import android.util.Log;
import com.google.android.gms.ads.MobileAds;

public class AdMobManager {

    private final RewardedAdHandler rewarded;
    private final BannerAdHandler banner;
    private final RewardedInterstitialAdHandler rewardedInterstitial;
    private final InterstitialAdHandler interstitial;

    public AdMobManager(Activity activity) {
        Log.d("AdMobPlugin", "Java: AdMobManager constructor created.");

        activity.runOnUiThread(() -> {
            MobileAds.initialize(activity, status ->
                Log.d("AdMobPlugin", "AdMob Initialized (Java)")
            );
        });

        rewarded = new RewardedAdHandler(activity, this);
        banner =  new BannerAdHandler(activity, this);
        rewardedInterstitial = new RewardedInterstitialAdHandler(activity, this);
        interstitial = new InterstitialAdHandler(activity, this);
    }

    // Unreal calls these
    public void loadRewarded(String id) { rewarded.load(id); }
    public void showRewarded() { rewarded.show(); }
    public native void onRewardedLoadSuccess();
    public native void onRewardedAdFailed(int error);
    public native void onRewardEarned(int amount, String type);

    
    public boolean isRewardedLoaded() { return rewarded.isLoaded(); }


    //Banner callback
    public void loadBanner(String id, boolean isAdaptive) { banner.load(id, isAdaptive); }
    public void showBanner() { banner.show(); }
    public void hideBanner() { banner.hide(); }
    public boolean isBannerLoaded() { return banner.isLoaded(); }
    public void destroyBanner() { banner.destroy(); }

    //Banner JNI callback
    public native void onBannerLoadSuccess();
    public native void onBannerLoadFailed(int error);


    public void loadRewardedInterstitial(String id) { rewardedInterstitial.load(id); }
    public void showRewardedInterstitial() { rewardedInterstitial.show(); }
    public boolean isRewardedInterstitialLoaded() { return rewardedInterstitial.isLoaded(); }

    //RewardedInterstitial JNI callback
    public native void onRewardedInterstitialLoadSuccess();
    public native void onRewardedInterstitialFailed(int error);
    public native void onRewardedInterstitialEarned(int amount, String type);


    public void loadInterstitial(String id) { interstitial.load(id); }
    public void showInterstitial() { interstitial.show(); }
    public boolean isInterstitialLoaded() { return interstitial.isLoaded(); }
    //Interstitial JNI callback
    public native void onInterstitialLoadSuccess();
    public native void onInterstitialFailed(int error);
    public native void onInterstitialCompleted();



}
