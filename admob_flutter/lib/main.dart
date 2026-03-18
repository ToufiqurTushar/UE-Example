import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_mobile_ads/google_mobile_ads.dart';

import 'AdController.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await MobileAds.instance.initialize();
  // Add this block to register your specific physical device for test ads
  MobileAds.instance.updateRequestConfiguration(
    RequestConfiguration(
      testDeviceIds: ["A52928748FF38C59F746DA17232584B7"], // Use the ID from your logs
    ),
  );
  runApp(const GetMaterialApp(home: AdView()));
}

class AdView extends StatelessWidget {
  const AdView({super.key});

  @override
  Widget build(BuildContext context) {
    // Initialize the controller
    final AdController controller = Get.put(AdController());

    return Scaffold(
      appBar: AppBar(title: const Text("GetX AdMob Example")),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              onPressed: controller.showInterstitial,
              child: const Text("Show Interstitial"),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: controller.showRewarded,
              child: const Text("Show Rewarded"),
            ),
          ],
        ),
      ),
      // Reactive Banner display using Obx
      bottomNavigationBar: Obx(() {
        if (controller.isBannerLoaded.value) {
          return SizedBox(
            height: controller.bannerAd!.size.height.toDouble(),
            width: controller.bannerAd!.size.width.toDouble(),
            child: AdWidget(ad: controller.bannerAd!),
          );
        }
        return const SizedBox.shrink();
      }),
    );
  }
}
