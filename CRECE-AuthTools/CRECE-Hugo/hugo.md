# Introduction to Hugo

## Installing a theme

### How to start 

You can download the theme manually by going to its url, in ths case, we'll instal the hugo theme [__hello-frien-ng__](https://themes.gohugo.io/hugo-theme-hello-friend-ng/). Most of hugo themes are located in a [Github](https://github.com) repository so we can easily download it from the repository the zip file and pasting it to `themes/hello-friend-ng` in your root directory.

You can also clone it directly to your Hugo folder:

```bash
$ git clone https://github.com/rhazdon/hugo-theme-hello-friend-ng.git themes/hello-friend-ng
```

If you don’t want to make any radical changes, it’s the best option, because you can get new updates when they are available. To do so, include it as a git submodule:

```bash
$ git submodule add https://github.com/rhazdon/hugo-theme-hello-friend-ng.git themes/hello-friend-ng
```

### Configuration 

The theme doesn’t require any advanced configuration, but it is very configurable. Just copying the following config file, you can see all possible configurations, [check the docs](https://themes.gohugo.io/hugo-theme-hello-friend-ng/docs/config.md). Note: There are more options to configure. Take a look into the `config.toml` in `exampleSite`. This is extensible to other hugo themes.

```toml
baseurl      = "localhost"
title        = "My Blog"
languageCode = "en-us"
theme        = "hello-friend-ng"
paginate     = 10

[params]
  dateform        = "Jan 2, 2006"
  dateformShort   = "Jan 2"
  dateformNum     = "2006-01-02"
  dateformNumTime = "2006-01-02 15:04"

  # Subtitle for home
  homeSubtitle = "A simple and beautiful blog"

  # Set disableReadOtherPosts to true in order to hide the links to other posts.
  disableReadOtherPosts = false

  # Enable sharing buttons, if you like
  enableSharingButtons = true

  # Metadata mostly used in document's head
  description = "My new homepage or blog"
  keywords = "homepage, blog"
  images = [""]

[taxonomies]
    category = "blog"
    tag      = "tags"
    series   = "series"

[languages]
  [languages.en]
    title = "Hello Friend NG"
    subtitle = "A simple theme for Hugo"
    keywords = ""
    copyright = '<a href="https://creativecommons.org/licenses/by-nc/4.0/" target="_blank" rel="noopener">CC BY-NC 4.0</a>'
    readOtherPosts = "Read other posts"

    [languages.en.params.logo]
      logoText = "hello friend ng"
      logoHomeLink = "/"
    # or
    #
    # path = "/img/your-example-logo.svg"
    # alt = "Your example logo alt text"

  # And you can even create generic menu
  [[menu.main]]
    identifier = "blog"
    name       = "Blog"
    url        = "/posts"
```

## 