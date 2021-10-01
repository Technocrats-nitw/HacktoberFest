import 'package:blogesta/constant.dart';
// ignore: import_of_legacy_library_into_null_safe
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:modal_progress_hud/modal_progress_hud.dart';

String email = "", pas = "";

class SignUp extends StatefulWidget {
  // SignUp({Key? key}) : super(key: key);
  @override
  _SignUpState createState() => _SignUpState();
}

class _SignUpState extends State<SignUp> {
  bool isSpin = false;
  final _nameController = TextEditingController();

  final _emailController = TextEditingController();

  final _pasController = TextEditingController();

  final _repasController = TextEditingController();

  Future<bool> registerUser(
      String name, String email, String pas, String rePas) async {
    FirebaseAuth _auth = FirebaseAuth.instance;
    try {
      AuthResult result = await _auth.createUserWithEmailAndPassword(
          email: email, password: pas);

      FirebaseUser user = result.user;
      UserUpdateInfo info = UserUpdateInfo();
      info.displayName = name;
      user.updateProfile(info);
      return true;
    } catch (e) {
      print(e);
      return false;
    }
  }

  final formKey1 = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: ModalProgressHUD(
        inAsyncCall: isSpin,
        child: SingleChildScrollView(
          child: Material(
            color: whiteCol,
            child: Form(
              child: Column(
                children: [
                  Image(
                    image: AssetImage('assets/images/pic6.png'),
                    height: 120,
                    width: 120,
                  ),
                  Text(
                    'Create Account',
                    style: boldHeading,
                  ),
                  SizedBox(
                    height: 5,
                  ),
                  Text(
                    'Create a new Account',
                    style: secondarytext,
                  ),
                  SizedBox(
                    height: 20,
                  ),
                  Padding(
                    padding: const EdgeInsets.symmetric(
                        horizontal: 28, vertical: 15),
                    child: Material(
                      color: whiteCol,
                      elevation: 2,
                      shadowColor: Colors.grey[100],
                      child: TextFormField(
                    //    key: formKey,
                        validator: (val) {
                          if (val.isEmpty)
                            return "This feild can be empty";
                          else
                            return null;
                        },
                        textCapitalization: TextCapitalization.sentences,
                        controller: _nameController,
                        style: TextStyle(color: colour),
                        keyboardType: TextInputType.name,
                        decoration: InputDecoration(
                          labelText: "NAME",

                          labelStyle:
                              TextStyle(color: colour, letterSpacing: 1.2),
                          border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(20),
                              borderSide: BorderSide.none),
                          //  filled: true,
                          // fillColor: Colors.grey[100],

                          prefixIcon: Icon(Icons.person, color: colour),
                        ),
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.symmetric(
                        horizontal: 28, vertical: 15),
                    child: Material(
                      color: whiteCol,
                      elevation: 2,
                      shadowColor: Colors.grey[100],
                      child: TextFormField(
                      //  key: formKey,
                        validator: (val) {
                          return RegExp(
                                      r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
                                  .hasMatch(val)
                              ? null
                              : "Please enter correct email";
                        },
                        controller: _emailController,
                        style: TextStyle(color: colour),
                        keyboardType: TextInputType.emailAddress,
                        decoration: InputDecoration(
                          labelText: "EMAIL",

                          labelStyle:
                              TextStyle(color: colour, letterSpacing: 1.2),
                          border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(20),
                              borderSide: BorderSide.none),
                          //  filled: true,
                          // fillColor: Colors.grey[100],

                          prefixIcon: Icon(Icons.email_outlined, color: colour),
                        ),
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.symmetric(
                        horizontal: 28, vertical: 15),
                    child: Material(
                      color: whiteCol,
                      elevation: 2,
                      shadowColor: Colors.grey[100],
                      child: TextFormField(
                  //      key: formKey,
                        validator: (val) {
                          return val.length > 6
                              ? null
                              : "Please provide password with 6 + characters";
                        },
                        controller: _pasController,
                        style: TextStyle(color: colour),
                        obscureText: true,
                        keyboardType: TextInputType.visiblePassword,
                        decoration: InputDecoration(
                          labelText: "PASSWORD",

                          labelStyle:
                              TextStyle(color: colour, letterSpacing: 1.2),
                          border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(20),
                              borderSide: BorderSide.none),
                          //  filled: true,
                          // fillColor: Colors.grey[100],

                          prefixIcon: Icon(Icons.lock, color: colour),
                        ),
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.symmetric(
                        horizontal: 28, vertical: 15),
                    child: Material(
                      color: whiteCol,
                      elevation: 2,
                      shadowColor: Colors.grey[100],
                      child: TextFormField(
                   //     key: formKey,
                        validator: (val) {
                          if (val.length > 5 && val == _pasController.text)
                            return null;
                          else {
                            if (val.length < 6)
                              return "Password must be atleast of 6 length ";
                            else {
                              return "Password do not match";
                            }
                          }
                        },
                        obscureText: true,
                        controller: _repasController,
                        style: TextStyle(color: colour),
                        keyboardType: TextInputType.visiblePassword,
                        decoration: InputDecoration(
                          labelText: "CONFIRM PASSWORD",

                          labelStyle:
                              TextStyle(color: colour, letterSpacing: 1.2),
                          border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(20),
                              borderSide: BorderSide.none),
                          //  filled: true,
                          // fillColor: Colors.grey[100],

                          prefixIcon: Icon(Icons.lock, color: colour),
                        ),
                      ),
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
                      //  if (formKey1.currentState.validate()) {
                        setState(() {
                              isSpin = true;
                            });
                          try {
                            

                            bool result = await registerUser(
                                _nameController.text.toString().trim(),
                                _emailController.text.toString().trim(),
                                _pasController.text.toString().trim(),
                                _repasController.text.toString().trim());

                            if (result) {
                              Navigator.pushNamed(context, '/home', arguments: {
                                "user": _nameController.text,
                                "email": _emailController.text,
                              });
                            } else {
                              print("error");
                            }
                            setState(() {
                              isSpin = false;
                            });
                          } catch (e) {
                            print(e);
                    //      }
                        }
                      },
                      child: Text(
                        'CREATE ACCOUNT',
                        style: TextStyle(letterSpacing: 1),
                      ),
                    ),
                  ),
                  SizedBox(
                    height: 15,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text('Already have a account?',
                          style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 16,
                              fontWeight: FontWeight.w600)),
                      TextButton(
                        onPressed: () {
                          Navigator.pushNamed(context, '/login');
                        },
                        child: Text(
                          'Login',
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

Widget feild(icon, txt, b, board) {
  return Padding(
    padding: const EdgeInsets.symmetric(horizontal: 28),
    child: Container(
      decoration: BoxDecoration(
        color: Color.fromRGBO(244, 243, 243, 1),
        borderRadius: BorderRadius.circular(15),
      ),
      child: TextField(
        keyboardType: board,
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
