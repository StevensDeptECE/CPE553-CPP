# MarkDown

Markdown is a document formatting language designed to be simpler than HTML/CSS, yet allow bringing in HTML and CSS if you want full control. It allows easily creating tables, has intuitive bullet lists and is far more compact.

Here is a [document](https://www.markdownguide.org/cheat-sheet/) defining standard markdown.

Equations are supported in github, though not in standard markdown. Anything in dollar signs gets turned into mathjax, typically implemented as either an image or mathml in the browser

Example equation: $x^2 + 2x + 1$

There are some things that markdown does not do well.

First of all, there is no good standard for variables. If I want to have many links in a document, all relative to https://test.com I have to actually type that string repeatedly. If I then want to change the URL to something else, I have to change every occurrence.

Similarly, suppose there are repetitive sections in multiple markdown files. There should be a macro preprocessor to bring in files, possibly parameterized.

The following syntax is proposed. Due to markdown using the hash sign \# the special character chosen is %.

```cpp
@def x=123          # support numbers, strings, lists?
@include filename   # brings in contents of a file
@include filename(12) #include a file passing a parameter?
@fn f(a,b,c) {}     # define a function to be called later contents are legal markdown
