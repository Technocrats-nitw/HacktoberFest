import 'dart:convert';

import 'package:http/http.dart' as http;

import 'package:./model/news.dart';

class NewsApi {
  final String base = 'https://newsapi.org/v2/top-headlines';
  String _apiKey = 'your_api_key';
  String _country = 'us';

  Future<News> getNews() async {
    final _response =
    await http.get(Uri.parse('$base?country=$_country&apiKey=$_apiKey'));

    return News.fromJson(jsonDecode(_response.body));
  }
}
