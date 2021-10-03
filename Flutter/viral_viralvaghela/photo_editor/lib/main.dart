import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

import 'filters.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final List<List<num>> filters = [
    SEPIA_MATRIX,
    GREYSCALE_MATRIX,
    VINTAGE_MATRIX,
    SWEET_MATRIX,
    COLD_MATRIX,
    LIGHTEN_MATRIX
  ];

  var selectedFilterIndex;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: SafeArea(
        child: Scaffold(
          body: SingleChildScrollView(
            child: Column(
              children: [
                Container(
                  padding: EdgeInsets.all(10),
                  child: selectedFilterIndex != null
                      ? ClipRRect(
                          borderRadius: BorderRadius.circular(30),
                          child: ColorFiltered(
                            colorFilter: ColorFilter.matrix(
                                filters[selectedFilterIndex]),
                            child: Container(
                              child: Image.network(
                                "https://icatcare.org/app/uploads/2018/07/Thinking-of-getting-a-cat.png",
                                fit: BoxFit.cover,
                                height: 400,
                                width: 400,
                              ),
                            ),
                          ))
                      : ClipRRect(
                          borderRadius: BorderRadius.circular(30),
                          child: Image.network(
                            "https://icatcare.org/app/uploads/2018/07/Thinking-of-getting-a-cat.png",
                            fit: BoxFit.cover,
                            height: 400,
                            width: 400,
                          ),
                        ),
                ),
                SizedBox(
                  height: 200,
                  child: ListView.builder(
                      itemCount: filters.length,
                      scrollDirection: Axis.horizontal,
                      itemBuilder: (BuildContext ctx, int index) {
                        return InkWell(
                          onTap: () {
                            setState(() {
                              selectedFilterIndex = index;
                            });
                          },
                          child: ColorFiltered(
                            colorFilter: ColorFilter.matrix(filters[index]),
                            child: Container(
                              padding: EdgeInsets.all(5),
                              child: Image.network(
                                "https://icatcare.org/app/uploads/2018/07/Thinking-of-getting-a-cat.png",
                                fit: BoxFit.cover,
                                height: 200,
                                width: 200,
                              ),
                            ),
                          ),
                        );
                      }),
                ),
                // Center(
                //     child: TextButton(onPressed: () {}, child: Text("Asd0"))),
              ],
            ),
          ),
          floatingActionButton: FloatingActionButton(
            child: Icon(
              Icons.refresh_outlined,
            ),
            onPressed: () {
              setState(() {
                selectedFilterIndex = null;
              });
            },
          ),
        ),
      ),
    );
  }
}
