import 'dart:async';
import 'dart:convert';

import 'package:http/http.dart' as http; //add http package in pubspec.yaml

class FlutterGithub {
  String url = "https://api.github.com/users/";
  late int _publicRepos, _publicGist, _followers, _following;
  late String _image, _name, _company, _location, _email, _bio;
  late bool _hireAble;
  var _createdAt,
      _updatedAt,
      _followersData,
      _followingData,
      _starredData,
      _subscriptionsData,
      _orgsData,
      _reposData;

  Future<void> getUserData(String userName) async {
    final response = await http.get(url + userName);
    final secondUrl = url + userName + "/";

    final responseData = json.decode(response.body) as Map<String, dynamic>;
    _image = responseData['avatar_url'];

    _name = responseData['name'];
    _company = responseData['company'];
    _bio = responseData['bio'];

    _location = responseData['location'];
    _email = responseData['email'];
    _hireAble = responseData['hireable'];

    _publicRepos = responseData['public_repos'];
    _publicGist = responseData['public_gists'];
    _followers = responseData['followers'];
    _following = responseData['following'];

    var createdAt = DateTime.parse(responseData['created_at']);
    _createdAt = "${createdAt.day}-${createdAt.month}-${createdAt.year}";

    var updatedAt = DateTime.parse(responseData['updated_at']);
    _updatedAt = "${updatedAt.day}-${updatedAt.month}-${updatedAt.year}";

    var followersUrl = responseData['followers_url'];
    final followersResponse = await http.get(followersUrl);

    _followersData = json.decode(followersResponse.body);
    var followingUrl = secondUrl + "following";
    final followingResponse = await http.get(followingUrl);
    _followingData = json.decode(followingResponse.body);
    var starredUrl = secondUrl + "starred";
    final starredResponse = await http.get(starredUrl);
    _starredData = json.decode(starredResponse.body);
    var subscriptionsUrl = secondUrl + "subscriptions";
    final subscriptionResponse = await http.get(subscriptionsUrl);
    _subscriptionsData = json.decode(subscriptionResponse.body);
    final orgsUrl = secondUrl + "orgs";
    final orgsResponse = await http.get(orgsUrl);
    _orgsData = json.decode(orgsResponse.body);
    final reposUrl = secondUrl + "repos";
    final reposResponse = await http.get(reposUrl);
    _reposData = json.decode(reposResponse.body);
  }

  String get image => _image;

  get email => _email;

  get company => _company;

  get location => _location;

  get hireAble => _hireAble;

  get name => _name;

  get createdAt => _createdAt;

  get followers => _followers;

  get following => _following;

  get followersData => _followersData;

  get publicRepos => _publicRepos;

  get publicGists => _publicGist;

  get followingData => _followingData;

  get updatedAt => _updatedAt;

  get starredData => _starredData;

  get subscriptionsData => _subscriptionsData;

  get orgsData => _orgsData;

  get bio => _bio;

  get reposData => _reposData;
}