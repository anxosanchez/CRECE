## Markdown dialects

One of the problems (or advantages) of markdown is the number of dialects generated last years. THere are several things you cant, and cannot do depending on the markdown dialect you choose. In the next table you can see a selection of dialects and features of some of the most popular markdown variations that exist now (see [https://github.com/rhythmus/markdown-resources/blob/master/markdown-dialects.yml](https://github.com/rhythmus/markdown-resources/blob/master/markdown-dialects.yml)) or the [wikipedia markdown article](https://en.wikipedia.org/w/index.php?search=Markdown&title=Special%3ASearch&profile=advanced&fulltext=1&ns0=1).

| Markdown dialect               | Supported features                                           |
| ------------------------------ | ------------------------------------------------------------ |
| Original (markdown)            | headers (six levels)<br>headers (six levels)<br>paragraphs<br>unordered lists<br>ordered lists<br>nested lists (?)<br>blockquotes<br>block code<br>inline code<br>inline format emphasize<br>inline format strong<br>auto links<br>inline links<br>referenced links<br>inline images<br>block level images<br>referenced images<br>horizontal rule<br>mplementations: Perl |
| CommonMark                     | *plain-markdown<br/>implementations: Javascript, C           |
| Madoko                         | *plain-markdown # plus some _may_ more…<br/>implementations: Koka |
| GitHub Flavored Markdown (GFM) | *plain-markdown<br/>fenced code blocks<br/>syntax highlighting<br/>task Lists<br/>emoji autocomplete |
| Stack Overflow Markdown flavor | Sama as Github?                                              |
| Pandoc Markdown                | implementations: Haskell                                     |
| MultiMarkdown                  | *plain-markdown<br>  tables citations and bibliography (using BibTeX)<br>math automatic cross-referencing ability<br>smart typography (multiple languages)<br/>image attributes captions (tables and images)<br/>definition lists<br/>glossary entries (LaTeX only)<br/>document metadata (title, author, etc.)<br/>footnotes<br>implementations: C |
| Markdown Extra                 | *plain-markdown<br>inline html<br>Markdown inside html<br/>blocksheader ID<br/>attributefenced code<br/>blockstables definition<br/>lists<br/>footnotes<br/>abbreviations<br/>emphasis<br/>backslash escapes<br/ |
| Maruku                         | implementations: Ruby                                        |
| Strictdown                     | *plain-markdown # (with a few differences)<br>table of contents<br/>simple code blocks<br/>fenced code blocks<br/>definition<br/>lists<br/>tables<br/>deletions<br/>literal text<br/>code snippets<br/>footnotes<br/>abbreviations<br/>anchors and inline references<br/>advanced reference links<br/>block divider<br/>sub-indented elements<br/>macros |

A nighmare isn't it?.

Most of the complains the basic syntax of markdown original. The advanced features can be enabled by using a lightweight markup language that builds upon the basic Markdown syntax, or by adding an extension to a compatible Markdown processor.

## Markdown software

Not all Markdown applications support extended syntax elements. You’ll need to check whether or not the lightweight markup language your application is using supports the extended syntax elements you want to use. If it doesn’t, it may still be possible to enable extensions in your Markdown processor. For example,Typora is an excellent  processor for Github flavor but, if you are a high math syntax use, probablily you may use Jupyter Lab.

There are several lightweight markup languages that are *supersets* of Markdown. They include Gruber’s basic syntax and build upon it by adding additional elements like tables, code blocks, syntax highlighting, URL auto-linking, and footnotes. Many of the most popular Markdown applications use one of the following lightweight markup languages:

- [CommonMark](https://commonmark.org/)
- [GitHub Flavored Markdown (GFM)](https://github.github.com/gfm/)
- [Markdown Extra](https://michelf.ca/projects/php-markdown/extra/)
- [MultiMarkdown](https://fletcherpenney.net/multimarkdown/)
- [R Markdown](https://rmarkdown.rstudio.com/)

## Tables

To add a table, use three or more hyphens (`---`) to create each column’s header, and use pipes (`|`) to separate each column. You can optionally add pipes on either end of the table.

```
| Syntax      | Description |
| ----------- | ----------- |
| Header      | Title       |
| Paragraph   | Text        |
```

The rendered output looks like this:

| Syntax    | Description |
| --------- | ----------- |
| Header    | Title       |
| Paragraph | Text        |

Cell widths can vary, as shown below. The rendered output will look the same.

```
| Syntax | Description |
| --- | ----------- |
| Header | Title |
| Paragraph | Text |
```

 **Tip:** Creating tables with hyphens and pipes can be tedious. To speed up the process, try using the [Markdown Tables Generator](https://www.tablesgenerator.com/markdown_tables). Build a table using the graphical interface, and then copy the generated Markdown-formatted text into your file.

### Alignment

You can align text in the columns to the left, right, or center by adding a colon (`:`) to the left, right, or on both side of the hyphens within the header row.

```
| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |
```

The rendered output looks like this:

| Syntax    | Description |   Test Text |
| :-------- | :---------: | ----------: |
| Header    |    Title    | Here’s this |
| Paragraph |    Text     |    And more |

### Formatting Text in Tables

You can format the text within tables. For example, you can add [links](https://www.markdownguide.org/basic-syntax/#links), [code](https://www.markdownguide.org/basic-syntax/#code-1) (words or phrases in backticks (```) only, not [code blocks](https://www.markdownguide.org/basic-syntax/#code-blocks)), and [emphasis](https://www.markdownguide.org/basic-syntax/#emphasis).

You can’t add headings, blockquotes, lists, horizontal rules, images, or HTML tags.

### Escaping Pipe Characters in Tables

You can display a pipe (`|`) character in a table by using its HTML character code (`|`).

## Fenced Code Blocks

The basic Markdown syntax allows you to create [code blocks](https://www.markdownguide.org/basic-syntax#code-blocks) by indenting lines by four spaces or one tab. If you find that inconvenient, try using fenced code blocks. Depending on your Markdown processor or editor, you’ll use three backticks (`````) or three tildes (`~~~`) on the lines before and after the code block. The best part? You don’t have to indent any lines!

```
​```
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
​```
```

The rendered output looks like this:

```
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```

 **Tip:** Need to display backticks inside a code block? See [this section](https://www.markdownguide.org/basic-syntax/#escaping-backticks) to learn how to escape them.

### Syntax Highlighting

Many Markdown processors support syntax highlighting for fenced code blocks. This feature allows you to add color highlighting for whatever language your code was written in. To add syntax highlighting, specify a language next to the backticks before the fenced code block.

```
​```json
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
​```
```

The rendered output looks like this:

```
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```

## Footnotes

Footnotes allow you to add notes and references without cluttering the body of the document. When you create a footnote, a superscript number with a link appears where you added the footnote reference. Readers can click the link to jump to the content of the footnote at the bottom of the page.

To create a footnote reference, add a caret and an identifier inside brackets (`[^1]`). Identifiers can be numbers or words, but they can’t contain spaces or tabs. Identifiers only correlate the footnote reference with the footnote itself — in the output, footnotes are numbered sequentially.

Add the footnote using another caret and number inside brackets with a colon and text (`[^1]: My footnote.`). You don’t have to put footnotes at the end of the document. You can put them anywhere except inside other elements like lists, block quotes, and tables.

```
Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.

[^bignote]: Here's one with multiple paragraphs and code.

    Indent paragraphs to include them in the footnote.

    `{ my code }`

    Add as many paragraphs as you like.
```

The rendered output looks like this:

Here’s a simple footnote,[1](https://www.markdownguide.org/extended-syntax/#fn:1) and here’s a longer one.[2](https://www.markdownguide.org/extended-syntax/#fn:bignote)

1. This is the first footnote. [↩](https://www.markdownguide.org/extended-syntax/#fnref:1)

2. Here’s one with multiple paragraphs and code.

   Indent paragraphs to include them in the footnote.

   `{ my code }`

   Add as many paragraphs as you like. [↩](https://www.markdownguide.org/extended-syntax/#fnref:bignote)

## Heading IDs

Many Markdown processors support custom IDs for [headings](https://www.markdownguide.org/basic-syntax/#headings) — some Markdown processors automatically add them. Adding custom IDs allows you to link directly to headings and modify them with CSS. To add a custom heading ID, enclose the custom ID in curly braces on the same line as the heading.

```
### My Great Heading {#custom-id}
```

The HTML looks like this:

```
<h3 id="custom-id">My Great Heading</h3>
```

### Linking to Heading IDs

You can link to headings with custom IDs in the file by creating a [standard link](https://www.markdownguide.org/basic-syntax/#links) with a number sign (`#`) followed by the custom heading ID.

| Markdown                      | HTML                                     | Rendered Output                                              |
| ----------------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| `[Heading IDs](#heading-ids)` | `<a href="#heading-ids">Heading IDs</a>` | [Heading IDs](https://www.markdownguide.org/extended-syntax/#heading-ids) |

Other websites can link to the heading by adding the custom heading ID to the full URL of the webpage (e.g, `[Heading IDs](https://www.markdownguide.org/extended-syntax#heading-ids)`).

## Definition Lists

Some Markdown processors allow you to create *definition lists* of terms and their corresponding definitions. To create a definition list, type the term on the first line. On the next line, type a colon followed by a space and the definition.

```
First Term
: This is the definition of the first term.

Second Term
: This is one definition of the second term.
: This is another definition of the second term.
```

The HTML looks like this:

```
<dl>
  <dt>First Term</dt>
  <dd>This is the definition of the first term.</dd>
  <dt>Second Term</dt>
  <dd>This is one definition of the second term. </dd>
  <dd>This is another definition of the second term.</dd>
</dl>
```

The rendered output looks like this:

- First Term

  This is the definition of the first term.

- Second Term

  This is one definition of the second term.

  This is another definition of the second term.

## Strikethrough

You can strikethrough words by putting a horizontal line through the center of them. The result looks ~~like this~~. This feature allows you to indicate that certain words are a mistake not meant for inclusion in the document. To strikethrough words, use two tilde symbols (`~~`) before and after the words.

```
~~The world is flat.~~ We now know that the world is round.
```

The rendered output looks like this:

~~The world is flat.~~ We now know that the world is round.

## Task Lists

Task lists allow you to create a list of items with checkboxes. In Markdown applications that support task lists, checkboxes will be displayed next to the content. To create a task list, add dashes (`-`) and brackets with a space (`[ ]`) in front of task list items. To select a checkbox, add an `x` in between the brackets (`[x]`).

```
- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media
```

The rendered output looks like this:

![Markdown task list](https://d33wubrfki0l68.cloudfront.net/54914727add678921954b094b9cca57f63bd6e2e/666d3/assets/images/tasklist.png)

## Emoji

There are two ways to add emoji to Markdown files: copy and paste the emoji into your Markdown-formatted text, or type *emoji shortcodes*.

### Copying and Pasting Emoji

In most cases, you can simply copy an emoji from a source like [Emojipedia](https://emojipedia.org/) and paste it into your document. Many Markdown applications will automatically display the emoji in the Markdown-formatted text. The HTML and PDF files you export from your Markdown application should display the emoji.

 **Tip:** If you're using a static site generator, make sure you [encode HTML pages as UTF-8](https://www.w3.org/International/tutorials/tutorial-char-enc/).

### Using Emoji Shortcodes

Some Markdown applications allow you to insert emoji by typing emoji shortcodes. These begin and end with a colon and include the name of an emoji.

```
Gone camping! :tent: Be back soon.

That is so funny! :joy:
```

The rendered output looks like this:

Gone camping! ⛺ Be back soon.

That is so funny! 😂

 **Note:** You can use this [list of emoji shortcodes](https://gist.github.com/rxaviers/7360908), but keep in mind that emoji shortcodes vary from application to application. Refer to your Markdown application's documentation for more information.

## Automatic URL Linking

Many Markdown processors automatically turn URLs into links. That means if you type http://www.example.com, your Markdown processor will automatically turn it into a link even though you haven’t [used brackets](https://www.markdownguide.org/basic-syntax/#links).

```
http://www.example.com
```

The rendered output looks like this:

[http://www.example.com](http://www.example.com/)

## Disabling Automatic URL Linking

If you don’t want a URL to be automatically linked, you can remove the link by [denoting the URL as code](https://www.markdownguide.org/basic-syntax/#code) with backticks.

```
`http://www.example.com`
```

The rendered output looks like this:

```
http://www.example.com
```

## Scientific articles

This is the subject of a separate tutorial.