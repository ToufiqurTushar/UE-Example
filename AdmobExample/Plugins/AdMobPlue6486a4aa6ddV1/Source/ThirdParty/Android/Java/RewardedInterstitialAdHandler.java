// Copyright (c) 2025 Loko. All Rights Reserved.
package com.google.admob;

import android.app.Activity;
import android.util.Log;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.rewardedinterstitial.RewardedInterstitialAd;
import com.google.android.gms.ads.rewardedinterstitial.RewardedInterstitialAdLoadCallback;

public class RewardedInterstitialAdHandler {

    private final Activity activity;
    private final AdMobManager parent;

    private RewardedInterstitialAd ad;
    private boolean isLoaded = false;
    private String currentId;

    public RewardedInterstitialAdHandler(Activity activity, AdMobManager parent) {
        this.activity = activity;
        this.parent = parent;
    }

    // -------------------------------------------------------
    // LOAD
    // -------------------------------------------------------
    public void load(String adUnitId) {

        if (adUnitId == null || adUnitId.isEmpty()) {
            Log.e("AdMob", "RewardedInterstitial: Invalid ID.");
            parent.onRewardedInterstitialFailed(-1);
            return;
        }

        currentId = adUnitId;
        isLoaded = false;

        activity.runOnUiThread(() -> {

            AdRequest request = new AdRequest.Builder().build();

            RewardedInterstitialAd.load(activity, adUnitId, request,
                    new RewardedInterstitialAdLoadCallback() {

                        @Override
                        public void onAdLoaded(RewardedInterstitialAd loadedAd) {
                            ad = loadedAd;
                            isLoaded = true;

                            Log.d("AdMob", "RewardedInterstitial loaded.");
                            parent.onRewardedInterstitialLoadSuccess();
                            setupCallbacks();
                        }

                        @Override
                        public void onAdFailedToLoad(LoadAdError error) {
                            ad = null;
                            isLoaded = false;

                            Log.e("AdMob", "RewardedInterstitial load FAILED: " + error.getMessage());
                            parent.onRewardedInterstitialFailed(error.getCode());
                        }
                    });
        });
    }

    // -------------------------------------------------------
    // CALLBACK SETUP
    // -------------------------------------------------------
    private void setupCallbacks() {

        if (ad == null)
            return;

        ad.setFullScreenContentCallback(new FullScreenContentCallback() {

            @Override
            public void onAdFailedToShowFullScreenContent(AdError error) {
                Log.e("AdMob", "R-Interstitial failed to show: " + error.getMessage());
                parent.onRewardedInterstitialFailed(error.getCode());
                ad = null;
                isLoaded = false;
            }

            @Override
            public void onAdDismissedFullScreenContent() {
                Log.d("AdMob", "R-Interstitial closed.");
                ad = null;
                isLoaded = false;
            }
        });
    }

    // -------------------------------------------------------
    // SHOW
    // -------------------------------------------------------
    public void show() {

        activity.runOnUiThread(() -> {

            if (ad == null || !isLoaded) {
                Log.d("AdMob", "RewardedInterstitial not loaded.");
                parent.onRewardedInterstitialFailed(-2);
                return;
            }

            ad.show(activity, rewardItem -> {
                parent.onRewardedInterstitialEarned(
                        rewardItem.getAmount(),
                        rewardItem.getType()
                );
            });
        });
    }

    public boolean isLoaded() {
        return isLoaded;
    }
}
