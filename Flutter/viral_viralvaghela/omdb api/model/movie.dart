class Movie {
  String _title;
  String _year;
  String _rated;
  String _released;
  String _runtime;
  String _genre;
  String _director;
  String _writer;
  String _actors;
  String _plot;
  String _language;
  String _country;
  String _awards;
  String _poster;
  List<Ratings> _ratings;
  String _metascore;
  String _imdbRating;
  String _imdbVotes;
  String _imdbID;
  String _type;
  String _dVD;
  String _boxOffice;
  String _production;
  String _website;
  String _response;

  Movie(
      {String title,
        String year,
        String rated,
        String released,
        String runtime,
        String genre,
        String director,
        String writer,
        String actors,
        String plot,
        String language,
        String country,
        String awards,
        String poster,
        List<Ratings> ratings,
        String metascore,
        String imdbRating,
        String imdbVotes,
        String imdbID,
        String type,
        String dVD,
        String boxOffice,
        String production,
        String website,
        String response}) {
    this._title = title;
    this._year = year;
    this._rated = rated;
    this._released = released;
    this._runtime = runtime;
    this._genre = genre;
    this._director = director;
    this._writer = writer;
    this._actors = actors;
    this._plot = plot;
    this._language = language;
    this._country = country;
    this._awards = awards;
    this._poster = poster;
    this._ratings = ratings;
    this._metascore = metascore;
    this._imdbRating = imdbRating;
    this._imdbVotes = imdbVotes;
    this._imdbID = imdbID;
    this._type = type;
    this._dVD = dVD;
    this._boxOffice = boxOffice;
    this._production = production;
    this._website = website;
    this._response = response;
  }

  String get title => _title;
  set title(String title) => _title = title;
  String get year => _year;
  set year(String year) => _year = year;
  String get rated => _rated;
  set rated(String rated) => _rated = rated;
  String get released => _released;
  set released(String released) => _released = released;
  String get runtime => _runtime;
  set runtime(String runtime) => _runtime = runtime;
  String get genre => _genre;
  set genre(String genre) => _genre = genre;
  String get director => _director;
  set director(String director) => _director = director;
  String get writer => _writer;
  set writer(String writer) => _writer = writer;
  String get actors => _actors;
  set actors(String actors) => _actors = actors;
  String get plot => _plot;
  set plot(String plot) => _plot = plot;
  String get language => _language;
  set language(String language) => _language = language;
  String get country => _country;
  set country(String country) => _country = country;
  String get awards => _awards;
  set awards(String awards) => _awards = awards;
  String get poster => _poster;
  set poster(String poster) => _poster = poster;
  List<Ratings> get ratings => _ratings;
  set ratings(List<Ratings> ratings) => _ratings = ratings;
  String get metascore => _metascore;
  set metascore(String metascore) => _metascore = metascore;
  String get imdbRating => _imdbRating;
  set imdbRating(String imdbRating) => _imdbRating = imdbRating;
  String get imdbVotes => _imdbVotes;
  set imdbVotes(String imdbVotes) => _imdbVotes = imdbVotes;
  String get imdbID => _imdbID;
  set imdbID(String imdbID) => _imdbID = imdbID;
  String get type => _type;
  set type(String type) => _type = type;
  String get dVD => _dVD;
  set dVD(String dVD) => _dVD = dVD;
  String get boxOffice => _boxOffice;
  set boxOffice(String boxOffice) => _boxOffice = boxOffice;
  String get production => _production;
  set production(String production) => _production = production;
  String get website => _website;
  set website(String website) => _website = website;
  String get response => _response;
  set response(String response) => _response = response;

  Movie.fromJson(Map<String, dynamic> json) {
    _title = json['Title'];
    _year = json['Year'];
    _rated = json['Rated'];
    _released = json['Released'];
    _runtime = json['Runtime'];
    _genre = json['Genre'];
    _director = json['Director'];
    _writer = json['Writer'];
    _actors = json['Actors'];
    _plot = json['Plot'];
    _language = json['Language'];
    _country = json['Country'];
    _awards = json['Awards'];
    _poster = json['Poster'];
    if (json['Ratings'] != null) {
      _ratings = new List<Ratings>();
      json['Ratings'].forEach((v) {
        _ratings.add(new Ratings.fromJson(v));
      });
    }
    _metascore = json['Metascore'];
    _imdbRating = json['imdbRating'];
    _imdbVotes = json['imdbVotes'];
    _imdbID = json['imdbID'];
    _type = json['Type'];
    _dVD = json['DVD'];
    _boxOffice = json['BoxOffice'];
    _production = json['Production'];
    _website = json['Website'];
    _response = json['Response'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['Title'] = this._title;
    data['Year'] = this._year;
    data['Rated'] = this._rated;
    data['Released'] = this._released;
    data['Runtime'] = this._runtime;
    data['Genre'] = this._genre;
    data['Director'] = this._director;
    data['Writer'] = this._writer;
    data['Actors'] = this._actors;
    data['Plot'] = this._plot;
    data['Language'] = this._language;
    data['Country'] = this._country;
    data['Awards'] = this._awards;
    data['Poster'] = this._poster;
    if (this._ratings != null) {
      data['Ratings'] = this._ratings.map((v) => v.toJson()).toList();
    }
    data['Metascore'] = this._metascore;
    data['imdbRating'] = this._imdbRating;
    data['imdbVotes'] = this._imdbVotes;
    data['imdbID'] = this._imdbID;
    data['Type'] = this._type;
    data['DVD'] = this._dVD;
    data['BoxOffice'] = this._boxOffice;
    data['Production'] = this._production;
    data['Website'] = this._website;
    data['Response'] = this._response;
    return data;
  }
}

class Ratings {
  String _source;
  String _value;

  Ratings({String source, String value}) {
    this._source = source;
    this._value = value;
  }

  String get source => _source;
  set source(String source) => _source = source;
  String get value => _value;
  set value(String value) => _value = value;

  Ratings.fromJson(Map<String, dynamic> json) {
    _source = json['Source'];
    _value = json['Value'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['Source'] = this._source;
    data['Value'] = this._value;
    return data;
  }
}