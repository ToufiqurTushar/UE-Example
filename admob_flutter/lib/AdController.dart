import 'package:get/get.dart';
import 'package:google_mobile_ads/google_mobile_ads.dart';

class AdController extends GetxController {
  // Observables for UI updates
  RxBool isBannerLoaded = false.obs;
  BannerAd? bannerAd;

  InterstitialAd? _interstitialAd;
  RewardedAd? _rewardedAd;

  // Test IDs (Android)
  final String bannerId = 'ca-app-pub-3940256099942544/6300978111';
  final String interstitialId = 'ca-app-pub-3940256099942544/1033173712';
  final String rewardedId = 'ca-app-pub-3940256099942544/5224354917';

  @override
  void onInit() {
    super.onInit();
    loadBanner();
    loadInterstitial();
    loadRewarded();
  }

  void loadBanner() {
    bannerAd = BannerAd(
      adUnitId: bannerId,
      request: const AdRequest(),
      size: AdSize.banner,
      listener: BannerAdListener(
        onAdLoaded: (ad) => isBannerLoaded.value = true,
        onAdFailedToLoad: (ad, error) {
          ad.dispose();
          isBannerLoaded.value = false;
        },
      ),
    )..load();
  }

  void loadInterstitial() {
    InterstitialAd.load(
      adUnitId: interstitialId,
      request: const AdRequest(),
      adLoadCallback: InterstitialAdLoadCallback(
        onAdLoaded: (ad) => _interstitialAd = ad,
        onAdFailedToLoad: (error) => _interstitialAd = null,
      ),
    );
  }

  void showInterstitial() {
    if (_interstitialAd != null) {
      _interstitialAd!.show();
      _interstitialAd = null;
      loadInterstitial(); // Reload for next use
    } else {
      Get.snackbar("Ads", "Interstitial not ready yet");
    }
  }

  void loadRewarded() {
    RewardedAd.load(
      adUnitId: rewardedId,
      request: const AdRequest(),
      rewardedAdLoadCallback: RewardedAdLoadCallback(
        onAdLoaded: (ad) => _rewardedAd = ad,
        onAdFailedToLoad: (error) => _rewardedAd = null,
      ),
    );
  }

  void showRewarded() {
    if (_rewardedAd != null) {
      _rewardedAd!.show(onUserEarnedReward: (ad, reward) {
        Get.snackbar("Reward", "You earned ${reward.amount} points!");
      });
      _rewardedAd = null;
      loadRewarded(); // Reload for next use
    } else {
      Get.snackbar("Ads", "Rewarded ad not ready yet");
    }
  }

  @override
  void onClose() {
    bannerAd?.dispose();
    _interstitialAd?.dispose();
    _rewardedAd?.dispose();
    super.onClose();
  }
}