// Copyright (c) 2025 Loko. All Rights Reserved.
package com.google.admob;

import android.app.Activity;
import android.util.Log;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.interstitial.InterstitialAd;
import com.google.android.gms.ads.interstitial.InterstitialAdLoadCallback;

public class InterstitialAdHandler {

    private final Activity activity;
    private final AdMobManager parent;

    private InterstitialAd interstitial;
    private boolean isLoaded = false;
    private String currentId;

    public InterstitialAdHandler(Activity activity, AdMobManager parent) {
        this.activity = activity;
        this.parent = parent;
    }

    // -------------------------------------------------------
    // LOAD
    // -------------------------------------------------------
    public void load(String adUnitId) {

        if (adUnitId == null || adUnitId.isEmpty()) {
            Log.e("AdMob", "Interstitial: Invalid ID.");
            parent.onInterstitialFailed(-1);
            return;
        }

        currentId = adUnitId;
        isLoaded = false;

        activity.runOnUiThread(() -> {

            AdRequest request = new AdRequest.Builder().build();

            InterstitialAd.load(activity, adUnitId, request, new InterstitialAdLoadCallback() {

                @Override
                public void onAdLoaded(InterstitialAd ad) {
                    interstitial = ad;
                    isLoaded = true;

                    Log.d("AdMob", "Interstitial loaded.");
                    parent.onInterstitialLoadSuccess();
                    setupCallbacks();
                }

                @Override
                public void onAdFailedToLoad(LoadAdError error) {
                    interstitial = null;
                    isLoaded = false;

                    Log.e("AdMob", "Interstitial load FAILED: " + error.getMessage());
                    parent.onInterstitialFailed(error.getCode());
                }
            });
        });
    }

    // -------------------------------------------------------
    // CALLBACK SETUP
    // -------------------------------------------------------
    private void setupCallbacks() {

        if (interstitial == null)
            return;

        interstitial.setFullScreenContentCallback(new FullScreenContentCallback() {

            @Override
            public void onAdFailedToShowFullScreenContent(AdError error) {
                Log.e("AdMob", "Interstitial failed to show: " + error.getMessage());
                parent.onInterstitialFailed(error.getCode());
                interstitial = null;
                isLoaded = false;
            }

            @Override
            public void onAdDismissedFullScreenContent() {
                Log.d("AdMob", "Interstitial closed.");
                parent.onInterstitialCompleted();
                interstitial = null;
                isLoaded = false;
            }
        });
    }

    // -------------------------------------------------------
    // SHOW
    // -------------------------------------------------------
    public void show() {

        activity.runOnUiThread(() -> {

            if (interstitial == null || !isLoaded) {
                Log.d("AdMob", "Interstitial not loaded.");
                parent.onInterstitialFailed(-2);
                return;
            }

            interstitial.show(activity);
        });
    }

    public boolean isLoaded() {
        return isLoaded;
    }
}
