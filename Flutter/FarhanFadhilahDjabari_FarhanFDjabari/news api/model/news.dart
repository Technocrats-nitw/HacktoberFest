class News {
  News({
    this.status,
    this.totalResults,
    this.articles,
  });

  final String? status;
  final int? totalResults;
  final List<Article>? articles;

  factory News.fromJson(Map<String, dynamic> json) => News(
    status: json["status"],
    totalResults: json["totalResults"],
    articles: List<Article>.from(
        json["articles"].map((x) => Article.fromJson(x))),
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "totalResults": totalResults,
    "articles": List<dynamic>.from(articles!.map((x) => x.toJson())),
  };
}

class Article {
  Article({
    this.source,
    this.author,
    this.title,
    this.description,
    this.url,
    this.urlToImage,
    this.publishedAt,
    this.content,
  });

  final Source? source;
  final String? author;
  final String? title;
  final String? description;
  final String? url;
  final String? urlToImage;
  final DateTime? publishedAt;
  final String? content;

  factory Article.fromJson(Map<String, dynamic> json) => Article(
    source: Source.fromJson(json["source"]),
    author: json["author"] == null ? null : json["author"],
    title: json["title"],
    description: json["description"] == null ? null : json["description"],
    url: json["url"],
    urlToImage: json["urlToImage"] == null ? null : json["urlToImage"],
    publishedAt: DateTime.parse(json["publishedAt"]),
    content: json["content"] == null ? null : json["content"],
  );

  Map<String, dynamic> toJson() => {
    "source": source!.toJson(),
    "author": author == null ? null : author,
    "title": title,
    "description": description == null ? null : description,
    "url": url,
    "urlToImage": urlToImage == null ? null : urlToImage,
    "publishedAt": publishedAt!.toIso8601String(),
    "content": content == null ? null : content,
  };
}

class Source {
  Source({
    this.id,
    this.name,
  });

  final String? id;
  final String? name;

  factory Source.fromJson(Map<String, dynamic> json) => Source(
    id: json["id"] == null ? null : json["id"],
    name: json["name"],
  );

  Map<String, dynamic> toJson() => {
    "id": id == null ? null : id,
    "name": name,
  };
}
