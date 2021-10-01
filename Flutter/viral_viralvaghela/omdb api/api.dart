import 'dart:convert';
import 'dart:core';

import 'package:http/http.dart' as http;
import 'package:./model/movie.dart';

class Omdb {
  final String base_url = "http://www.omdbapi.com/?t=";
  String _api;
  String _movieName;
  Movie movie;
  Omdb(this._api, this._movieName);
  Future<void> getMovie() async {
    String myurl = "$base_url$_movieName&apikey=$_api";
    var res = await http.get(myurl);
    var decodedjson = jsonDecode(res.body);
    movie= Movie.fromJson(decodedjson);
  }

}