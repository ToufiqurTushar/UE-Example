// Copyright (c) 2025 Loko. All Rights Reserved.
package com.google.admob;

import android.app.Activity;
import android.util.Log;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.rewarded.RewardedAd;
import com.google.android.gms.ads.rewarded.RewardedAdLoadCallback;

public class RewardedAdHandler {

    private final Activity activity;
    private final AdMobManager parent;

    private RewardedAd rewardedAd;
    private boolean isLoaded = false;
    private String currentId;

    public RewardedAdHandler(Activity activity, AdMobManager parent) {
        this.activity = activity;
        this.parent = parent;
    }

    // -------------------------------------------------------
    // LOAD
    // -------------------------------------------------------
    public void load(String adUnitId) {

        if (adUnitId == null || adUnitId.isEmpty()) {
            Log.e("AdMob", "RewardedAd: Invalid ID.");
            parent.onRewardedAdFailed(-1);
            return;
        }

        currentId = adUnitId;
        isLoaded = false;

        activity.runOnUiThread(() -> {

            AdRequest request = new AdRequest.Builder().build();

            RewardedAd.load(activity, adUnitId, request, new RewardedAdLoadCallback() {

                @Override
                public void onAdLoaded(RewardedAd ad) {
                    rewardedAd = ad;
                    isLoaded = true;
                    parent.onRewardedLoadSuccess();
                    Log.d("AdMob", "Rewarded loaded.");
                    setupCallbacks();
                }

                @Override
                public void onAdFailedToLoad(LoadAdError error) {
                    rewardedAd = null;
                    isLoaded = false;

                    Log.e("AdMob", "Rewarded load FAILED: " + error.getMessage());
                    parent.onRewardedAdFailed(error.getCode());
                }
            });
        });
    }

    // -------------------------------------------------------
    // CALLBACK SETUP (Show failed, closed, etc.)
    // -------------------------------------------------------
    private void setupCallbacks() {

        rewardedAd.setFullScreenContentCallback(new FullScreenContentCallback() {

            @Override
            public void onAdFailedToShowFullScreenContent(AdError error) {
                Log.e("AdMob", "Rewarded failed to show: " + error.getMessage());
                parent.onRewardedAdFailed(error.getCode());
            }

            @Override
            public void onAdDismissedFullScreenContent() {
                Log.d("AdMob", "Rewarded closed.");
                parent.onRewardedAdFailed(-1);
                rewardedAd = null;
                isLoaded = false;
            }
        });
    }

    // -------------------------------------------------------
    // SHOW
    // -------------------------------------------------------
    public void show() {

        activity.runOnUiThread(() -> {

            if (rewardedAd == null || !isLoaded) {
                Log.d("AdMob", "Rewarded not loaded.");
                parent.onRewardedAdFailed(-2);
                return;
            }

            rewardedAd.show(activity, reward -> {
                parent.onRewardEarned(reward.getAmount(), reward.getType());
            });
        });
    }

    public boolean isLoaded() {
        return isLoaded;
    }
}
