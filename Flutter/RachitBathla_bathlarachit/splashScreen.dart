/*

 dependencies:
  flutter:
    sdk: flutter


  # The following adds the Cupertino Icons font to your application.
  # Use with the CupertinoIcons class for iOS style icons.
  cupertino_icons: ^1.0.2
  curved_navigation_bar: ^1.0.1
  cloud_firestore: ^0.12.9+5
  firebase_core: ^0.4.0+9
  firebase_auth: ^0.14.0+5
  firebase_analytics: ^5.0.2
  cached_network_image: ^3.1.0
  modal_progress_hud: ^0.1.3
  animated_splash_screen: ^1.1.0
  google_fonts: ^2.1.0
  flutter_launcher_icons: ^0.9.2

flutter_icons:
  android: true
  ios: true
  image_path: "assets/images/logo.png"

dev_dependencies:
  flutter_test:
    sdk: flutter


*/

import 'package:animated_splash_screen/animated_splash_screen.dart';
import 'package:blogesta/login.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import 'constant.dart';

class Splash extends StatelessWidget {
  const Splash({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: AnimatedSplashScreen(
        splashIconSize: 200,
        //  centered: true,
        splashTransition: SplashTransition.fadeTransition,
        nextScreen: Login(),
        splash: SizedBox(
          height: 450,
          width: 350,
          child: ListView(
            children: [
              Image(
                height: 120,
                image: AssetImage('assets/images/read.png'),
              ),
              Align(
                  alignment: Alignment.center,
                  child: Text(
                    "Blogesta",
                    style: GoogleFonts.permanentMarker(
                        color: colour, fontSize: 32),
                  )),
            ],
          ),
        ),
      ),
    );
  }
}
