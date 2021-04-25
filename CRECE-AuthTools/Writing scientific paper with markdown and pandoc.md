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

To know more read [Jaan Tollander de Balsch](https://jaantollander.com/post/scientific-writing-with-markdown/#introduction) blog.





## [¡Haz una donación a *The Programming Historian*!](https://www.patreon.com/theprogramminghistorian)

[The Programming Historian](https://programminghistorian.org/es)

- ACERCA 
- CONTRIBUCIONES 
- [LECCIONES](https://programminghistorian.org/es/lecciones)
- APÓYANOS 
- [BLOG](https://programminghistorian.org/blog)
- [EN](https://programminghistorian.org/en/lessons/sustainable-authorship-in-plain-text-using-pandoc-and-markdown)ES[FR](https://programminghistorian.org/fr/lecons/redaction-durable-avec-pandoc-et-markdown)[PT](https://programminghistorian.org/pt)
- 

![Hombre leyendo y escribiendo en un escritorio](https://programminghistorian.org/gallery/sustainable-authorship-in-plain-text-using-pandoc-and-markdown.png)

# [Escritura sostenible en texto plano usando Pandoc y Markdown](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown)

## Dennis Tenen y Grant Wythoff

En este tutorial aprenderás lo básico de Markdown—una sintaxis de marcado para texto plano que es fácil de leer y de escribir así como Pandoc, una herramienta de línea de comandos que convierte el texto plano en varios tipos de archivos bellamente formateados: PDF, .docx, HTML, LaTeX, presentaciones de diapositivas y más.

[ Revisado por pares](https://github.com/programminghistorian/ph-submissions/issues/57)

[ CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/deed.en)

[ Apoyar PH](https://programminghistorian.org/es/apoyanos#donaciones)

### EDITADO POR

- Fred Gibbs

### REVISADO POR



### TRADUCIDO POR

- Víctor Gayol [![ORCID id icon](https://programminghistorian.org/images/ORCIDiD_iconvector.svg)](https://orcid.org/0000-0002-2442-3193)

### TRADUCCIÓN EDITADA POR

- Maria José Afanador-Llach

### TRADUCCIÓN REVISADA POR

- Antonio Rojas Castro [![ORCID id icon](https://programminghistorian.org/images/ORCIDiD_iconvector.svg)](https://orcid.org/0000-0002-8916-4997)
- Maria José Afanador-Llach

#### PUBLICADO

 2014-03-19

#### TRADUCIDO

 2017-04-04

#### MODIFICADO

 2021-03-25

#### DIFICULTAD

 Medio

![DOI id icon](https://programminghistorian.org/images/doi_icon.jpg) https://doi.org/10.46430/phes0008

## ¡Haz una donación!

Producir buenos tutoriales de acceso abierto cuesta dinero. Únete al creciente número de personas que [apoya a *The Programming Historian*](https://www.patreon.com/theprogramminghistorian) para que podamos continuar compartiendo conocimientos de forma gratuita.

Disponible en: [EN ](https://programminghistorian.org/en/lessons/sustainable-authorship-in-plain-text-using-pandoc-and-markdown)(original) | [ES ](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown)| [FR](https://programminghistorian.org/fr/lecons/redaction-durable-avec-pandoc-et-markdown)

## Contenidos

- [Objetivos](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#objetivos)
- [Filosofía](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#filosofía)
- [Principios](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#principios)
- [Requisitos de *software*](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#requisitos-de-software)
- [Bases de Markdown](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#bases-de-markdown)
- [Estar en contacto con la terminal de la máquina](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#estar-en-contacto-con-la-terminal-de-la-máquina)
- [Usar Pandoc para convertir Markdown a un documento de MS Word](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#usar-pandoc-para-convertir-markdown-a-un-documento-de-ms-word)
- [Trabajar con bibliografías](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#trabajar-con-bibliografías)
- [Cambiar los estilos de citación](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#cambiar-los-estilos-de-citación)
- [Resumen](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#resumen)
- [Recursos útiles](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#recursos-útiles)

![img](https://programminghistorian.org/images/sustainable-authorship-in-plain-text-using-pandoc-and-markdown/lexoriter.jpg)

## Objetivos

En este tutorial aprenderás lo básico de Markdown -una sintaxis de marcado para texto plano que es fácil de leer y de escribir-, así como [Pandoc](http://johnmacfarlane.net/pandoc/), una herramienta de línea de comandos que convierte el texto plano en varios tipos de archivos bellamente formateados: PDF, .docx, HTML, LaTeX, presentaciones de diapositivas y más.[1](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:1) Con Pandoc como tu herramienta digital de composición tipográfica, puedes usar la sintaxis de Markdown para añadir figuras, una bibliografía, formato, y cambiar fácilmente estilos de citación de Chicago a MLA (por ejemplo), todo ello utilizando texto plano.

El tutorial asume que no tienes conocimientos técnicos previos, pero escala con la experiencia ya que a menudo sugerimos técnicas más avanzadas hacia el final de cada sección. Éstas están claramente marcadas y pueden ser revisitadas después de alguna práctica y experimentación.

En vez de seguir este tutorial de una manera mecánica, te recomendamos esforzarte por entender las soluciones ofrecidas aquí como una *metodología* que necesitarías adaptar posteriormente para ajustarla a tu entorno y flujo de trabajo. La instalación de las herramientas necesarias presenta tal vez el mayor obstáculo para la participación. Destina suficiente tiempo y paciencia para instalar todo correctamente o házlo con un colega que tenga una configuración similar para ayudarse mutuamente. Consulta la sección [Recursos útiles](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#recursos-útiles) más adelante si te quedas atascado.[2](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:2)

## Filosofía

Escribir, almacenar y recuperar documentos son actividades centrales en el flujo de trabajo de la investigación en humanidades. Sin embargo, muchos autores basan su práctica en herramientas y formatos propietarios que a veces no cubren ni siquiera los requerimientos básicos de la escritura académica. Habrás experimentado cierta frustación por la fragilidad de las notas a pie de página, las bibliografías, figuras y borradores de libros escritos en Microsoft Word o Google Docs. Sin embargo, la mayoría de las revistas aún insisten en recibir textos en formato .docx.

Pero más que causar una frustación personal, esta dependencia a las herramientas y formatos propietarios tiene implicaciones negativas a largo plazo para la comunidad académica. En este entorno, las revistas deben subcontratar la composición tipográfica, alienan a los autores de los contextos materiales de la publicación añadiendo otros obstáculos innecesarios a la libre circulación del conocimiento.[3](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:3)

Cuando utilizas MS Word, Google Docs u Open Office para escribir documentos, lo que ves no es lo que obtienes. Debajo de la capa visible de palabras, oraciones y párrafos se encuentra una complicada capa de código comprensible solamente para las máquinas. Debido a esta capa oculta, tus archivos `.docx` y `.pdf` dependen de herramientas propietarias para mostrarse correctamente. Dichos documentos son difíciles de buscar, de imprimir y de convertir a archivos con otros formatos.

Más aún, el tiempo utilizado en formar el documento en MS Word u Open Office se desperdicia, porque el editor de la revista donde lo envías retira todo ese formato. Tanto los autores como los editores se beneficiarían si intercambiaran archivos con un formato mínimo, dejando la composición tipográfica a la etapa de composición final del proceso de publicación.

Aquí es donde brilla Markdown. Markdown es una sitaxis para el marcado semántico de elementos dentro de un documento de forma explícita, no en alguna capa oculta. La idea es identificar las unidades que tienen significado para los seres humanos como títulos, secciones, subsecciones, notas a pie de página y las ilustraciones. Por lo menos, los archivos seguirán siendo comprensibles para ti, incluso si el editor de textos que estás utilizando deja de funcionar o si queda fuera del mercado.

Escribir en esta forma libera al autor de la herramienta. Markdown se puede escribir en cualquier editor de texto y ofrece un rico ecosistema de *software* que puede representar ese texto en documentos con aspecto atractivo. Por esta razón, Markdown está experimentando un periodo de crecimiento, no solamente como un medio para la escritura de documentos académicos sino como una convención para la edición en línea en general.

Los editores de texto para todo prósito más populares incluyen [Atom](https://atoms.io/) (para todas las plataformas) y [Notepad++](https://notepad-plus-plus.org/) (para Windows).

Es importante entender que Markdown no es más que una convención. Los archivos Markdown se almacenan como texto plano, además de añadir la flexibilidad del formato. Los archivos de texto plano han existido desde los tiempos de las máquinas de escribir eléctrónicas. La longevidad de este estándar hace, de manera inherente, que sean más sostenibles y más estables que los formatos propietarios. Mientras que los archivos producidos hace diez años en Microsfot Word o en Pages de Apple pueden causar serios problemas cuando se abren con la última versión del programa, aún es posible abrir un archivo de texto plano escrito en alguno de los editores de texto “muertos”, del pasado, muchas décadas después: AlphaPlus, Perfect Writer, Text Wizard, Spellbinder, WordStar o SCRIPSIT2.0, el favorito de Isaac Asimov producido por Radio Shack. Escribir en texto plano te garantiza que tus archivos permanecerán legibles diez, quince o veinte años a partir de ahora. En esta lección se describe un flujo de trabajo que libera al investigador de programas de procesamiento de texto propietarios y archivos de formatos frágiles.

Ahora es posible escribir una amplia gama de documentos en un formato -artículos, entradas de blogs, wikis, programas de estudio y cartas de recomendación-, utilizando el mismo conjunto de herramientas y técnicas para buscar, descubrir, hacer copias de seguridad y distribuir nuestros materiales. Tus notas, entradas de blog, documentación de código y wikis pueden ser creados en Markdown. Cada vez más, muchas plataformas como WorPress, Reddit y GitHub soportan nativamente la escritura en Markdown. A largo plazo, tu investigación se beneficiará de este tipo de flujos de trabajo unificados, lo que hace que sea más fácil guardar, buscar, compartir y organizar tus materiales.

## Principios

Inspirados en las buenas prácticas de una variedad de disciplinas nos hemos guiado por los siguientes principios:

1. *Sostenibilidad.* El texto plano a la vez garantiza transparencia y responde a las normas de conservación a largo plazo. MS Word puede seguir el camino de Word Perfect en el futuro, pero el texto plano seguirá siendo siempre fácil de leer, catalogar, minar y transformar. Por otra parte, el control de versiones de texto plano permite efectuar cambios de manera fácil y potente, lo cual es muy útil en la creación colaborativa y organización de borradores. Tus archivos de texto plano serán accesibles en teléfonos celulares, tabletas, o tal vez en una terminal de baja potencia de alguna biblioteca lejana. El texto plano es compatible con versiones anteriores y tiene garantía de futuro. Cualquier *software* o *hardware* que se presente más adelante será capaz de entender tus archivos de texto plano.
2. *Preferencia por formatos legibles por humanos.* Al escribir en Word o en Google Docs, lo que se ve no es lo que se obtiene. El archivo .docx tiene caracteres escondidos, generados automáticamente, que crean una capa de composición tipográfica eclipsada que hace que al usuario le sea difícil solucionar problemas. Algo tan sencillo como pegar una imagen o un texto desde el navegador puede tener efectos impredecibles en el formato del documento.
3. *Separación de forma y contenido.* Escribir y formar al mismo tiempo distrae. La idea es escribir primero y dar formato más tarde, lo más cerca posible al momento de la publicación. Una tarea como cambiar el estilo de citación de Chicago a MLA debe ser posible sin esfuerzo. Los editores de revistas que quieran ahorrar tiempo ante formatos innecesarios y corrección de textos, deben ser capaces de proporcionar a sus autores una plantilla de formato que se encargue de las minucias de la composición tipográfica.
4. *Soporte del aparato crítico.* El flujo de trabajo tiene que manejar con gracia notas a pie de página, cifras, caracteres internacionales y bibliografía.
5. *Independencia de plataforma.* Como las plataformas de publicación se multiplican, tenemos que ser capaces de generar una multiplicidad de formatos, incluyendo presentaciones de diapositivas, impresión, web y dispositivos móviles. Idealmente, nos gustaría ser capaces de generar los formatos más comunes sin romper las referencias bibliográficas. Nuestro flujo de trabajo debe ser portátil al grado que sería bueno poder copiar una carpeta a un *pendrive* y saber que contiene todo lo necesario para su publicación. Escribir en texto plano significa que puedes compartir fácilmente, editar y archivar tus documentos en prácticamente cualquier entorno. Por ejemplo, un temario de clase escrito en Markdown puede ser guardado como PDF, impreso como hoja de mano, convertido a HTML para la Web, todo desde el mismo archivo. Los archivos impresos y subidos a la web pueden ser publicados de la misma fuente y tener un aspecto similar, preservando la distribución lógica del material.

Markdown y LaTeX responden a todas estas exigencias. Elegimos Markdown (y no LaTeX) porque ofrece la sintaxis más ligera y libre de desorden (de ahí “mark *down*”), y porque cuando se combina con Pandoc permite una mayor flexibilidad de salidas (incluyendo archivos .docx y .tex).[4](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:4)

## Requisitos de *software*

Expresamente omitiremos algunos detalles menudos relacionados con la instalación del *software* listado abajo para cada plataforma o sistema. Por ejemplo, no tiene sentido proporcionar las instrucciones de instalación para LaTeX cuando las instrucciones en línea para tu sistema operativo siempre serán más completas y actualizadas. De la misma manera la mecánica de la instalación de Pandoc se obtiene de manera más completa si buscas en Google “installing Pandoc”, con lo que probablemente el primer resultado sea la página principal de Pandoc.

- **Editor de Texto Plano**. Entrar al mundo de la edición en texto plano amplía tu capacidad de seleccionar herramientas innovadoras de manera espectacular. Busca en línea “markdown text editor” y experimenta con las opciones. No importa lo que utilices siempre que sea explícitamente un editor de texto plano como Atom o Notepad++. Recuerda: ya no estamos atados a la herramienta, se puede cambiar de editor en cualquier momento.
- **Terminal de línea de comandos.** Trabajar en la “línea de comandos” es lo mismo que escribir comandos en la terminal. En Mac sólo tienes que utilizar tu *Finder* para acceder a “Terminal”. En Windows utiliza *PowerShell*. Es probable que los usuarios de Linux ya estén familiarizados con sus terminales. A continuación, vamos a cubrir los conceptos más basicos de cómo encontrar y utilizar la línea de comandos.
- **Pandoc**. Las instrucciones detalladas de instalación específica para cada plataforma están disponibles en el [sitio web de Pandoc](http://johnmacfarlane.net/pandoc/installing.html). *Para este tutorial es crucial que instales Pandoc en tu ordenador*, así que asegúrate de invertir tiempo navegando por las instrucciones. Pandoc fue creado y es mantenido por John MacFarlane, profesor de Filosofía en la Universidad de California en Berkeley. Esto es *humanidades digitales* en su mejor expresión y servirá como el motor de nuestro flujo de trabajo. Con Pandoc serás capaz de compilar el texto y la bibliografía de tu trabajo en documentos con un formato flexible y atractivo. Una vez que hayas seguido las instrucciones de instalación, verifica su instalación escribiendo en la línea de comandos de tu máquina “pandoc –version”. Asumimos que por lo menos tienes la versión 1.12.3 publicada en enero de 2014.

Recomendamos que instales los dos siguientes programas de aplicación, aunque no son un requisito indispensable para completar este tutorial.

- **Zotero o Endnote**. El *software* para referencias bibliográficas como Zotero y Endnote son herramientas indispensables para organizar y formar citaciones en un trabajo de investigación. Estos programas pueden exportar tus biliotecas como un archivo BibTeX (sobre el que aprenderás inmediatamente en el caso 2, más abajo). Este archivo, que es en sí mismo un documento de texto con el formato de todas tus referencias bibliográficas, te permitirá citar publicaciones rápida y fácilmente utilizando `@tags`. Cabe señalar que también es posible escribir todas tus referencias bibliograficas a mano usando [nuestra bibliografía](https://github.com/dhcolumbia/pandoc-workflow/blob/master/pandoctut.bib) como plantilla.
- **LaTeX**. Las instrucciones detalladas para la instalación específica en cada plataforma están disponibles en el [sitio web de Pandoc](http://johnmacfarlane.net/pandoc/installing.html). A pesar de que este tutorial no cubre LaTeX, éste es utilizado por Pandoc para la creación de PDF. Los usuarios suelen convertir en LaTeX directamente para tener un control más minucioso de la composición tipográfica de los .pdf. Los principiantes pueden considerar saltarse este paso. De lo contrario, escribe en tu terminal `latex -v`para ver si LaTeX se ha instalado correctamente (obtendrás un error si así no fuera y algo de información sobre la versión si fue exitosa).

## Bases de Markdown

Markdown es una convención para estructurar tus documentos en texto plano de una manera semántica. La idea es identificar estructuras lógicas en tu documento (un título, una sección, subsecciones, notas al pie, etc.), marcarlas con algunos caracteres distintivos y luego “compilar” el texto resultante con un intérprete de composición tipográfica que dará forma al documento en consonancia con el estilo especificado.

Las convenciones para Markdown están disponibles en varios tipos o “*flavors*”, diseñados para su uso en contextos particulares como blogs, *wikis* o repositorios de código. El *flavor* de Markdown utilizado por Pandoc está orientado para un uso académico. Sus convenciones están descritas en la página de [Pandoc’s Markdown](http://pandoc.org/README.html#pandocs-markdown). Estas convenciones incluyen el [“YAML” block](http://johnmacfarlane.net/pandoc/README.html#yaml-metadata-block), que contiene una serie de metadatos muy útiles. [5](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:ft-1)

Vamos a crear ahora un documento simple en Markdown. Abre tu editor de texto plano seleccionado y escribe algo que debe tener un aspecto como el siguiente:

```
---
title: Flujo de trabajo en texto plano
author: Gabriel García
date: 20 de enero de 2014
fontfamily: times
---
```

El Markdown “Pandoc-flavored” almacena cada uno de los valores anteriores y los “imprime” en la ubicación apropiada de tu documento de salida una vez que está listo para la composición tipográfica. Más adelante aprenderemos a incluir campos más potentes en YAML. Por ahora, vamos a suponer que estamos escribiendo un documento compuesto por tres secciones, cada una subdividida en dos. Hay que dejar una línea en blanco después de los tres últimos guiones del bloque YAML para que puedas pegar lo que sigue:

```
# Sección 1

## Subsección 1.1

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

El siguiente párrafo debe empezar como éste, sin sangría:

## Subsección 1.2

Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque  ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.

# Sección 2

## Subsección 2.1
```

Sigue adelante e introduce cualquier texto de relleno. Los espacios vacíos tienen significado en Markdown por lo que no debes poner sangría en los párrafos pero sí es importante que separes los párrafos con una línea en blanco. Las líneas en blanco también deben preceder a los encabezados de sección.

Puedes añadir asteriscos para dar énfasis a las palabras con negritas o cursivas de esta manera: `*cursivas*`y `**negritas**`. También hay que añadir a nuestro texto un enlace y una nota a pie de página para cubrir los requisitos de un texto promedio. Escribe:

```
Una oración que requiere una cita.[^1]

[^1]: ¡Ésta es mi primer nota a pie de página! Y un [enlace](https://www.eff.org/).
```

Cuando el texto del enlace y la dirección del mismo son iguales es más rápido escribir: `<https://www.eff.org/>, en vez de [https://www.eff.org/](https://www.eff.org/)`.

Vamos a guardar nuestro archivo antes de ir más lejos. Haz una carpeta para albergar este proyecto. Es probable que tengas un sistema de organización de tus documentos, proyectos, ilustraciones y bibliografías, pero a menudo tu documento, tus proyectos, tus ilustraciones y bibliografías se encuentran en diferentes carpetas, lo que los hace difíciles de encontrar. Nuestro objetivo es crear una carpeta única para cada proyecto con todos los materiales relevantes incluidos en ella. La regla general es “un proyecto, un texto, una carpeta”. Denomina a tu archivo algo así como “principal.md”, donde “md” significa que es un archivo Markdown.

Una vez que has guardado el archivo, vamos a añadir una imagen. Copia una imagen pequeña a la carpeta y añade lo siguiente en alguna parte del cuerpo de texto: `![una imagen](tu_imagen.jpg)`.

En este punto tu archivo `principal.md` debe verse como sigue

```
---
title: Flujo de trabajo en texto plano
author: Gabriel García
date: 20 de enero de 2014
---

# Sección 1

## Subsección 1.1

Lorem *ipsum* dolor sit amet, **consectetur** adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

El siguiente párrafo debe empezar como este, sin sangría:

## Subsección 1.2

Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque  ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.

# Sección 2

## Subsección 2.1
![una imagen](tu_imagen.jpg)

## Subsección 2.2.

Una oración que requiere una cita.[^1]

[^1]: ¡Ésta es mi primer nota a pie de página! Y un [enlace](https://www.eff.org/).
```

Y como veremos en breve, este archivo de texto plano se puede representar como un muy buen PDF.

![Captura de pantalla de un PDF interpretado por Pandoc](https://programminghistorian.org/images/sustainable-authorship-in-plain-text-using-pandoc-and-markdown/Screen-Shot-2014-11-06.png)

Captura de pantalla de un PDF interpretado por Pandoc

Si quieres tener una idea de cómo serán interpretado en un fomato HTML este tipo de marcado, prueba este [sitio de prueba en línea](https://daringfireball.net/projects/markdown/dingus) y juega con varios tipos de sintaxis. Recuerda que ciertos elementos del *Pandoc-flavored markdown* (como el bloque de título o las notas al pie) no funcionan en esta versión web ya que solamente acepta lo básico.

En este punto, deberás ocupar algún tiempo explorando algunas de las características de Markdown como las citas de texto (referidas con el símbolo `>`), los listados que empiezan con `*` o `-`, los saltos de línea literales que empiezan con `|` (útiles para poesía), las tablas y algunas otras funciones señaladas en la página sobre Markdown de Pandoc.

Presta particular atención a los espacios en blanco y al flujo de los párrafos. La documentación lo explica sucintamente cuando define un párrafo como “una o más líneas de texto seguidas por una o más líneas en blanco.” Consiedra que “las nuevas líneas son tratadas como espacios” y que “si necesitas un salto de línea elocuente, utiliza dos o más espacios en blanco al final de la línea.” La mejor manera de entender lo que significa es experimentar libremente. Utiliza el modo de vista previa de tu editor o solamente ejecuta Pandoc para ver los resultados de tus experimentos.

Pero sobre todo, evita la necesidad de formatear. Recuerda que estás identificando unidades semánticas: secciones, subsecciones, énfasis, notas al pie y figuras. Incluso `*cursivas*`y `**negritas**` en Markdown no son en realidad marcas de formato, sino que indican un nivel diferente de énfasis. La aplicación del formato sucederá después, una vez que conozcas el momento del proceso en el que hay que hacerlo y los requerimientos de la publicación.

Existen programas que te permiten obtener una vista previa en vivo de la salida de markdown al tiempo que editas tu archivo de texto plano y que detallaremos más adelante en la sección de Recursos útiles. Algunos de ellos soportan notas a pie, figuras, incluso bibliografías. Sin embargo, para sacar provecho al máximo de Pandoc, te recomendamos que te quedes con lo más sencillo: archivos de texto plano almacenados localmente en tu computadora.

## Estar en contacto con la terminal de la máquina

Antes de que podamos publicar nuestro archivo `principal.md` en otros formatos, necesitamos un poco de orientación para trabajar en la interfaz de línea de comandos utilizando la aplicación de la terminal de nuestro ordenador, que es la única manera (y la mejor) de utilizar Pandoc.

La interfaz de línea de comandos es un sitio amigable una vez que te acostumbras a ella. Si ya te es familiar la utilización de línea de comandos, puedes saltarte esta sección. Para el resto de lectores, es importante entender que al usar la terminal directamente podrán acceder a una amplia gama de herramientas de investigación poderosas que de otra manera es imposible, y será la base para trabajos más avanzados. Para el propósito de este tutorial necesitas aprender solamente unos cuantos comandos muy sencillos.

Primero, abre una nueva ventana de línea de comandos. Si utilizas una macOS, abre Terminal en el directorio `Aplicaciones/Utilidades`. En Windows utilizarás PowerShell. En Windows 7 o posterior, recomendamos que utilices el “poweshell” o, para una solución más robusta, instala el subsistema de Windows para Linux y utiliza la terminal que viene con tu distribución Linux favorita. Para una excelente introducción a la línea de comando, consulta “[Introduction to the Bash Command Line](https://programminghistorian.org/es/lecciones/introduccion-a-bash)” por Ian Milligan y James Baker.

En el terminal debe ver una ventana de texto y un puntero (*prompt*) que puede verse más o menos como esto: `nombre-del-ordenador:~nombre-de-usuario$`. La tilde indica que estás en el directorio de usuario, y de hecho puedes escribir `$ cd ~`en cualquier punto para regresar a tu directorio de usuario. No escribas el símbolo de moneda pues solamente indica el puntero de tu terminal, solicitándote que escribas algo en la terminal (como opuesto a que escribas algo en un documento); recuerda introducir Enter después de escribir cada comando.

Es muy común que tu carpeta “Documents” esté localizada en este directorio. Escribe `$ pwd` (= “*print working directory*”) y oprime Enter para mostrar el nombre del directorio actual. Utiliza `$ pwd` cada vez que sientas que te has extraviado.

El comando `$ ls` (= *list*), simplemente enlista los archivos en el directorio actual. Finalmente, puedes usar `$ cd>` (= *change directory*) como `$ cd NOMBRE_DE_LA_CARPETA` (en donde `NOMBRE_DE_LA_CARPETA` indica la carpeta en la que quieres navegar). Puedes utilizar `$ cd ..`para moverte automáticamente un nivel arriba en la estructura del directorio (el directorio principal de la carpeta en la que te encuentras actualmente). Una vez que has empezado a escribir el nombre de la carpeta, utiliza la tecla de tabulador para autocompletar el nombre -lo cual es particularmente útil para carpetas con nombre muy largos o nombres de carpetas que contienen espacios en blanco.[6](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:5)

Estos tres comandos de terminal: `pwd`, `ls` y `cd` es todo lo que necesitas en este tutorial. Practica con ellos la navegación por las carpetas de tus documentos por unos minutos y mientras piensa en la manera en la que has organizado tus archivos. Si lo deseas, sigue lo que haces ayudándote de tu organizador de archivos de la interfaz gráfica de usuario (Finder) para poder orientarte.

## Usar Pandoc para convertir Markdown a un documento de MS Word

¡Ya estamos listos para la composición tipográfica! Abre la ventana de tu terminal, utiliza `$ pwd`y `$ cd` NOMBRE_DE_LA_CARPETA para navegar hasta la carpeta en la que se encuentra tu proyecto. Una vez que estés ahí escribe `$ ls` en la terminal para enlistar los archivos. Si ves tu archivo `.md` y tus imágenes te encuentras en el lugar correcto. Para convertir `.md` a `.docx` escribe:

```
$ pandoc principal.md -o principal.docx
```

Abre el arhivo con MS Word para contejar tus resultados. Si utilizas Open- o Libre Office puedes ejecutar:

```
$ pandoc principal.md -o principal.odt
```

Si la linea de comandos es una novedad para ti, imagina que lees los comandos anteriores y que dicen algo como: “Pandoc: crea un archivo MS Word a partir de mi archivo Markdown.” La partícula `-o` es una “bandera” que en este caso dice algo como “en vez de que explícitamente tenga yo que indicarte la fuente y el objeto de los formatos de archivos, adivina con sólo ver la extensión de los archivos.” Hay muchas opciones disponibles en Pandoc a través de estas “banderas”. Puedes ver la lista completa en el [sitio web de Pandoc](http://johnmacfarlane.net/pandoc/README.html), o escribiendo en la terminal:

```
$ man pandoc
```

Intenta ejecutar el comando:

```
$ pandoc principal.md -o proyecto.html
```

Ahora navega de nuevo por el directorio de tu proyecto. ¿Puedes decir qué sucedió?

Los usuarios más avanzados que tienen instalado LaTeX querrán experimentar con la conversión de markdown a un archivo `.txt` o a un archivo `.pdf` formateado especialmente. Una vez que se ha instalado LaTeX se pueden crear archivos PDF bellamente formados utilizando la misma estructura de comandos:

```
$ pandoc -o principal.pdf principal.md
```

Asegúrate que tu editor de texto soporte el formato de codificación UTF-8. Cuando utilices LaTeX para convertir al formato .pdf, en vez del atributo `fontfamily` en YAML para cambiar la fuente, especifica el atributo `mainfont` para producir algo como esto:

------

```
title: Flujo de trabajo en texto plano
author: Dennis Tenen, Grant Wythoff
date: 20 de enero de 2014
mainfont: times    ---
```

## Trabajar con bibliografías

En esta sección agregaremos una bibliografía a nuestro documento y después la convertiremos de un formato estilo Chicago a un formato estilo MLA.

Si no estás usando un gestor de referencias bibliográficas como Endnote o Zotero, deberías comenzar a hacerlo inmediatamente. Nosotros preferimos Zotero porque, al igual que Pandoc, fue creado por la comunidad académica y, al igual que otros proyectos de código abierto, es distribuido con una Licencia Pública General de GNU. Mucho más importante para nosotros es que tu gestor de referencias tenga la habilidad de generar bibliografías en formato de texto plano para estar en consonancia con nuestro principio de “todo en texto plano”. Prosigue y abre el gestor de referencias de tu elección y añade algunas entradas de ejemplo. Cuando hayas terminado, encuentra la opción para exportar tu bibliografía en formato BibTeX (`.bib`). Guarda tu archivo `.bib` en el directorio de tu proyecto y dale un nombre razonable como `proyecto.bib`.

La idea general es mantener tus fuentes organizadas en una base de datos bibliográfica centralizada mientras vas generando archivos `.bib` específicos y más pequeños que serán almacenados en el mismo diretorio de tu proyecto. Prosigue y abre tu archivo `.bib` con el editor de texto plano que hayas elegido.[7](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:6)

Tu archivo `.bib` deberá contener múltiples entradas que se ven más o menos así:

```
   @article{fyfe_digital_2011,
        title = {Digital Pedagogy Unplugged},
        volume = {5},
        url = {http://digitalhumanities.org/dhq/vol/5/3/000106/000106.html},
        number = {3},
        urldate = {2013-09-28},
        author = {Fyfe, Paul},
        year = {2011},
        file = {fyfe_digital_pedagogy_unplugged_2011.pdf}
    }
```

Rara vez tendrás que editar esto a mano (aunque puedes hacerlo). En la mayoría de los casos, simplemente exportas el archivo `.bib` de Zotero o de un gestor de referencias similar. Tomate un tiempo para orientarte en esto. Cada entrada consiste en un tipo de documento, “artículo” (*article*) en nuestro caso, un identificador único (fyfe_digital_2011) y los metadatos relevantes de título (*title*), autor (*author*), etc. Lo que más nos interesa es el identificador (ID) único que sigue inmediatamente al símbolo de llave ( { ) en la primera línea de cada entrada. El ID único es lo que nos permite conectar la bibliografía con el documento principal. Deja este archivo abierto por ahora y regresa a tu archivo `principal.md`.

Edita la nota a pie de página en la primera línea de tu archivo `principal.md` para que se vea de una forma parecida a los siguientes ejemplos en los cuales `@nombre_título_fecha` puede ser reemplazado por uno de los ID únicos de tu archivo `proyecto.bib`.

- `Una referencia bibliográfica formateada como ésta se traducirá apropiadamente tanto en un estilo de citación en texto -como en nota a pie- [@nombre_título_fecha, 67].`[8](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fn:7)
- `"Para citas entrecomilladas, pon la coma afuera de los signos de las comillas" [@nombre_título_fecha, 67].`

Una vez que ejecutes el markdown a través de Pandoc, “@fyfe_digital_2011” se ampliará a una citación completa en el estilo que hayas seleccionado. Puedes usar la sintaxis `@citacion` de cualquier manera que veas que encaja: dentro de las líneas de tu texto o en las notas a pie. Para generar una bibliografía simplemente incluye una sección llamada `# Bibliografía` al final del documento.

Ahora, vayamos de nuevo a nuestro bloque de metadatos en el encabezado de tu documento `.md`, y especifica el archivo de bibliografía que deberá utilizarse, algo como:

```
---
title: Flujo de trabajo en texto plano
author: Gabriel García
date: 20 de enero de 2014
bibliography: proyecto.bib
---
```

Esto le dice a Pandoc que busque tu bibliografía en el archivo `proyecto.bib` dentro del mismo directorio de tu archivo `principal.md`. Veamos si esto trabaja. Guarda tu archivo, ve a la ventana de terminal y ejecuta:

```
$ pandoc principal.md --filter pandoc-citeproc -o principal.docx
```

El filtro “pandoc-citeproc” compila todas tus etiquetas de citas. El resultado debe ser un archivo de MS Word formateado decentemente. Si tienes instalado LaTeX, conviértelo a .pdf utilizando la misma sintaxis para mejores resultados. No te preocupes si las cosas no aparecen exactamente de la manera que tú quisieras -recuerda que vas a afinar el formato de todo una vez y más tarde, lo más cerca posible del momento de la publicación. Por ahora solamente estamos creando borradores basados en valores por defecto.

## Cambiar los estilos de citación

El estilo de citación por defecto en Pandoc es el de Chicago Autor-fecha. Podemos especificar un estilo diferente utilizando una hoja de estilo escrita en “lenguaje de estilo de citación” (CSL por *citation style language*, otra convención en texto plano utilizada para describir estilos de citas) y que es designado por la extensión de archivo `.csl`. Afortunadamente, el proyecto CSL mantiene un repositorio de estilos de citaciones comunes, algunas incluso ajustadas a ciertas revistas en específico. Visita http://editor.citationstyles.org/about/ para encontrar el archivo `.csl` para el estilo Modern Language Association (MLA), descarga el archivo `modern-language-association.csl` y guárdalo en la carpeta de tu proyecto como `mla.csl`. Ahora, necesitamos indicarle a Pandoc que utilice la hoja de estilo de MLA en vez de la de Chicago que tiene por defecto. Haremos esto actualizando el encabezado o bloque YAML:

```
---
title: Flujo de trabajo en texto plano
author: Gabriel García
date: 20 de enero de 2014
bibliography: proyecto.bib
csl: mla.csl
---
```

Después simplemente utiliza la funcionalidad de Pandoc para transformar tu archivo de markdown a tu formato objetivo (.pdf o .docx):

```
$ pandoc principal.md --filter pandoc-citeproc -o principal.pdf
```

## Resumen

Ahora debes ser capaz de escribir artículos en Markdown, crear borradores en varios formatos, añadir bibliografías y cambiar estilos de citación de manera sencilla. Un vistazo final al directorio de tu proyecto te mostrará un número de archivos de origen de datos: tu archivo `principal.md`, el archivo `proyecto.bib`, el archivo `mla.csl`, y algunas imágenes. Además de los archivos de origen, deberías ver algunos archivos de salida que creamos durante el tutorial: `principal.docx` o `principal.pdf`. Tu carpeta debe verse más o menos de esta manera.

```
	tutorial-Pandoc/
		principal.md
		proyecto.bib
		mla.csl
		image.jpg
		principal.docx
```

Trata tus archivos de origen como versiones autorizadas de tu texto y los archivos de salida como impresiones desechables que puedes generar fácilmente y sobre la marcha con Pandoc. Todas las revisiones deben ir dentro del archivo `principal.md`. El archivo `principal.docx` está ahí para la última etapa de limpieza y formato. Por ejemplo, si la revista requiere manuscritos a doble espacio, puedes darle el doble espacio rápidamente en Open Office o Microsoft Word. Pero no gastes demasiado tiempo formando. Recuerda que el manuscrito debe ir despojado de todo cuando va a imprenta. El tiempo dedicado a formar cosas innecesarias puede aprovecharse mejor en pulir la prosa de tu borrador.

## Recursos útiles

En caso de meterte en problemas no hay un mejor lugar para empezar a buscar soluciones que el [sitio web de Pandoc](http://johnmacfarlane.net/pandoc/) de John MacFarlane y la [lista de correos](https://groups.google.com/forum/#!forum/pandoc-discuss) afiliada (en inglés). Al menos en dos sitios de tipo “Pregunta y respuesta” puedes encontrar respuestas a preguntas sobre Pandoc: [Stack Overflow](https://stackoverflow.com/questions/tagged/pandoc) y [Digital Humanities Q&A](https://web.archive.org/web/20190203062832/http://digitalhumanities.org/answers/). Puedes hacer preguntas en vivo en Freenode IRC, #Pandoc channel, frecuentado por un amistoso grupo de asiduos. A medida que aprendas más acerca de Pandoc, puedes explorar una de sus particularidades más poderosa: [filtros](https://github.com/jgm/pandoc/wiki/Pandoc-Filters).

Aunque te sugerimos comenzar con un simple editor de texto plano, hay muchas más alternativas (más de 70, de acuerdo con [esta entrada de blog](https://web.archive.org/web/20140120195538/http://mashable.com/2013/06/24/markdown-tools/) a MS Word para trabajar específicamente con Markdown, disponibles en línea y a menudo sin costo. Para las autónomas nos gustan [Mou](http://mouapp.com/), [Write Monkey](http://writemonkey.com/), y [Sublime Text](https://www.sublimetext.com/). Varias plataformas web que han surgido recientemente proporcionan interfaces gráficas adecuadas para desarrollar una escritura colaborativa con seguimiento de cambios en las versiones utilizando Markdown. Éstas incluyen: [prose.io](http://prose.io/), [Authorea](https://www.authorea.com/), [Penflip](http://www.penflip.com/), [Draft](http://www.draftin.com/), y [StackEdit](https://stackedit.io/).

Pero el ecosistema no está limitado sólo a editores. [Gitit](http://gitit.net/) e [Ikiwiki](https://github.com/dubiousjim/pandoc-iki) soportan escritura en Markdown utilizando Pandoc como compilador. A esta lista se puede agregar una serie de herramientas que generan páginas web estáticas de manera rápida: [Yst](https://github.com/jgm/yst), [Jekyll](https://github.com/fauno/jekyll-pandoc-multiple-formats), [Hakyll](http://jaspervdj.be/hakyll/) y [bash shell script](https://github.com/wcaleb/website) por el historiador Caleb McDaniel.

Finalmente, se están creando plataformas de publicación enteras basadas en el uso de Markdown. La plataforma de mercado [Leanpub](https://leanpub.com/) puede ser una alternativa interesante al modelo tradicional de publicación y nosotros mismos estamos experimentando con el diseño de una revista académica en GitHub y [readthedocs.org](https://readthedocs.org/) (herramientas que suelen utilizarse para técnicas de documentación).

1. ¡No te preocupes si no entiendes aún esta terminología! [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:1)
2. [GitHub](https://github.com/dhcolumbia/pandoc-workflow). Utiliza la opción “raw” cuando lo veas en GitHub para observar la fuente de Markdown. Los autores queremos agradecer a Alex Gil y sus colegas del Columbia’s Digital Humanities Center, y a los participantes de openLab en el Studio de la Bilioteca Butler por probar el código de este tutorial en diversas plataformas. [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:2)
3. Véase la excelente discusión sobre este tema, por Charlie Stross, en [Why Microsoft Word Must Die](http://www.antipope.org/charlie/blog-static/2013/10/why-microsoft-word-must-die.html). [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:3)
4. Considera que la extensión `.bib` debe estar “vinculada” a Zotero en tu sistema operativo. Esto significa que si haces doble click en un archivo `.bib`, es probable que Zotero intente abrir el archivo mientras que nosotros queremos abrirlo con un editor de texto. Es posible que en el futuro quieras asociar la extensión `.bib` a tu editor de texto. [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:4)
5. Ten en cuenta que a menudo el YAML replica algo, aunque no todo, de la funcionalidad (bandera) de la línea de comando. Por ejemplo, los estilos de fuentes pueden pasarse a Pandoc en la forma de `pandoc principal.md --mainfont=times -o target.pdf`. Sin embargo, preferimos utilizar las opciones de, encabezado YAML siempre cuando sea posible, pues hace la funcionalidad de nuestra línea de comandos más fácil de escribir y recordar. Utilizando una herramienta de control de cambios como Git preservará tus cambios al YAML, mientras lo que escribes en la terminal es más efímero. Consulta la sección de plantillas en el manual de Pandoc (`man pandoc`) para ver la lista de variables YAML disponibles. [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:ft-1)
6. No hay buenas soluciones para traducir a MS Word desde LaTeX. [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:5)
7. Es una buena idea crearse el hábito de no usar espacios en el nombre de una carpeta o un archivo. Los guiones y guiones bajos en vez espacios en los nombres de archivo aseguran una compatibilidad perdurable entre plataformas cruzadas. [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:6)
8. Gracias a [@njbart](https://github.com/njbart?) por la corrección. En respuesta a nuestra sugerencia original: `Alguna frase que necesita citación.^[@fyfe_digital_2011 argues that too.]` [él escribe](https://github.com/programminghistorian/jekyll/issues/46#issuecomment-59219906): “This is not recommended since it keeps you from switching easily between footnote and author-date styles. Better use the [corrected] (no circumflex, no final period inside the square braces, and the final punctuation of the text sentence after the square braces; with footnote styles, pandoc automatically adjusts the position of the final punctuation).” [↩](https://programminghistorian.org/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown#fnref:7)

##### ACERCA DE LOS AUTORES

Dennis Tenen es profesor asistente de Inglés y Literatura Comparativa en la Universidad de Columbia.



Grant Wythoff es profesor adjunto en el Departamento de Inglés y Literatura Comparativa de la Universidad de Columbia.



##### CITA SUGERIDA

Dennis Tenen y Grant Wythoff, "Escritura sostenible en texto plano usando Pandoc y Markdown", traducido por Víctor Gayol, *The Programming Historian en español* 1 (2017), https://doi.org/10.46430/phes0008.

## ¡Haz una donación!

Producir buenos tutoriales de acceso abierto cuesta dinero. Únete al creciente número de personas que [apoya a *The Programming Historian*](https://www.patreon.com/theprogramminghistorian) para que podamos continuar compartiendo conocimientos de forma gratuita.

*The Programming Historian en español* (ISSN: 2517-5769) se publica con una licencia [CC-BY](https://creativecommons.org/licenses/by/4.0/deed.es).

Este proyecto es administrado por ProgHist Limited, con número de compañía [12192946](https://beta.companieshouse.gov.uk/company/12192946).

[ISSN 2397-2068 (inglés)](https://programminghistorian.org/)

**[ISSN 2517-5769 (español)](https://programminghistorian.org/es)**

[ISSN 2631-9462 (francés)](https://programminghistorian.org/fr)

[ISSN 2753-9296 (portugués)](https://programminghistorian.org/pt)

 [Alojado en GitHub](https://github.com/programminghistorian/jekyll)

 [Última actualización el 19 April 2021](https://github.com/programminghistorian/jekyll/commits/gh-pages)

 [Suscripción a RSS](https://programminghistorian.org/feed.xml)

 [Versiones anteriores](https://github.com/programminghistorian/jekyll/commits/gh-pages/es/lecciones/escritura-sostenible-usando-pandoc-y-markdown.md)

 [Envíanos tus comentarios](https://programminghistorian.org/es/retroalimentacion)

 [Política de retirada de lecciones](https://programminghistorian.org/es/politica-retirada-lecciones)

 [Concordancia de traducción](https://programminghistorian.org/translation-concordance)

