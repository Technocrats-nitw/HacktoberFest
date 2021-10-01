/* 
  Blog Home Page
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
import 'package:blogesta/signUp.dart';
import 'package:cached_network_image/cached_network_image.dart';
import 'package:curved_navigation_bar/curved_navigation_bar.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

import 'drawer.dart';

class Home extends StatelessWidget {
  // const Home({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final Map userInfo = ModalRoute.of(context).settings.arguments;
    return SafeArea(
        child: Scaffold(
      bottomNavigationBar: CurvedNavigationBar(
        backgroundColor: Colors.black87,
        items: <Widget>[
          Icon(Icons.home, size: 30),
          Icon(CupertinoIcons.pencil, size: 30),
          Icon(Icons.favorite_sharp, size: 30),
          Icon(Icons.menu_book, size: 30),
        ],
        onTap: (index) async {
          Future.delayed(Duration(milliseconds: 600), () async {
            if (index == 1) {
              Navigator.pushNamed(context, '/write');
            }
            if (index == 0) {
              Navigator.pushNamed(context, '/');
            }
            if (index == 2) {
              FirebaseAuth _auth = FirebaseAuth.instance;
              final user = await _auth.currentUser();
              final dis = user.email;

              Navigator.pushNamed(context, '/fav', arguments: {
                "email": dis,
              });
            }
            if (index == 3) {
              final email = userInfo['email'];
              print(email);
              Navigator.pushNamed(context, '/list',
                  arguments: {"email": email});
            }
          });
        },
      ),
      backgroundColor: whiteCol,
      drawer: DrawerWig(
        display: userInfo['user'],
        email: userInfo['email'],
      ),
      appBar: AppBar(
        elevation: 0,
        backgroundColor: whiteCol,
        iconTheme: IconThemeData(color: colour),
        // leading: ,
        // /*Icon(
        //   Icons.list_outlined,
        //   color: colour,
        // ),*/
        title: Text(
          'Blogesta',
          style: TextStyle(
              color: colour, fontSize: 26, fontWeight: FontWeight.w900),
        ),
        centerTitle: true,
      ),
      body: HomeBody(
        email: email,
      ),
    ));
  }
}

class HomeBody extends StatelessWidget {
  final email;

  const HomeBody({Key key, this.email}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 16),
      child: SingleChildScrollView(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            SizedBox(
              height: 20,
            ),
            Container(
              color: Colors.grey[50],
              child: Row(
                children: [
                  Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'Feed Your',
                        style: TextStyle(
                            fontSize: 26, fontWeight: FontWeight.w600),
                      ),
                      SizedBox(
                        height: 5,
                      ),
                      Text(
                        'Curiosity',
                        style: curiosity,
                      ),
                    ],
                  ),
                  Image(
                    height: 140,
                    width: MediaQuery.of(context).size.width / 2 - 10,
                    image: AssetImage('assets/images/open.png'),
                  )
                ],
              ),
            ),
            Container(
              decoration: BoxDecoration(
                color: Color.fromRGBO(244, 243, 243, 1),
                borderRadius: BorderRadius.circular(15),
              ),
              child: TextField(
                decoration: InputDecoration(
                  border: InputBorder.none,
                  hintText: "Search you'r looking for",
                  prefixIcon: Icon(Icons.search),
                  hintStyle: TextStyle(fontSize: 13, color: Colors.grey),
                ),
              ),
            ),
            SizedBox(
              height: 20,
            ),
            Container(
              height: 160,
              child: ListView(
                scrollDirection: Axis.horizontal,
                children: [
                  horizonatlCard('assets/images/ms.jpg'),
                  horizonatlCard('assets/images/meeting.jpg'),
                  horizonatlCard('assets/images/magzine.jpg'),
                  horizonatlCard('assets/images/ms.jpg'),
                ],
              ),
            ),
            SizedBox(
              height: 20,
            ),
            cardList(context),
            Align(
              alignment: Alignment.centerRight,
              child: TextButton(
                onPressed: () {
                  Navigator.pushNamed(context, '/list',
                      arguments: {"email": email});
                },
                child: Text(
                  'See all',
                  style: TextStyle(color: Colors.orange, fontSize: 12),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

Widget horizonatlCard(image) {
  return Padding(
    padding: const EdgeInsets.only(right: 15),
    child: AspectRatio(
      aspectRatio: 2.2 / 3,
      child: Container(
          decoration: BoxDecoration(
            //    color:Colors.orange,
            borderRadius: BorderRadius.circular(12),
            image: DecorationImage(
              image: AssetImage(image),
              fit: BoxFit.fill,
            ),
          ),
          child: Container(
            decoration: BoxDecoration(
              borderRadius: BorderRadius.circular(12),
              gradient: LinearGradient(
                begin: Alignment.bottomRight,
                stops: [0.2, 0.9],
                colors: [
                  Colors.black.withOpacity(0.8),
                  Colors.black.withOpacity(0.1),
                ],
              ),
            ),
          )),
    ),
  );
}

String demoImg =
    "https://images.unsplash.com/photo-1516245834210-c4c142787335?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=749&q=80";
String demo =
    "Do you want to become a blockchain developer? If you do, then you have come to the right place Today, we will learn how anyone can become a blockchain developer.Blockchain development requires a different approach. It is not similar to web development, which makes it far more complex.Rohit99, a blockchain developer from India, knows the demand of blockchain developers. His word of advice is to stay updated with every changing move. According to him, blockchain technology is still in the nascent phase and will grow rapidly, improving demand for the best ones out there.";
String demoAuth = "Kerry Paly";
Widget cardList(context) {
  return SizedBox(
    height: 130,
    child: GestureDetector(
      onTap: () {
        Navigator.pushNamed(context, '/read', arguments: {
          "title": "Learn blockchain in 2021",
          "img": demoImg,
          "content": demo,
          "author": demoAuth
        });
      },
      child: Row(
        children: [
          Hero(
            tag: 'photo',
            child: ClipRRect(
              borderRadius: BorderRadius.circular(15),
              child: Container(
                height: 120,
                width: 160,
                child: CachedNetworkImage(
                  fit: BoxFit.fill,
                  imageUrl: demoImg,
                  maxHeightDiskCache: 200,
                ),
                decoration: BoxDecoration(
                  color: Colors.orange,
                  borderRadius: BorderRadius.circular(15),
                ),
              ),
            ),
          ),
          Flexible(
            child: Padding(
              padding: const EdgeInsets.only(left: 20, top: 5),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.baseline,
                textBaseline: TextBaseline.ideographic,
                children: [
                  Text('05 Mins Read', style: cardMIn),
                  SizedBox(
                    height: 5,
                  ),
                  Text(
                    'Learn blockchain in 2021',
                    softWrap: true,
                    maxLines: 3,
                    overflow: TextOverflow.ellipsis,
                    style: TextStyle(fontSize: 20, fontWeight: FontWeight.w600),
                  ),
                  Padding(
                    padding: const EdgeInsets.only(top: 8.0),
                    child: Align(
                        alignment: Alignment.bottomCenter,
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Text('By - Kerry paly'),
                            Icon(
                              Icons.favorite_border_outlined,
                              color: Colors.red,
                              size: 25,
                            ),
                          ],
                        )),
                  ),
                ],
              ),
            ),
          )
        ],
      ),
    ),
  );
}
