// Copyright (c) 2025 Loko. All Rights Reserved.
package com.google.admob;

import android.app.Activity;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.widget.FrameLayout;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;

public class BannerAdHandler {

    private final Activity activity;
    private final AdMobManager parent;

    private AdView bannerView;
    private boolean isLoaded = false;
    private String currentId;

    private FrameLayout bannerContainer;

    public BannerAdHandler(Activity activity, AdMobManager parent) {
        this.activity = activity;
        this.parent = parent;

        activity.runOnUiThread(() -> {
            bannerContainer = new FrameLayout(activity);
            FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(
                FrameLayout.LayoutParams.MATCH_PARENT,
                FrameLayout.LayoutParams.WRAP_CONTENT
            );
            params.gravity = Gravity.BOTTOM;

            activity.addContentView(bannerContainer, params);
        });
    }

    // -------------------------------------------------------
    // LOAD BANNER WITH ADAPTIVE OR FIXED
    // -------------------------------------------------------
    public void load(String adUnitId, boolean adaptive) {

        if (adUnitId == null || adUnitId.isEmpty()) {
            Log.e("AdMob", "Banner: Invalid AdUnit ID");
            return;
        }

        currentId = adUnitId;
        isLoaded = false;

        activity.runOnUiThread(() -> {

            destroyInternal();  // clear old banner

            bannerView = new AdView(activity);
            bannerView.setAdUnitId(adUnitId);

            // choose banner type
            if (adaptive) {
                bannerView.setAdSize(getAdaptiveSize());
                Log.d("AdMob", "Banner: Using ADAPTIVE size.");
            } else {
                bannerView.setAdSize(AdSize.BANNER);
                Log.d("AdMob", "Banner: Using FIXED (320x50).");
            }

            bannerContainer.addView(bannerView);

            bannerView.loadAd(new AdRequest.Builder().build());

            bannerView.setAdListener(new com.google.android.gms.ads.AdListener() {
                @Override
                public void onAdLoaded() {
                    isLoaded = true;
                    parent.onBannerLoadSuccess();
                }

                @Override
                public void onAdFailedToLoad(com.google.android.gms.ads.LoadAdError error) {
                    isLoaded = false;
                    parent.onBannerLoadFailed(error.getCode());
                }
            });
        });
    }

    // -------------------------------------------------------
    // ADAPTIVE SIZING
    // -------------------------------------------------------
    private AdSize getAdaptiveSize() {
        DisplayMetrics metrics = new DisplayMetrics();
        activity.getWindowManager().getDefaultDisplay().getMetrics(metrics);

        float widthPixels = metrics.widthPixels;
        float density = metrics.density;

        int adWidthDp = (int) (widthPixels / density);

        return AdSize.getCurrentOrientationAnchoredAdaptiveBannerAdSize(
            activity,
            adWidthDp
        );
    }

    // -------------------------------------------------------
    // SHOW / HIDE
    // -------------------------------------------------------
    public void show() {
        activity.runOnUiThread(() -> {
            if (bannerView != null)
                bannerView.setVisibility(android.view.View.VISIBLE);
        });
    }

    public void hide() {
        activity.runOnUiThread(() -> {
            if (bannerView != null)
                bannerView.setVisibility(android.view.View.GONE);
        });
    }

    // -------------------------------------------------------
    // DESTROY
    // -------------------------------------------------------
    private void destroyInternal() {
        if (bannerView != null) {
            bannerView.destroy();
            bannerContainer.removeView(bannerView);
            bannerView = null;
        }
    }

    public void destroy() {
        activity.runOnUiThread(this::destroyInternal);
    }

    public boolean isLoaded() {
        return isLoaded;
    }
}
