Writting scietific articles with markdown and Pandoc

## Introduction

[*Markdown*](https://daringfireball.net/projects/markdown/) is a lightweight markup language with plain text formatting syntax. Markdown was initially designed for creating content for websites (HTML), but we can also create other document formats such as PDF and EPUB using converters like *Pandoc*. We can also use Markdown to write scientific pa per with the support of *LaTeX*  but without We can also use Markdown to write *LaTeX* documents more easily compared to using pure LaTeX. 

Using markdown we can write stunning looking documents more easily compared to using pure LaTeX. Since Markdown files are text files, they need to be converted to a separate output document, 

Markdown is not the best choice for documents requiring lots of small customizations in styles, fonts, colors, or outlooks. On the other hand, Markdown excels at creating documents that need little customization or have premade styles or templates available like bibliography files and styles, which is basically the nightmare of writing magazine articles from different publishers, even from the same one.

# How to write academic papers in Markdown

## Tired of that silly LaTeX syntax?

###  [14 February 2021 ](https://brainbaking.com/post/2021/02/writing-academic-papers-in-markdown/) |  [software](https://brainbaking.com/categories/software)

 [publishing](https://brainbaking.com/tags/publishing) [pandoc](https://brainbaking.com/tags/pandoc) [Markdown](https://brainbaking.com/tags/markdown) [latex](https://brainbaking.com/tags/latex)

In 2020, I explained [how to use pandoc](https://brainbaking.com/post/2020/05/using-pandoc/) to publish a book. Essentially, I use the same workflow to write papers in academia. A couple of colleagues asked me how this was done, although they suspected it had something to do with [Pandoc](https://pandoc.org/). When I’m not writing in collaboration with someone, and thus using [Overleaf](https://overleaf.com/), I like to keep things simple, by resorting to my favorite way of writing things: Markdown.

However geeky and cool LaTeX might be, it violates a lot of *Clean Code* rules by ignoring separation of concerns. Even `html` has most of the layout separated - albeit not in a particularly good way - using `css`. Having to write `\textbf{wowza}` just to get something in bold gets tiresome fast, and creating your own rules, tags, or scripts ultimately do not resolve the issue, they just work around it. I’m not advocating for writing your dissertation in Word. It’s simply very confusing to look at a document and try to read sections and streams of thought without the LaTeX syntax getting in the way.

Enter Markdown: instead of

```tex
Hello \textbf{bold} stuff! Oh wait, here's ``an image" - weird quotations
\begin{figure}[h!]
  \centering
  \includegraphics{something.png}
  \caption{My caption. \label{fig:delphi}}
\end{figure}
Yeah. That sucks. 
```

You write:

```md
Hello **bold** stuff! Oh wait, here's "an image" - regular quotes, whew.
!["My caption."](something.png)
Yeah. Much better.
```

Sure, there’s still “syntax” to be learned the uninitiated. Still, it’s a heck of a lot less, and it makes reading source files (`.md` instead of `.tex`) much, *much* easier. Take a look at an Overleaf window of our latest paper draft:



[![img](https://brainbaking.com/post/2021/02/overleaf.jpg)](https://brainbaking.com/post/2021/02/overleaf.jpg)



The left part - where you do the work - is simply hideous, and usually riddled with layout-specific syntax. Don’t get me wrong, I love the collaborative plus-side of Overleaf, but it’s still raw LaTeX. As a Java developer, I do not write `.class` files either: I write the `.java` ones and compile the latter.

### The toolchain

As mentioned in the [pandoc article](https://brainbaking.com/post/2020/05/using-pandoc/), this is the setup:



[![The pandoc toolchain.](https://brainbaking.com/post/2021/02/paper-toolchain.jpg)](https://brainbaking.com/post/2021/02/paper-toolchain.jpg)The pandoc toolchain.



Simple enough, and the [Pandoc User Guide](https://pandoc.org/MANUAL.html) helps you in understanding the specifics when converting from Markdown to Tex. The most challenging part of writing academic papers in Markdown is not the conversion process but the annoying details you have to get right when adhering to a layout/template of a conference or journal. I write most things in Sublime, and put simple commands in a `Makefile` in order for `⌘+B` (Build) to work. The build file itself is straightforward enough:

```make
all:
  pandoc -f markdown+smart delphi_report.pd.md --include-in-header=delphi_report_preamble.tex  --template=$(templatedir)/acm-pandoc-conf.tex --filter panflute --natbib --variable --biblio-style=$(csldir)/ACM-Reference-Format --bibliography=delphi.bib -t latex > delphi.tex
  xelatex delphi.tex
  bibtex delphi
```

### Templates

You’ll need both a **Pandoc-specific** template and a **LaTeX-specific** template. The latter is usually up for grabs at your favorite conference/journal submission website. For instance, at ACM-sponsored conferences, your `.tex` file usually starts with:

```tex
\documentclass[sigconf]{acmart}
```

Meaning you’ll need to have the file `acmart.cls` LaTeX class somewhere nearby. These files are automatically included in Overleaf after selecting the correct starting template. Right, nothing new here.

What is new, is the Pandoc template, called `acm-pandoc-conf.tex` in the above Makefile. This file adheres to Pandoc-specific syntax and allows you to fill in variables that are defined in the Frontmatter of Markdown files. The file will contain something like this:

```tex
\documentclass[sigconf,anonymous=$anonymous$]{acmart}

% use packages, acm-specific commands, etc

$if(title)$
  \title{$title$}
$endif$
$if(subtitle)$
  \subtitle{$subtitle$}
$endif$

\maketitle
\bibliographystyle{ACM-Reference-Format}

$body$


$if(bibliography)$
  \balance
  \bibliography{$bibliography$}
$endif$
\end{document}
\endinput
```

I published the full template as a [GitHub gist](https://gist.github.com/wgroeneveld/b6e2751c6da2a7bac73f668ddff5c3d0), in case anyone would like to reuse it.

Now, every `$var` sign will be auto-replaced with the corresponding key in your `.md` file. For example:

```md
---
title: 'My Fancy Work'
date: '2019-07-16'
anonymous: "false"
author: 
    - name: Wouter Groeneveld
      institution: KU Leuven
      orcid: https://orcid.org/0000-0001-5099-7177
      city: Leuven
      country: Belgium
      email: wouter.groeneveld at university
    - name: Other Guy
output: pdf_document
abstract: "blah blah"
published: true
bibliography: "delphi"
tags: [Publishing]
panflute-filters: [scientific-twocolumn-tables]
panflute-path: '../../pandoc/filters'
---

# INTRODUCTION

Knowledge of software development is becoming more and more important, as shortcomings in the software engineering workforce require companies to come up with creative solutions such as coding boot-camps, to initiate candidates into the wonderful world of programming. However, to be successful as a developer, it no longer suffices to be technically proficient [@garousi2019closing]. There is still no agreement on what separates a great developer from a good one, even if both the academic and industrial world are starting to acknowledge the need for something more besides cognitive knowledge, however good this might be [@capretz2017soft]. 
Software is first and foremost created by people, for people, hinting on the need for so-called '_soft skills_', or, more generally, '_non-cognitive abilities_', defined as the subset of abilities not related to technical skills. 
```

This excerpt was taken from [my 2020 Delphi study](https://lirias.kuleuven.be/retrieve/549747/). Note the Section Header (`#`), easy way of citing (`[@key]`) and emphasizing terms (`_`). This gets compiled into the usual LaTex junk and you’re off. You can make up as many variables as you’d like, and also loop through things like multiple authors - see the full gist for more details.

### Post-processing

Did you notice the weird `panflute-filters` stuff? [Panflute](http://scorreia.com/software/panflute/), a Pandoc filter that makes Pandoc filters fun to write (according to the website), can be enabled with the `--filter panflute` flags after installing it as a Python 3 package. I use it to do the necessary post-processing on the generated Pandoc output - before it is made “final” as LaTex output. You can create custom hooks that lets you transform blocks, such as paragraphs, images, links, … This comes in handy when your conference works with a double-column template. Pandoc is not so keen on those, and you sometimes want to convert a figure into a double-column one, or the other way around: `\begin{figure}` to `\begin{figure*}` or something similar.

Of course, another way to do simple find and replace post-processing things is to just further transform the `.tex` output yourself using `sed` or whatever. This works, but is cumbersome, as sometimes you want to select specific blocks without resorting to artisan regular expressions that take hours to create. For something like **tables**, you’d write the following Markdown:

```md
blaaleft        blaright
----------   -----------
something              9
something             10

Table:  Demonstration of simple table syntax.
```

Pandoc by default generates something like this:

```tex
\begin{longtable}[]{@{}lr@{}}
\caption{Demonstration of simple table syntax.}\tabularnewline
\toprule
blaaleft & blaright\tabularnewline
\midrule
\endfirsthead
\toprule
blaaleft & blaright\tabularnewline
\midrule
\endhead
something & 9\tabularnewline
something & 10\tabularnewline
\bottomrule
\end{longtable}
```

With my filter, I managed to modify it to something like this:

```tex
\begin{table}[h!]
\centering
\caption{Demonstration of simple table syntax.\label{table:Demonstration_of_sim}}
\begin{tabular}{l r}
\hline
blaaleft & blaright\\ [0.5ex]
\hline
\hline
something & 9\tabularnewline
something & 10\tabularnewline
\hline\end{tabular}
\end{table}
```

Transforming the `longtable` into a `table` is simple enough, but this filter does more than that, as you can see. Passing in extra options as part of the `tabular` block is also possible. Inspect the full python file [in this GitHub gist](https://gist.github.com/wgroeneveld/9dbeb0d0b60c6cb5d8dfe9b938c5e94e) (yes it’s a bit messy). A word of warning: Panflute’s latest version is a bit experimental and might not be compatible with the latest Pandoc release.

### Other nasty stuff

In essence, I try to remove as much markup-specific syntax as possible by letting the templates do their thing. Now and then, this is simply not possible, especially for complicated formulas or tables. If all else fails, it is still possible to combine both languages and embed LaTeX inside your Markdown file. Use this as your last resort.

I also usually create a `preamble.tex` file that contains the necessary metadata for the conference, such as the ACM taxonomy, and a few extra TeX package includes. Furthermore, they’re also handy when customizing standardized blocks, such as quotes in Markdown, prepended with `>`. The package `etoolbox` allows you to customize these using something like:

```tex
\AtBeginEnvironment{quote}{\begin{tcolorbox}[leftrule=2mm,bottomrule=0mm,toprule=0mm,rightrule=0mm,boxsep=0mm,grow to right by=-3mm, grow to left by=-3mm]\small}
\AtEndEnvironment{quote}{ \end{tcolorbox}}
```

Remember, the less clutter in your Markdown, the less strain for your eyes! I also know people who write most of their stuff in Markdown, convert it into TeX using Pandoc, and then copy over the compiled garbage into Overleaf to continue and chip away at it together with others. Of course, you can also simply check in your `.md` source files and use Git to collaborate, although without something like Overleaf, your CI server - and preferably also yourself - will have to install the required build toolchain.

####  Bio and Support

![A photo of Me!](https://brainbaking.com/img/avatar.jpg)

I'm Wouter Groeneveld, a level 35 *Brain Baker*, and I love the smell of freshly baked thoughts (and bread) in the morning. I sometimes convince others to bake their brain (and bread) too.

If you found this article amusing and/or helpful, you can [**buy me a coffee**](https://ko-fi.com/woutergroeneveld) - although I'm more of a tea fan myself. I also like to hear your feedback via [Mastodon](https://chat.brainbaking.com/@wouter) or e-mail. Thanks!

#### [ ](https://brainbaking.com/post/2021/02/writing-academic-papers-in-markdown/#related)Related Articles

#### [Using Pandoc to publish a book](https://brainbaking.com/post/2020/05/using-pandoc/)

 01 May 2020 | Successfully combining writing and LaTeX skills

------

[Top](https://brainbaking.com/post/2021/02/writing-academic-papers-in-markdown/#header) | [Read on Gemini](gemini://brainbaking.com/post/2021/02/writing-academic-papers-in-markdown/)

[No © and no tracking](https://brainbaking.com/no-copyright-no-tracking). [Brain Baking](https://brainbaking.com/) | [Gemini](gemini://brainbaking.com/). [RSS Feeds](https://brainbaking.com/subscribe).







## Creating Documents

### Structure of a markdown article

The best practice is to use  [_Markdown Templates_](https://github.com/jaantollander/Markdown-Templates) whuch are structured as follows:

```plaintext
<name>/
├─ build/
├─ <filename.md>
├─ <bibliography.bib>
└─ Makefile
```

where _<filename.md>_ is the name of the markdown file itself, _<bibliography.bib>_ the name of the [bibtext ](http://www.bibtex.org/)bibliography file, which must be refered in the document just as in Latex.

The `Makefile` contains commands for converting the Markdown file into the desired document format using Pandoc. Pandoc creates the output files to the `build/` directory, which Makefile automatically creates if it does not exist.

### Makefile

We define the build directory and the filename at the beginning of `Makefile` as follows.

```makefile
BUILDDIR=build
FILENAME=<filename>
```

Then, we define the command to create the document.

```makefile
<command>:
    mkdir $(BUILDDIR) -p  # Creates the BUILDDIR if it doesn't already exist.
    pandoc $(FILENAME).md \
    --filter pandoc-citeproc \
    --from=markdown+tex_math_single_backslash+tex_math_dollars \
    # ...
```

The option `--from=markdown` tells that input file is a Markdown file. Markdown extensions `+tex_math_single_backslash` and `+tex_math_dollars` enable Pandoc to parse equations. 

Pandoc-citeproc enables us to use citations in Markdown. Pandoc installation includes it by default. We need to enable it by using the option `--filter pandoc-citeproc`.

We can execute the Makefile command in the terminal as follows.

```c
make <command>
```

### Front Matter

We can include document-specific metadata and functionality for the converter in the Front Matter at the top of a `<filename>.md` file. We write the front matter in YAML between two triple-minus lines `---` as follows.

```yaml
---
title: "Title"
date: \today
author: "Author"
bibliography: "bibliography.bib"
link-citations: true
urlcolor: "blue"
csl: "https://raw.githubusercontent.com/citation-style-language/styles/master/harvard-anglia-ruskin-university.csl"
---
```

The `title`, `date`, and `author` variables specify information for creating the title. The `bibliography` variable specifies the location of the bibliography file, `link-citations` toggles links to citations on and off, `urlcolor` defines the link color, and the `csl` variable defines the [Citation Style Language](http://citationstyles.org/). We can find examples of citation styles from [Zotero styles](https://www.zotero.org/styles) and use them by either downloading them or referring directly to the URL of the raw CLS file in [citation styles](https://github.com/citation-style-language/styles) repository.

### Layout

We can change the layout of a PDF document by including a LaTeX preamble using a Pandoc command or the Front matter. For example, if we want to create an ebook friendly PDF output, we can use the layout described in [“Effort to make latex ebook friendly”](https://tex.stackexchange.com/a/16388/229156) as follows.

------

We can include `--include-in-header=<layout>.tex` option in the Makefile with `<layout>.tex` file:

```latex
\usepackage[papersize={4.5in,6in},margin=0.5cm]{geometry}
\setlength{\parskip}{2pt}
\newcommand\textbreak{%
  \begin{center}%
  \decothreeleft \aldineleft \decosix \aldineright \decothreeright%
  \end{center}}
\pagestyle{empty}
```

------

Alternatively, we can include the `header-includes` variable in the front matter:

```yaml
header-includes: |
    \usepackage[papersize={4.5in,6in},margin=0.5cm]{geometry}
    \setlength{\parskip}{2pt}
    \newcommand\textbreak{%
    \begin{center}%
    \decothreeleft \aldineleft \decosix \aldineright \decothreeright%
    \end{center}}
    \pagestyle{empty}
```

## Syntax

### Basic Syntax

[John Gruber’s original spec](https://daringfireball.net/projects/markdown/syntax) and [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) in GitHub demonstrate the basic Markdown syntax. We recommend reading at least them to understand the basics. In addition to Markdown understanding, basics on HTML can be useful for creating web content if using inline HTML.

### Code Blocks

Regular Markdown supports code blocks but does not highlight their syntax. However, converters such as Pandoc will add syntax highlighting for code block as long as we supply the appropriate language for the code block. For example:

~~~plaintext
```python
def foo():
    return "bar"
```
~~~

Displays as:

```python
def foo():
    return "bar"
```

### Equations

We can write inline equations using single dollars `$...$` or backslashed parentheses `\(...\)` and display using double dollars `$$...$$` or backslashed square brackets `\[...\]`. The use of dollar symbols is more common. Optionally, we can add tags `\tag{<tag>}` for numbering equations and labels `\label{<label>}` for referring to equations later in text using `\ref{<label>}`. For example, we can write Cauchy’s integral formula as

```plaintext
$$
f(a)={\frac {1}{2\pi i}}\oint _{\gamma }{\frac {f(z)}{z-a}}\,dz
\tag{1}
\label{1}
$$
```

Mathjax displays the equation as

(1)f(a)=12πi∮γf(z)z−adz.

We can now refer to the equation using syntax `(\ref{1})` which displays as (1). Markdown displays inline equations such as `$a^2+b^2=c^2$` in the same line as the text, a2+b2=c2.

Some markdown parsers do not detect the equation mode for characters that are part of the Markdown syntax, which might interfere with parsing. For example, instead of using the asterisk symbol `*` inside the equation mode, we can use the backslashed ASCII `\*`, latex command `\ast`, or the Unicode version `∗`.

### Unicode Symbols for Equations

We write equations easier by using Unicode characters for mathematical symbols. For example, instead of `\mathbf{x}\in\mathbb{R}^2` we can write `$𝐱∈ℝ^2$` for the same output 𝐱∈ℝ2. You can input Unicode symbols with editor plugins mentioned in the Editors section.

### Colored Equations

Better Explained in their article [Colorized Math Equations](https://betterexplained.com/articles/colorized-math-equations/) shows how to use colors to improve the way we can describe equations. The article has excellent examples, such as a colorized explanation for the constant e, which they also provide as a [LaTeX document](https://www.overleaf.com/project/5c3e247141897965b7e064d4). We can use it to recreate the output on the web:

To use colors in LaTeX, we must include the color package in the header.

```latex
\usepackage{color}
```

Then, we can define new colors in the body and use them in math mode. For example:

```latex
\definecolor{c1}{RGB}{114,0,172}
\newcommand{\newcolor}{\color{c1}}
$$
\newcolor x^2
$$
```

Overleaf has a helpful article about [Using colors in LaTeX](https://www.overleaf.com/learn/latex/Using_colours_in_LaTeX).

------

When using Mathjax or KaTeX to render equations on the web, we can use the extended [color keywords](https://developer.mozilla.org/en-US/docs/Web/CSS/color_value#Color_keywords) or RBG hex values for the color argument. The commands must be inside math mode.

We can define colors using the `\color` command.

αβαβα−β,∀α,β>0

```latex
$$
\newcommand{\positive}{\color{darkblue}}
\newcommand{\negative}{\color{darkred}}
{\positive α} {\negative -β}, \quad ∀α,β>0
$$
```

Alternatively, we can define the colors using the `\textcolor` command.

αβαβα−β,∀α,β>0

```latex
$$
\newcommand{\positive}[1]{\textcolor{darkblue}{#1}}
\newcommand{\negative}[1]{\textcolor{darkred}{#1}}
\positive{α} \negative{-β}, \quad ∀α,β>0
$$
```

------

We can take into account color blindness by using a colorblind safe palette. We can use [Colorbrewer](https://colorbrewer2.org/), a tool for coloring planar graphs (aka maps), to select different colorblind safe palettes. In Colorbrewer, choose the *colorblind safe* option, select the *color scheme* from *sequential* or *diverging*, the *number of data classes* and HEX or RGB output. Finally, copy the color codes from the bottom left to the LaTeX commands.

### Citations

Let us have the following BibTeX entry stored in `bibliography.bib` file.

```plaintext
@article{key_name,
    author  = {Peter Adams},
    title   = {The title of the work},
    journal = {The name of the journal},
    year    = {1993},
    number  = {2},
    pages   = {201-213},
    month   = {7},
    note    = {An optional note},
    volume  = {4}
}
```

We can refer to this entry in the Markdown document using syntax `@key_name` or `[@key_name]`. Pandoc creates references at the bottom of the document. Remember that most of bibliography software can export bibliography to bibtex format and that the scientific journals have cls styles to be used with Latex and Bibtex, so we can use them with markdown-pandoc too.

### Vector Graphics

Markdown allows inserting vector graphics with the standard syntax.

```markdown
![](<filename>.svg)
```

Using vector graphics when creating PDFs requires [*Inkscape*](https://inkscape.org/).

To know more:

- [Jaan Tollander de Balsch](https://jaantollander.com/post/scientific-writing-with-markdown/#introduction) blog.

- [Github repository of Ben Marwick]([benmarwick/atom-for-scholarly-writing-with-markdown (github.com)](https://github.com/benmarwick/atom-for-scholarly-writing-with-markdown)

- [R Studio Tutorial]([Workflow: How to write a journal article with R markdown when code/figures spread across multiple directories? - R Markdown - RStudio Community](https://community.rstudio.com/t/workflow-how-to-write-a-journal-article-with-r-markdown-when-code-figures-spread-across-multiple-directories/6934))

