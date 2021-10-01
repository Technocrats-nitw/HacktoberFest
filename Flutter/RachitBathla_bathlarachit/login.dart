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
import 'package:blogesta/constant.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
// ignore: import_of_legacy_library_into_null_safe
import 'package:firebase_auth/firebase_auth.dart';
import 'package:modal_progress_hud/modal_progress_hud.dart';

class Login extends StatefulWidget {
  // Login({Key? key}) : super(key: key);
  @override
  _LoginState createState() => _LoginState();
}

class _LoginState extends State<Login> {
  bool isSpin = false;

  String vali(val) {
    return RegExp(
                r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
            .hasMatch(val)
        ? null
        : "Please enter correct email";
  }

  String userVali(val) {
    return val.length > 5
        ? null
        : "Please provide password with 6 or more  characters";
  }

  final _emailController = TextEditingController();

  final _passController = TextEditingController();

  Future<FirebaseUser> login(String email, String password) async {
    try {
      FirebaseAuth _auth = FirebaseAuth.instance;
      AuthResult result = await _auth.signInWithEmailAndPassword(
          email: email, password: password);
      FirebaseUser user = result.user;
      return user;
    } catch (e) {
      print("error");
      return null;
    }
  }

  final formKey = GlobalKey<FormState>();
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Material(
        color: whiteCol,
        child: ModalProgressHUD(
          inAsyncCall: isSpin,
          child: SingleChildScrollView(
            child: Form(
              key: formKey,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                mainAxisAlignment: MainAxisAlignment.start,
                children: [
                  SizedBox(
                    height: 40,
                  ),
                  Image(
                    image: AssetImage("assets/images/boy.png"),
                    height: 180,
                    width: 180,
                  ),
                  SizedBox(
                    height: 15,
                  ),

                  Text(
                    'Welcome Back ',
                    style: boldHeading,
                  ),
                  SizedBox(
                    height: 5,
                  ),
                  Text(
                    'Sign to continue',
                    style: secondarytext,
                  ),
                  SizedBox(
                    height: 40,
                  ),
                  feild(Icons.email_outlined, "EMAIL", false, _emailController,
                      vali),

                  SizedBox(
                    height: 40,
                  ),

                  feild(Icons.lock_outline_rounded, "PASSWORD", true,
                      _passController, userVali),

                  // password

                  Padding(
                    padding: const EdgeInsets.only(top: 18, left: 200),
                    child: Text(
                      'Forgot Password?',
                      style: forgot,
                    ),
                  ),
                  SizedBox(
                    height: 40,
                  ),
                  SizedBox(
                    height: 48,
                    width: 340,
                    child: ElevatedButton(
                      style: btnStyle,
                      onPressed: () async {
                        if (formKey.currentState.validate()) {
                          setState(() {
                            isSpin = true;
                          });
                          try {
                            FirebaseUser user = await login(
                                _emailController.text.toString().trim(),
                                _passController.text.toString().trim());

                            if (user != null) {
                              print(user.displayName);
                              //    FirebaseAuth _auth = FirebaseAuth.instance;
                              //  final user = await _auth.currentUser();
                              Navigator.pushNamed(context, '/home', arguments: {
                                "user": user.displayName,
                                "email": user.email,
                              });
                            } else {
                              print('error occur');
                              setState(() {
                                isSpin = false;
                              });
                            }
                          } catch (e) {
                            print(e);
                          }
                        }
                      },
                      child: Text(
                        'LOGIN',
                        style: TextStyle(letterSpacing: 1),
                      ),
                    ),
                  ),
                  SizedBox(
                    height: 10,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text('Don\'t have account?',
                          style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 16,
                              fontWeight: FontWeight.w400)),
                      TextButton(
                        onPressed: () {
                          Navigator.pushNamed(context, '/SignUp');
                        },
                        child: Text(
                          'create a new account',
                          style: account,
                        ),
                      )
                    ],
                  )
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}

Widget feild(icon, txt, b, cont, vali) {
  return Padding(
    padding: const EdgeInsets.symmetric(horizontal: 28),
    child: Container(
      decoration: BoxDecoration(
        color: Color.fromRGBO(244, 243, 243, 1),
        borderRadius: BorderRadius.circular(15),
      ),
      child: TextFormField(
        validator: vali,
        controller: cont,
        keyboardType: (b == true)
            ? TextInputType.visiblePassword
            : TextInputType.emailAddress,
        obscureText: b,
        decoration: InputDecoration(
          border: InputBorder.none,
          hintText: txt,
          prefixIcon: Icon(icon),
          hintStyle: TextStyle(fontSize: 13, color: Colors.grey),
        ),
      ),
    ),
  );
}
